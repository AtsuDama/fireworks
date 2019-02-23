#include "Particle.h"

Particle::Particle(float _h, float _s, float _b, int _r, float _particleType, float _x0, float _y0, float _z0) {
  mass = 1.0;
  radius = _r;
  friction = 0.02;
  gravity.set(0.0, 0.005, 0.0);
  h = _h;
  s = _s;
  b = _b;
  position.set(_x0, _y0, _z0);
  velocity.set(0.0, 0.0, 0.0);
  acceleration.set(0.0, 0.0, 0.0);
  lifetime = 0.7;
  status = 1;
  particleType = _particleType;
  col = ofFloatColor(0);
  col.setHsb(h, s, b, lifetime);
}

void Particle::particleColorSet() {
  if (particleType <= 0.4) {
    col.setHsb(h, s, b, lifetime / 2);
  } else if (particleType > 0.4 && particleType <= 0.45) {
    col.setHsb(ofRandom(1), ofRandom(1), ofRandom(1), lifetime / 2);
  } else if (particleType > 0.45 && particleType <= 0.6) {
    col.setHsb(h * abs(cos(1.5 * lifetime)), s, b, lifetime / 2);
  } else if (particleType > 0.6 && particleType <= 0.8) {
    if (ofRandom(1) < 0.2) {
      col.setHsb(h, s, b, lifetime);
    } else {
      col.setHsb(1.0, 0.0, 0.0, 0.0);
    }
  } else if (particleType > 0.8 && particleType <= 1.0) {
    if (ofRandom(1) < 0.7) {
      col.setHsb(h, s, b, lifetime);
    } else {
      col.setHsb(1.0 - h, s, b, lifetime);
    }
  }
}

void Particle::update() {
  acceleration += gravity;
  velocity += acceleration;
  velocity *= (1.0 - friction);
  position += velocity;
  lifetime -= 0.004;
  acceleration.set(0.0, 0.0, 0.0);
  particleColorSet();
}

void Particle::addForce(ofVec3f force) {
  acceleration += force / mass;
}

void Particle::statusChange() {
  if (lifetime <= 0) {
    status = 0;
  } else {
    status = 1;
  }
}
