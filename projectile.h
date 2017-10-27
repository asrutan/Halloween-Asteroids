// projectile.h
// Alex Rutan
// 10/25/17

#ifndef PROJECTILE_EXIST
#define PROJECTILE_EXIST

#include "collideBox.h"
#include "entity.h"

class Projectile : public Entity
{
    private:
		int jumpStrength;
		//int dir;

    public:
        Projectile();
		Projectile(int direction);
        ~Projectile();
        virtual void tryMove();
		virtual void move();
        virtual void update();
		void fall();
		virtual void hit();
		void checkBottom();
		bool left;
		bool right;
		int frame; //animation frame TEST
		int tick; //for animation frame TEST
}; //end Projectile

#endif //PROJECTILE_EXISTS
