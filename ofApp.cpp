#include "ofApp.h"
#include "Particle.h"
#include "Firework.h"

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
  gui.add(pCount.setup("Particle", 1000, 100, 10000));
  gui.add(nl.setup("Launch", 1, 1, 50));
  gui.add(iFrame.setup("Interval", 60, 1, 600));
  gui.add(pmax.setup("Maximum Size", 8, 2, 12));
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
  //ofEnableAlphaBlending();
  ofEnableBlendMode(OF_BLENDMODE_ALPHA);
  ofSetColor(0, 0, 0, 40);
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  ofDisableAlphaBlending();
  ofEnableBlendMode(OF_BLENDMODE_ADD);
  vboMesh.clear();
  if (frameCount % iFrame == 0) {
    for (int i = 0; i < nl; i++) {
      fireworks.push_back(new Firework(pCount, pmax));
    }
  }
  for (auto i = 0u; i < fireworks.size(); i++) {
    fireworks[i]->launch();
    fireworks[i]->explode();
    fireworks[i]->update();
    for (auto j = 0u; j < fireworks[i]->particles.size(); j++) {
      vboMesh.addVertex(fireworks[i]->particles[j].position);
      vboMesh.addColor(fireworks[i]->particles[j].col);
      if (fireworks[i]->offset == 0) {
        vboMesh.addVertex(fireworks[i]->particles_mod[j].position);
        vboMesh.addColor(fireworks[i]->particles_mod[j].col);
      }
      else if (fireworks[i]->offset == 1) {
        ofVec3f p;
        p.set(ofRandom(-5, 5), ofRandom(-5, 5), ofRandom(-5, 5));
        vboMesh.addVertex(fireworks[i]->particles_mod[j].position + p);
        vboMesh.addColor(fireworks[i]->particles_mod[j].col);
      }
    }
    if (fireworks[i]->statusTotal() == 0 && fireworks[i]->particles.size() > 1) {
      fireworks.erase(fireworks.begin() + i);
    }
  }
  vboMesh.setMode(OF_PRIMITIVE_POINTS);
  glPointSize(3.0);
  vboMesh.draw();
  frameCount += 1;
  gui.draw();

  //stringstream ss;
  //ss << "Framerate: " << ofToString(ofGetFrameRate(), 0);
  //ofDrawBitmapString(ss.str(), 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  if (key == 's') {
    img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    img.save("screenShot_" + ofGetTimestampString() + ".png", OF_IMAGE_QUALITY_BEST);
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
