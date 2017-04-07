#include "Particle.h"

Particle::Particle(float x, float y, float z)
{
	this->location = ofVec3f(x, y, z);
	this->velocity = ofVec3f(0, 0, 0);
	this->acceleration = ofVec3f(0, 0, 0);

	this->max_speed = 20;
	this->max_force = 5;
	this->radius = 30;
	this->angle = ofRandom(360);

	float body_value = ofRandom(255);
	this->body_color.setHsb(body_value, 255, 255, 255);
	this->body_size = 5;
}

Particle::~Particle()
{

}

void Particle::applyForce(ofVec3f force)
{
	this->acceleration += force;
}

ofVec3f Particle::seek(ofVec3f target)
{
	ofVec3f desired = this->location - target;
	float distance = desired.length();
	desired.normalize();
	if (distance < this->radius)
	{
		float m = ofMap(distance, 0, this->radius, 0, this->max_speed);
		desired *= m;
	}
	else
	{
		desired *= this->max_speed;
	}

	ofVec3f steer = this->velocity - desired;
	steer.limit(this->max_force);
	return steer;
}

void Particle::update()
{
	this->velocity += this->acceleration;
	this->velocity.limit(max_speed);
	this->location += this->velocity;
	
	this->acceleration *= 0;
	this->velocity *= 0.98;

	/*
	this->log.push_back(this->location);
	if (this->log.size() > 20)
	{
		this->log.erase(this->log.begin());
	}
	*/
}

void Particle::draw()
{
	//ofSetColor(this->body_color, 128);
	//ofSetLineWidth(0.01);
	//ofLine(ofVec3f(0, 0, 0), this->location);

	ofPushMatrix();
	ofTranslate(this->location.x, this->location.y, this->location.z);
	ofSetColor(this->body_color);
	ofSphere(this->body_size);
	ofPopMatrix();

	/*
	ofPath line = ofPath();
	line.setStrokeColor(this->body_color);
	line.setStrokeWidth(1);
	line.setFilled(false);

	for (auto itr = log.begin(); itr != log.end(); ++itr)
	{
		if (itr == log.begin())
		{
			line.moveTo(itr->x, itr->y);
		}
		else
		{
			line.lineTo(itr->x, itr->y);
		}
	}

	line.draw();
	line.close();
	*/
}