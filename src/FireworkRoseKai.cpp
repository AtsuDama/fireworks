#include "FireworkRoseKai.h"

FireworkRoseKai::FireworkRoseKai(int _n, int _pmax) : FireworkBase(_n, _pmax) {
  offset = 1;
}

void FireworkRoseKai::explode() {
  if (particles.size() == 1 && particles[0].velocity.y > 0) {
    float t = floor(ofRandom(1, 10));
    float s = floor(ofRandom(1, 10));
    float p;
    float k = t/s;
    if (fmod(t * s, 2.0) == 0){
        p = 2.0;
    } else {
        p = 1.0;
    }
    //float r = ofRandom(2, pmax);
    float r = pmax;
    for (int i = 0; i < n; i++) {
      float x0 = particles[0].position.x;
      float y0 = particles[0].position.y;
      float z0 = particles[0].position.z;
      float theta = ofRandom(0, PI * s * p);
      float x = (r * sin(k * theta)) * cos(theta);
      float y = (r * sin(k * theta)) * sin(theta);
      ofVec3f f;
      f.set(x, y, 0);
      particles.push_back(Particle(h1, s1, b1, 2, particleType, x0, y0, z0));
      particles_mod.push_back(Particle(h2, s2, b2, 2, particleType, x0, y0, z0));
      particles[i + 1].addForce(f);
      particles_mod[i + 1].addForce(f);
    }
    float pan = ofMap(particles[0].position.x, 0, ofGetWidth(), -1.0f, 1.0f);
    float vol = ofMap(pmax, 2, 12, 0.2f, 5.0f);
    soundPlayer.setPan(pan);
    soundPlayer.setVolume(vol);
    soundPlayer.play();
    particles.erase(particles.begin() + 0);
    particles_mod.erase(particles_mod.begin() + 0);
  }
}