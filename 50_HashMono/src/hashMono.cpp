

#include "hashMono.h"


//---------------------------------------------------------------
void hashMono::setup(){
    
    float xUnit = 0.071;
    float w1 = 1 * xUnit;
    float w2 = 2 * xUnit;
    float w3 = 3 * xUnit;
    float w4 = 4 * xUnit;
    float w5 = 5 * xUnit;
    float w6 = 6 * xUnit;
    float w7 = 7 * xUnit;
    float w10 = 10 * xUnit;
    float w12 = 12 * xUnit;

    float yUnit = 0.05;
    float h7 = 7 * yUnit;
    float h8 = 8 * yUnit;
    float h9 = 9 * yUnit;
    float h10 = 10 * yUnit;
    float h11 = 11 * yUnit;
    float h13 = 13 * yUnit;
    float h14 = 14 * yUnit;
    float h16 = 16 * yUnit;
    float h23 = 23 * yUnit;

    float r1 =  15;
    float r2 =  20;

    letterShape tempA;
    A.kerning = 0;
    
    tempA.lineType(true);
        tempA.bIsLine = true; // l vert
        tempA.bIsMultiLine = true;

        tempA.pts[0].set(1,0, 1, 0,w7,0, 0,0);
        tempA.pts[1].set(1,0, 1, 0,0,0, 1,0);
        A.shapes.push_back(tempA);
        
        tempA.bIsLine = true; // r ver
        tempA.bIsMultiLine = false;

        tempA.pts[0].set(1,0, 1, 0,w7,0, 0,0);
        tempA.pts[1].set(1,0, 1, 0,1,0, 1,0);
        A.shapes.push_back(tempA);
    
        tempA.bIsLine = true; // hor
        tempA.pts[0].set(1,0, 1, 0,w2,0, h14,0);
        tempA.pts[1].set(1,0, 1, 0,w12,0, h14,0);
        A.shapes.push_back(tempA);

    
    letterShape tempB;
    B.kerning = w1;
        tempB.bIsLine = true; // l vert
        tempB.bIsMultiLine = true;
        tempB.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempB.pts[1].set(1,0, 1, 0,0,0, 1,0);
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = true; // r vert
        tempB.bIsMultiLine = false;
        tempB.pts[0].set(1,0, 1, 0,w12,0, 0,r1);
        tempB.pts[1].set(1,0, 1, 0,w12,0, h10,-r1);
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = true; // t hor
        tempB.pts[0].set(1, 0, 1, 0, 0, 0, 0, 0);
        tempB.pts[1].set(1, 0, 1, 0, w12, -r1, 0, 0);
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = true; // m hor
        tempB.pts[0].set(1, 0, 1, 0, 0, 0, h10, 0);
        tempB.pts[1].set(1, 0, 1, 0, w12, -r1, h10, 0);
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = false; // tr
        tempB.center.set(1,0, 1, r1, w12,-r1, 0,0);
        tempB.startAngle = 3*PI/2.0;
        tempB.radius = r1;
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = false; // mr
        tempB.center.set(1,0, 1, -r1, w12, -r1, h10, 0);
        tempB.startAngle = 0;
        tempB.radius = r1;
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = false; // mr2
        tempB.center.set(1,0, 1, r1, w12,-r1, h10,0);
        tempB.startAngle = 3*PI/2.0;
        tempB.radius = r1;
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = true; // r vert2
        tempB.pts[0].set(1,0, 1, 0,w12,0, h10,r1);
        tempB.pts[1].set(1,0, 1, 0,w12,0, 1,-r1);
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = false; // mr
        tempB.center.set(1,0, 1, -r1, w12, -r1, 1, 0);
        tempB.startAngle = 0;
        tempB.radius = r1;
        B.shapes.push_back(tempB);
    
        tempB.bIsLine = true; // b hor
        tempB.pts[0].set(1, 0, 1, 0, 0, 0, 1, 0);
        tempB.pts[1].set(1, 0, 1, 0, w12, -r1, 1, 0);
        B.shapes.push_back(tempB);
    
    letterShape tempC;
    C.kerning = w1;
        tempC.bIsLine = true; // l vert
        tempC.bIsMultiLine = true;
        tempC.pts[0].set(1,0, 1, r1,0,0, 0,0);
        tempC.pts[1].set(1,0, 1, 0,0,0, 1,-r1);
        C.shapes.push_back(tempC);
    
        tempC.bIsLine = true; // t hor
        tempC.bIsMultiLine = false;
        tempC.pts[0].set(1, r1, 1, 0, 0, 0, 0, 0);
        tempC.pts[1].set(1, 0, 1, 0, w12, -r1, 0, 0);
        C.shapes.push_back(tempC);
    
        tempC.bIsLine = true; //b hor
        tempC.pts[0].set(1, r1, 1, 0, 0, 0, 1, 0);
        tempC.pts[1].set(1, 0, 1, 0, w12, -r1, 1, 0);
        C.shapes.push_back(tempC);
    
        tempC.bIsLine = false; // tl
        tempC.center.set(1,r1, 1, r1,0,0, 0,0);
        tempC.startAngle = PI;
        tempC.radius = r1;
        C.shapes.push_back(tempC);
    
        tempC.bIsLine = false; // tr
        tempC.center.set(1,0, 1, r1, w12,-r1, 0,0);
        tempC.startAngle = 3*PI/2.0;
        tempC.radius = r1;
        C.shapes.push_back(tempC);
    
        tempC.bIsLine = false; // bl
        tempC.center.set(1,r1, 1, 0,0,0, 1,-r1);
        tempC.startAngle = PI/2.0;
        tempC.radius = r1;
        C.shapes.push_back(tempC);
    
        tempC.bIsLine = false; // br
        tempC.center.set(1,0, 1, -r1, w12, -r1, 1, 0);
        tempC.startAngle = 0;
        tempC.radius = r1;
        C.shapes.push_back(tempC);
    
    letterShape tempD;
    D.kerning = w1;
        tempD.bIsLine = true; // l vert
        tempD.bIsMultiLine = true;
        tempD.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempD.pts[1].set(1,0, 1, 0,0,0, 1,0);
        D.shapes.push_back(tempD);
        
        tempD.bIsLine = true; // r vert
        tempD.bIsMultiLine = false;
        tempD.pts[0].set(1,0, 1, 0,w12,0, 0,r2);
        tempD.pts[1].set(1,0, 1, 0,w12,0, 1,-r2);
        D.shapes.push_back(tempD);
    
        tempD.bIsLine = true; // t hor
        tempD.pts[0].set(1, 0, 1, 0, 0, 0, 0, 0);
        tempD.pts[1].set(1, 0, 1, 0, w12, -r2, 0, 0);
        D.shapes.push_back(tempD);
        
        tempD.bIsLine = false; // tr
        tempD.center.set(1,0, 1, r2, w12,-r2, 0,0);
        tempD.startAngle = 3*PI/2.0;
        tempD.radius = r2;
        D.shapes.push_back(tempD);
        
        tempD.bIsLine = false; // mr
        tempD.center.set(1,0, 1, -r2, w12, -r2, 1, 0);
        tempD.startAngle = 0;
        tempD.radius = r2;
        D.shapes.push_back(tempD);
    
        tempD.bIsLine = true; // b hor
        tempD.pts[0].set(1, 0, 1, 0, 0, 0, 1, 0);
        tempD.pts[1].set(1, 0, 1, 0, w12, -r2, 1, 0);
        D.shapes.push_back(tempD);
    
    letterShape tempE;
    E.kerning = w1;
        tempE.bIsLine = true; // l vert
        tempE.bIsMultiLine = true;
        tempE.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempE.pts[1].set(1,0, 1, 0,0,0, 1,0);
        E.shapes.push_back(tempE);

        tempE.bIsLine = true; // t hor
        tempE.bIsMultiLine = false;
        tempE.pts[0].set(1,0, 1, 0,0,0, 0 ,0);
        tempE.pts[1].set(1,0, 1, 0,w12,0, 0,0);
        E.shapes.push_back(tempE);
    
        tempE.bIsLine = true; // m hor
        tempE.pts[0].set(1,0, 1, 0,0,0, h9,0);
        tempE.pts[1].set(1,0, 1, 0,w10,0, h9,0);
        E.shapes.push_back(tempE);
    
        tempE.bIsLine = true; // b hor
        tempE.pts[0].set(1,0, 1, 0,0,0, 1,0);
        tempE.pts[1].set(1,0, 1, 0,w12,0, 1,0);
        E.shapes.push_back(tempE);
    
    letterShape tempF;
    F.kerning = w1;
        tempF.bIsLine = true; // l vert
        tempF.bIsMultiLine = true;
        tempF.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempF.pts[1].set(1,0, 1, 0,0,0, 1,0);
        F.shapes.push_back(tempF);
    
        tempF.bIsLine = true; // t hor
        tempF.bIsMultiLine = false;
        tempF.pts[0].set(1,0, 1, 0,0,0, 0 ,0);
        tempF.pts[1].set(1,0, 1, 0,w12,0, 0,0);
        F.shapes.push_back(tempF);
    
        tempF.bIsLine = true; // m hor
        tempF.pts[0].set(1,0, 1, 0,0,0, h9,0);
        tempF.pts[1].set(1,0, 1, 0,w10,0, h9,0);
        F.shapes.push_back(tempF);
    
    letterShape tempG;
    G.kerning = w1;
        tempG.bIsLine = true; // l vert
        tempG.bIsMultiLine = true;
        tempG.pts[0].set(1,0, 1, r1,0,0, 0,0);
        tempG.pts[1].set(1,0, 1, 0,0,0, 1,-r1);
        G.shapes.push_back(tempG);
    
        tempG.bIsLine = true; // t hor
        tempG.bIsMultiLine = false;
        tempG.pts[0].set(1, r1, 1, 0, 0, 0, 0, 0);
        tempG.pts[1].set(1, 0, 1, 0, w12, -r1, 0, 0);
        G.shapes.push_back(tempG);
    
        tempG.bIsLine = true; //b hor
        tempG.pts[0].set(1, r1, 1, 0, 0, 0, 1, 0);
        tempG.pts[1].set(1, 0, 1, 0, w12, -r1, 1, 0);
        G.shapes.push_back(tempG);
    
        tempG.bIsLine = false; // tl
        tempG.center.set(1,r1, 1, r1,0,0, 0,0);
        tempG.startAngle = PI;
        tempG.radius = r1;
        G.shapes.push_back(tempG);
    
        tempG.bIsLine = false; // tr
        tempG.center.set(1,0, 1, r1, w12,-r1, 0,0);
        tempG.startAngle = 3*PI/2.0;
        tempG.radius = r1;
        G.shapes.push_back(tempG);
    
        tempG.bIsLine = true; // m hor
        tempG.pts[0].set(1, 0, 1, 0, w7, 0, h11, 0);
        tempG.pts[1].set(1, 0, 1, 0, w12, 0, h11, 0);
        G.shapes.push_back(tempG);
    
        tempG.bIsLine = true; // r vert
        tempG.pts[0].set(1,0, 1, 0,w12,0, h11,0);
        tempG.pts[1].set(1,0, 1, 0,w12, 0, 1,0);
        G.shapes.push_back(tempG);
    
        tempG.bIsLine = false; // bl
        tempG.center.set(1,r1, 1, 0,0,0, 1,-r1);
        tempG.startAngle = PI/2.0;
        tempG.radius = r1;
        G.shapes.push_back(tempG);
    
        tempG.bIsLine = false; // br
        tempG.center.set(1,0, 1, -r2, w12, -r2, 1, 0);
        tempG.startAngle = 0;
        tempG.radius = r2;
        G.shapes.push_back(tempG);
    
    letterShape tempH;
    H.kerning = w1;
        tempH.bIsLine = true; // l vert
        tempH.bIsMultiLine = true;
        tempH.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempH.pts[1].set(1,0, 1, 0,0,0, 1,0);
        H.shapes.push_back(tempH);
    
        tempH.bIsLine = true; // r ver
        tempH.bIsMultiLine = false;
        tempH.pts[0].set(1,0, 1, 0,w12,0, 0,0);
        tempH.pts[1].set(1,0, 1, 0,w12,0, 1,0);
        H.shapes.push_back(tempH);
    
        tempH.bIsLine = true; // hor
        tempH.pts[0].set(1,0, 1, 0,0,0, h10,0);
        tempH.pts[1].set(1,0, 1, 0,w12,0, h10,0);
        H.shapes.push_back(tempH);
    
    letterShape tempI;
    I.kerning = w1;
        tempI.bIsLine = true; // c vert
        tempI.bIsMultiLine = true;
        tempI.pts[0].set(1,0, 1, 0,w6,0, 0,0);
        tempI.pts[1].set(1,0, 1, 0,w6,0, 1,0);
        I.shapes.push_back(tempI);
    
        tempI.bIsLine = true; // t hor
        tempI.bIsMultiLine = false;
        tempI.pts[0].set(1,0, 1, 0,0,0, 0 ,0);
        tempI.pts[1].set(1,0, 1, 0,w12,0, 0,0);
        I.shapes.push_back(tempI);
   
        tempI.bIsLine = true; // t hor
        tempI.pts[0].set(1,0, 1, 0,0,0, 1 ,0);
        tempI.pts[1].set(1,0, 1, 0,w12,0, 1,0);
        I.shapes.push_back(tempI);
    
    letterShape tempJ;
    J.kerning = w1;
        tempJ.bIsLine = true; // r ver
        tempJ.bIsMultiLine = true;
        tempJ.pts[0].set(1,0, 1, 0,w12,0, 0,0);
        tempJ.pts[1].set(1,0, 1, 0,w12,0, 1,-r1);
        J.shapes.push_back(tempJ);
    
        tempJ.bIsLine = true; //b hor
        tempJ.bIsMultiLine = false;
        tempJ.pts[0].set(1, r1, 1, 0, 0, 0, 1, 0);
        tempJ.pts[1].set(1, 0, 1, 0, w12, -r1, 1, 0);
        J.shapes.push_back(tempJ);
    
        tempJ.bIsLine = false; // bl
        tempJ.center.set(1,r1, 1, 0,0,0, 1,-r1);
        tempJ.startAngle = PI/2.0;
        tempJ.radius = r1;
        J.shapes.push_back(tempJ);
    
        tempJ.bIsLine = false; // br
        tempJ.center.set(1,0, 1, -r1, w12, -r1, 1, 0);
        tempJ.startAngle = 0;
        tempJ.radius = r1;
        J.shapes.push_back(tempJ);
    
    letterShape tempK;
    K.kerning = w1;
        tempK.bIsLine = true; // t dia
        tempK.bIsMultiLine = true;
        tempK.pts[0].set(1,0, 1, 0,w12,0, 0,0);
        tempK.pts[1].set(1,0, 1, 0,0,0, h13,0);
        K.shapes.push_back(tempK);
    
        tempK.bIsLine = true; // b dia
        tempK.bIsMultiLine = false;
        tempK.pts[0].set(1,0, 1, 0,w5,0, h8,0);
        tempK.pts[1].set(1,0, 1, 0,w12,0, 1,0);
        K.shapes.push_back(tempK);

        tempK.bIsLine = true; // l vert
        tempK.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempK.pts[1].set(1,0, 1, 0,0,0, 1,0);
        K.shapes.push_back(tempK);
    
    letterShape tempL;
    L.kerning = w1;
        tempL.bIsLine = true; // l vert
        tempL.bIsMultiLine = true;
        tempL.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempL.pts[1].set(1,0, 1, 0,0,0, 1,0);
        L.shapes.push_back(tempL);
    
        tempL.bIsLine = true; // b hor
        tempL.bIsMultiLine = false;
        tempL.pts[0].set(1,0, 1, 0,0,0, 1,0);
        tempL.pts[1].set(1,0, 1, 0,w12,0, 1,0);
        L.shapes.push_back(tempL);
    
    letterShape tempM;
    M.kerning = 0;
        tempM.bIsLine = true; // l vert
        tempM.bIsMultiLine = true;
        tempM.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempM.pts[1].set(1,0, 1, 0,0,0, 1,0);
        M.shapes.push_back(tempM);
    
        tempM.bIsLine = true; // r vert
        tempM.bIsMultiLine = false;
        tempM.pts[0].set(1,0, 1, 0,w12,0, 0,0);
        tempM.pts[1].set(1,0, 1, 0,w12,0, 1,0);
        M.shapes.push_back(tempM);
    
        tempM.bIsLine = true; // l dia
        tempM.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempM.pts[1].set(1,0, 1, 0,w6,0, h14,0);
        M.shapes.push_back(tempM);
    
        tempM.bIsLine = true; // r dia
        tempM.pts[0].set(1,0, 1, 0,w12,0, 0,0);
        tempM.pts[1].set(1,0, 1, 0,w6,0, h14,0);
        M.shapes.push_back(tempM);
   
    letterShape tempN;
    N.kerning = w1;
        tempN.bIsLine = true; // l dia
        tempN.bIsMultiLine = true;
        tempN.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempN.pts[1].set(1,0, 1, 0,w12,0, 1,0);
        N.shapes.push_back(tempN);
    
        tempN.bIsLine = true; // l vert
        tempN.bIsMultiLine = false;
        tempN.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempN.pts[1].set(1,0, 1, 0,0,0, 1,0);
        N.shapes.push_back(tempN);
    
        tempN.bIsLine = true; // r vert
        tempN.pts[0].set(1,0, 1, 0,w12,0, 0,0);
        tempN.pts[1].set(1,0, 1, 0,w12,0, 1,0);
        N.shapes.push_back(tempN);
    
    letterShape tempO;
    O.kerning = w1;
        tempO.bIsLine = true; // l vert
        tempO.bIsMultiLine = true;
        tempO.pts[0].set(1,0, 1, r1,0,0, 0,0);
        tempO.pts[1].set(1,0, 1, 0,0,0, 1,-r1);
        O.shapes.push_back(tempO);
    
        tempO.bIsLine = true; // r ver
        tempO.bIsMultiLine = false;
        tempO.pts[0].set(1,0, 1, r1,w12,0, 0,0);
        tempO.pts[1].set(1,0, 1, 0,w12,0, 1,-r1);
        O.shapes.push_back(tempO);
    
        tempO.bIsLine = true; // t hor
        tempO.pts[0].set(1, r1, 1, 0, 0, 0, 0, 0);
        tempO.pts[1].set(1, 0, 1, 0, w12, -r1, 0, 0);
        O.shapes.push_back(tempO);
    
        tempO.bIsLine = true; //b hor
        tempO.pts[0].set(1, r1, 1, 0, 0, 0, 1, 0);
        tempO.pts[1].set(1, 0, 1, 0, w12, -r1, 1, 0);
        O.shapes.push_back(tempO);
    
        tempO.bIsLine = false; // tl
        tempO.center.set(1,r1, 1, r1,0,0, 0,0);
        tempO.startAngle = PI;
        tempO.radius = r1;
        O.shapes.push_back(tempO);
    
        tempO.bIsLine = false; // tr
        tempO.center.set(1,0, 1, r1, w12,-r1, 0,0);
        tempO.startAngle = 3*PI/2.0;
        tempO.radius = r1;
        O.shapes.push_back(tempO);
    
        tempO.bIsLine = false; // bl
        tempO.center.set(1,r1, 1, 0,0,0, 1,-r1);
        tempO.startAngle = PI/2.0;
        tempO.radius = r1;
        O.shapes.push_back(tempO);
    
        tempO.bIsLine = false; // br
        tempO.center.set(1,0, 1, -r1, w12, -r1, 1, 0);
        tempO.startAngle = 0;
        tempO.radius = r1;
        O.shapes.push_back(tempO);
    
    letterShape tempP;
    P.kerning = w1;
        tempP.bIsLine = true; // l vert
        tempP.bIsMultiLine = true;
        tempP.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempP.pts[1].set(1,0, 1, 0,0,0, 1,0);
        P.shapes.push_back(tempP);
    
        tempP.bIsLine = true; // r vert
        tempP.bIsMultiLine = false;
        tempP.pts[0].set(1,0, 1, 0,w12,0, 0,r1);
        tempP.pts[1].set(1,0, 1, 0,w12,0, h11,-r1);
        P.shapes.push_back(tempP);
    
        tempP.bIsLine = true; // t hor
        tempP.pts[0].set(1, 0, 1, 0, 0, 0, 0, 0);
        tempP.pts[1].set(1, 0, 1, 0, w12, -r1, 0, 0);
        P.shapes.push_back(tempP);
    
        tempP.bIsLine = true; // m hor
        tempP.pts[0].set(1, 0, 1, 0, 0, 0, h11, 0);
        tempP.pts[1].set(1, 0, 1, 0, w12, -r1, h11, 0);
        P.shapes.push_back(tempP);
    
        tempP.bIsLine = false; // tr
        tempP.center.set(1,0, 1, r1, w12,-r1, 0,0);
        tempP.startAngle = 3*PI/2.0;
        tempP.radius = r1;
        P.shapes.push_back(tempP);
    
        tempP.bIsLine = false; // mr
        tempP.center.set(1,0, 1, -r1, w12, -r1, h11, 0);
        tempP.startAngle = 0;
        tempP.radius = r1;
        P.shapes.push_back(tempP);
    
    letterShape tempQ;
    Q.kerning = w1;
        tempQ.bIsLine = true; // l vert
        tempQ.bIsMultiLine = true;
        tempQ.pts[0].set(1,0, 1, r1,0,0, 0,0);
        tempQ.pts[1].set(1,0, 1, 0,0,0, 1,-r1);
        Q.shapes.push_back(tempQ);
    
        tempQ.bIsLine = true; // r ver
        tempQ.bIsMultiLine = false;
        tempQ.pts[0].set(1,0, 1, r1,w12,0, 0,0);
        tempQ.pts[1].set(1,0, 1, 0,w12,0, 1,-r1);
        Q.shapes.push_back(tempQ);
    
        tempQ.bIsLine = true; // t hor
        tempQ.pts[0].set(1, r1, 1, 0, 0, 0, 0, 0);
        tempQ.pts[1].set(1, 0, 1, 0, w12, -r1, 0, 0);
        Q.shapes.push_back(tempQ);
    
        tempQ.bIsLine = true; //b hor
        tempQ.pts[0].set(1, r1, 1, 0, 0, 0, 1, 0);
        tempQ.pts[1].set(1, 0, 1, 0, w12, -r1, 1, 0);
        Q.shapes.push_back(tempQ);
    
        tempQ.bIsLine = false; // tl
        tempQ.center.set(1,r1, 1, r1,0,0, 0,0);
        tempQ.startAngle = PI;
        tempQ.radius = r1;
        Q.shapes.push_back(tempQ);
    
        tempQ.bIsLine = false; // tr
        tempQ.center.set(1,0, 1, r1, w12,-r1, 0,0);
        tempQ.startAngle = 3*PI/2.0;
        tempQ.radius = r1;
        Q.shapes.push_back(tempQ);
    
        tempQ.bIsLine = false; // bl
        tempQ.center.set(1,r1, 1, 0,0,0, 1,-r1);
        tempQ.startAngle = PI/2.0;
        tempQ.radius = r1;
        Q.shapes.push_back(tempQ);
    
        tempQ.bIsLine = false; // br
        tempQ.center.set(1,0, 1, -r1, w12, -r1, 1, 0);
        tempQ.startAngle = 0;
        tempQ.radius = r1;
        Q.shapes.push_back(tempQ);
    
        tempQ.bIsLine = true; // b dia
        tempQ.pts[0].set(1,0, 1, 0, w7,0, h16,0);
        tempQ.pts[1].set(1,0, 1, 0, w10,0, h23, 0);
        Q.shapes.push_back(tempQ);
    
    letterShape tempR;
    R.kerning = w1;
        tempR.bIsLine = true; // l vert
        tempR.bIsMultiLine = true;
        tempR.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempR.pts[1].set(1,0, 1, 0,0,0, 1,0);
        R.shapes.push_back(tempR);
    
        tempR.bIsLine = true; // r vert
        tempR.bIsMultiLine = false;
        tempR.pts[0].set(1,0, 1, 0,w12,0, 0,r1);
        tempR.pts[1].set(1,0, 1, 0,w12,0, h11,-r1);
        R.shapes.push_back(tempR);
    
        tempR.bIsLine = true; // t hor
        tempR.pts[0].set(1, 0, 1, 0, 0, 0, 0, 0);
        tempR.pts[1].set(1, 0, 1, 0, w12, -r1, 0, 0);
        R.shapes.push_back(tempR);
    
        tempR.bIsLine = true; // m hor
        tempR.pts[0].set(1, 0, 1, 0, 0, 0, h11, 0);
        tempR.pts[1].set(1, 0, 1, 0, w12, -r1, h11, 0);
        R.shapes.push_back(tempR);
    
        tempR.bIsLine = false; // tr
        tempR.center.set(1,0, 1, r1, w12,-r1, 0,0);
        tempR.startAngle = 3*PI/2.0;
        tempR.radius = r1;
        R.shapes.push_back(tempR);
    
        tempR.bIsLine = false; // mr
        tempR.center.set(1,0, 1, -r1, w12, -r1, h11, 0);
        tempR.startAngle = 0;
        tempR.radius = r1;
        R.shapes.push_back(tempR);
    
        tempR.bIsLine = true; // r dia
        tempR.pts[0].set(1,0, 1, 0,w12, -r1, h11,0);
        tempR.pts[1].set(1,0, 1, 0,w12, 0, 1,0);
        R.shapes.push_back(tempR);
    
    letterShape tempS;
    S.kerning = w1;
        tempS.bIsLine = true; // l vert
        tempS.bIsMultiLine = true;
        tempS.pts[0].set(1,0, 1, r1,0,0, 0,0);
        tempS.pts[1].set(1,0, 1, 0,0,0, h9,-r1);
        S.shapes.push_back(tempS);
    
        tempS.bIsLine = true; // r vert
        tempS.bIsMultiLine = false;
        tempS.pts[0].set(1,0, 1, r1,w12,0, h9,0);
        tempS.pts[1].set(1,0, 1, 0,w12,0, 1,-r1);
        S.shapes.push_back(tempS);
    
        tempS.bIsLine = true; // t hor
        tempS.pts[0].set(1, r1, 1, 0, 0, 0, 0, 0);
        tempS.pts[1].set(1, 0, 1, 0, w12, -r1, 0, 0);
        S.shapes.push_back(tempS);
    
        tempS.bIsLine = true; //m hor
        tempS.pts[0].set(1, r1, 1, 0, 0, 0, h9, 0);
        tempS.pts[1].set(1, 0, 1, 0, w12, -r1, h9, 0);
        S.shapes.push_back(tempS);
    
        tempS.bIsLine = true; //b hor
        tempS.pts[0].set(1, r1, 1, 0, 0, 0, 1, 0);
        tempS.pts[1].set(1, 0, 1, 0, w12, -r1, 1, 0);
        S.shapes.push_back(tempS);
    
        tempS.bIsLine = false; // tl
        tempS.center.set(1,r1, 1, r1,0,0, 0,0);
        tempS.startAngle = PI;
        tempS.radius = r1;
        S.shapes.push_back(tempS);
    
        tempS.bIsLine = false; // tr
        tempS.center.set(1,0, 1, r1, w12,-r1, 0,0);
        tempS.startAngle = 3*PI/2.0;
        tempS.radius = r1;
        S.shapes.push_back(tempS);
    
        tempS.bIsLine = false; // mr
        tempS.center.set(1,0, 1, r1, w12,-r1, h9,0);
        tempS.startAngle = 3*PI/2.0;
        tempS.radius = r1;
        S.shapes.push_back(tempS);
    
        tempS.bIsLine = false; // ml
        tempS.center.set(1,r1, 1, 0,0,0, h9,-r1);
        tempS.startAngle = PI/2.0;
        tempS.radius = r1;
        S.shapes.push_back(tempS);

        tempS.bIsLine = false; // bl
        tempS.center.set(1,r1, 1, 0,0,0, 1,-r1);
        tempS.startAngle = PI/2.0;
        tempS.radius = r1;
        S.shapes.push_back(tempS);
    
        tempS.bIsLine = false; // br
        tempS.center.set(1,0, 1, -r1, w12, -r1, 1, 0);
        tempS.startAngle = 0;
        tempS.radius = r1;
        S.shapes.push_back(tempS);
    
    letterShape tempT;
    T.kerning = 0;
        tempT.bIsLine = true; // c vert
        tempT.bIsMultiLine = true;
        tempT.pts[0].set(1,0, 1, 0,w7,0, 0,0);
        tempT.pts[1].set(1,0, 1, 0,w7,0, 1,0);
        T.shapes.push_back(tempT);
    
        tempT.bIsLine = true; // t hor
        tempT.bIsMultiLine = false;
        tempT.pts[0].set(1,0, 1, 0,0,0, 0 ,0);
        tempT.pts[1].set(1,0, 1, 0,1,0, 0,0);
        T.shapes.push_back(tempT);
    
    letterShape tempU;
    U.kerning = w1;
        tempU.bIsLine = true; // l vert
        tempU.bIsMultiLine = true;
        tempU.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempU.pts[1].set(1,0, 1, 0,0,0, 1,-r1);
        U.shapes.push_back(tempU);
        
        tempU.bIsLine = true; // r ver
        tempU.bIsMultiLine = false;
        tempU.pts[0].set(1,0, 1, 0,w12,0, 0,0);
        tempU.pts[1].set(1,0, 1, 0,w12,0, 1,-r1);
        U.shapes.push_back(tempU);
        
        tempU.bIsLine = true; //b hor
        tempU.pts[0].set(1, r1, 1, 0, 0, 0, 1, 0);
        tempU.pts[1].set(1, 0, 1, 0, w12, -r1, 1, 0);
        U.shapes.push_back(tempU);
        
        tempU.bIsLine = false; // bl
        tempU.center.set(1,r1, 1, 0,0,0, 1,-r1);
        tempU.startAngle = PI/2.0;
        tempU.radius = r1;
        U.shapes.push_back(tempU);
        
        tempU.bIsLine = false; // br
        tempU.center.set(1,0, 1, -r1, w12, -r1, 1, 0);
        tempU.startAngle = 0;
        tempU.radius = r1;
        U.shapes.push_back(tempU);
    
    letterShape tempV;
    V.kerning = 0;
        tempV.bIsLine = true; // l dia
        tempV.bIsMultiLine = true;
        tempV.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempV.pts[1].set(1,0, 1, 0,w7,0, 1,0);
        V.shapes.push_back(tempV);
    
        tempV.bIsLine = true; // r dia
        tempV.bIsMultiLine = false;
        tempV.pts[0].set(1,0, 1, 0,1,0, 0,0);
        tempV.pts[1].set(1,0, 1, 0,w7,0, 1,0);
        V.shapes.push_back(tempV);
    
    letterShape tempW;
    W.kerning = 0;
        tempW.bIsLine = true; // l dia L
        tempW.bIsMultiLine = true;
        tempW.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempW.pts[1].set(1,0, 1, 0,w4,0, 1,0);
        W.shapes.push_back(tempW);
    
        tempW.bIsLine = true; // l dia S
        tempW.bIsMultiLine = false;
        tempW.pts[0].set(1,0, 1, 0,w7,0, h7,0);
        tempW.pts[1].set(1,0, 1, 0,w4,0, 1,0);
        W.shapes.push_back(tempW);
    
        tempW.bIsLine = true; // l dia S
        tempW.pts[0].set(1,0, 1, 0,w7,0, h7,0);
        tempW.pts[1].set(1,0, 1, 0,w10,0, 1,0);
        W.shapes.push_back(tempW);
    
        tempW.bIsLine = true; // r dia L
        tempW.pts[0].set(1,0, 1, 0,1,0, 0,0);
        tempW.pts[1].set(1,0, 1, 0,w10,0, 1,0);
        W.shapes.push_back(tempW);
    
    letterShape tempX;
    X.kerning = w1;
        tempX.bIsLine = true; // l dia
        tempX.bIsMultiLine = true;
        tempX.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempX.pts[1].set(1,0, 1, 0,w12,0, 1,0);
        X.shapes.push_back(tempX);
    
        tempX.bIsLine = true; // r dia
        tempX.bIsMultiLine = false;
        tempX.pts[0].set(1,0, 1, 0,w12,0, 0,0);
        tempX.pts[1].set(1,0, 1, 0,0,0, 1,0);
        X.shapes.push_back(tempX);
    
    letterShape tempY;
    Y.kerning = 0;
        tempY.bIsLine = true; // c vert
        tempY.bIsMultiLine = true;
        tempY.pts[0].set(1,0, 1, 0,w7,0, h10,0);
        tempY.pts[1].set(1,0, 1, 0,w7,0, 1,0);
        Y.shapes.push_back(tempY);
    
        tempY.bIsLine = true; // l dia
        tempY.bIsMultiLine = false;
        tempY.pts[0].set(1,0, 1, 0,0,0, 0,0);
        tempY.pts[1].set(1,0, 1, 0,w7,0, h10,0);
        Y.shapes.push_back(tempY);
    
        tempY.bIsLine = true; // r dia
        tempY.pts[0].set(1,0, 1, 0,1,0, 0,0);
        tempY.pts[1].set(1,0, 1, 0,w7,0, h10,0);
        Y.shapes.push_back(tempY);
    
    letterShape tempZ;
    Z.kerning = w1;
        tempZ.bIsLine = true; // c dia
        tempZ.bIsMultiLine = true;
        tempZ.pts[0].set(1,0, 1, 0,w12,0, 0,0);
        tempZ.pts[1].set(1,0, 1, 0,0,0, 1,0);
        Z.shapes.push_back(tempZ);
    
        tempZ.bIsLine = true; // t hor
        tempZ.bIsMultiLine = false;
        tempZ.pts[0].set(1,0, 1, 0,0,0, 0 ,0);
        tempZ.pts[1].set(1,0, 1, 0,w12,0, 0,0);
        Z.shapes.push_back(tempZ);
    
        tempZ.bIsLine = true; // t hor
        tempZ.pts[0].set(1,0, 1, 0,0,0, 1 ,0);
        tempZ.pts[1].set(1,0, 1, 0,w12,0, 1,0);
        Z.shapes.push_back(tempZ);
    
}


