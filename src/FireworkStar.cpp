#include "FireworkStar.h"

FireworkStar::FireworkStar(int _n, int _pmax) : FireworkBase(_n, _pmax) {
}

void FireworkStar::explode() {
  if (particles.size() == 1 && particles[0].velocity.y > 0) {
    float R = 5;
    float r = 3;
    float d = 5;
    //float k = ofRandom(2, pmax) / 5;
    float theta_r = ofRandom(0,  TWO_PI / 5);
    for (int i = 0; i < n; i++) {
      float x0 = particles[0].position.x;
      float y0 = particles[0].position.y;
      float z0 = particles[0].position.z;
      float k = ofRandom(0, pmax) / 5;
      float theta = ofRandom(0, 3 * TWO_PI);
      float x = (R - r) * cos(theta) + d * cos((R - r) * theta / r);
      float y = (R - r) * sin(theta) - d * sin((R - r) * theta / r);
      float x_r = cos(theta_r) * x - sin(theta_r) * y;
      float y_r = sin(theta_r) * x + cos(theta_r) * y;
      ofVec3f f;
      f.set(k * x_r, k * y_r, 0);
      particles.push_back(Particle(h1, s1, b1, 2, particleType, x0, y0, z0));
      particles_mod.push_back(Particle(h2, s2, b2, 2, particleType, x0, y0, z0));
      particles[i + 1].addForce(f);
      particles_mod[i + 1].addForce(f);
    }
    particles.erase(particles.begin() + 0);
    particles_mod.erase(particles_mod.begin() + 0);
  }
}
