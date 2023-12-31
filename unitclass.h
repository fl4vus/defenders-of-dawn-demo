#include <iostream>
#include <string.h>
using namespace std;

#define GRID_SIZE 16

int masterArray[GRID_SIZE][GRID_SIZE][2];

int tarType, tarStrength, tarHP, tarPosX, tarPosY, tarArmour;
int ctrlType, ctrlStrength, ctrlPosX, ctrlPosY, ctrlAA, ctrlAT, ctrlDmg;


class Unit
{
	public:
		string unitName;
		int allegiance; // 1 is player-controlled, 2 is scripted
		int unitStrength;
		int armour;
		int unitType; // 1: infantry, 2: mech. inf. (AT), 3: mech. inf (AA), 4: light tank, 5: heavy tank, 6: atrillery, 7: aircraft, 8: SAM system
		int active;
		int arrayID;

// SETTERS

		void setAttr(int type, int flag, string name, int id)
		{	
			arrayID = id;
			allegiance = flag;
			unitType = type;
			unitName = name;
			active = 1;
			movePool = 2;
			switch (allegiance)
			{
				case 1:
					status = "In position";
					break;

				case 2:
					status = "Unknown";
					break;

				default:
					status = "Unknown";
					break;
			}

			switch (unitType)
			{
				case 1:
					unitStrength = 20;
					damageEffect = 4;
					armour =  1;
					hitPoints = 1;
					antiArmour = 1;
					antiAircraft = 1;
					mobility = 3;
					range = 1;
					break;
				
				case 2:
					unitStrength = 16;
					damageEffect = 8;
					armour =  4;
					hitPoints = 2;
					antiArmour = 7;
					antiAircraft = 1;
					mobility = 6;
					range = 1;
					break;
				
				case 3:
					unitStrength = 16;
					damageEffect = 4;
					armour =  4;
					hitPoints = 2;
					antiArmour = 2;
					antiAircraft = 7;
					mobility = 6;
					range = 1;
					break;

				case 4:
					unitStrength = 4;
					damageEffect = 12;
					armour =  7;
					hitPoints = 8;
					antiArmour = 6;
					antiAircraft = 0;
					mobility = 10;
					range = 4;
					break;

				case 5:
					unitStrength = 4;
					damageEffect = 20;
					armour =  9;
					hitPoints = 10;
					antiArmour = 9;
					antiAircraft = 0;
					mobility = 8;
					range = 6;
					break;
				
				case 6:
					unitStrength = 4;
					damageEffect = 24;
					armour =  5;
					hitPoints = 4;
					antiArmour = 9;
					antiAircraft = 0;
					mobility = 0;
					range = 8;
					break;

				case 7:
					unitStrength = 4;
					damageEffect = 16;
					armour =  2;
					hitPoints = 4;
					antiArmour = 6;
					antiAircraft = 6;
					mobility = 24;
					range = 16;
					break;

				case 8:
					unitStrength = 3;
					damageEffect = 4;
					armour =  1;
					hitPoints = 3;
					antiArmour = 2;
					antiAircraft = 8;
					mobility = 0;
					range = 8;
					break;
				
				default:
					unitStrength = 20;
					damageEffect = 4;
					armour =  1;
					hitPoints = 1;
					antiArmour = 1;
					antiAircraft = 1;
					mobility = 3;
					range = 1;
					break;

			}
		}
		
		void setPos(int x, int y)
		{
			if (((x < GRID_SIZE) && (x >= 0)) && ((y < GRID_SIZE) && (y >= 0)))
			{
				posY = y;
				posX = x;
				masterArray[x][y][0] = unitType;
				masterArray[x][y][1] = allegiance;
			}
		}

		void engage(int unitPosX, int unitPosY, int enemyPosX, int enemyPosY)
		{
			if (((unitPosX - enemyPosX)*(unitPosX - enemyPosX)  <= range*range) && ((unitPosY - enemyPosY)*(unitPosY - enemyPosY) <= range*range))
			{
				status = "Engaged";
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
				active = 0;
			}
		}

		int scanAround()
		{
			for (int i = posX - 2; i <= posX + 2; i++)
				{
					for(int j = posY - 2; posY <= posY + 2; j++)
					{
						if (masterArray[i][j][1] == 1)
						{	

							return 1;
						} else
						{
							return 0;
						}
					}
				}
		}

		int move(int x, int y)
		{
			if ((((posX - x)*(posX - x) + (posY -y)*(posY - y)) <= mobility*mobility) && movePool > 0)
			{	
				masterArray[posX][posY][0] = 0;
				masterArray[posX][posY][1] = 0;

				movePool--;
				return 1;
			} else
			{
				return 0;
			}
		}

		void resetMove()
		{
			movePool = 2;
		}

		void assignCtrl()
		{

		}

		void assignTar()
		{

		}

		void setTarAttr()
		{

		}

	private:

		int posX;
		int prevPosX;
		int posY;
		int prevPosY;
		string status;
		int movePool;

		int hitPoints;
		int antiArmour;
		int antiAircraft;
		int mobility;
		int range;
		int damageEffect;

};

class Infantry : public Unit
{
	public:
		int turns2entrench;
		bool entrenchment;
	
		void setAttr2(int t2ent, bool ent)
		{	
			if (unitType == 1 || unitType == 2 || unitType ==3)
			{
				turns2entrench = t2ent;
				entrenchment = ent;
			}
		}

		void entrench()
		{	
			if (turns2entrench > 0)
			{
				if (entrenchment == 1)
				{
					armour = armour + 2;
				}
			}
		}	
};

//Unit *userArray[];
//Unit *scriptArray[];

