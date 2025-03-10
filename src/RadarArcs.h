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
	Arc(int idKPI){
		this->idKPI = idKPI;
	}
	
	//create memory
	static ArcRef create(int kpis) {
		return std::make_shared<Arc>(kpis);
	}
	
	void createArc(float startArc, int numKpis){
		float endCicle 	= startArc*4.0;
		float circleStep = (endCicle - startArc)/(float)numBlocks;
		float radStart =  ofDegToRad(270);
		mCenter = glm::vec2(ofGetWidth()/2.0, ofGetHeight()/2.0);
		
		//block increments
		for(int j = 0; j < numBlocks; j++){
			ofPath 	arcp;
			
			float currCircle = (startArc) + j * circleStep;
			float nextCircle = (startArc) + (j + 1) * circleStep;
			
			float div = 0.01;
			
			float stepArcCurr = (TWO_PI/numKpis) * idKPI +radStart;
			float stepArcNext = (TWO_PI/numKpis) * (idKPI + 1) + radStart;
			
			auto arcPointsInner = computeArcSegment(mCenter, currCircle + 1, stepArcCurr + div, stepArcNext - div, 25);
			auto arcPointsOuter = computeArcSegment(mCenter, nextCircle - 1, stepArcNext - div, stepArcCurr + div , 25);
		
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
			
			auto arcPointsInner = computeArcSegment(mCenter, currCircle + 1, stepArcCurr + div, stepArcNext - div, 25);
			auto arcPointsOuter = computeArcSegment(mCenter, nextCircle - 1, stepArcNext - div, stepArcCurr + div , 25);
			
			
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
			
			auto arcPointsInner = computeArcSegment(mCenter, currCircle + 1, stepArcCurr + div, stepArcNext - div, 25);
			auto arcPointsOuter = computeArcSegment(mCenter, nextCircle - 1, stepArcNext - div, stepArcCurr + div , 25);
			
			
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
	
	glm::vec2  mCenter;
	float idKPI;
	float value;
	float numBlocks;
	ofColor mBasedColor;
};

class RadarArcs{
public:
	RadarArcs(int startRad, int numKPIs){
		this->startRad = startRad;
		this->numKPIs = numKPIs;
	}
	
	~RadarArcs(){
	}
	
	//create memory
	static RadarArcsRef create(int startRad, int numKPIs) {
		return std::make_shared<RadarArcs>(startRad, numKPIs);
		
	}
	
	void createArcs(float numKPIs, float numBlocks){
	
		for(int i = 0; i < numKPIs; i++){
			ArcRef ar  = Arc::create(i);
			ar->createArc(startRad, numKPIs);
			mArcs.push_back(ar);
		}
	}
	
	void draw(){
		for(const auto & arcs : mArcs){
			arcs->drawIncArcs();
			arcs->drawOuterdArc();
			arcs->drawEndArc();
		}
	}
	
	void updateArc(int i, float amt){
		
	}
	
	std::vector<ArcRef> mArcs;
	float groupType;
	
	float numKPIs;
	float numBlocks;
	
	float startRad;

	
};
