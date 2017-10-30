#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    wA = 100;
    wB = 500;
    
    ptA.set(0,300);
    ptB.set(ofGetWidth(), 300);


    startTime = ofGetElapsedTimef();
    duration = 5;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float elapsedTime = ofGetElapsedTimef() - startTime;
    float pct = elapsedTime / duration;
    pct = powf(pct, .1);
    
    w = (1-pct) * wA + pct * wB;

    if (pct > 1){
        w = wB;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    // basic animation!
    
    ofBackground(0);
    ofCircle(pos, 5);
    ofDrawRectangle(0, 0, w, 100);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' '){
        startTime = ofGetElapsedTimef();
    }
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
