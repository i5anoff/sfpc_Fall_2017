#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(255);
    
    ofColor c1 = ofColor(0);
//    ofColor c1 = ofColor(255);
    ofColor c2 = ofColor(230, 1, 16);
    ofColor c3 = ofColor(0, 131, 206);
    
    
//    OF_BLENDMODE_DISABLED
//    OF_BLENDMODE_ALPHA
//    OF_BLENDMODE_ADD
//    OF_BLENDMODE_SUBTRACT
//    OF_BLENDMODE_MULTIPLY
//    OF_BLENDMODE_SCREEN
    

    
    
    
    ofPushStyle();
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);

    ofSetColor(c2);
    ofDrawCircle(215, 215, 30);
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofPopStyle();
    
    
    
    ofPushStyle();
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);

    ofSetColor(c3);
    ofDrawCircle(185, 215, 30);
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofPopStyle();

   
    ofPushStyle();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    ofSetColor(c1);
    ofDrawCircle(200, 200, 30);
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofPopStyle();

   


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
