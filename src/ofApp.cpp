#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(false);
	ofSetCircleResolution(50);
	ofEnableSmoothing();
	ofEnableAntiAliasing();

	
	//arc paths
	int kpis 		= 24;
	int numBlocks   = 6;
	float starRad   = 200;
	glm::vec2 center = glm::vec2(ofGetWidth()/2.0, ofGetHeight()/2.0);
	mRadarArcs = RadarArcs::create(starRad, center, kpis, numBlocks);
	mRadarArcs->createArcs();
	mRadarArcs->createLabels();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	mRadarArcs->draw();
	
}



//--------------------------------------------------------------
void ofApp::exit(){
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	mx = ofMap(x, 0, ofGetWidth(), 0.0, 360);
	my = ofMap(y, 0, ofGetHeight(), -50.0, 350.0);

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
