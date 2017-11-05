#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    gui.setup("slider", "settings", ofGetWidth() - 225, ofGetHeight() - 350);
    gui.setup();
    t.setup();
    
    // type basics
    gui.add(unit.setup("unit", 5, 3, 15));

    
    // type position
    lines.push_back("null");
    
    // animation
    bIsPrevUpdate = false;
    widthPrev.push_back(50);
    patOff = 0;
    startTime = ofGetElapsedTimef();
    duration =0.5;
    gui.add(amp.setup("letter Width Noise Amp", 6.4, 0, 10));
    gui.add(speed.setup("letter Width Noise Speed", 0.04, 0.00, 2));
    
    //type manipulation
    gui.add(mod1.setup("mod1", 1, 1, 20));
    gui.add(mod2.setup("mod2", 2, 1, 20));
    gui.add(mod3.setup("mod3", 2, 1, 20));
    gui.add(mod4.setup("mod4", 5, 1, 20));
    gui.add(noMultiLineA.setup("Multi Line A: Number", 25, 0, 60));
    gui.add(MultiLineADis.setup("Multi Line A: Distance", 0.03, 0.00, 1));
    gui.add(noMultiLineB.setup("Multi Line B: Number", 25, 0, 60));
    gui.add(MultiLineBDis.setup("Multi Line B: Distance", 0.06, 0.0000, 1));

    gui.add(r.setup("rotate", 0, -360, 360));
    gui.add(dist.setup("dist", 0.0, 0.001, 0.5));
    
    
    //layout
    //    ofSetColor(15);
    ofSetBackgroundColor(30);
    ofSetLineWidth(2);
    padding = 60;
    
}

