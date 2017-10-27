// entity.cpp
// PA
// 1/5/16
#include <iostream>
#include <cmath>
#include "entity.h"

using namespace std;

Entity::Entity()
{
    spriteX = 0;
    spriteY = 0;
    //end private vars
    //x = 200;
   // y = 300;
    height = 50;
    width = 50;
	dir[0] = true;
	dir[1] = false;
	dir[2] = false;
	dir[3] = false;
	dir[4] = false;
    //end public var
} //end constructor

Entity::~Entity()
{
} //end deconstructor

void Entity::setListID(int id)
{
	listID = id;
}
int Entity::getListID()
{
	return listID;
}
int Entity::getEntityID()
{
	return entityID;
}
//end setListID

void Entity::update()
{
} //end update

bool Entity::getIsDead()
{
	return dead;
}//end setXY

void Entity::setXY(double mx,double my)
{
	x = mx;
	y = my;
}

void Entity::setNewXY(double mx, double my)
{
	newX = x + mx;
	newY = y + my;
}
double Entity::getX()
{
	return x;
}
double Entity::getY()
{
	return y;
}
double Entity::getXVelocity()
{
	return xVelocity;
}
double Entity::getYVelocity()
{
	return yVelocity;
}
void Entity::setXVelocity(double xVel)
{
	xVelocity = xVel;
}
void Entity::setYVelocity(double yVel)
{
	yVelocity = yVel;
}
bool Entity::getDir(int i)
{
	return dir[i];
}
double Entity::getFriction()
{
	return friction;
}
int Entity::getSpeed()
{
	return speed;
}
double Entity::getAcceleration()
{
	return acceleration;
}

double Entity::getDegree()
{
	return degree;
}

int Entity::getSpeedCap()
{
	return speedCap;
}

void Entity::setDegree(double newDeg)
{
	degree = newDeg;
}

void Entity::setThrust(bool)
{
	cout << "Not the player, can't thrust" << endl;
}

bool Entity::getThrust()
{
	return thrust;
}

void Entity::kill()
{
	dying = true;
}
