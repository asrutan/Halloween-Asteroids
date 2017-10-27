//movement.h
//Alex Rutan
//11/21/15

#ifndef MOVEMENT_EXIST
#define MOVEMENT_EXIST

#include "entity.h"

class Movement
{
    private:  
		double x;
		double y;
		double xVelocity;
		double yVelocity;
		double friction;
		int speed;
		int angle;
		double acceleration;
		double degree;

    public:
        Movement();
        ~Movement();
		void move(Entity*);
		void move(Entity*, double);
        
}; //end Movement

#endif //MOVEMENT_EXISTS
