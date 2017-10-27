// projectile.cpp
// Alex Rutan
// 10/25/17
#include <iostream>
#include "projectile.h"
#include "entity.h"

using namespace std;

Projectile::Projectile()
{
	collided[0] = false;
	collided[1] = false;
	speed = 9;
	speedCap = 10;
	acceleration = 1;
    xVelocity = 0;
	yVelocity = 0;
    //end protected inherited vars

	dir[0] = false;
	dir[1] = false;
	dir[2] = false;
	dir[3] = false;
	dir[4] = false;

	newX = 0;
	newY = 0;

    x = 0;
    y = 0;

    //end public inherited vars
    left = false;
    right = true;
    tick = 0;
    frame = 0;
    //end new vars

	entityID = 2;
} //end constructor

Projectile::Projectile(int direction)
{
	collided[0] = false;
	collided[1] = false;

	dir[0] = false;
	dir[1] = false;
	dir[2] = false;
	dir[3] = false;
	dir[4] = false;

	dir[direction] = true;

	degree = 45;

	speed = 5;
	speedCap = 10;
	acceleration = 1;
	xVelocity = 0;
	yVelocity = 0;
	//end protected inherited vars

	newX = 0;
	newY = 0;

	x = 0;
	y = 0;

	height = 20;
	width = 20;

	//end public inherited vars
	left = false;
	right = true;
	tick = 0;
	frame = 0;
	//end new vars

	entityID = 2;
} //end constructor

Projectile::~Projectile()
{
} //end deconstructor

void Projectile::update()
{
	if (!dying)
	{
		if (collided[1])kill(); //if collided with enemy (entID = 1)

		if (!collided[1])
		{
			x = newX;
			y = newY;

			if (x < 0)
			{
				kill();
			}

			if (x > 800)
			{
				kill();
			}

			if (y < 0)
			{
				kill();
			}

			if (y > 600)
			{
				kill();
			}
		}
		else
		{
			dir[0] = true;
			dir[1] = false;
			dir[2] = false;
			//xVelocity = 0;
			//yVelocity = 0;

			//Bouncing effect when hit wall
			x -= xVelocity;
			y -= yVelocity;
		}
	}
	else
	{
		if (height > 0 && width > 0)
		{
			height -= 2;
			width -= 2;
		}
		else dead = true;
	}
}//end update

void Projectile::tryMove()
{
    if(right)
    {
//	xNew = x + 5;
    }
    if(left)
    {
//	xNew = x - 5;
    }
//    if(!yCollided)
//    {
//	airbound = true;
//    } //end if
    
} //end move

void Projectile::fall()
{
    if(y < 10000)//max y dist at 800
    { 
  //      y = y - yVelocity;
       // yVelocity--;
	//if(yVelocity <= -45)
	//{
	//    yVelocity = -45;
	//}
	checkBottom();
    }
    else
    {
	y = 799;
	//yVelocity = 0;
//	airbound = false;
//	yCollided = true;
    }
} //end fall

void Projectile::checkBottom()
{
//    if(yCollided)
//        //y = bottom - height;
//	airbound = false;
//	yVelocity = 0;
 //   } //end if
} //end checkBottom

void Projectile::move()
{
 //   if(xCollided == 0)
    {
 //       x = xNew;
    }
  //  else
  //  {
	if(right)
	{
	    right = false;
	    left = true;
	}
	else
	{
	    right = true;
	    left = false;
	}
  //  }
//    if(airbound)
//    {
	//fall();
   // } //end if

}

void Projectile::hit()
{
    cout << "Enemy OW!!" << endl;
}
