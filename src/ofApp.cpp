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
  gui.add(mode.setup("Shape mode", 0, 0, 4)); //モード
  gui.add(pause.setup("Pause", true)); //チェックで花火を打ち上げない
  guiShow = true; //GUIの表示を切り替えるためのステート
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
  if (demoShow == true) {
    demoRun();
  }

  //打ち上げオンオフ用トグル
  if (pause == true) {
    system.noLaunchRun(pSize);  //トグルオンで花火を打ち上げない  
  } else {
    system.run(frameCount, pCount, nl, iFrame, pmax, pSize, mode);  //トグルオフで花火を打ち上げる
  }

  if (guiShow == true) {
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
    img.save("tmp/screenshot_" + ofGetTimestampString() + ".jpeg", OF_IMAGE_QUALITY_BEST);
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
    img.save("screenshot_" + ofGetTimestampString() + ".jpeg", OF_IMAGE_QUALITY_BEST);
  }
  //gキーでGUIパネルをオンオフ
  if (key == 'g') {
    if (guiShow == false) {
      guiShow = true;
    } else {
      guiShow = false;
    }
  }
  //0キーで通常モード
  if (key == '0') {
    mode = 0;
  }
  //1キーで"Rose curve"モード
  if (key == '1') {
    mode = 1;
  }
  //2キーで"heart shape"モード
  if (key == '2') {
    mode = 2;
  }
  //3キーで"star shape"モード
  if (key == '3') {
    mode = 3;
  }
  //4キーで"Children"モード
  if (key == '4') {
    mode = 4;
  }

  //dキーでデモスタート
  if (key == 'd') {
    frameCount = 0;
    if (demoShow == false) {
      demoShow = true;
      pause = false;
    } else {
      demoShow = false;
      pause = true;
    }
  }

  //pキーで打ち上げオンオフ切り替え
  if (key == 'p') { 
    if (pause == true) {
      pause = false;  
    } else {
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
