#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    t.setup();
    
    typeSpeedMin;
    typeSpeedMax;
    timeStamp.push_back(ofGetFrameNum());
    
    gui.setup();
    gui.add(typeSpeedMin.setup("TS Min", 0, 0, 100));
    gui.add(typeSpeedMax.setup("TS Max", 60, 0, 500));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    unit = 3;
//    w = 14 * unit;
    h = 20 * unit;
    leading = 3 * unit;
    space = 14 * unit;
    
    w.clear();
    for(int i = 0; i < letters.size(); i++){
        if(timeStamp.size() < 1){
            timeStamp.clear();
            timeStamp.push_back(ofGetFrameNum());
        }
        float typeSpeed = timeStamp[i] - timeStamp[i-1];
        float width =  ofMap(ofClamp(typeSpeed, typeSpeedMin, typeSpeedMax), typeSpeedMin, typeSpeedMax,  40, 436);
        w.push_back(width);
        //        cout << "current: " << timeStamp[i] << " prev: " << timeStamp[i-1] << " speed: " << typeSpeed << endl;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(15);
    ofSetBackgroundColor(240);
    ofSetLineWidth(3);
    gui.draw();
    
    float padding = 100;
    ofTranslate(padding,padding);
    
    xPos = 0;
    yPos = 0;
    
    for (int i =0; i < letters.size(); i++){
        t.draw(letters[i], xPos, yPos, w[i], h);
        xPos += w[i] + leading;
        if (xPos > ofGetWidth() - padding * 3){
            xPos = 0;
            yPos += h * 1.5;
        }
    }
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    timeStamp.push_back(ofGetFrameNum());

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
    if (key == 127 && letters.size() > 0) {
        letters.erase(letters.end()-1);
    }
    if (key == 32) {
        letters.push_back("32");
    }

    cout << key << endl;
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
