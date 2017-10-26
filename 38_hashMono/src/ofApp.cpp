#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(240);
    ofSetColor(15);
    
    // Initial Morphing Values
    widthValue = 1;
    
    // Text Output
    leading = 7 * 5;
    lineHeight = 33 * 5;
    lineNum = 1;

}

//--------------------------------------------------------------
void ofApp::update(){
    

    // Storing Morphing Data
    for(int i = 0; i < text.size(); i++){
        if(i % 2 == 1){widthValue = 1.61;}
        else if(i % 3 == 1){widthValue = 2.61;}
        else { widthValue = 1;}
        
        widthIn[i] = widthValue;
    }
    
    // Cursor Position
    for(int i = 0; i < text.size(); i++){
        char ascii = text[i];
        
        cursorYPos[i] = 0;
        cursorXPos[i] = drawChar(ascii, widthIn[i]) + leading;
        
        if(text[i-1] == 13){
        cursorYPos[i] = 200;
        cursorXPos[i] = 0;
        }
    
    }

}


//--------------------------------------------------------------
void ofApp::draw(){
    ofSetLineWidth(2);
    ofNoFill();
    
    for(int i = 0; i < text.size(); i++){
        int ascii = text[i];
        if (text[i] != 13 && text[i] != 127) {
            drawChar(ascii, widthIn[i]);
            ofTranslate(cursorXPos[i], cursorYPos[i]);
        }
       
    }
}

//--------------------------------------------------------------
float ofApp::drawChar(int ascii, float widthIn){
   
    // Grid for all Characters
    gridX = 5 * widthIn;
    gridY = 5;
    
    // Lines on the y-axsis
    ascLine = 0;
    capLine = 6 * gridY;
    baseLine = 26 * gridY;
    desLine = 33 * gridY;
    
    if (ascii == 120) {

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
    
    if (ascii == 13){
        float width = 0;
        return width;
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (key == 127 && text.size() > 0) {
        text.erase(text.end()-1);
    }else {
        text.push_back(key);
        if (key == 13){
            lineNum += 1;
        }
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
