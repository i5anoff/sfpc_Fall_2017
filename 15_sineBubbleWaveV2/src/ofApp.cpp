#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    circleNumber = 20;
    rowNumber = 30;
}

float ofApp::circleLine(float xIn, float yIn, float wIn, float hIn, float scaleIn){
    ofSeedRandom(0);
    ofSetCircleResolution(ofRandom(1,10));

    
    container.set(xIn, yIn, wIn, hIn);
    container.scaleFromCenter(scaleIn, scaleIn);
    
    float x = container.getX() + (container.getWidth() * 0.5);
    float y = container.getY();
    float spaceing = container.getHeight() / (circleNumber-1);
    radius = spaceing * 0.4;
    
    for (int i =0; i < circleNumber; i++) {
        ofDrawCircle(x + (ofMap(sin((ofGetElapsedTimef() + i * 2.15) * 3), -1, 1, -100, 100)),
                     y + i * spaceing,
                     radius * scaleIn * 1.2);
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
  
    frame = .6;
    frameWidth = ofGetWidth() * frame;
    frameHeight = ofGetHeight() * frame;

    ofPushMatrix();
        ofTranslate(150, (ofGetHeight() - frameHeight) * 0.5 );
    
        x[0] = 0;
    
        for (int i = 0; i < rowNumber; i++) {
            
            float scale = ofMap(sin((ofGetElapsedTimef() + i * 2.15) * 3), -1, 1, .8, 1.2);
            r[i] = circleLine(x[i], 0, 0, frameHeight, scale);
            
            if (i > 0) {
                x[i] = (x[i-1] + r[i-1] + r[i] * scale * 1.5);
            }
        }
        
    ofPushMatrix();
    
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
