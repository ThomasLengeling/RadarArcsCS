//
//  RadaArcs.h
//  SFRadar
//
//  Created by thomas on 3/10/25.
//

#pragma once

#include "ofMain.h"

#include <vector>

class RadarArcs;
class Arc;

typedef std::shared_ptr<RadarArcs> RadarArcsRef;

typedef std::shared_ptr<Arc> ArcRef;



class Arc{
public:
	~Arc(){}
	Arc(int idKPI, glm::vec2 center, int numKpis, int numBlocks){
		this->idKPI  = idKPI;
		this->center = center;
		this->numKpis   = numKpis;
		this->numBlocks = numBlocks;
	}
	
	//create memory
	static ArcRef create(int kpis, glm::vec2 center, int numKpis, int numBlocks) {
		return std::make_shared<Arc>(kpis, center, numKpis, numBlocks);
	}
	
	void createArc(float startArc){
		float endCicle 	= startArc*4.0;
		circleStep = (endCicle - startArc)/(float)numBlocks;
		float radStart =  ofDegToRad(270);
		
		
		//block increments
		for(int j = 0; j < numBlocks; j++){
			ofPath 	arcp;
			
			float currCircle = (startArc) + j * circleStep;
			float nextCircle = (startArc) + (j + 1) * circleStep;
			
			float div = 0.01;
			
			float stepArcCurr = (TWO_PI/numKpis) * idKPI +radStart;
			float stepArcNext = (TWO_PI/numKpis) * (idKPI + 1) + radStart;
			
			auto arcPointsInner = computeArcSegment(center, currCircle + 1, stepArcCurr + div, stepArcNext - div, 25);
			auto arcPointsOuter = computeArcSegment(center, nextCircle - 1, stepArcNext - div, stepArcCurr + div , 25);
		
			for (const auto &pt : arcPointsInner) {
				arcp.lineTo(pt.x, pt.y);
			}
			
			for (const auto &pt : arcPointsOuter) {
				arcp.lineTo(pt.x, pt.y);
			}
			
			float alpha =  0.25 + (j/(float)numBlocks)*0.75;
			ofFloatColor mColor = ofFloatColor( (idKPI/6.0)*0.25 + 0.20, alpha);
			
			arcp.setFilled(true);
			arcp.setColor(mColor);
			arcp.close();
			arcInc.push_back(arcp);
		}
		//outer block
		{
			ofPath 	arcp;
			
			float div = 0.0;
			float step = 20;
			
			float currCircle =  (numBlocks+2.05) * circleStep;
			float nextCircle =  (numBlocks + 3.55) * circleStep ;
			
			
			float stepArcCurr = (TWO_PI/numKpis) * idKPI + radStart;
			float stepArcNext = (TWO_PI/numKpis) * (idKPI + 1) + radStart;
			
			auto arcPointsInner = computeArcSegment(center, currCircle + 1, stepArcCurr + div, stepArcNext - div, 25);
			auto arcPointsOuter = computeArcSegment(center, nextCircle - 1, stepArcNext - div, stepArcCurr + div , 25);
			
			for (const auto &pt : arcPointsInner) {
				arcp.lineTo(pt.x, pt.y);
			}
			
			for (const auto &pt : arcPointsOuter) {
				arcp.lineTo(pt.x, pt.y);
			}
			
			float alpha =  0.25 + (idKPI/(float)numKpis)*0.75;
			ofFloatColor mColor = ofFloatColor( (idKPI/6.0)*0.25 + 0.20, 0.75, alpha);
			
			arcp.setFilled(true);
			arcp.setColor(mColor);
			arcp.close();
			
			arcOuter = arcp;
		}
		
		//end block
		{
			ofPath 	arcp;
			
			float div = 0.0;
			float step = 20;
			
			float currCircle =  (numBlocks+3.53) * circleStep;
			float nextCircle =  (numBlocks + 3.73) * circleStep ;
			
			float stepArcCurr = (TWO_PI/numKpis) * idKPI + radStart;
			float stepArcNext = (TWO_PI/numKpis) * (idKPI + 1) + radStart;
			
			auto arcPointsInner = computeArcSegment(center, currCircle + 1, stepArcCurr + div, stepArcNext - div, 25);
			auto arcPointsOuter = computeArcSegment(center, nextCircle - 1, stepArcNext - div, stepArcCurr + div , 25);
			
			for (const auto &pt : arcPointsInner) {
				arcp.lineTo(pt.x, pt.y);
			}
			
			for (const auto &pt : arcPointsOuter) {
				arcp.lineTo(pt.x, pt.y);
			}
			
			float alpha =  0.25 + (idKPI/(float)numKpis)*0.75;
			ofFloatColor mColor = ofFloatColor( (idKPI/6.0)*0.25 + 0.20, 0.75, 0.0, alpha);
			
			arcp.setFilled(true);
			arcp.setColor(mColor);
			
			arcp.close();
			arcEnd = arcp;
		}
	}
	
