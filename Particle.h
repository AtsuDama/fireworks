#pragma once
#include "ofMain.h"

class Particle {

  public:

    Particle(float _h, float _s, float _b, int _r, float _particleType, float _x0, float _y0, float _z0);

    void particleColorSet();
    void update();
    void addForce(ofVec3f force);
    void statusChange();
    ofVec3f position;
    ofVec3f velocity;
    ofVec3f acceleration;
    ofVec3f gravity;
    float mass;
    float radius;
    float h;
    float s;
    float b;
    float friction;
    float lifetime;
    int status;
    float particleType;
    ofFloatColor col;

};
