#include <iostream>
#include <string.h>
#include "unitsdef.h"

/*
class Unit
{
	public:
		string unitName;
		bool allegiance; // 1 is player-controlled, 0 is scripted
		int unitStrength;
		int armour;
		int hitPoints;
		int antiArmour;
		int antiAircraft;
		int mobility;
		int range;
		int damageEffect;
		string unitType; 

// SETTERS

		void setAttr(string type, bool flag, string name, int strength, int armr, int hp, int at, int aa, int mob, int rng, int dmg)
		{
			allegiance = flag;
			unitType = type;
			unitName = name;
			unitStrength = strength;
			armour = armr;
			hitPoints = hp;
			antiArmour = at;
			antiAircraft = aa;
			range = rng;
			damageEffect = dmg;
			mobility = mob;
			
			if (allegiance == 1)
			{
				status = "In Position";
			}
			
			if (allegiance == 0)
			{
				status = "Unknown";
			}
		}
		
		void setPos(int x, int y)
		{
			if (((x < 64) && (x >= 0)) && ((y < 64) && (y >= 0)))
			{
				posY = y;
				posX = x;
			}
		}

//GETTERS

		int getPosX()
		{
			return posX;
		}
		
		int getPosY()
		{
			return posY;
		}

		string getStatus()
		{
			return status;
		}		

		void engage(int unitPosX, int unitPosY, int enemyPosX, int enemyPosY)
		{
			if (((unitPosX - enemyPosX)*(unitPosX - enemyPosX)  <= range*range) && ((unitPosY - enemyPosY)*(unitPosY - enemyPosY) <= range*range))
			{
				status = "Engaged";
			}
		}

// METHODS

		void retreatCheck(int casualties)
		{
			if (casualties >= unitStrength/2)
			{
				status = "Retreating";
			}

			if (unitStrength <= 0)
			{
				status = "Eliminated";
			}
		}

		// for movement of infantry, manually add code at end of move() to set entrenchment variable to 0
		int move(int a, char dir) // dir is direction of movement, dir = 'x' along x axis, 'y' along y axis 
		{
			if ((a <= movePool) && (dir == 'x'))
			{	
				prevPosX = posX;
				posX = posX + a;
				movePool = movePool - a;
				return 1;
			} 
			if ((a <= movePool) && (dir == 'y'))
			{	
				prevPosY = posY;
				posY = posY + a;
				movePool = movePool - a;
				return 1;
			}
			if ((a <= movePool) && (dir == 'Y'))
			{	
				prevPosY = posY;
				posY = posY + a;
				movePool = movePool + a;
				return 1;
			}
			if ((a <= movePool) && (dir == 'X'))
			{	
				prevPosX = posX;
				posX = posX + a;
				movePool = movePool + a;
				return 1;
			}
			else 
			{
				return 0;
			}
		}

		void resetMove()
		{
			movePool = mobility;
		}

	private:
		int posX;
		int prevPosX;
		int posY;
		int prevPosY;
		string status;
		int movePool;
};

class Infantry : public Unit
{
	public:
		int turns2entrench;
		bool entrenchment;
		int entMobility;
	
		void setAttr2(int t2ent, bool ent, int entMob)
		{
			turns2entrench = t2ent;
			entMobility = entMob;
			entrenchment = ent;
		}

		void entrench()
		{
			if (entrenchment == 1)
			{
				mobility = entMobility;
			}
		}	
};

class MechInf : public Infantry
{
	public: 
		bool spec; // 1 for anti-armour, 0 for anti-aircraft 
		
		void setAttr2(int t2ent, bool ent, int entMob, bool sp)
		{
			turns2entrench = t2ent;
			entMobility = entMob;
			entrenchment = ent;
			spec = sp;
		}
};

/*
class Paratroopers : public Infantry
{
	public:
		bool deployed;
		int deploymentMobility;
		
		void setAttr2(int t2ent, bool ent, int entMob, bool dped)
		{
			turns2entrench = t2ent;
			entMobility = entMob;
			entrenchment = ent;
			deployed = dped;
		}

		void deploy()
		{
			if (entrenchment == 1)
			{
				mobility = entMobility;
			}
		}
};
*/

/*
class Tanks : public Units
{
	public:
		bool identifier; // identifier = 1 for tanks, 0 for planes
};

class Aircraft : public Units
{
	public:
		bool identifier;
};
*/
			
// DEFINING GLOBAL OBJECTS

int main ()
{
	Infantry userInf1;
	Infantry userInf2;
	Infantry userInf3;
	Infantry userInf4;
	Infantry scptInf1;
	Infantry scptInf2;
	Infantry scptInf3;

	Unit userHvyTnk1;
	Unit scptHvyTnk1;
	Unit scptHvyTnk2;

	Unit userLgtTnk1;
	Unit userLgtTnk2;
	Unit scptLgtTnk1;
	Unit scptLgtTnk2;
	Unit scptLgtTnk3;

	Unit userArt1;
	Unit userArt2;

	Unit userSAM1;
	Unit userSAM2;
	Unit userSAM3;
	Unit userSAM4;
	Unit scptSAM1;
	Unit scptSAM2;

	Unit userAir1;
	Unit userAir2;
	Unit scptAir1;
	Unit scptAir2;

	userInf1.setAttr("Light Infantry", 1, "Alpha Coy. 1st Plt", 24, 1, 1, 1, 1, 5, 1, 4);
	userInf1.setAttr2(2, 0, 1);

	userInf2.setAttr("Light Infantry", 1, "Alpha Coy. 2nd Plt", 24, 1, 1, 1, 1, 5, 1, 4);
	userInf2.setAttr2(2, 0, 1);

	userInf3.setAttr("Light Infantry", 1, "Delta Coy. 1st Plt", 24, 1, 1, 1, 1, 5, 1, 4);
	userInf3.setAttr2(2, 0, 1);

	userInf4.setAttr("Light Infantry", 1, "Delta Coy. 2nd Plt", 24, 1, 1, 1, 1, 5, 1, 4);
	userInf4.setAttr2(2, 0, 1);

	scptInf1.setAttr("Marine Infantry", 0, "Eagle Brig. 1st Det.", 24, 1, 1, 1, 1, 5, 1, 4);
	scptInf1.setAttr2(2, 0, 1);

	scptInf2.setAttr("Marine Infantry", 0, "Eagle Brig. 2nd Det.", 24, 1, 1, 1, 1, 5, 1, 4);
	scptInf2.setAttr2(2, 0, 1);

	scptInf3.setAttr("Marine Infantry", 0, "Shark Brig. 3rd Det.", 24, 1, 1, 1, 1, 5, 1, 4);
	scptInf3.setAttr2(2, 0, 1);

	printf("%d", userInf1.unitStrength);
	return 0;
}
