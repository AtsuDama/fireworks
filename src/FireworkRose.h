#pragma once
#include "FireworkBase.h"
#include "FireworkRose.h"

class FireworkRose: public FireworkBase {

  public:

    FireworkRose(int _n, int _pmax);
    void explode();

};
