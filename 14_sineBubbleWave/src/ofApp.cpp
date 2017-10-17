#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    circleNumber = 22;
    rowNumber = 100;
}

float ofApp::circleLine(float xIn, float yIn, float wIn, float hIn, float scaleIn){
    ofSeedRandom(0);
    ofSetCircleResolution(100);

    container.set(xIn, yIn, wIn, hIn);
    container.scaleFromCenter(scaleIn, scaleIn);
    
    float x = container.getX() + (container.getWidth() * 0.5);
    float y = container.getY();
    float spaceing = container.getHeight() / (circleNumber-1);
    radius = spaceing * 0.4;

    for (int i =0; i < circleNumber; i++) {
        ofDrawCircle(x,
                     y + i * spaceing,
                     radius);
    }
    
    return radius;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetBackgroundColor(240);
    ofSetColor(15);
  
    frame = 0.85;
    frameWidth = ofGetWidth() * frame;
    frameHeight = ofGetHeight() * frame;

    ofTranslate(0, (ofGetHeight() - frameHeight) * 0.5 );
    
    x[0] = 0;
    
    for (int i = 0; i < rowNumber; i++) {
        
      //  float scale = ofMap(sin((ofGetElapsedTimef() + i * 2.15) * 3), -1, 1, .8, 1.4);
        float scale = ofMap(sin((ofGetElapsedTimef() / 2 + i * 2.15) * 3), -1, 1, .8, 1.4);
        r[i] = circleLine(x[i], 0, 0, frameHeight, scale);
        
        if (i > 0) {
            x[i] = (x[i-1] + r[i-1] + r[i] * scale * 1.5);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
