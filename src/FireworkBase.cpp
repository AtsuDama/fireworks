#include "FireworkBase.h"

FireworkBase::FireworkBase(int _n, int _pmax) {
  n = _n;
  h1 = ofRandom(1);
  s1 = ofRandom(1);
  b1 = ofRandom(1);
  h2 = ofRandom(1);
  s2 = ofRandom(1);
  b2 = ofRandom(1);
  pmax = ofRandom(2, _pmax);
  status = 0;
  particleType = ofRandom(0, 1);
  offset = int(ofRandom(0, 2));
  soundPlayer.setMultiPlay(true);
  soundPlayer.load("sound.wav");
}

void FireworkBase::launch() {
  if (particles.size() == 0) {
    int offset = 100;
    float x0 = ofRandom(offset, ofGetWidth() - offset);
    float y0 = ofGetHeight();
    float z0 = 0;
    particles.push_back(Particle(h1, s1, b1, 2, particleType, x0, y0, z0));
    particles_mod.push_back(Particle(h2, s2, b2, 2, particleType, x0, y0, z0));
    ofVec3f f;
    f.set(0, ofRandom(-15, -10), 0);
    particles[0].addForce(f);
    particles_mod[0].addForce(f);
  }
}

void FireworkBase::explode() {
  if (particles.size() == 1 && particles[0].velocity.y > 0) {
    for (int i = 0; i < n; i++) {
      float x0 = particles[0].position.x;
      float y0 = particles[0].position.y;
      float z0 = particles[0].position.z;
      float theta = ofRandom(0, TWO_PI);
      float r = ofRandom(0, pmax);
      float x = r * cos(theta);
      float y = r * sin(theta);
      ofVec3f f;
      f.set(x, y, 0);
      particles.push_back(Particle(h1, s1, b1, 2, particleType, x0, y0, z0));
      particles_mod.push_back(Particle(h2, s2, b2, 2, particleType, x0, y0, z0));
      particles[i + 1].addForce(f);
      particles_mod[i + 1].addForce(f);
    }
    float pan = ofMap(particles[0].position.x, 0, ofGetWidth(), -1.0f, 1.0f);
    float vol = ofMap(pmax, 2, 12, 0.5f, 3.0f);
    soundPlayer.setPan(pan);
    soundPlayer.setVolume(vol);
    soundPlayer.play();
    particles.erase(particles.begin() + 0);
    particles_mod.erase(particles_mod.begin() + 0);
  }
}

void FireworkBase::update() {
  for (auto i = 0u; i < particles.size(); i++ ) {
    particles[i].update();
    particles_mod[i].update();
    particles[i].statusChange();
    particles_mod[i].statusChange();
  }
}

int FireworkBase::statusTotal() {
  status = 0;
  for (auto i = 0u; i < particles.size(); i++) {
    status += particles[i].status;
  }
  return status;
}
