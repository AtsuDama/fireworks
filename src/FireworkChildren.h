#pragma once
#include "FireworkBase.h"
#include "FireworkChildren.h"

class FireworkChildren: public FireworkBase {

  public:

    FireworkChildren(int _n, int _pmax);
    void explode();

};
