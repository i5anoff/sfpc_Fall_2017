

#include "hashMono.h"

//---------------------------------------------------------------
void hashMono::setup(){
    // General Proportion
    float h = 150;

    
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


//---------------------------------------------------------------
void hashMono::update(){
}


//---------------------------------------------------------------
void hashMono::draw(){
}
