#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    t.setup();
    
    unit = 3;
    h = 20 * unit;
    leading = 3.5 * unit;
    space = 14 * unit;
    
    letters.push_back("A");
    letters.push_back("B");
    letters.push_back("C");
    letters.push_back("D");
    letters.push_back("E");
    letters.push_back("F");
    letters.push_back("G");
    letters.push_back("H");
    letters.push_back("I");
    letters.push_back("J");
    letters.push_back("K");
    letters.push_back("L");
    letters.push_back("M");
    letters.push_back("N");
    letters.push_back("O");
    letters.push_back("P");
    letters.push_back("Q");
    letters.push_back("R");
    letters.push_back("S");
    letters.push_back("T");
    letters.push_back("U");
    letters.push_back("V");
    letters.push_back("W");
    letters.push_back("X");
    letters.push_back("Y");
    letters.push_back("Z");

}

//--------------------------------------------------------------
void ofApp::update(){
    
    width.clear();
    for(int i = 0; i < letters.size(); i++){
        w = 14 * unit;

        if(i % 6 == 1){
            w = w * 1.61;
        }
        if(i % 4 == 1){
            w = w * 2.61;
        }
        width.push_back(w);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(15);
    ofSetBackgroundColor(240);
    ofSetLineWidth(2);
//    gui.draw();
    
    float padding = 100;
    ofTranslate(padding,padding);
    
    xPos = 0;
    yPos = 0;
    
    for (int i =0; i < letters.size(); i++){
        t.draw(letters[i], xPos, yPos, width[i], h);
        xPos += width[i] + leading;
        if (xPos > ofGetWidth() - padding * 3){
            xPos = 0;
            yPos += h * 1.5;
        }
    }
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 127 && letters.size() > 0) {
        letters.erase(letters.end()-1);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if (key == 'a') {
        letters.push_back("A");
    }
    if (key == 'b') {
        letters.push_back("B");
    }
    if (key == 'c') {
        letters.push_back("C");
    }
    if (key == 'd') {
        letters.push_back("D");
    }
    if (key == 'e') {
        letters.push_back("E");
    }
    if (key == 'f') {
        letters.push_back("F");
    }
    if (key == 'g') {
        letters.push_back("G");
    }
    if (key == 'h') {
        letters.push_back("H");
    }
    if (key == 'i') {
        letters.push_back("I");
    }
    if (key == 'j') {
        letters.push_back("J");
    }
    if (key == 'k') {
        letters.push_back("K");
    }
    if (key == 'l') {
        letters.push_back("L");
    }
    if (key == 'm') {
        letters.push_back("M");
    }
    if (key == 'n') {
        letters.push_back("N");
    }
    if (key == 'o') {
        letters.push_back("O");
    }
    if (key == 'p') {
        letters.push_back("P");
    }
    if (key == 'q') {
        letters.push_back("Q");
    }
    if (key == 'r') {
        letters.push_back("R");
    }
    if (key == 's') {
        letters.push_back("S");
    }
    if (key == 't') {
        letters.push_back("T");
    }
    if (key == 'u') {
        letters.push_back("U");
    }
    if (key == 'v') {
        letters.push_back("V");
    }
    if (key == 'w') {
        letters.push_back("W");
    }
    if (key == 'x') {
        letters.push_back("X");
    }
    if (key == 'y') {
        letters.push_back("Y");
    }
    if (key == 'z') {
        letters.push_back("Z");
    }
    if (key == 32) {
        letters.push_back("32");
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
