#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    t.setup();
    
    letters.push_back("O");
    letters.push_back("H");
    letters.push_back("P");
    letters.push_back("G");
    letters.push_back("I");
    letters.push_back("A");
    letters.push_back("D");
    letters.push_back("B");
    letters.push_back("R");
    letters.push_back("E");
    letters.push_back("F");
    letters.push_back("U");
    letters.push_back("C");
    letters.push_back("J");
    letters.push_back("L");
    letters.push_back("T");

    
}

//--------------------------------------------------------------
void ofApp::update(){
    unit = 3;
//    w = 14 * unit;
//    h = 20 * unit;
    leading = 5 * unit;
    w = ofMap(mouseX, 0, ofGetWidth(), 14 * unit, 50 * unit);
    h = ofMap(mouseY, 0, ofGetHeight(), 20 * unit, 150 * unit);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(15);
    ofSetBackgroundColor(240);
    ofSetLineWidth(3);
    
    ofTranslate(50,50);
    
    for (int i =0; i < letters.size(); i++){
        t.draw(letters[i], 0, 0, w, h);
        ofTranslate(w + leading, 0);

    }
    
//    t.draw("O", 0, 0, w, h);
//    ofTranslate(w + leading, 0);
//    t.draw("H", 0, 0, w, h);

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
