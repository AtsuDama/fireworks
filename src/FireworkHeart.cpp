#include "FireworkHeart.h"

FireworkHeart::FireworkHeart(int _n, int _pmax) : FireworkBase(_n, _pmax) {
}

void FireworkHeart::explode() {
  if (particles.size() == 1 && particles[0].velocity.y > 0) {
    float r = ofRandom(2, pmax) / 10;
    float theta_r = ofRandom(0,  TWO_PI);
    for (int i = 0; i < n; i++) {
      float x0 = particles[0].position.x;
      float y0 = particles[0].position.y;
      float z0 = particles[0].position.z;
      float theta = ofRandom(0, TWO_PI);
      float x = 16 * pow(sin(theta), 3);
      float y = 13 * cos(theta) - 5 * cos(2 * theta) - 2 * cos(3 * theta) - cos(4 * theta);
      float x_r = cos(theta_r) * x - sin(theta_r) * y;
      float y_r = sin(theta_r) * x + cos(theta_r) * y;
      ofVec3f f;
      f.set(r * x_r, r * y_r, 0);
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
