#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    h = 150;
    typeSpeedMin;
    typeSpeedMax;
    
    
    gui.setup();
    gui.add(typeSpeedMin.setup("TS Min", 0, 0, 100));
    gui.add(typeSpeedMax.setup("TS Max", 60, 0, 500));

    
    // E
    letterShape tempE;
    
    tempE.bIsLine = true;
    tempE.pts[0].set(1, 0, 1, 0, 0, 0, 0, 0);
    tempE.pts[1].set(1, 0, 1, 0, 0, 0, 1, 0);
    E.shapes.push_back(tempE);

    tempE.bIsLine = true;
    tempE.pts[0].set(1, 0, 1, 0, 0, 0, 0, 0);
    tempE.pts[1].set(1, 0, 1, 0, 1, 0, 0, 0);
    E.shapes.push_back(tempE);
    
    tempE.bIsLine = true;
    tempE.pts[0].set(1, 0, 1, -h*0.5, 0, 0, 1, 0);
    tempE.pts[1].set(1, 0, 1, -h*0.5, 0.75, 0, 1, 0);
    E.shapes.push_back(tempE);
    
    tempE.bIsLine = true;
    tempE.pts[0].set(1, 0, 1, 0, 0, 0, 1, 0);
    tempE.pts[1].set(1, 0, 1, 0, 1, 0, 1, 0);
    E.shapes.push_back(tempE);
    
    
    // H
    letterShape tempH;
    tempH.bIsLine = true;
    tempH.pts[0].set(1, 0, 1, 0, 0, 0, 0, 0);
    tempH.pts[1].set(1, 0, 1, 0, 0, 0, 1, 0);
    H.shapes.push_back(tempH);
    
    tempH.bIsLine = true;
    tempH.pts[0].set(1, 0, 1, 0, 1, 0, 0, 0);
    tempH.pts[1].set(1, 0, 1, 0, 1, 0, 1, 0);
    H.shapes.push_back(tempH);

    tempH.bIsLine = true;
    tempH.pts[0].set(1, 0, 1, -h*0.5, 0, 0, 1, 0);
    tempH.pts[1].set(1, 0, 1, -h*0.5, 1, 0, 1, 0);
    H.shapes.push_back(tempH);
    
    // L
    letterShape tempL;
    tempL.bIsLine = true;
    tempL.pts[0].set(1, 0, 1, 0, 0, 0, 0, 0);
    tempL.pts[1].set(1, 0, 1, 0, 0, 0, 1, 0);
    L.shapes.push_back(tempL);
    
    tempL.bIsLine = true;
    tempL.pts[0].set(1, 0, 1, 0, 0, 0, 1, 0);
    tempL.pts[1].set(1, 0, 1, 0, 1, 0, 1, 0);
    L.shapes.push_back(tempL);
    
    
    // O
    letterShape tempO;
    tempO.bIsLine = true;
    tempO.pts[0].set(1, 20, 1, 0, 0, 0, 0, 0);
    tempO.pts[1].set(1, 0, 1, 0, 1, -20, 0, 0);
    O.shapes.push_back(tempO);

    tempO.bIsLine = true;
    tempO.pts[0].set(1, 20, 1, 0, 0, 0, 1, 0);
    tempO.pts[1].set(1, 0, 1, 0, 1, -20, 1, 0);
    O.shapes.push_back(tempO);

    tempO.bIsLine = true;
    tempO.pts[0].set(1,0, 1, 20,0,0, 0,0);
    tempO.pts[1].set(1,0, 1, 0,0,0, 1,-20);
    O.shapes.push_back(tempO);

    tempO.bIsLine = true;
    tempO.pts[0].set(1,0, 1, 20,1,0, 0,0);
    tempO.pts[1].set(1,0, 1, 0,1,0, 1,-20);
    O.shapes.push_back(tempO);

    tempO.bIsLine = false;
    tempO.center.set(1,20, 1, 20,0,0, 0,0);
    tempO.startAngle = PI;
    tempO.radius = 20;
    O.shapes.push_back(tempO);

    tempO.bIsLine = false;
    tempO.center.set(1,0, 1, 20,1,-20, 0,0);
    tempO.startAngle = 3*PI/2.0;
    tempO.radius = 20;
    O.shapes.push_back(tempO);

    tempO.bIsLine = false;
    tempO.center.set(1,20, 1, 0,0,0, 1,-20);
    tempO.startAngle = PI/2.0;
    tempO.radius = 20;
    O.shapes.push_back(tempO);

    tempO.bIsLine = false;
    tempO.center.set(1,0, 1, 0,1,-20, 1,-20);
    tempO.startAngle = 0;
    tempO.radius = 20;
    O.shapes.push_back(tempO);
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    w.clear();
    for(int i = 0; i < letters.size(); i++){
        float typeSpeed;

        if (letters.size() < 1) {
            timeStamp.push_back(ofGetFrameNum());
            timeStamp.push_back(ofGetFrameNum());

        }
        typeSpeed = timeStamp[i] - timeStamp[i-1];

        float width =  ofMap(ofClamp(typeSpeed, typeSpeedMin, typeSpeedMax), typeSpeedMin, typeSpeedMax,  40, 436);
        w.push_back(width);
        
        cout << "letter: " << i << " Prev Time: " << timeStamp[i-1] << " Cur Time: " << timeStamp[i] <<  " Speed: " << typeSpeed << endl;
    }
    
    cout << "TS " << timeStamp.size() << " L: " << letters.size() << endl;
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
        
        if (letters.size() == 0) {
            timeStamp.clear();
            timeStamp.push_back(ofGetFrameNum());
        }else {
            letters.erase(letters.end()-1);
            timeStamp.erase(timeStamp.end()-1);
        }
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
