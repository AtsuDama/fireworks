#pragma once
#include "FireworkBase.h"
#include "FireworkStar.h"

class FireworkStar: public FireworkBase {

  public:

    FireworkStar(int _n, int _pmax);
    void explode();

};
