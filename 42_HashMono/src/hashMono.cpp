

#include "hashMono.h"

//---------------------------------------------------------------
void hashMono::setup(){
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


//---------------------------------------------------------------
void hashMono::update(){
}


//---------------------------------------------------------------
void hashMono::draw(string letter, float x, float y, float width, float height){
    if (letter == "O") {
        O.draw(x, y, width, height);
    }
}
