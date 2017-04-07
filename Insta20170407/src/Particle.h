#pragma once

#include "ofMain.h"

class Particle
{
public:
	Particle(float x, float y, float z);
	~Particle();
	
	void applyForce(ofVec3f force);
	ofVec3f seek(ofVec3f target);

	void update();
	void draw();

private:
	ofVec3f location;
	vector<ofVec3f> log;
	ofVec3f velocity;
	ofVec3f acceleration;
	ofVec3f future;
	ofVec3f target;
	float max_speed;
	float max_force;
	float radius;
	float angle;
	
	ofColor body_color;
	float body_size;
};