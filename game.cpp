// game.cpp
// Alex Rutan
// 4/1/15
#include <iostream>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <ctime>

#include "game.h"

using namespace std;

/*
Game constructor 
defines the values used for the resolution of the screen
initializes values used by SDL for renderer, window, and textures
 */
Game::Game()
{
	Entity *entlist = new Entity[255];
	//entlist = new Entity[255];
	entcount = 0;
    //cout << "Game constructed" << endl;
	srand(time(NULL));
	quit = false;

} //end constructor

Game::~Game()
{
	delete[] *entlist;
} //end destructor

bool Game::loadTextures()
{  
    return true;
} //end loadTextures

//Spawn an entity, first int is the type of entity, modifier for subtype.
int Game::spawn(int entid, int mod)
{
	if (entid == 0)
		{ 
			entlist[entcount] = new Player();
			entlist[entcount]->setListID(entcount);
			entcount++;

			return 0;
		}
	else if (entid == 1 && mod == 1)
	{
		entlist[entcount] = new Enemy(mod);
		entlist[entcount]->setListID(entcount);
		entlist[entcount]->setXY(mousex, mousey);
		entcount++;
		return 0;
	}
	else if (entid == 1 && mod == 2)
	{
		entlist[entcount] = new Enemy(mod);
		entlist[entcount]->setListID(entcount);
		entlist[entcount]->setXY(mousex, mousey);
		entcount++;
		return 0;
	}
	else if (entid == 1 && mod == 3) //spawn at random location
	{
		entlist[entcount] = new Enemy(mod);
		entlist[entcount]->setListID(entcount);
		int randx = rand() % 800 + 1;
		int randy = rand() % 600+1;
		entlist[entcount]->setXY(randx, randy);
		entlist[entcount]->setDegree(rand() % 359 + 1);
		entcount++;
		return 0;
	}
	else if (entid == 2)
	{
		entlist[entcount] = new Projectile(mod);
		entlist[entcount]->setListID(entcount);
		entlist[entcount]->setXY(mousex, mousey);
		entcount++;
		return 0;
	}
	else { cout << "can't spawn entity" << endl; return 0; }
} //end spawn

int Game::spawn(int entid, int mod, Entity *entity)
{
	if (entid == 2)
	{
		entlist[entcount] = new Projectile(mod);
		entlist[entcount]->setListID(entcount);
		entlist[entcount]->setXY(entity->getX(), entity->getY());
		entlist[entcount]->setDegree(entity->getDegree());
		entcount++;
		return 0;
	}
	else { cout << "can't spawn entity" << endl; return 0; }
} //end spawn

int Game::despawn(Entity* entity)
{
	if (entcount < 1) { cout << "nothing to despawn" << endl;  return 0; }

	int old = entity->getListID();
	int right = entcount - old;

	if (old < entcount)
	{
		delete entity;
		entity = NULL;
		for (int i = old; i < entcount-1; i++)
		{
			entlist[i] = entlist[i+1];
			entlist[i]->setListID(i);
		}
		entcount--;
		return 0;
	}
	else if(entity->getListID() == entcount)
	{
		delete entity;
		entity = NULL;
		entcount--;
		return 0;
	}
	else { cout << "can't despawn entity" << endl; return 0; }
} //end spawn

/*
First, take each of the textures and assign them to their own specific rectangles to be drawn later
Create and instance of map, map is loaded when it is constructed
Pass the map information on to player and the setEnemyMap via pointer
Create an instance of camera and send it values for number of rays and player's initial position
Create an instance of SDL_Event for player input, events change bools to "true"
 */
int Game::run()
{
    if (!display.init())
    {
		cout << "Coudn't initialize" << endl;
    } //end if
	else
	{
		bool create = true;

		World *world = new World;
		world->define();

		display.loadTextures("ghost.bmp", 0);
		display.loadTextures("jack.bmp", 1);
		display.loadTextures("blocks.bmp", 2);

		spawn(0, 0);
		for (int i = 0; i < 5; i++)
		{
			spawn(1, 3);
		}


        bool keepGoing = true;
        while(keepGoing)
		{
			input.keyEvents();
			input.getMousePos(); //redo this
			mousex = input.mousex;
			mousey = input.mousey;

			if (input.getMouseClick())
			{
				cout << "click" << endl;
				if (mousex > 700 && mousex < 750 && mousey > 500 && mousey < 550)
				{
					if(create)
					{
						create = false;
					}
					else create = true;
					//entlist[0]->kill();
				}
				else 
				{
					if (create)
					{
						//test
						spawn(2, 1, entlist[0]);
					}
				}
			} //end if

			if (input.getKeys(0))
			{
				for (int i = 0; i < entcount; i++) 
				{
					if (i != 0)
					{
						entlist[i]->setDegree(1);
					}
				}
			}
			if (input.getKeys(1))
			{
				for (int i = 0; i < entcount; i++)
				{
					if (i != 0)
					{
						entlist[i]->setDegree(-1);
					}
				}
			}

			if (input.getKeys(2)) //Space bar
			{
				entlist[0]->setThrust(true);
				
			}
			if (entlist[0]->getThrust())
			{
				if (!input.getKeys(2))
				{
					entlist[0]->setThrust(false);
				}
			}

			double rise = mousey - entlist[0]->getY();
			double run = mousex - entlist[0]->getX();
			double deg = atan2f(rise, run);
			entlist[0]->setDegree(deg);

			if (quit)
			{
				keepGoing = false;
			} //end if

			
			display.update(); // background and clear		  
			/**************/
			movement.move(entlist[0], entlist[0]->getDegree()); //move, checkbounds, update

			 //skeleton
			collision.checkBounds(entlist[0], world->horizonts[0]);
			//collision.checkBounds(entlist[0], world->verts[0]);
			//collision.checkBounds(entlist[0], world->verts[1]);

			//skeleton

			display.draw(world);

			for (int i = 0; i < entcount; i++)
			{
				//Original move using up, down, left, right
				//if (i != 0)movement.move(entlist[i]);
			
				//New move using degrees for direction of movement
				if (i != 0)movement.move(entlist[i], entlist[i]->getDegree());

				//Test collision with world
				//collision.checkBounds(entlist[i], world->verts[0]);
				//collision.checkBounds(entlist[i], world->verts[1]);

				//Collision with each int
				for (int j = 0; j < entcount; j++)
				{
					if (j != 0)
					{
						collision.checkBounds(entlist[i], entlist[j]);
					}
				}


				if (i != 0)collision.checkBounds(entlist[0], entlist[i]);
				if (i != 0 && !create)collision.checkBounds(entlist[i], mousex, mousey);
				entlist[i]->update(); //if collide, do not update to newX/newY
				display.draw(entlist[i]);
				if (entlist[i]->getIsDead())despawn(entlist[i]);
			} //update entities
			  /**************/
			//display.print("Test Text!");
			display.render(); //draw to screen

	    // end updates
		} //end while 
    } //end else 
    display.close();
    return (0);
}//end run
