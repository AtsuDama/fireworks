#pragma once
#include "FireworkBase.h"
#include "FireworkHeart.h"

class FireworkHeart: public FireworkBase {

  public:

    FireworkHeart(int _n, int _pmax);
    void explode();

};
