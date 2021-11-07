#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetFrameRate(60); //set framerate at 60fps
  ofSetVerticalSync(true);  //V-Sync on
  ofSetBackgroundAuto(false); //set BackgroundAuto off
  ofBackground(0);  //set Background color black
  //ofEnableDepthTest();
  ofEnableSmoothing();  //set smoothing on
  //ofEnableBlendMode(OF_BLENDMODE_ADD);
  //ofEnableAlphaBlending();
  frameCount = 0; //initialize frameCount and set it 0
  gui.setup();  //GUIをセット
  gui.add(pCount.setup("Particle number", 1000, 500, 10000)); //パーティクル数
  gui.add(nl.setup("Launching number", 1, 1, 50));  //同時打上数
  gui.add(iFrame.setup("Launching interval", 36, 1, 600));  //打ち上げ間隔
  gui.add(pmax.setup("Firework size", 5, 2, 12));  //花火サイズ
  gui.add(pSize.setup("Point size", 2, 1, 10)); //パーティクルサイズ
  gui.add(rInterval.setup("Refresh interval", 2, 1, 10)); //リフレッシュ間隔（黒い四角で塗る間隔）
  gui.add(trace.setup("Trace", 25, 0, 100));  //黒い四角の透過具合
  gui.add(mode.setup("Shape mode", 0, 0, 3)); //モード
  gui.add(pause.setup("Pause", true)); //チェックで花火を打ち上げない
  guiState = 1; //GUIの表示を切り替えるためのステート
  system = ManagementSystem();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
  ofEnableBlendMode(OF_BLENDMODE_ALPHA);
  ofSetColor(0, 0, 0, trace);
  if (frameCount % rInterval == 0) {
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  }
  ofDisableAlphaBlending();
  ofEnableBlendMode(OF_BLENDMODE_ADD);
  
  //Demo用の記述
  if (demoState == 1) {
    demoRun();
  }

  //打ち上げオンオフ用トグル
  if (pause == true) {
    system.noLaunchRun(pSize);  //トグルオンで花火を打ち上げない  
  } else {
    system.run(frameCount, pCount, nl, iFrame, pmax, pSize, mode);  //トグルオフで花火を打ち上げる
  }

  if (guiState == 1) {
    gui.draw();   //gキーでGUIをオンオフ
  }
  frameCount ++;  //フレーム数カウント用
  //capture(300, 3400); //動画用スクリーンショットを取得、キャプチャの際はコメントアウト
}
//--------------------------------------------------------------
//動画用の連続したスクリーンショットを取得するための関数
void ofApp::capture(int start, int end) {
  if (frameCount > start && frameCount < end) {
    img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    img.save("tmp/screenshot_" + ofGetTimestampString() + ".png", OF_IMAGE_QUALITY_BEST);
  }
}
//--------------------------------------------------------------
//デモ用
void ofApp::demoRun() {

  if (frameCount > 3000) {
    frameCount = 0;
    nl = 1;
    pmax = 5;
    iFrame = 36;
    mode = 0;    
  }
  
  if (frameCount == 300) {
    pause = false;
  } else if (frameCount == 900) {
    pause = true;
  } else if (frameCount == 1080) {
    pause = false;
    mode = 1;
  } else if (frameCount == 1380) {
    mode = 2;
  } else if (frameCount == 1680) {
    mode = 3;
  } else if (frameCount == 1980) {
    pause = true;
  } else if (frameCount == 2160) {
    pause = false;
    mode = 0;
    pmax = 8;
    iFrame = 60;
    nl = 2;
  } else if (frameCount == 2760) {
    pmax = 3;
    iFrame = 1;
    nl = 1;
  } else if (frameCount == 2880) {
    pause = true;
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  //sキーでスクリーンショットを取得
  if (key == 's') {
    img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    img.save("screenshot_" + ofGetTimestampString() + ".png", OF_IMAGE_QUALITY_BEST);
  }
  //gキーでGUIパネルをオンオフ
  if (key == 'g') {
    if (guiState == 0) {
      guiState = 1;
    } else {
      guiState = 0;
    }
  }
  //nキーで通常モード
  if (key == 'n') {
    mode = 0;
  }
  //rキーで"Rose curve"モード
  if (key == 'r') {
    mode = 1;
  }
  //hキーで"heart shape"モード
  if (key == 'h') {
    mode = 2;
  }
  //sキーで"star shape"モード
  if (key == 's') {
    mode = 3;
  }

  //dキーでデモスタート
  if (key == 'd') {
    frameCount = 0;
    if (demoState == 0) {
      demoState = 1;
      pause = false;
    } else {
      demoState = 0;
      pause = true;
    }
  }
  
  
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
