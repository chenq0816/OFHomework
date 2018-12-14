#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    count = 1;
    
    
    
    sound1.load("0.mp3");
    sound1.setMultiPlay(true);
//    sound1.play();
    
    sound2.load("1.mp3");
    sound2.setMultiPlay(true);
//    sound2.play();
    
    sound3.load("3.mp3");
    sound3.setMultiPlay(true);
//    sound3.play();
    
    ofSetBackgroundColor(0);

    for(int i = 0; i < 100; i++){
    pos = ofPoint(ofRandom(10,ofGetWidth()-10), ofRandom(10,ofGetHeight()-10));
    ballPos.push_back(pos);
        
    acc = .2 * ofPoint(ofRandom(-1,1), ofRandom(-1,1));
    ballAcc.push_back(acc);
        
    vel = 15 * ofPoint(ofRandom(-1,1), ofRandom(-1,1));
    ballVel.push_back(vel);
        
    force = ofPoint(ofRandom(-1,1), ofRandom(-1,1));
    ballForce.push_back(force);
        
    color = ofPoint(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
    ballColor.push_back(color);

    }
}

//--------------------------------------------------------------
void ofApp::update(){

//    vel += acc;
//    pos += vel;
//    for(int i = 0; i <100; i++){
//        ballVel[i] += ballAcc[i];
//        ballPos[i] += ballVel[i];
//    
//    
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i = 0; i < count; i++){
    ofSetColor(ballColor[i].x,ballColor[i].y, ballColor[i].z);
    ofDrawCircle(ballPos[i], 14);
        
//        ballVel[i] += ballAcc[i];
        ballPos[i] += ballVel[i];
        ofPoint board = ofPoint(ofGetMouseX(), ofGetHeight()-15);
     diffx = (ballPos[i].x - board.x) * (ballPos[i].x - board.x);
        diffy = (ballPos[i].y -board.y) * (ballPos[i].y -board.y);
        
        
        if((ballPos[i].x < 10 || ballPos[i].x > (ofGetWidth()-10)) && ballPos[i].y < ofGetHeight()-10){
//            ballAcc[i] += ballForce[i];
//            ballAcc[i] = - ballAcc[i];
            ballVel[i].x = - ballVel[i].x;
             sound1.play();
            
        }
        
//            if(ballPos[i].y < 10 || (diffx < 5625 && diffy < 144 && ballPos[i].y < ofGetHeight()-10)){
        if(ballPos[i].y < 10){

            
//            ballAcc[i] += ballForce[i];
//            ballAcc[i] = - ballAcc[i];
            ballVel[i].y = - ballVel[i].y;
                 sound1.play();
           
            
        }
        
        if(diffx < 5625 && diffy < 144 && ballPos[i].y < ofGetHeight()-10){
            ballVel[i].y = - ballVel[i].y;
            sound3.play();
        }
        
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofSetColor(255);
        ofDrawRectangle(ofGetMouseX(), ofGetHeight()-15, 150, 12);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    count += 1;
    sound2.play();
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
