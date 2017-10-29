#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    t.setup();
    
    // type grid
    unit = 3;
    h = 20 * unit;
    leading = 3.5 * unit;
    space = 14 * unit;
    lineHeight = h * 1.5;
    
    // letter position
    lines.push_back("null");
    
//    letters.push_back("A");
//    letters.push_back("B");
//    letters.push_back("C");
//    letters.push_back("D");
//    letters.push_back("E");
//    letters.push_back("F");
//    letters.push_back("G");
//    letters.push_back("H");
//    letters.push_back("I");
//    letters.push_back("J");
//    letters.push_back("K");
//    letters.push_back("L");
//    letters.push_back("M");
//    letters.push_back("N");
//    letters.push_back("O");
//    letters.push_back("P");
//    letters.push_back("Q");
//    letters.push_back("R");
//    letters.push_back("S");
//    letters.push_back("T");
//    letters.push_back("U");
//    letters.push_back("V");
//    letters.push_back("W");
//    letters.push_back("X");
//    letters.push_back("Y");
//    letters.push_back("Z");

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
    
    yPos.clear();
    float yPosTemp = 0;
    for (int i = 0; i < letters.size(); i++) {
        if (lines[i] == "13"){
            yPosTemp += lineHeight;
        }
        yPos.push_back(yPosTemp);
    }    
    xPos.clear();
    float xPosTemp = 0;
    for (int i = 0; i < letters.size(); i++) {
        if (blanks[i] == "32"){
            xPosTemp += leading + space;
        }if (lines[i+1] == "13"){
            xPosTemp = 0;
        }
        else {
            xPosTemp += width[i] + leading;
        }
        xPos.push_back(xPosTemp);
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
    
    for(int i = 0; i < letters.size(); i++){
        t.draw(letters[i], xPos[i-1], yPos[i], width[i], h);
    }
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 127 && letters.size() > 0) { //backspace
        letters.erase(letters.end()-1);
        lines.erase(lines.end()-1);
        blanks.erase(blanks.end()-1);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (key == 32) { // blank
        blanks.erase(blanks.end()-1);
        blanks.push_back("32");
    }
    if (key == 13){ // enter
        lines.erase(lines.end()-1);
        lines.push_back("13");
    }

    if (key == 'a') {
        letters.push_back("A");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'b') {
        letters.push_back("B");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'c') {
        letters.push_back("C");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'd') {
        letters.push_back("D");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'e') {
        letters.push_back("E");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'f') {
        letters.push_back("F");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'g') {
        letters.push_back("G");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'h') {
        letters.push_back("H");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'i') {
        letters.push_back("I");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'j') {
        letters.push_back("J");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'k') {
        letters.push_back("K");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'l') {
        letters.push_back("L");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'm') {
        letters.push_back("M");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'n') {
        letters.push_back("N");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'o') {
        letters.push_back("O");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'p') {
        letters.push_back("P");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'q') {
        letters.push_back("Q");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'r') {
        letters.push_back("R");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 's') {
        letters.push_back("S");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 't') {
        letters.push_back("T");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'u') {
        letters.push_back("U");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'v') {
        letters.push_back("V");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'w') {
        letters.push_back("W");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'x') {
        letters.push_back("X");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'y') {
        letters.push_back("Y");
        lines.push_back("null");
        blanks.push_back("null");

    }
    if (key == 'z') {
        letters.push_back("Z");
        lines.push_back("null");
        blanks.push_back("null");

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
