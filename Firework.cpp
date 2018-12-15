#include "Firework.h"
#include "Particle.h"

Firework::Firework(int _n, int _pmax) {
  n = _n;
  h1 = ofRandom(1);
  s1 = ofRandom(1);
  b1 = ofRandom(1);
  h2 = ofRandom(1);
  s2 = ofRandom(1);
  b2 = ofRandom(1);
  pmax = ofRandom(2, _pmax);
  status = 0;
  shapeType = ofRandom(0, 1);
  particleType = ofRandom(0, 1);
  offset = int(ofRandom(0, 2));
}

void Firework::launch() {
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

void Firework::explode() {
  if (particles.size() == 1 && particles[0].velocity.y > 0) {
    if (shapeType < 0.6) {
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
    }
    else if (shapeType >= 0.6 && shapeType < 0.8) {
      for (int i = 0; i < n; i++) {
        float x0 = particles[0].position.x;
        float y0 = particles[0].position.y;
        float z0 = particles[0].position.z;
        float theta = ofRandom(0, TWO_PI);
        float r;
        float p = ofRandom(1);
        if (p < 0.5) {
          r = ofRandom(0, pmax / 2);
        }
        else {
          r = ofRandom(pmax / 2, pmax);
        }
        float x = r * cos(theta);
        float y = r * sin(theta);
        ofVec3f f;
        f.set(x, y, 0);
        if (r < pmax / 2) {
          particles.push_back(Particle(h1, s1, b1, 2, particleType, x0, y0, z0));
          particles_mod.push_back(Particle(h1, s1, b1, 2, particleType, x0, y0, z0));
        }
        else {
          particles.push_back(Particle(h2, s1, b1, 2, particleType, x0, y0, z0));
          particles_mod.push_back(Particle(h2, s1, b1, 2, particleType, x0, y0, z0));
        }
        particles[i + 1].addForce(f);
        particles_mod[i + 1].addForce(f);
      }
    }
    else if (shapeType >= 0.8 && shapeType < 1.0) {
      float k = floor(ofRandom(2, 5));
      float r = ofRandom(2, pmax);
      for (int i = 0; i < n; i++) {
        float x0 = particles[0].position.x;
        float y0 = particles[0].position.y;
        float z0 = particles[0].position.z;
        float theta = ofRandom(0, TWO_PI);
        float x = (r * sin(k * theta)) * cos(theta);
        float y = (r * sin(k * theta)) * sin(theta);
        ofVec3f f;
        f.set(x, y, 0);
        particles.push_back(Particle(h1, s1, b1, 2, particleType, x0, y0, z0));
        particles_mod.push_back(Particle(h2, s2, b2, 2, particleType, x0, y0, z0));
        particles[i + 1].addForce(f);
        particles_mod[i + 1].addForce(f);
      }
    }
    particles.erase(particles.begin() + 0);
    particles_mod.erase(particles_mod.begin() + 0);
  }
}

void Firework::update() {
  for (auto i = 0u; i < particles.size(); i++ ) {
    particles[i].update();
    particles_mod[i].update();
    particles[i].statusChange();
    particles_mod[i].statusChange();
  }
}

int Firework::statusTotal() {
  status = 0;
  for (auto i = 0u; i < particles.size(); i++) {
    status += particles[i].status;
  }
  return status;
}
