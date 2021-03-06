#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup("slider", "settings", ofGetWidth() - 225, ofGetHeight() - 350);
//        gui.setup();
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
    duration = 0.5;
    gui.add(amp.setup("Wobble Amp", 6.4, 0, 10));
    gui.add(speed.setup("Wobble Speed", 0.04, 0.00, 2));
    
    bIsInactive = false;
    modInact = 0;
    
    
    //attract mode
    bIsAttractMode = false;
    bIsloadText = true ;
    prevIndex = 0;
    
    //type manipulation
    gui.add(mod1.setup("mod1", 6, 1, 20));
    gui.add(mod2.setup("mod2", 4, 1, 20));
    gui.add(mod3.setup("mod3", 2, 1, 20));
    gui.add(mod4.setup("mod4", 3, 1, 20));
    gui.add(mod5.setup("mod5", 7, 1, 20));

    //layout
    ofSetBackgroundColor(244);
    padding = 80;
    
    
    
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // type basics
    w = 14 * unit;
    h = 20 * unit;
    lineHeight = h * 1.35;
    leading = 3 * unit;
    blank = 7 * unit;
    
    // animation
    elapsedTime = ofGetElapsedTimef() - startTime;
    pct = elapsedTime / duration;
    pct = powf(pct, .5);
    if (pct > 1) pct = 1;
    
    bool test = true;


//    attractMode();
    
    if (test) { //elapsedTime > 1
        string screen1 = "THISSUCKS";
        
        if (bIsAttractMode == false ) {
            attractStartTime = ofGetElapsedTimef();
            bIsAttractMode = true;
            letters.clear();
            blanks.clear();
            lines.clear();
            lastAddedIndex = -1;
        }
        
        float elapsedTime = ofGetElapsedTimef() - attractStartTime;
        float pct = elapsedTime / 6;
//        pct = powf(pct, .5);
        if (pct > 1) pct = 1;
        
//        cout << "pct: " << pct << endl;
        
        int index = ofMap(pct, 0, 1, 0, screen1.size()-1);
        
        if(bIsloadText){
            
            cout << index << endl;
            
 
            if(prevIndex < index){
//                startTime = ofGetElapsedTimef();
//                patOff = ofRandom(1,6);
//                bIsPrevUpdate = true;
                
                keyPressed('1');
//                keyReleased(screen1.at(index));
//                lastAddedIndex = index;
//                prevIndex = index;
                
                cout << "true" << endl;
            }
            if(index > lastAddedIndex){
                keyReleased(screen1.at(index));
                lastAddedIndex = index;
                
//                keyPressed('1');
//                keyReleased(screen1.at(index));
//                lastAddedIndex = index;
//                prevIndex = index;
            }
            

            
            if(letters.size() == screen1.size()) bIsloadText = false;
        }
   
    }

//    cout << bIsAttractMode << endl;
    
    prevUpdate();


    



    width.clear();
    float wTemp = w;
    for(int i = 0; i < letters.size(); i++){
        
        noise = ofMap(ofNoise(i * amp, (ofGetElapsedTimef() * speed)), 0, 1, 0.8, 1.2);
        if((i + patOff - modInact) % mod1 == 1)          wTemp = w * 1.61;
        else if((i + patOff - modInact) % mod2 == 1)     wTemp = w * 2.61;
        else                                   wTemp = w;
        
        width.push_back((1-pct) * widthPrev[i] + pct * (wTemp * noise));
        
        cout<< "letters: " << letters.size() << " prev: " << widthPrev[i] << " cur: " << width[i] << " update: " << bIsPrevUpdate << " frame: " << ofGetFrameNum() << endl;
//        if(widthPrev.at(i) == 0){
//            cout << "glitch" << endl;
//        }

        
    }
    
    
    horAlt.clear();
    bool horAltTemp = false;
    for (int i = 0; i < letters.size(); i++){
        
        if ((i + patOff - modInact) % mod2 == 1) horAltTemp = true;
        else horAltTemp = false;
        horAlt.push_back(horAltTemp);
    }
    
    downStrokeAlt.clear();
    bool downStrokeAltTemp = false;
    for (int i = 0; i < letters.size(); i++){
        
        if ((i + patOff - modInact) % mod3 == 1) downStrokeAltTemp = true;
        else downStrokeAltTemp = false;
        downStrokeAlt.push_back(downStrokeAltTemp);
        
    }
    
    cirAlt.clear();
    bool dcirAltTemp = false;
    for (int i = 0; i < letters.size(); i++){
        
        if ((i + patOff - modInact) % mod3 == 1) dcirAltTemp = true;
        else dcirAltTemp = false;
        cirAlt.push_back(dcirAltTemp);
        
    }
