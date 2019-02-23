#include "FireworkDoubleColors.h"

FireworkDoubleColors::FireworkDoubleColors(int _n, int _pmax) : FireworkBase(_n, _pmax) {
}

void FireworkDoubleColors::explode() {
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
      if (theta < PI) {
        particles.push_back(Particle(h1, s1, b1, 2, particleType, x0, y0, z0));
        particles_mod.push_back(Particle(h1, s1, b1, 2, particleType, x0, y0, z0));
      } else {
        particles.push_back(Particle(1 - h1, s1, b1, 2, particleType, x0, y0, z0));
        particles_mod.push_back(Particle(1 - h1, s1, b1, 2, particleType, x0, y0, z0));
      }
      particles[i + 1].addForce(f);
      particles_mod[i + 1].addForce(f);
    }
    particles.erase(particles.begin() + 0);
    particles_mod.erase(particles_mod.begin() + 0);
  }
}