//---------------------------------------------------------------
void hashMono::update(){
}


//---------------------------------------------------------------
void hashMono::draw(string letter, float x, float y, float width, float height, int multiLine, int r, float dist, bool horAlt){
    if (letter == "A") {
        A.draw(LETTERARGUMENTS);
    }
    if (letter == "B") {
        B.draw(LETTERARGUMENTS);
    }
    if (letter == "C") {
        C.draw(LETTERARGUMENTS);
    }
    if (letter == "D") {
        D.draw(LETTERARGUMENTS);
    }
    if (letter == "E") {
        E.draw(LETTERARGUMENTS);
    }
    if (letter == "F") {
        F.draw(LETTERARGUMENTS);
    }
    if (letter == "G") {
        G.draw(LETTERARGUMENTS);
    }
    if (letter == "H") {
        H.draw(LETTERARGUMENTS);
    }
    if (letter == "I") {
        I.draw(LETTERARGUMENTS);
    }
    if (letter == "J") {
        J.draw(LETTERARGUMENTS);
    }
    if (letter == "K") {
        K.draw(LETTERARGUMENTS);
    }
    if (letter == "L") {
        L.draw(LETTERARGUMENTS);
    }
    if (letter == "M") {
        M.draw(LETTERARGUMENTS);
    }
    if (letter == "N") {
        N.draw(LETTERARGUMENTS);
    }
    if (letter == "O") {
        O.draw(LETTERARGUMENTS);
    }
    if (letter == "P") {
        P.draw(LETTERARGUMENTS);
    }
    if (letter == "Q") {
        Q.draw(LETTERARGUMENTS);
    }
    if (letter == "R") {
        R.draw(LETTERARGUMENTS);
    }
    if (letter == "S") {
        S.draw(LETTERARGUMENTS);
    }
    if (letter == "T") {
        T.draw(LETTERARGUMENTS);
    }
    if (letter == "U") {
        U.draw(LETTERARGUMENTS);
    }
    if (letter == "V") {
        V.draw(LETTERARGUMENTS);
    }
    if (letter == "W") {
        W.draw(LETTERARGUMENTS);
    }
    if (letter == "X") {
        X.draw(LETTERARGUMENTS);
    }
    if (letter == "Y") {
        Y.draw(LETTERARGUMENTS);
    }
    if (letter == "Z") {
        Z.draw(LETTERARGUMENTS);
    }

}