//    inActiveAnimation();
    xyUpdate();

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    
    ofPushMatrix();
    ofTranslate(padding,padding);
    
    for(int i = 0; i < letters.size(); i++){
        t.draw(letters[i], xPos[i-1], yPos[i],
               i,
               width[i],
               h,
               downStrokeAlt[i],
               horAlt[i],
               cirAlt[i]);
    }
    ofPopMatrix();
    
    stringstream ss;
    ss <<
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
    " load text: " <<
    bIsloadText <<
    endl;
    
    ofDrawBitmapStringHighlight(ss.str(), 30, ofGetHeight() - 100);
    
}


//--------------------------------------------------------------
void ofApp::prevUpdate(){
    if (bIsPrevUpdate){
        widthPrev.clear();
        
        if(letters.size() > 1){
            for (int i = 0; i < letters.size(); i++) {
                widthPrev.push_back(width[i]);
//                cout << widthPrev[i] << endl;

            }
        }
        else{
            widthPrev.push_back(w);
        }
//        widthPrev.push_back(w);

        bIsPrevUpdate = false;
//        cout << "updated" << endl;
    }

}
//--------------------------------------------------------------
void ofApp::inActiveAnimation(){
    if (elapsedTime > 3 && bIsInactive == false ) {
        inactStartTime = ofGetElapsedTimef();
        bIsInactive = true;
    }

    if(bIsInactive){
        inactElapsedTime = ofGetElapsedTimef() - inactStartTime;
        inactPct = inactElapsedTime / 20;
        inactPct = powf(inactPct, .8);
        
        if (inactPct > 1) inactPct = 1;
            modInact = (1-inactPct) * 0 + inactPct * 60;
        }

}
//--------------------------------------------------------------
void ofApp::attractMode(){
    if (elapsedTime > 1 && bIsInactive == false ) {
        inactStartTime = ofGetElapsedTimef();
        bIsInactive = true;
    }
    
    string screen1 = "hello";
    
    if(bIsloadText){
        
        letters.clear();

        for (int i = 0; i < screen1.size(); i++) {
            
            letters.push_back(string());
            letters.back() = screen1.at(i);
            blanksAndLinesNull();
        }
        bIsloadText = false;
    }

//    cout << "attract Mode" << endl;
    
//
//    letters.push_back("A");
//    blanksAndLinesNull();
    
//    if(bIsInactive){
//        inactElapsedTime = ofGetElapsedTimef() - inactStartTime;
//        inactPct = inactElapsedTime / 20;
//        inactPct = powf(inactPct, .8);
//
//        if (inactPct > 1) inactPct = 1;
//        modInact = (1-inactPct) * 0 + inactPct * 60;
//    }
//    cout << "inact mod: " << modInact << endl;
    
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
    for (int i = 0; i < letters.size() && i < width.size(); i++) {
        
        if (blanks[i] == "blank")       xPosTemp += leading + blank;
        if (lines[i+1] == "newLine")    xPosTemp = 0;
        else                            xPosTemp += width[i] + leading;
        xPos.push_back(xPosTemp);
        
//        if (xPosTemp > ofGetWidth() - (padding)){
//            lines.erase(lines.end()-1);
//            lines.push_back("newLine");
//        }
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // animation
    startTime = ofGetElapsedTimef();
    patOff = ofRandom(1,6);
    bIsPrevUpdate = true;
    bIsInactive = false;
    modInact = 0;
    
    // typing
    if (key == 127 && letters.size() > 0) { //backspace
        letters.erase(letters.end()-1);
        lines.erase(lines.end()-1);
        blanks.erase(blanks.end()-1);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (key == 32 && letters.size() > 0) {
        blanks.erase(blanks.end()-1);
        blanks.push_back("blank");
    }
    if (key == 13 && letters.size() > 0){
        lines.erase(lines.end()-1);
        lines.push_back("newLine");
    }
    if(key >= 'a' && key <= 'z'){
        letters.push_back(string(1, (char)key + 'A' - 'a'));
        blanksAndLinesNull();
    }else if(key >= 'A' && key <= 'Z'){
        letters.push_back(string(1, (char)key ));
        blanksAndLinesNull();
    }
//    if (key == 'a') {
//        letters.push_back("A");
//        blanksAndLinesNull();
//    }
//    if (key == 'b') {
//        letters.push_back("B");
//        blanksAndLinesNull();
//    }
//    if (key == 'c') {
//        letters.push_back("C");
//        blanksAndLinesNull();
//    }
//    if (key == 'd') {
//        letters.push_back("D");
//        blanksAndLinesNull();
//    }
//    if (key == 'e') {
//        letters.push_back("E");
//        blanksAndLinesNull();
//    }
//    if (key == 'f') {
//        letters.push_back("F");
//        blanksAndLinesNull();
//    }
//    if (key == 'g') {
//        letters.push_back("G");
//        blanksAndLinesNull();
//    }
//    if (key == 'h') {
//        letters.push_back("H");
//        blanksAndLinesNull();
//    }
//    if (key == 'i') {
//        letters.push_back("I");
//        blanksAndLinesNull();
//    }
//    if (key == 'j') {
//        letters.push_back("J");
//        blanksAndLinesNull();
//    }
//    if (key == 'k') {
//        letters.push_back("K");
//        blanksAndLinesNull();
//    }
//    if (key == 'l') {
//        letters.push_back("L");
//        blanksAndLinesNull();
//    }
//    if (key == 'm') {
//        letters.push_back("M");
//        blanksAndLinesNull();
//    }
//    if (key == 'n') {
//        letters.push_back("N");
//        blanksAndLinesNull();
//    }
//    if (key == 'o') {
//        letters.push_back("O");
//        blanksAndLinesNull();
//    }
//    if (key == 'p') {
//        letters.push_back("P");
//        blanksAndLinesNull();
//    }
//    if (key == 'q') {
//        letters.push_back("Q");
//        blanksAndLinesNull();
//    }
//    if (key == 'r') {
//        letters.push_back("R");
//        blanksAndLinesNull();
//    }
//    if (key == 's') {
//        letters.push_back("S");
//        blanksAndLinesNull();
//    }
//    if (key == 't') {
//        letters.push_back("T");
//        blanksAndLinesNull();
//    }
//    if (key == 'u') {
//        letters.push_back("U");
//        blanksAndLinesNull();
//    }
//    if (key == 'v') {
//        letters.push_back("V");
//        blanksAndLinesNull();
//    }
//    if (key == 'w') {
//        letters.push_back("W");
//        blanksAndLinesNull();
//    }
//    if (key == 'x') {
//        letters.push_back("X");
//        blanksAndLinesNull();
//    }
//    if (key == 'y') {
//        letters.push_back("Y");
//        blanksAndLinesNull();
//    }
//    if (key == 'z') {
//        letters.push_back("Z");
//        blanksAndLinesNull();
//    }
    
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
