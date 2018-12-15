#pragma once
#include "ofMain.h"
#include "Particle.h"

class Firework {

  public:

    Firework(int _n, int _pmax);

    void update();
    void launch();
    void explode();
    int statusTotal();
    vector<Particle> particles;
    vector<Particle> particles_mod;
    int n;
    float h1;
    float s1;
    float b1;
    float h2;
    float s2;
    float b2;
    int pmax;
    int status;
    float shapeType;
    float particleType;
    int offset;

};
