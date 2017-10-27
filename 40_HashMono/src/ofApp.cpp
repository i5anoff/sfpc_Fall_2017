#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    timeStamp.push_back(ofGetFrameNum());
    
    letterShape temp;
    temp.bIsLine = true;
    temp.pts[0].set(1, 20, 1, 0, 0, 0, 0, 0);
    temp.pts[1].set(1, 0, 1, 0, 1, -20, 0, 0);
    O.shapes.push_back(temp);
    
    temp.bIsLine = true;
    temp.pts[0].set(1, 20, 1, 0, 0, 0, 1, 0);
    temp.pts[1].set(1, 0, 1, 0, 1, -20, 1, 0);
    O.shapes.push_back(temp);
    
    temp.bIsLine = true;
    temp.pts[0].set(1,0, 1, 20,0,0, 0,0);
    temp.pts[1].set(1,0, 1, 0,0,0, 1,-20);
    O.shapes.push_back(temp);
    
    
    temp.bIsLine = true;
    temp.pts[0].set(1,0, 1, 20,1,0, 0,0);
    temp.pts[1].set(1,0, 1, 0,1,0, 1,-20);
    O.shapes.push_back(temp);
    
    
    temp.bIsLine = false;
    temp.center.set(1,20, 1, 20,0,0, 0,0);
    temp.startAngle = PI;
    temp.radius = 20;
    O.shapes.push_back(temp);
    
    temp.bIsLine = false;
    temp.center.set(1,0, 1, 20,1,-20, 0,0);
    temp.startAngle = 3*PI/2.0;
    temp.radius = 20;
    O.shapes.push_back(temp);
    
    temp.bIsLine = false;
    temp.center.set(1,20, 1, 0,0,0, 1,-20);
    temp.startAngle = PI/2.0;
    temp.radius = 20;
    O.shapes.push_back(temp);
    
    temp.bIsLine = false;
    temp.center.set(1,0, 1, 0,1,-20, 1,-20);
    temp.startAngle = 0;
    temp.radius = 20;
    O.shapes.push_back(temp);
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    w.clear();
    for(int i = 0; i < letters.size(); i++){
        float typeSpeed = timeStamp[i] - timeStamp[i-1];
        float width = ofMap(typeSpeed, 0, 60,  40, 136);
        w.push_back(width);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(80);
    
    cout << timeStamp[timeStamp.size()-1] << endl;
    
    float xPos = 100;
    float yPos = 100;
    for (int i = 0; i < letters.size(); i++){
        letters[i].draw(xPos, yPos, w[i], 150);
        xPos += w[i] + 20;
        if (xPos > 500){
            xPos = 100;
            yPos += 200;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'o'){
        letters.push_back(O);
        timeStamp.push_back(ofGetFrameNum());
    }
    if (key == 127 && letters.size() > 0) {
        letters.erase(letters.end()-1);
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
