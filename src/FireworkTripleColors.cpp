#include "FireworkTripleColors.h"

FireworkTripleColors::FireworkTripleColors(int _n, int _pmax) : FireworkBase(_n, _pmax) {
}

void FireworkTripleColors::explode() {
  if (particles.size() == 1 && particles[0].velocity.y > 0) {
    for (int i = 0; i < n; i++) {
      float x0 = particles[0].position.x;
      float y0 = particles[0].position.y;
      float z0 = particles[0].position.z;
      float theta = ofRandom(0, TWO_PI);
      float r;
      float p = ofRandom(1);
      if (p < 0.33) {
        r = ofRandom(0, pmax / 3);
      } else if (p >= 0.33 && p < 0.66) {
        r = ofRandom(pmax / 3, 2 * pmax / 3);
      } else {
        r = ofRandom(2 * pmax / 3, pmax);
      }
      float x = r * cos(theta);
      float y = r * sin(theta);
      ofVec3f f;
      f.set(x, y, 0);
      if (r < pmax / 3) {
        particles.push_back(Particle(h1, s1, b1, 2, particleType, x0, y0, z0));
        particles_mod.push_back(Particle(h1, s1, b1, 2, particleType, x0, y0, z0));
      } else if (r >= pmax / 3 && r < 2 * pmax / 3) {
        particles.push_back(Particle((h1 + h2) / 2, s1, b1, 2, particleType, x0, y0, z0));
        particles_mod.push_back(Particle((h1 + h2) / 2, s1, b1, 2, particleType, x0, y0, z0));
      } else {
        particles.push_back(Particle(h2, s1, b1, 2, particleType, x0, y0, z0));
        particles_mod.push_back(Particle(h2, s1, b1, 2, particleType, x0, y0, z0));
      }
      particles[i + 1].addForce(f);
      particles_mod[i + 1].addForce(f);
    }
    particles.erase(particles.begin() + 0);
    particles_mod.erase(particles_mod.begin() + 0);
  }
}
