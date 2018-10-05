#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
ofBackground(0,0,0);
    counter = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
//    counter = ofRandom(0, ofGetWidth());
//     counter2 = ofRandom(0, ofGetWidth());
//    
//    for (auto &vert : line.getVertices()){
//        
//        
//        vert.x += ofSignedNoise(counter*.001,counter * 8000)*2*ofRandom(0,1);;
//        vert.y += ofSignedNoise(counter2 * 8000,counter2*.001)*1*ofRandom(0,1);
    float rotate = sin(ofGetElapsedTimef());
    
    counter += 0.002;
     for (auto &vert : line.getVertices()){
         
         vert.x += ofSignedNoise(vert.x * rotate, counter);
         vert.y += ofSignedNoise(counter, vert.y * rotate);
         
    
        
        
        
        
//        vert.x += ofRandom(-1,1);
//        vert.y += ofRandom(-1,1);
    }
    
//    auto & vert = line.getVertices();
//
//     for(int i   = 0; i <10; i++){
//        float x = ofNoise(counter, i );
//        float y = ofNoise(i , counter);
//         vert[i].x += x;
//         vert[i].y += y;
//         
//    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    line.draw();
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
    ofPoint pt;
    pt.set(x,y);
    line.addVertex(pt);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
line.clear();
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
