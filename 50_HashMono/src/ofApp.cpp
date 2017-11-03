#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    t.setup();
    
    // type basics
    gui.add(unit.setup("unit", 7, 3, 15));

    
    // type position
    lines.push_back("null");
    
    // animation
    patOff = 0;
    startTime = ofGetElapsedTimef();
    duration =0.5;
    gui.add(amp.setup("amp", 1.1852, 0, 2));
    gui.add(speed.setup("speed", 0.03, 0.00, 2));
    
    //type manipulation
    gui.add(patW1.setup("patW1", 1, 1, 20));
    gui.add(patW2.setup("patW2", 2, 1, 20));
    gui.add(patMl1.setup("patMl1", 2, 1, 20));
    gui.add(patMl2.setup("patMl2", 5, 1, 20));
    gui.add(patMl1dist.setup("patMl1dist", 0.015, 0.00, 1));
    gui.add(patMl2dist.setup("patMl2dist", 0.015, 0.0000, 1));


    gui.add(r.setup("rotate", 0, -360, 360));
    gui.add(dist.setup("dist", 0.0, 0.001, 0.5));

    
    //layout
//    ofSetColor(15);
    ofSetBackgroundColor(15);
    ofSetLineWidth(2);
    padding = 75;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // type basics
    ////////////////////////////////////////////////////////////
    w = 14 * unit;
    h = 20 * unit;
    lineHeight = h * 1.5;
    leading = 3 * unit;
    blank = 14 * unit;
    
    // animation
    ////////////////////////////////////////////////////////////
    elapsedTime = ofGetElapsedTimef() - startTime;
    pct = elapsedTime / duration;
    pct = powf(pct, .5);
    if (pct > 1) pct = 1;
    
    // type manipulation
    ////////////////////////////////////////////////////////////
    
    

    
    width.clear();

    float wTemp = w;
    for(int i = 0; i < letters.size(); i++){
        
        if((i + patOff) % patW1 == 1)          wTemp = w * 1.61;
        else if((i + patOff) % patW2 == 1)     wTemp = w * 2.61;
        else                    wTemp = w;
        
        width.push_back((1-pct) * widthPrev[i] + pct * wTemp);
    }
    
    
    
//    width.clear(); // with noise
//    float wTemp = w;
//    for(int i = 0; i < letters.size(); i++){
//        noise = ofMap(ofNoise(i * amp, (ofGetElapsedTimef() * speed)),
//                      0, 1, 0.8, 1.2);
//        if((i + patOff) % patW1 == 1)          wTemp = w * 1.61;
//        else if((i + patOff) % patW2 == 1)     wTemp = w * 2.61;
//        else                    wTemp = w;
//        width.push_back(wTemp * noise);
//    }
    
    
//    width.clear(); // with animation
//    float wTemp = w;
//    for(int i = 0; i < letters.size(); i++){
//
//        if((i + patOff) % patW1 == 1)          wTemp = w * 1.61;
//        else if((i + patOff) % patW2 == 1)     wTemp = w * 2.61;
//        else                    wTemp = w;
//        width.push_back((1-pct) * w + pct * wTemp);
//    }
    
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
    float rTemp = 0;
    for(int i = 0; i < letters.size(); i++){
        
        if((i + patOff) % patMl1 == 1)          rTemp = 360;
        else if((i + patOff) % patMl2 == 1)     rTemp = r;
        else                    rTemp = r;
        rotate.push_back(rTemp);
    }
    
    distance.clear(); // 50s
    float dTemp = 0;
    for(int i = 0; i < letters.size(); i++){
        
        if((i + patOff) % patMl1 == 1)          dTemp = patMl1dist;
        else if(i % patMl2 == 1)     dTemp = -patMl2dist;
//        else                    dTemp = 0.00599;
        distance.push_back(dTemp);
    }
    

    
    multiLine.clear();
    int multiLineTemp = 1;
    for(int i = 0; i < letters.size(); i++){
        
        if((i + patOff) % patMl1 == 1)          multiLineTemp = 60;
        else if(i % patMl2 == 1)     multiLineTemp = 20;
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
    
    cout <<
    "width: " <<
    width.size() <<
    " width prev: " <<
    widthPrev.size() <<
    endl;
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
    
    
    // animation
    startTime = ofGetElapsedTimef();
    patOff = ofRandom(1,5);
    
    
    // typing
    if (key == 127 && letters.size() > 0) { //backspace
        letters.erase(letters.end()-1);
        lines.erase(lines.end()-1);
        blanks.erase(blanks.end()-1);
    }
    
    if (widthPrev.size() == 0) {
        widthPrev.push_back(w);
    }else{
        widthPrev.clear();
        
        for (int i = 0; i < width.size(); i++) {
            widthPrev.push_back(width[i]);
        }
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
