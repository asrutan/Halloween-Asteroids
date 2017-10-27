// player.cpp
// Alex Rutan
// 11//21/15
#include <iostream>
#include <cmath>
#include "player.h"

using namespace std;

Player::Player()
{
    spriteX = 50;//wraps collision box closer to sprite
    spriteY = 0;
    speed = 10;//movement speed
    //end protected inherited vars

	collided[0] = false;
	collided[1] = false;
	
	dir[0] = false;

	x = 400;
    y = 300;
    height = 50;//height of player/sprite - used by collidebox
    width = 50;//width of player/sprite - used by collidebox
    //end public inherited vars

	thrust = false;

	entityID = 0;
	//sprite = "player.bmp";
	floorHit = false;
	this->xVelocity = 4;
	degree = 30;
    //make this an array or list or some shit
    //end new vars
} //end constructor


Player::~Player()
{
} //end deconstructor

void Player::update()//changed from entity
{
	if (dying)dead = true; //no death animation, so skip right to dead.

	if (thrust)
	{
		if (speed < speedCap)
		{
			speed++;
		}
	}
	else
	{
		if (speed > 0)
		{
			speed--;
		}
	}

	x = newX;
	y = newY;
	if (x < 0)
	{
		x = 800;
	}

	if (x > 800)
	{
		x = 0;
	}

	if (y < 0)
	{
		y = 600;
	}

	if (y > 600)
	{
		y = 0;
	}
} //end update

void Player::move()
{
	x = x + xVelocity;//update x by xVelocity
}


//void Entity::move()
//{
//	x = x + xVelocity;//update x by xVelocity
//}

void Player::setThrust(bool toggle)
{
	thrust = toggle;
}
