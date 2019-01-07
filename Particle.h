#pragma once
#include "ofMain.h"

//Particle class
class Particle {

  public:

    Particle(float _h, float _s, float _b, int _r, float _particleType, float _x0, float _y0, float _z0);

    void particleColorSet();          //set color to particle
    void update();                    //update particle status (position, velocity, etc.)
    void addForce(ofVec3f force);     //apply force to particle
    void statusChange();              //particle is alive or dead depending on its lifetime
    ofVec3f position;                 //position
    ofVec3f velocity;                 //velocity
    ofVec3f acceleration;             //acceleration
    ofVec3f gravity;                  //gravity
    float mass;                       //mass
    float radius;                     //radius
    float h;                          //H value on HSV model
    float s;                          //S value on HSV model
    float b;                          //B value on HSV model
    float friction;                   //friction
    float lifetime;                   //lifetime
    int status;                       //status(particle is alive(1) or dead(0))
    float particleType;               //particle type
    ofFloatColor col;                 //particle color

};
