#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(240);
    ofSetColor(15);
    
    // Grid for all Characters
    gridX = 5;
    charGrid.set(0, 0, 14 * gridX, 33 * gridX);
    
    // Lines on the y-axsis
    ascLine = 0;
    capLine = 6 * gridX;
    baseLine = 26 * gridX;
    desLine = 33 * gridX;
    
    // Output
    counter = 0;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(100, 100);
    ofSetLineWidth(2);
    ofNoFill();
    
    drawChar("X");
    
}
//--------------------------------------------------------------
void ofApp::drawChar(string character){
    
    if (character == "X") {
        float charValue = 58; // == Ascii Code for X
        
        // Poroportional Adjustment within the grid
        float wAdj = 2 * gridX;
        float width = charGrid.getWidth() - wAdj;
        
        // Points (d = diagonal)
        ofPoint d1A = ofPoint(0, capLine);
        ofPoint d1B = ofPoint(width, baseLine);
        ofPoint d2A = ofPoint(width, capLine);
        ofPoint d2B = ofPoint(0, baseLine);
        
        ofDrawLine(d1A, d1B);
        ofDrawLine(d2A, d2B);

    }
   
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'X'){
        drawChar("X");
    }
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
