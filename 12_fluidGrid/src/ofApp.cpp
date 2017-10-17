#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetBackgroundColor(240);
    ofSetColor(15);
    
    // Basic variables to calculate the grid and the frame of the canvas
    float frame = 0.75;
    float gridUnits = 4;
    float gridUnitsWidth = ofGetWidth() * frame / gridUnits;
    float gridUnitsHeight = ofGetHeight() * frame / gridUnits;
    
    // variable to scale the content of a grid unit and function to do so from the center
    ofSetRectMode(OF_RECTMODE_CENTER);
    float contentScale = ofMap(sin(ofGetElapsedTimef()*2), -1, 1, 0.5, 0.9);

    // translate X and Y to make the grid begin from inside the frame
    ofTranslate((ofGetWidth() - ofGetWidth() * frame) * 0.5,
                (ofGetHeight() - ofGetHeight() * frame) * 0.5);
   
   // loop to draw the content in the grid
    for (int i = 0; i < gridUnits; i++) {
        for (int j = 0; j < gridUnits; j++) {
            
            // !! push & pop work the other way arround. read according to numbers
            ofPushMatrix();
                // 3. changes X every i and Y every j to draw the element in every grid unit
                //    + 0.5 is needed since we use rectmode center
                ofTranslate(gridUnitsWidth * (i + 0.5), gridUnitsHeight * (j + 0.5));
            
                // 2. here we scale the content within a grid unit
                ofScale(contentScale, contentScale);
            
                // 1. the content (rectangle) is pushed through the grid with Push and Pop.
                //    thats why we can drawn the content from X0 Y0
                //    you can replace this with any other drawing function
                ofDrawRectangle(0, 0, gridUnitsWidth, gridUnitsHeight);
            ofPopMatrix();
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
