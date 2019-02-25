#include "ManagementSystem.h"

ManagementSystem::ManagementSystem() {
}

void ManagementSystem::fireworkSelector(int frameCount, int pCount, int nl, int iFrame, int pmax) {
  if (frameCount % iFrame == 0) {
    for (int i = 0; i < nl; i++) {
      float probability = ofRandom(1);
      //float probability = 0.99;
      if (probability < 0.8) {
        fireworks.push_back(new FireworkBase(pCount, pmax));
      } else if (probability >= 0.8 && probability < 0.82) {
        fireworks.push_back(new FireworkDoubleColors(pCount, pmax));
      } else if (probability >= 0.82 && probability < 0.90) {
        fireworks.push_back(new FireworkTripleColors(pCount, pmax));
      } else if (probability >= 0.90 && probability < 0.91) {
        fireworks.push_back(new FireworkRainbowColors(pCount, pmax));
      } else if (probability >= 0.91 && probability < 0.93){
        fireworks.push_back(new FireworkRose(pCount / 2, pmax));
      } else if (probability >= 0.93 && probability < 0.95) {
        fireworks.push_back(new FireworkHeart(pCount / 2, pmax));
      } else {
        fireworks.push_back(new FireworkStar(pCount, pmax));
      }
    }
  }
}

void ManagementSystem::toMesh() {
  for (auto i = 0u; i < fireworks.size(); i++) {
    fireworks[i]->launch();
    fireworks[i]->explode();
    fireworks[i]->update();
    for (auto j = 0u; j < fireworks[i]->particles.size(); j++) {
      vboMesh.addVertex(fireworks[i]->particles[j].position);
      vboMesh.addColor(fireworks[i]->particles[j].col);
      if (fireworks[i]->offset == 0) {
        vboMesh.addVertex(fireworks[i]->particles_mod[j].position);
        vboMesh.addColor(fireworks[i]->particles_mod[j].col);
      } else if (fireworks[i]->offset == 1) {
        ofVec3f p;
        p.set(ofRandom(-5, 5), ofRandom(-5, 5), ofRandom(-5, 5));
        vboMesh.addVertex(fireworks[i]->particles_mod[j].position + p);
        vboMesh.addColor(fireworks[i]->particles_mod[j].col);
      }
    }
    if (fireworks[i]->statusTotal() == 0 && fireworks[i]->particles.size() > 1) {
      fireworks[i]->soundPlayer.unload();
      fireworks.erase(fireworks.begin() + i);
    }
  }
}

void ManagementSystem::run(int frameCount, int pCount, int nl, int iFrame, int pmax) {
  vboMesh.clear();
  fireworkSelector(frameCount, pCount, nl, iFrame, pmax);
  toMesh();
  vboMesh.setMode(OF_PRIMITIVE_POINTS);
  glPointSize(3.0);
  vboMesh.draw();
}
