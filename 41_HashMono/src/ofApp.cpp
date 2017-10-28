#include "ofApp.h"
#include "hashMono.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    typeSpeedMin;
    typeSpeedMax;
    
    timeStamp.push_back(ofGetFrameNum());
        
    gui.setup();
    gui.add(typeSpeedMin.setup("TS Min", 0, 0, 100));
    gui.add(typeSpeedMax.setup("TS Max", 60, 0, 500));
    
    h = 150;
    
   
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
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
    //        cout << "TS " << timeStamp.size() << " L: " << letters.size() << endl;
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(80);
    gui.draw();
    
    float scale = 0.5;
    float frame = ofGetWidth() * 0.9;
    float xPos = 100;
    float yPos = 100;
    for (int i = 0; i < letters.size(); i++){
        ofPushMatrix();
        ofScale(scale, scale);
        letters[i].draw(xPos, yPos, w[i], h);
        ofPopMatrix();
        xPos += w[i] + 20;
        if (xPos > 2400){
            xPos = 100;
            yPos += 200;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'e'){
        letters.push_back(E);
        timeStamp.push_back(ofGetFrameNum());
    }
    if (key == 'h'){
        letters.push_back(H);
        timeStamp.push_back(ofGetFrameNum());
    }
    if (key == 'l'){
        letters.push_back(L);
        timeStamp.push_back(ofGetFrameNum());
    }
    if (key == 'o'){
        letters.push_back(O);
        timeStamp.push_back(ofGetFrameNum());
    }
    
    
    if (key == 127 && letters.size() > 0) {
        letters.erase(letters.end()-1);
        timeStamp.erase(timeStamp.end()-1);
    }
    
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

