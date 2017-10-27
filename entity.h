// entity.h
// Alex Rutan
// 1/3/16

#ifndef ENTITY_EXIST
#define ENTITY_EXIST

class Entity
{
    protected:
		int speed = 0;
		int speedCap = 10;
		double spriteX;
		double spriteY;
		double newX = 0;
		double newY = 0;
		double xVelocity = 0;
		double yVelocity = 0;
		bool dead = false;
		bool dying = false;
		bool dir[5];
		int entityID; //TYPE OF ENTITY (Player, Enemy, etc.)
		int uniqueID; //IDENTIFIER IN CURRENT SESSION
		int listID; //CURRENT SPOT IN ENTITY LIST
		double friction = 1;
		double acceleration = 1;
		double degree = 45;
		bool thrust;

    public:
        Entity();
        ~Entity();
        virtual void update();
		double x; // CHANGE THESE VALUES BACK TO PRIVATE
		double y; // THIS IS JUST TO TEST MOVING THE SPRITE IN Game!!!
		int height;
		int width;
		//void mover(int);
		//void move();
		//string sprite;
		void setListID(int id);
		int getListID();
		int getEntityID();
		bool getIsDead();
		void kill();
		bool collided[3];
		bool floorHit = false;
		bool wallHit = false;
		bool collideSide[4]; //1=right 2=left 3=top 4=bottom
		void setXY(double, double);
		void setNewXY(double, double);
		double getX();
		double getY();
		double getXVelocity();
		double getYVelocity();
		void setXVelocity(double);
		void setYVelocity(double);
		bool getDir(int);
		double getFriction();
		int getSpeed();
		double getAcceleration();
		double getDegree();
		int getSpeedCap();
		void setDegree(double);
		virtual void setThrust(bool);
		bool getThrust();

}; //end Entity

#endif //ENTITY_EXISTS
