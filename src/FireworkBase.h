#pragma once
#include "Particle.h"

class FireworkBase {

  public:

    FireworkBase(int _n, int _pmax);

    virtual void update();
    virtual void launch();
    virtual void explode();
    virtual int statusTotal();
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
    float particleType;
    int offset;

};
