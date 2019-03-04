#pragma once
#include "FireworkBase.h"
#include "FireworkDoubleColors.h"
#include "FireworkTripleColors.h"
#include "FireworkRainbowColors.h"
#include "FireworkRose.h"
#include "FireworkHeart.h"
#include "FireworkStar.h"

class ManagementSystem {

  public:

    ManagementSystem();

    void fireworkSelector(int frameCount, int pCount, int nl, int iFrame, int pmax);
    void toMesh();
    void run(int frameCount, int pCount, int nl, int iFrame, int pmax, int pSize);
		void programedLaunch();

		ofVboMesh vboMesh;

		vector<FireworkBase*> fireworks;

};
