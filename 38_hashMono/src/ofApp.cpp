#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(240);
    ofSetColor(15);
    
    // Initial Morphing Values
    widthIn = 1;
    
    // Text Output
    cursorPos = 0;
    leading = 7 * 5;

}

//--------------------------------------------------------------
void ofApp::update(){

    // Calculating Morphing Values

//    for(int i = 0; i < myString.size(); i++){
//        if(i == 2){
//            widthIn = 1.61;
//        } if(i == 3){
//            widthIn = 2.61;
//        }else {
//            widthIn = 1;
//        }
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetLineWidth(2);
    ofNoFill();
    
    for(int i = 0; i < myString.size(); i++){
        if(i % 3 == 1){
            widthIn = 1.61;
        } else if (i % 2 == 1){
            widthIn = 2.61;
        }else {
            widthIn = 1;
        }
         char c = myString[i];
         cursorPos = drawChar(c, widthIn);
         drawChar(c, widthIn);
         ofTranslate(cursorPos + leading, 0);
    }
}

//--------------------------------------------------------------
float ofApp::drawChar(char character, float widthIn){
   
    // Grid for all Characters
    gridX = 5 * widthIn;
    gridY = 5;
    
    // Lines on the y-axsis
    ascLine = 0;
    capLine = 6 * gridY;
    baseLine = 26 * gridY;
    desLine = 33 * gridY;
    
    if (character == 'X') {

        float width = 12 * gridX;
        
        // Points (d = diagonal)
        ofPoint d1A = ofPoint(0, capLine);
        ofPoint d1B = ofPoint(width, baseLine);
        ofPoint d2A = ofPoint(width, capLine);
        ofPoint d2B = ofPoint(0, baseLine);
        
        ofDrawLine(d1A, d1B);
        ofDrawLine(d2A, d2B);
        
        return width;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (key == 127 && myString.size() > 0) {
        myString.erase(myString.end()-1);
    } else {
        myString.push_back(key);
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
