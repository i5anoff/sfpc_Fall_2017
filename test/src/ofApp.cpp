#include "ofApp.h"

float function_DoubleExponentialSigmoid (float x, float a){
    float min_param_a = 0.0 + FLT_EPSILON;
    float max_param_a = 1.0 - FLT_EPSILON;
    a = ofClamp(a, min_param_a, max_param_a);
    a = 1-a;
    
    float y = 0;
    if (x<=0.5){
        y = (pow(2.0*x, 1.0/a))/2.0;
    }
    else {
        y = 1.0 - (pow(2.0*(1.0-x), 1.0/a))/2.0;
    }
    return y;
}


//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    
    float elapsedTime = ofGetElapsedTimef() - startTime;
    float  pctS = function_DoubleExponentialSigmoid(elapsedTime / durationS, 0.85);
    
    if(pctS > 0.99){
        startTime = ofGetElapsedTimef();
        pctS = 0;
    }
    
   widthA = 100;
    float widthB = 500;
    float scale;
    
//    scale = ofMap((pctS-1) * widthA + pctS * widthB, -1, -0, 1, 0);
    scale = (pctS-1) * widthA + pctS * widthB;

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawRectangle(0, 0, 500, 100);
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