//--------------------------------------------------------------
void ofApp::update(){
        
    // type basics
    w = 14 * unit;
    h = 20 * unit;
    lineHeight = h * 1.5;
    leading = 3 * unit;
    blank = 14 * unit;

    // animation
    elapsedTime = ofGetElapsedTimef() - startTime;
    pct = elapsedTime / duration;
    pct = powf(pct, .5);
    if (pct > 1) pct = 1;
    
    prevUpdate();

    
    // type manipulation
    width.clear();
    float wTemp = w;
    for(int i = 0; i < letters.size(); i++){

        noise = ofMap(ofNoise(i * amp, (ofGetElapsedTimef() * speed)), 0, 1, 0.8, 1.2);
        if((i + patOff) % mod1 == 1)          wTemp = w * 1.61;
        else if((i + patOff) % mod2 == 1)     wTemp = w * 2.61;
        else                                   wTemp = w;

        width.push_back((1-pct) * widthPrev[i] + pct * (wTemp * noise));

    }
    
    rotate.clear(); //50s
    float rTemp = 0;
    for(int i = 0; i < letters.size(); i++){

        if((i + patOff) % mod3 == 1)          rTemp = 360;
        else if((i + patOff) % mod4 == 1)     rTemp = r;
        else                    rTemp = r;
        rotate.push_back(rTemp);
    }
  
    multiLine.clear();
    int multiLineTemp = 1;
    for(int i = 0; i < letters.size(); i++){

        if((i + patOff) % mod3 == 1)          multiLineTemp = noMultiLineA;
        else if(i % mod4 == 1)     multiLineTemp = noMultiLineB;
        else                    multiLineTemp = 1;
        multiLine.push_back(multiLineTemp);
    }
    
    distance.clear(); // 50s
    float dTemp = 0;
    for(int i = 0; i < letters.size(); i++){
        
        if((i + patOff) % mod3 == 1)          dTemp = MultiLineADis;
        else if(i % mod4 == 1)     dTemp = -MultiLineBDis;
        //        else                    dTemp = 0.00599;
        distance.push_back(dTemp);
    }
    
    horAlt.clear();
    bool horAltTemp = false;
    for (int i = 0; i < letters.size(); i++){
        
        if ((i + patOff) % mod2 == 1) horAltTemp = true;
        else horAltTemp = false;
        horAlt.push_back(horAltTemp);
    }
    
    xyUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();

    
    ofTranslate(padding,padding);
    
    for(int i = 0; i < letters.size(); i++){
        t.draw(letters[i], xPos[i-1], yPos[i],
               width[i],
               h,
               multiLine[i],
               rotate[i],
               distance[i],
               horAlt[i]);
    }
    

    
    cout <<
    " letters: " <<
    letters.size() <<
    " blanks: " <<
    blanks.size() <<
    " lines: " <<
    lines.size() <<
    " width: " <<
    width.size() <<
    " width prev: " <<
    widthPrev.size() <<
    " letter count: " <<
    endl;
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // animation
    startTime = ofGetElapsedTimef();
    patOff = ofRandom(1,5);
    bIsPrevUpdate = true;
    
    // typing
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
        blanksAndLinesNull();
    }
    if (key == 'b') {
        letters.push_back("B");
        blanksAndLinesNull();
    }
    if (key == 'c') {
        letters.push_back("C");
        blanksAndLinesNull();
    }
    if (key == 'd') {
        letters.push_back("D");
        blanksAndLinesNull();
    }
    if (key == 'e') {
        letters.push_back("E");
        blanksAndLinesNull();
    }
    if (key == 'f') {
        letters.push_back("F");
        blanksAndLinesNull();
    }
    if (key == 'g') {
        letters.push_back("G");
        blanksAndLinesNull();
    }
    if (key == 'h') {
        letters.push_back("H");
        blanksAndLinesNull();
    }
    if (key == 'i') {
        letters.push_back("I");
        blanksAndLinesNull();
    }
    if (key == 'j') {
        letters.push_back("J");
        blanksAndLinesNull();
    }
    if (key == 'k') {
        letters.push_back("K");
        blanksAndLinesNull();
    }
    if (key == 'l') {
        letters.push_back("L");
        blanksAndLinesNull();
    }
    if (key == 'm') {
        letters.push_back("M");
        blanksAndLinesNull();
    }
    if (key == 'n') {
        letters.push_back("N");
        blanksAndLinesNull();
    }
    if (key == 'o') {
        letters.push_back("O");
        blanksAndLinesNull();
    }
    if (key == 'p') {
        letters.push_back("P");
        blanksAndLinesNull();
    }
    if (key == 'q') {
        letters.push_back("Q");
        blanksAndLinesNull();
    }
    if (key == 'r') {
        letters.push_back("R");
        blanksAndLinesNull();
    }
    if (key == 's') {
        letters.push_back("S");
        blanksAndLinesNull();
    }
    if (key == 't') {
        letters.push_back("T");
        blanksAndLinesNull();
    }
    if (key == 'u') {
        letters.push_back("U");
        blanksAndLinesNull();
    }
    if (key == 'v') {
        letters.push_back("V");
        blanksAndLinesNull();
    }
    if (key == 'w') {
        letters.push_back("W");
        blanksAndLinesNull();
    }
    if (key == 'x') {
        letters.push_back("X");
        blanksAndLinesNull();
    }
    if (key == 'y') {
        letters.push_back("Y");
        blanksAndLinesNull();
    }
    if (key == 'z') {
        letters.push_back("Z");
        blanksAndLinesNull();
    }
    
}

//--------------------------------------------------------------
void ofApp::blanksAndLinesNull(){
    lines.push_back("null");
    blanks.push_back("null");
}
//--------------------------------------------------------------
void ofApp::xyUpdate(){

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
        
                    if (xPosTemp > ofGetWidth() - (padding * 3)){
                        lines.erase(lines.end()-1);
                        lines.push_back("newLine");
                    }
    }
}
//--------------------------------------------------------------
void ofApp::prevUpdate(){
    if (bIsPrevUpdate){
        widthPrev.clear();
        for (int i = 0; i < letters.size(); i++) {
            widthPrev.push_back(width[i]);
        }
    }
    if (widthPrev.size() == 0) {
        widthPrev.push_back(w);
        bIsPrevUpdate = false;
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
