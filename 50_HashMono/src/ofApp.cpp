#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    t.setup();
    
    // type basics
    gui.add(unit.setup("unit", 5, 3, 15));

    
    // type position
    lines.push_back("null");
    
    //type manipulation
    gui.add(mod1.setup("mod1", 2, 1, 20));
    gui.add(mod2.setup("mod2", 3, 1, 20));
    gui.add(mod3.setup("mod3", 3, 1, 20));
    gui.add(mod4.setup("mod4", 3, 1, 20));

    gui.add(r.setup("rotate", 7, -360, 360));
    gui.add(dist.setup("dist", 0.0, 0.001, 0.5));

    
    //layout
    ofSetColor(15);
    ofSetBackgroundColor(240);
    ofSetLineWidth(2);
    padding = 100;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // type basics
    ////////////////////////////////////////////////////////////
    w = 14 * unit;
    h = 20 * unit;
    lineHeight = h * 1.5;
    leading = 3.5 * unit;
    blank = 14 * unit;
    
    // type manipulation
    ////////////////////////////////////////////////////////////
    
    width.clear();
    float wTemp = w;
    for(int i = 0; i < letters.size(); i++){
        
        if(i % mod1 == 1)          wTemp = w * 1.61;
        else if(i % mod2 == 1)     wTemp = w * 2.61;
        else                    wTemp = w;
        width.push_back(wTemp);
    }
    
//    rotate.clear(); //feathers
//    float rTemp = 0;
//    for(int i = 0; i < letters.size(); i++){
//
//        if(i % mod3 == 1)          rTemp = -10;
//        else if(i % mod4 == 1)     rTemp = 10;
//        else                    rTemp = 360;
//        rotate.push_back(rTemp);
//    }
    
    //    distance.clear(); // feathers
    //    float dTemp = 0;
    //    for(int i = 0; i < letters.size(); i++){
    //
    //        if(i % mod3 == 1)          dTemp = 0.01;
    //        else if(i % mod4 == 1)     dTemp = 0.01;
    //        else                    dTemp = 0.03593;
    //        distance.push_back(dTemp);
    //
    
    rotate.clear(); //50s
    float rTemp = 360;
    for(int i = 0; i < letters.size(); i++){
        
//        if(i % mod3 == 1)          rTemp = -10;
//        else if(i % mod4 == 1)     rTemp = 10;
//        else                    rTemp = 360;
        rotate.push_back(rTemp);
    }
    
    distance.clear(); // 50s
    float dTemp = 0;
    for(int i = 0; i < letters.size(); i++){
        
        if(i % mod3 == 1)          dTemp = 0.013475;
        else if(i % mod4 == 1)     dTemp = 0.00699;
//        else                    dTemp = 0.00599;
        distance.push_back(dTemp);
    }
    

    
    multiLine.clear();
    int multiLineTemp = 1;
    for(int i = 0; i < letters.size(); i++){
        
        if(i % mod3 == 1)          multiLineTemp = 30;
        else if(i % mod4 == 1)     multiLineTemp = 15;
        else                    multiLineTemp = 1;
        multiLine.push_back(multiLineTemp);
    }
    
    // type position
    ////////////////////////////////////////////////////////////

    yPos.clear();
    float yPosTemp = 0;
    for (int i = 0; i < letters.size(); i++) {
        
        if (lines[i] == "newLine")  yPosTemp += lineHeight;
        yPos.push_back(yPosTemp);
    }
    
    xPos.clear();
    float xPosTemp = 0;
    for (int i = 0; i < letters.size(); i++) {
        
        if (blanks[i] == "blank")       xPosTemp += leading + blank;
        if (lines[i+1] == "newLine")    xPosTemp = 0;
        else                            xPosTemp += width[i] + leading;
        xPos.push_back(xPosTemp);
        
        if (xPosTemp > ofGetWidth() - (padding * 2)){
            lines.erase(lines.end()-1);
            lines.push_back("newLine");
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();

    ofTranslate(padding,padding);

//    for(int i = 0; i < letters.size(); i++){
//        t.draw(letters[i], xPos[i-1], yPos[i], width[i], h, multiLine[i], r, dist);
//    }
    
    
    for(int i = 0; i < letters.size(); i++){
        t.draw(letters[i], xPos[i-1], yPos[i], width[i], h, multiLine[i], rotate[i], distance[i]);
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
    
    if (key == 32) {
        blanks.erase(blanks.end()-1);
        blanks.push_back("blank");
    }
    if (key == 13){
        lines.erase(lines.end()-1);
        lines.push_back("newLine");
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
