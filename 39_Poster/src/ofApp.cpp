#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundAuto(240);
    ofSetColor(15);
    
    
    for(int i = 0; i < 18; i++){
        ofPoint a = ofPoint(ofGetWidth() /2 + i * 50, 20);
        ofPoint b = ofPoint(ofGetWidth() /2 - i * 50, ofGetHeight() - 20);
        ofDrawLine(a, b);
    }
    
//    line1.clear();
//    line2.clear();
//    line3.clear();
//    line4.clear();
//    line5.clear();
//
//    for (int i =0; i< ofGetHeight(); i++) {
//        float sine =  ofMap(sin(i*0.075), -1, 1, -100, 100);
//
//        line1.addVertex(ofGetWidth() /2 + sine, i);
//        line2.addVertex(ofGetWidth() /2 + sine * 1.2, i);
//        line3.addVertex(ofGetWidth() /2 + sine * 1.3, i);
//        line4.addVertex(ofGetWidth() /2 + sine * 1.4, i);
//        line5.addVertex(ofGetWidth() /2 + sine * 1.5, i);
//
//    }
//
//    line1.draw();
//    line2.draw();
//    line3.draw();
//    line4.draw();
//    line5.draw();
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
