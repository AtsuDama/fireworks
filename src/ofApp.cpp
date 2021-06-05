#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetFrameRate(60);
  ofSetVerticalSync(true);
  ofSetBackgroundAuto(false);
  ofBackground(0);
  //ofEnableDepthTest();
  ofEnableSmoothing();
  //ofEnableBlendMode(OF_BLENDMODE_ADD);
  //ofEnableAlphaBlending();
  frameCount = 0;
  gui.setup();
  gui.add(pCount.setup("Particle", 1000, 500, 10000));
  gui.add(nl.setup("Launch", 1, 1, 50));
  gui.add(iFrame.setup("Interval", 20, 1, 600));
  gui.add(pmax.setup("Maximum Size", 8, 2, 12));
  gui.add(pSize.setup("Point Size", 3, 1, 10));
  gui.add(toggle.setup("Rest", true));
  system = ManagementSystem();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
  //system.programedLaunch();
  //ofEnableAlphaBlending();
  ofEnableBlendMode(OF_BLENDMODE_ALPHA);
  ofSetColor(0, 0, 0, 40);
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  ofDisableAlphaBlending();
  ofEnableBlendMode(OF_BLENDMODE_ADD);
  if (toggle == true) {
    system.noLaunchRun(pSize);  
  } else {
    system.run(frameCount, pCount, nl, iFrame, pmax, pSize);
  }
  gui.draw();
  frameCount ++;
  //capture(600, 1200);
}
//--------------------------------------------------------------
void ofApp::capture(int start, int end) {
  if (frameCount > start && frameCount < end) {
    img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    img.save("tmp/screenshot_" + ofGetTimestampString() + ".bmp", OF_IMAGE_QUALITY_BEST);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  if (key == 's') {
    img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    img.save("screenshot_" + ofGetTimestampString() + ".bmp", OF_IMAGE_QUALITY_BEST);
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
