#pragma once
#include "FireworkBase.h"
#include "FireworkDoubleColors.h"
#include "FireworkTripleColors.h"
#include "FireworkRainbowColors.h"
#include "FireworkRose.h"
#include "FireworkRoseKai.h"
#include "FireworkHeart.h"
#include "FireworkStar.h"

class ManagementSystem {

  public:

    ManagementSystem();

    void fireworkSelector(int frameCount, int pCount, int nl, int iFrame, int pmax, int mode);
    void toMesh();
    void run(int frameCount, int pCount, int nl, int iFrame, int pmax, int pSize, int mode);
    void noLaunchRun(int pSize);
		void programedLaunch();

		ofVboMesh vboMesh;

		vector<FireworkBase*> fireworks;

};
