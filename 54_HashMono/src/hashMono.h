#pragma once

#include "ofMain.h"
#define LETTERARGUMENTS x, y, letterCount, width, height, downStrokeAlt, horAlt, horAlt2

class letterPoint {
    
public:
    
    float xScale;
    float xOffset;
    
    float yScale;
    float yOffset;
    
    float wScale;
    float wOffset;
    
    float hScale;
    float hOffset;
    
    void set(float _xScale, float _xOffset,
             float _yScale, float _yOffset,
             float _wScale, float _wOffset,
             float _hScale, float _hOffset){
        
        xScale = _xScale;
        yScale = _yScale;
        wScale = _wScale;
        hScale = _hScale;
        
        xOffset = _xOffset;
        yOffset = _yOffset;
        wOffset = _wOffset;
        hOffset = _hOffset;
        
    }
    
    ofPoint getPointFor(float x, float y, float w, float h){
        ofPoint pos;
        pos.x = (x*xScale + xOffset) + (w*wScale + wOffset);
        pos.y = (y*yScale + yOffset) + (h*hScale + hOffset);
        return pos;
    }
    
};


class letterShape {
    
public:
    
    bool bIsLine;
    bool bIsDownStrokAlt;
    bool bIsHorAlt;
    bool bIsHorAlt2;

    
    // if line!
    letterPoint pts[2];
    
    // if curve:
    letterPoint center;
    float radius;
    float startAngle;
    
    
    void lineType(bool line, bool downStrokAlt = false, bool horAlt = false, bool horAlt2 = false){
        bIsLine = line;
        bIsHorAlt = horAlt;
        bIsDownStrokAlt = downStrokAlt;
        bIsHorAlt2 = horAlt2;
    }
    
    void draw( float x, float y, int letterCount, float w, float h, bool downStrokAlt, bool horAlt, bool horAlt2) {
        
        float lineS = 2;
        float lineL = 8;
        ofColor c1 = ofColor(0, 0, 0);
        ofColor c2 = ofColor(230, 1, 16);
        ofColor c3 = ofColor(0, 131, 206);

        ofSetLineWidth(lineS);
        ofSetColor(c1);
        
        if (bIsLine){
            
            ofPoint ptA = pts[0].getPointFor(x,y,w,h);
            ofPoint ptB = pts[1].getPointFor(x,y,w,h);
            
            if (bIsDownStrokAlt){
                ofPushStyle();
                    if(downStrokAlt) {
                        ofSetLineWidth(lineL);
//                        if (letterCount % 3 == 0) ofSetColor(c2);
                        ofLine(ptA, ptB);

                        for (int i = 0; i < 2; i++){
                            ofPushMatrix();
                                ofTranslate(i * (lineL * 0.9), 0);
                                ofLine(ptA, ptB);
                            ofPopMatrix();
                        }
                    }
                    else ofLine(ptA, ptB);
                ofPopStyle();
            }
            
            if (bIsHorAlt){
                if(horAlt){
                    ofPolyline lineTemp;
                    lineTemp.addVertex( ptA );
                    lineTemp.addVertex( ptB );
                    
                    ofPolyline lineRsTemp = lineTemp.getResampledByCount(25);
                    ofPolyline lineRs;
                    
                    lineRs.clear();
                    for (int i = 0; i < lineRsTemp.size(); i++){
                        float noise = 0;
                        noise = ofMap(sin((ofGetElapsedTimef() + i * 1.9) * 3.1)*0.25,0, 1, 0, 10);
                        lineRs.addVertex(lineRsTemp[i].x, lineRsTemp[i].y + noise);
                    }
                    lineRs.draw();
                }else{
                    ofLine(ptA, ptB);
                }
          
            }
            if (bIsHorAlt2){
                
                if(horAlt2){
                    for(int i = 0; i < 2; i++){
                        ofPushStyle();
                            ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
                            if(i == 0) ofSetColor(c2);
                            if(i == 1) ofSetColor(c3);
                            ofSetLineWidth(lineL);
                        
                        ofPushMatrix();
                            if(i == 0) ofTranslate(-(w*0.15), -(h*0.15));
                            if(i == 1) ofTranslate(-(w*0.5), +(h*0.15));
                        
                            for (int j = 0; j < 2; j++){
                                ofPushMatrix();
                                    ofTranslate(j * (lineL * 0.9), j * (lineL * 0.9));
                                    ofLine(ptA, ptB);
                                ofPopMatrix();
                            }
                        
                        ofPopMatrix();
                            ofEnableBlendMode(OF_BLENDMODE_ALPHA);
                        ofPopStyle();
                    }
                }
                else{
                    ofLine(ptA, ptB);
                    }
            }
            if(bIsHorAlt == false && bIsHorAlt2 == false ) {
                ofLine(ptA, ptB);
            }
        }
        
        if (bIsLine == false){
            
            
            ofPoint pt = center.getPointFor(x,y,w,h);
            ofPolyline line;
            for (int i = 0; i < 30; i++){
                float angle = startAngle + ofMap(i, 0, 29, 0, PI/2);
                line.addVertex( pt + (radius) * ofPoint(cos(angle), sin(angle)));
            }
                ofPushStyle();
                ofSetColor(c1);
                line.draw();
                ofPopStyle();
            }
        
        }
    
};

class letter {
    
public:
    
    vector < letterShape > shapes;
    float kerning;
    void draw( float x, float y, int letterCount, float w, float h, bool downStrokeAlt, bool horAlt, bool horAlt2){
        
        
        for (int i = 0; i < shapes.size(); i++){
            shapes[i].draw(x + (w * kerning), y, letterCount, w, h, downStrokeAlt, horAlt, horAlt2);
        }
        
    }
};

class hashMono {
    
public:
    
    void setup();
    void update();
    void draw(string letter,
              float x,
              float y,
              int letterCount,
              float width,
              float height,
              bool downStrokeAlt,
              bool horAlt,
              bool horAlt2);

    
    letter A;
    letter B;
    letter C;
    letter D;
    letter E;
    letter F;
    letter G;
    letter H;
    letter I;
    letter J;
    letter K;
    letter L;
    letter M;
    letter N;
    letter O;
    letter P;
    letter Q;
    letter R;
    letter S;
    letter T;
    letter U;
    letter V;
    letter W;
    letter X;
    letter Y;
    letter Z;
    
    
};