	void drawIncArcs(){
		for(const auto & arcBlocks : arcInc){
			arcBlocks.draw();
		}
	}
	
	void drawOuterdArc(){
		arcOuter.draw();
	}
	
	void drawEndArc(){
		arcEnd.draw();
	}
	
	void drawLabel(std::string str1, std::string str2, ofTrueTypeFont radarFont, ofTrueTypeFont numFont){
		float offSet = ofDegToRad(272);
		float ioffSet = ofDegToRad(267);
		float offInc = 0.007;
		
		float rad   =  (numBlocks + 4.12) * circleStep ;
		float irad  =  (numBlocks + 3.95) * circleStep ;
		
		float step = (idKPI/(float)numKpis + offInc)*TWO_PI;
		
		float x = rad*cos(step + offSet) + center.x;
		float y = rad*sin(step + offSet) + center.y;
		
		float ix = irad*cos(step + ioffSet) + center.x;
		float iy = irad*sin(step + ioffSet) + center.y;
		
		float xdir = std::copysign(1.0f, cos(step + offSet));
		
		numFont.drawString(ofToString(idKPI), ix, iy);
		
		if(xdir == -1){
			radarFont.setDirection(OF_TTF_RIGHT_TO_LEFT);
			radarFont.drawString(str2, x, y);
		}else{
			radarFont.setDirection(OF_TTF_LEFT_TO_RIGHT);
			radarFont.drawString(str1, x, y);
		}
		
	}
	
	std::vector<glm::vec2> computeArcSegment(const glm::vec2 &center, float radius, float startAngle, float endAngle, int numPoints){
		std::vector<glm::vec2> arcPoints;
		float angleStep = (endAngle - startAngle) / (numPoints - 1);
		for (int i = 0; i < numPoints; i++) {
			float angle = startAngle + i * angleStep;
			glm::vec2 point(center.x + radius * cos(angle), center.y + radius * sin(angle));
			arcPoints.push_back(point);
		}
		return arcPoints;
	}

	
	std::vector<ofPath> arcInc;
	ofPath				arcOuter;
	ofPath				arcEnd;
	
	float circleStep;
	
	glm::vec2 center;
	
	float idKPI;
	
	int numKpis;
	int numBlocks;
	
	float value;
	ofColor mBasedColor;
};

class RadarArcs{
public:
	RadarArcs(int startRad, glm::vec2 center, int numKPIs, int numBlocks){
		this->startRad = startRad;
		this->numKPIs = numKPIs;
		this->numBlocks =  numBlocks;
		this->mCenter	= center;
		
		radarFont.load("verdana.ttf", 18);
		numFont.load("verdana.ttf", 11);
	}
	
	~RadarArcs(){
	}
	
	//create memory
	static RadarArcsRef create(int startRad, glm::vec2 center, int numKPIs, int numBlocks) {
		return std::make_shared<RadarArcs>(startRad, center, numKPIs, numBlocks);
		
	}
	
	void createArcs(){
		for(int i = 0; i < numKPIs; i++){
			ArcRef ar  = Arc::create(i, mCenter, numKPIs, numBlocks);
			ar->createArc(startRad);
			mArcs.push_back(ar);
		}
	}
	
	void createLabels(){
		std::vector<std::string> tlabel = {
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
		
		label = tlabel;
		
		// New vector to store the processed (word-reversed) strings.
		labelReverse.reserve(label.size()); // Reserve space for efficiency.
		
		// Process each string in the original vector.
		for (const auto &line : label) {
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
			labelReverse.push_back(processedString);
		}
	}
	
	void draw(){
		
		float rad = startRad*0.85;
		ofFill();
		ofSetColor(230, 200);
		ofDrawCircle(mCenter.x, mCenter.y, rad);
			
		for(const auto & arcs : mArcs){
			arcs->drawIncArcs();
			arcs->drawOuterdArc();
			arcs->drawEndArc();
		}
		
		int i=0;
		for(const auto & arcs : mArcs){
			arcs->drawLabel(label[i], labelReverse[i], radarFont, numFont);
			i++;
		}
		
	}
	
	void updateArc(int i, float amt){
		
	}
	
	std::vector<ArcRef> mArcs;
	float groupType;
	
	float numKPIs;
	float numBlocks;
	
	float startRad;
	glm::vec2  mCenter;
	
	//labels
	ofTrueTypeFont radarFont;
	ofTrueTypeFont numFont;
	
	std::vector<std::string> label;
	std::vector<std::string> labelReverse;
};
