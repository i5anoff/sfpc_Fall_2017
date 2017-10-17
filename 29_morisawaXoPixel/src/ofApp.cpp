#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myString = "XO";
    myFont.load("NeueHaasUnicaPro-Bold.ttf", 1000);
    
    for (int i = 0; i < 500; i++) {
        rotation[i] = ofSignedNoise((i*0.5, i*0.005));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    myRect.set(myFont.getStringBoundingBox("XO", 0, 0));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(240);
    ofSetColor(15);
    
    float frame = 0.85;
    float width = ofGetWidth() * frame;
    float height = ofGetHeight() * frame;
    ofTranslate((ofGetWidth() - width) * 0.5, (ofGetHeight() - height) * 0.5, 1);
    
    float totalHeight = 0;
    float y = 0;
    
    int counter = 0;

    for (int i = 0; totalHeight < height; i++) {
        float numElements = 1+i;
        float grid = width / numElements;
        float scale = grid / myRect.getWidth();
        float x = 0;
        
        for (int j = 0; j < numElements; j++) {
            counter += +1;
            cout << counter << endl;

            ofPushMatrix();
                // position in grid
                ofTranslate(x , y);
            
                //align top and left
                ofTranslate(scale * myRect.getWidth() * 0.5, scale * myRect.getHeight() * 0.5);
            
                //draw from center rotate and scale
                ofScale(scale, scale);
                ofRotateY(ofMap(rotation[counter], 0, 1, 0, 25) + ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 360));
                ofTranslate(-myRect.getWidth() * 0.5, myRect.getHeight() * 0.5);
                myFont.drawString("XO", - myRect.x, 0);
            ofPopMatrix();
            x += scale * myRect.getWidth();
        }
        y += scale * myRect.getHeight();
        totalHeight += myRect.getHeight() * scale;
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
