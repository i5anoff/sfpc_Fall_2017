#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundColor(0);
    
    for(int i = 0; i < NUM; i++){
        particles[i].setup(ofRandom(0, ofGetWidth()),
                           0 + i * (ofGetHeight() / NUM));
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

    for( int i = 0; i < NUM; i++){
        particles[i].update();
       
        if (particles[i].radius > ofGetWidth()) {
            for(int i = 0; i < NUM; i++){
                particles[i].setup(ofRandom(0, ofGetWidth()),
                                   0 + i * (ofGetHeight() / NUM));
            }
            if (colorPositive == 1) {
                ofSetColor(0);
                ofSetBackgroundColor(255);
                colorPositive = 0;
            } else {
                ofSetColor(255);
                ofSetBackgroundColor(0);
                colorPositive = 1;
            }
        }
    }
    
  
}

//--------------------------------------------------------------
void ofApp::draw(){

    for( int i = 0; i < NUM; i++){
        particles[i].draw();
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
