// movement.cpp
// Alex Rutan
// 11/21/15
#include <iostream>
#include <math.h>
#include "movement.h"

using namespace std;

Movement::Movement()
{
} //end constructor

Movement::~Movement()
{
} //end destructor

void Movement::move(Entity *entity)
{

	xVelocity = entity->getXVelocity();
	yVelocity = entity->getYVelocity();
	speed = entity->getSpeed();
	friction = entity->getFriction();
	acceleration = entity->getAcceleration();


	//0 = stopped
	//1 = right
	//2 = left
	//3 = up
	//4 = down
	if (entity->getDir(0))
	{
		if (xVelocity != 0)
		{
			if (xVelocity > 0) entity->setXVelocity(xVelocity - friction); //increment by friction

			else if (xVelocity < 0) entity->setXVelocity(xVelocity + friction);
		} //end if

		if (yVelocity != 0)
		{
			if (yVelocity > 0) entity->setYVelocity(xVelocity - friction); //increment by friction

			else if (yVelocity < 0) entity->setYVelocity(yVelocity + friction);
		} //end if
	} //end if
	else
	{
		if (entity->getDir(1)) // move right
		{
			if (xVelocity < speed)
			{
				entity->setXVelocity(xVelocity + acceleration);
			}
			//entity->setNewXY(entity->getXVelocity, 0);
		} //end if

		if (entity->getDir(2)) // move left
		{
			if (xVelocity > speed*-1)
			{
				entity->setXVelocity(xVelocity - acceleration);
			}
			//entity->setNewXY(entity->getXVelocity, 0);
		} //end if

		if (entity->getDir(3)) // move up
		{

		} //end if

		if (entity->getDir(4)) // move down
		{

		} //end if
	} //end else

	entity->setNewXY
	(
		xVelocity,
		yVelocity
	);
}

void Movement::move(Entity *entity, double direction)
{
	xVelocity = entity->getXVelocity();
	yVelocity = entity->getYVelocity();
	speed = entity->getSpeed();
	friction = entity->getFriction();
	acceleration = entity->getAcceleration();
	degree = entity->getDegree();

	if (entity->getDir(0))
	{
		if (xVelocity != 0)
		{
			if (xVelocity > 0) entity->setXVelocity(xVelocity - friction); //increment by friction

			else if (xVelocity < 0) entity->setXVelocity(xVelocity + friction);
		} //end if

		if (yVelocity != 0)
		{
			if (yVelocity > 0) entity->setYVelocity(xVelocity - friction); //increment by friction

			else if (yVelocity < 0) entity->setYVelocity(yVelocity + friction);
		} //end if
	} //end if

	else
	{ 
		if (xVelocity < entity->getSpeedCap())
		{
			//xVelocity += acceleration;
			entity->setXVelocity(cos(degree) * speed);
		}

		if (yVelocity < entity->getSpeedCap())
		{
			//yVelocity += acceleration;
			entity->setYVelocity(sin(degree) * speed);
		}
	} //end else

	entity->setNewXY
	(
		xVelocity,
		yVelocity
	);
}
