#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetBackgroundAuto(false);
	
	ofSetCircleResolution(50);
	
	ofEnableSmoothing();
	ofEnableAntiAliasing();
	
	radarFont.load("verdana.ttf", 18);
	numFont.load("verdana.ttf", 11);
	
	//arc paths

	kpis 		= 24;
	numBlocks   = 6;
	
	starRad = 200;
	
	mRadarArcs
	
//	float endCicle 	= starRad*4.0;
//	circleStep = (endCicle - starRad)/(float)numBlocks;
//	
//	float radStart =  ofDegToRad(270);
//	
//	centerW = glm::vec2(ofGetWidth()/2.0, ofGetHeight()/2.0);
//	
//	for(int i = 0; i < kpis; i++){
//		for(int j = 0; j < numBlocks; j++){
//			
//			ofPath 	arcp;
//			
//			float currCircle = (starRad) + j * circleStep;
//			float nextCircle = (starRad) + (j + 1) * circleStep;
//			
//			float div = 0.01;
//			
//			float stepArcCurr = (TWO_PI/kpis)* i +radStart;
//			float stepArcNext = (TWO_PI/kpis)*(i+1) + radStart;
//			
//			auto arcPointsInner = computeArcSegment(centerW, currCircle + 1, stepArcCurr + div, stepArcNext - div, 25);
//			auto arcPointsOuter = computeArcSegment(centerW, nextCircle - 1, stepArcNext - div, stepArcCurr + div , 25);
//			
//			
//			for (const auto &pt : arcPointsInner) {
//				arcp.lineTo(pt.x, pt.y);
//			}
//			
//			for (const auto &pt : arcPointsOuter) {
//				arcp.lineTo(pt.x, pt.y);
//			}
//			
//			arcp.setFilled(true);
//			
//			float alpha =  0.25 + (j/(float)numBlocks)*0.75;
//			if(i >= 0 &&  i <= 6){
//				arcp.setColor(ofFloatColor( (i/6.0)*0.25 + 0.20, alpha));
//			}
//			
//			if(i >= 7 &&  i <= 13){
//				arcp.setColor(ofFloatColor( ((i - 7.0)/13.0)*0.4 + 0.3, alpha));
//			}
//			
//			if(i >= 14 && i <= 23){
//				arcp.setColor(ofFloatColor( 0.55 - ((i -14.0)/23.0)*0.45,  alpha));
//			}
//			
//			arcp.close();
//			arcPaths.push_back(arcp);
//		}
//	}
//	
//	//around circle
//	for(int i = 0; i < kpis; i++){
//		
//		ofPath 	arcp;
//		
//		float div = 0.0;
//		float step = 20;
//		
//		float currCircle =  (numBlocks+2.05) * circleStep;
//		float nextCircle =  (numBlocks + 3.55) * circleStep ;
//		
//		
//		float stepArcCurr = (TWO_PI/kpis)*i + radStart;
//		float stepArcNext = (TWO_PI/kpis)*(i+1) + radStart;
//		
//		auto arcPointsInner = computeArcSegment(centerW, currCircle + 1, stepArcCurr + div, stepArcNext - div, 25);
//		auto arcPointsOuter = computeArcSegment(centerW, nextCircle - 1, stepArcNext - div, stepArcCurr + div , 25);
//		
//		
//		for (const auto &pt : arcPointsInner) {
//			arcp.lineTo(pt.x, pt.y);
//		}
//		
//		for (const auto &pt : arcPointsOuter) {
//			arcp.lineTo(pt.x, pt.y);
//		}
//		
//		
//		arcp.setFilled(true);
//		if(i >= 0 &&  i <= 6){
//			arcp.setColor(ofFloatColor( (i/6.0)*0.25 + 0.20, 0.75));
//		}
//		
//		if(i >= 7 &&  i <= 13){
//			arcp.setColor(ofFloatColor( ((i - 7.0)/13.0)*0.4 + 0.3, 0.75));
//		}
//		
//		if(i >= 14 && i <= 23){
//			arcp.setColor(ofFloatColor( 0.55 - ((i -14.0)/23.0)*0.45, 0.75));
//		}
//		
//		arcp.close();
//		arcPaths.push_back(arcp);
//	}
//	
//	
//	//around circle
//	for(int i = 0; i < kpis; i++){
//		ofPath 	arcp;
//		
//		float div = 0.0;
//		float step = 20;
//		
//		float currCircle =  (numBlocks+3.53) * circleStep;
//		float nextCircle =  (numBlocks + 3.73) * circleStep ;
//		
//		
//		float stepArcCurr = (TWO_PI/kpis)*i + radStart;
//		float stepArcNext = (TWO_PI/kpis)*(i+1) + radStart;
//		
//		auto arcPointsInner = computeArcSegment(centerW, currCircle + 1, stepArcCurr + div, stepArcNext - div, 25);
//		auto arcPointsOuter = computeArcSegment(centerW, nextCircle - 1, stepArcNext - div, stepArcCurr + div , 25);
//		
//		
//		for (const auto &pt : arcPointsInner) {
//			arcp.lineTo(pt.x, pt.y);
//		}
//		
//		for (const auto &pt : arcPointsOuter) {
//			arcp.lineTo(pt.x, pt.y);
//		}
//		
//		
//		arcp.setFilled(true);
//		
//		if(i >= 0 &&  i <= 6){
//			arcp.setColor(ofFloatColor( (i/6.0)*0.25 + 0.20, 0.35));
//		}
//		
//		if(i >= 7 &&  i <= 13){
//			arcp.setColor(ofFloatColor( ((i - 7.0)/13.0)*0.4 + 0.3, 0.35));
//		}
//		
//		if(i >= 14 && i <= 23){
//			arcp.setColor(ofFloatColor( ((i -14.0)/23.0)*0.4 + 0.6, 0.35));
//		}
//		
//		arcp.close();
//		arcPaths.push_back(arcp);
//	}
	
	
	
	

	
	
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	float kpis = 24;
	

	float centerX = ofGetWidth()/2.0;
	float centerY = ofGetHeight()/2.0;
	
	ofPoint center(centerX, centerY);
	ofFill();
	ofSetColor(0, 155);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	
	
	//center circle
	float rad = starRad*0.85;
	ofFill();
	ofSetColor(230, 200);
	ofDrawCircle(centerX, centerY, rad);
	
	//centr-outer circle
	
	//outer circle
	
	//outer outer circle
	
	
