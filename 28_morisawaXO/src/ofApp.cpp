#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(240);
    ofSetColor(15);
    
    myString = "XO";
    typeTTF.load("NHaasGroteskDSStd-75Bd.otf", 500, true, false, true);

    vector <ofTTFCharacter> typePath = typeTTF.getStringAsPoints(myString);
    for(int i = 0; i < typePath.size(); i++){
        typeMesh.push_back(typePath[i].getTessellation());
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    typeBound.set(typeTTF.getStringBoundingBox(myString, 0, 0));
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float frame = 0.85;
    float width = ofGetWidth() * frame;
    float height = ofGetHeight() * frame;
    ofTranslate((ofGetWidth() - width) * 0.5, (ofGetHeight() - height) * 0.5);

    float totalHeight = 0;
    float y = 0;
    
    for (int i = 0; totalHeight < height; i++) {
    
        float numElements = 1+i;
        float grid = width / numElements;
        float scale = grid / typeBound.getWidth();
        float x = 0;
        
        for (int j = 0; j < numElements; j++) {
            ofPushMatrix();
                //position in grid
                ofTranslate(x , y);

                //align top and left
                ofTranslate(scale * typeBound.getWidth() * 0.5, scale * typeBound.getHeight() * 0.5);
            
                //draw from center and scale
                ofScale(scale, scale);
                ofTranslate(-typeBound.getWidth() * 0.5, typeBound.getHeight() * 0.5);
                for(int i = 0; i < typeMesh.size(); i++){
                    typeMesh[i].draw();
                }
            
            ofPopMatrix();
            x += scale * typeBound.getWidth();
        }
        y += scale * typeBound.getHeight();
        totalHeight += typeBound.getHeight() * scale;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