//	ofPolyline outerCircles;
//	outerCircles.arc(center, 100, 100, 0, 360, 50);
//	ofSetColor(0, 200, 200);
//	//ofSetLineWidth(5);
//	//ofSetPointSize(5);
//	//outerCircles.draw();
//	
//	for(int i = 0; i< 24; i++){
//		ofPath outerCircles;
//		float angleInc = 360/kpis;
//		float startAng = ofDegToRad(angleInc*i);
//		float endAng =   ofDegToRad(angleInc*(i+1)-1);
//		float midAng =   ofDegToRad(angleInc*(i+0.5));
//		
//		
//		float rad = 400;
//		float posXc =  rad*cos(ofDegToRad(angleInc*(i))) + centerX;
//		float posYc =  rad*sin(ofDegToRad(angleInc*(i))) + centerY;
//		
//		float posX2c =  rad*cos(ofDegToRad(angleInc*(i+1))) + centerX;
//		float posY2c =  rad*sin(ofDegToRad(angleInc*(i+1))) + centerY;
//		
//		float posX = rad*cos(startAng) + centerX;
//		float posY = rad*sin(startAng) + centerY;
//		
//		float posX2 = rad*cos(endAng) +centerX;
//		float posY2 = rad*sin(endAng)+ centerY;
//		
//		float posCX = (rad)*cos(midAng) + centerX;
//		float posCY = (rad)*sin(midAng) + centerY;
//		
//		//outerCircles.setMode(ofPath::POLYLINES);
//		//outerCircles.curveTo(posXc, posYc);
//		//outerCircles.curveTo(posX, posY);
//		//outerCircles.curveTo(posX2, posY2);
//		//outerCircles.curveTo(posX2c, posY2c);
//		
//		//outerCircles.moveTo(centerX, centerY);
//		//outerCircles.arc(centerX, centerY, 300+i*2, 300+i*2, (angleInc*i), angleInc*(i+1));
//		
//		outerCircles.setMode(ofPath::POLYLINES);
//		outerCircles.quadBezierTo(posX, posY, posCX, posCY, posX2, posY2);
//
//		//outerCircles.setPolyWindingMode(OF_POLY_WINDING_ODD);
//		
//		//outerCircles.close();
//		ofSetColor(255, 0, 0);
//		ofDrawEllipse(posX, posY, 5, 5);
//		ofSetColor(0, 255, 0);
//		ofDrawEllipse(posX2, posY2, 5, 5);
//		ofSetColor(0, 0, 255);
//		ofDrawEllipse(posCX, posCY, 5, 5);
//		outerCircles.setColor(ofFloatColor(i/24.0, 0.2 + i/50.0, 0.8, 1.0));
//		//outerCircles.setStrokeColor(ofFloatColor(i/24.0, 0.2 + i/50.0, 0.8, 0.2));
//		outerCircles.setStrokeWidth(1);
//		outerCircles.setFilled(false);
//		//outerCircles.close();
//		
//		//ofPath path;
//		//path.append(outerCircles);
//		//path.draw();
//		outerCircles.draw();
//	}
	
	

	//arcPath.draw();
	
	for(const auto & arcs : arcPaths){
		arcs.draw();
	}
	

	std::vector<std::string> lines = {
		"PRICE\nAFFORDABILITY",
		"RENTAL\nAFFORDABILITY",
		"WAGE\nACCESIBILITY",
		"HOMEOWNERSHIP\nOPPORTUNITY INDEX",
		"FAIR RENTAL\nOPPORTUNITY INDEX",
		"AFFORDABLE HOUSING\nSUPPORT INDEX",
		"ACCESSIBILITY &\nCOVERAGE",
		"PARKS &\nGREEN SPACES",
		"COMMUNITY &\nSOCIAL INTERACTION",
		"PUBLIC SCHOOLS &\nEDUCATION FACILITIES",
		"COMMUNITY SERVICES &\nCULTURAL SPACES",
		"ECONOMIC &\nJOB OPPORTUNITIES",
		"& SUSTAINABLE \nSPACES PUBLIC SMART",
		"& AFFORDABILITY \n EQUITY",
		"AVERAGE\nTIME WAIT",
		"TRANSPORT PUBLIC\nCOVERAGE",
		"OVERCROWDING\nBUSES OF",
		"OF FREQUENCY\n BUSES",
		"MILES PER MODE",
		"MODE SHARE",
		"COMMUNITY\nINDEX STABILITY",
		"HOUSING HEALTHY\nRATE VACANCY ",
		"AVAILABILITY\nINDEX",
		"COST\nEFFICIENCY"
	};
	
	// New vector to store the processed (word-reversed) strings.
	std::vector<std::string> processedLines;
	processedLines.reserve(lines.size()); // Reserve space for efficiency.

	// Process each string in the original vector.
	for (const auto &line : lines) {
		// Use an istringstream to handle possible newline characters.
		std::istringstream iss(line);
		std::string segment;
		std::string processedString;
		bool firstSegment = true;
		// Process each segment separated by newline.
		while(std::getline(iss, segment, '\n')) {
			if (!firstSegment)
				processedString += "\n"; // Preserve the newline separator.

			// Now process this segment by reversing each word.
			std::istringstream wordStream(segment);
			std::string word;
			std::string processedSegment;
			bool firstWord = true;
			while (wordStream >> word) {
				if (!firstWord)
					processedSegment += " ";
				std::reverse(word.begin(), word.end());
				processedSegment += word;
				firstWord = false;
			}
			processedString += processedSegment;
			firstSegment = false;
		}
		// Add the processed string to the new vector.
		processedLines.push_back(processedString);
	}
	
	
	
	float spacing = 10; // additional spacing between lines
	float totalHeight = 0;
	std::vector<float> lineHeights;
	for (auto &s : lines) {
		//ofRectangle bbox = myFont.getStringBoundingBox(s, 0, 0);
		// Store each line's height for later use.
		//lineHeights.push_back(bbox.height);
		//totalHeight += bbox.height + spacing;
	}
	//totalHeight -= spacing;
	
	
	float offSet = ofDegToRad(272);
	float ioffSet = ofDegToRad(267);
	
	float offInc = 0.007;
	
	ofSetColor(255);
	for(int i = 0; i < kpis; i++){
		float rad  =  (numBlocks + 4.12) * circleStep ;
		float irad  =  (numBlocks + 3.95) * circleStep ;
		
		float step = (i/(float)kpis + offInc)*TWO_PI;
		
		float x = rad*cos(step + offSet) + centerW.x;
		float y = rad*sin(step + offSet) + centerW.y;
		
		float ix = irad*cos(step + ioffSet) + centerW.x;
		float iy = irad*sin(step + ioffSet) + centerW.y;
		
		float xdir = std::copysign(1.0f, cos(step + offSet));
		
//		ofRectangle bbox = myFont.getStringBoundingBox(lines[i], 0, 0);
//		float bx = (bbox.width) / 2.0;
//		float by = bbox.height / 2.0;
		
		numFont.drawString(ofToString(i), ix, iy);
		
		if(xdir == -1){
			radarFont.setDirection(OF_TTF_RIGHT_TO_LEFT);
			radarFont.drawString(processedLines[i], x, y);
		
		}else{
			radarFont.setDirection(OF_TTF_LEFT_TO_RIGHT);
			radarFont.drawString(lines[i], x, y);
		}
	}
	
	ofSetColor(255);
	ofDrawBitmapString(mx, 50, 50);
	ofDrawBitmapString(offSet, 50, 80);
	ofDrawBitmapString(my, 50, 120);
	
}


std::vector<glm::vec2> ofApp::computeArcSegment(const glm::vec2 &center, float radius, float startAngle, float endAngle, int numPoints){
	std::vector<glm::vec2> arcPoints;
	float angleStep = (endAngle - startAngle) / (numPoints - 1);
	for (int i = 0; i < numPoints; i++) {
		float angle = startAngle + i * angleStep;
		glm::vec2 point(center.x + radius * cos(angle), center.y + radius * sin(angle));
		arcPoints.push_back(point);
	}
	return arcPoints;
	
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
