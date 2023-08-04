#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "unitclass.h"

using namespace std;


void initMasterArray()
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                masterArray[i][j][k] = 0;
            }
        }
    }
}


int main()
{
    //int superArray[16][16][2];      // x, y, {unitType, allegiance, status}
    initMasterArray();

    int runStat = 1;

    Infantry userInf1;
	Infantry userInf2;
	Infantry userInf3;
	Infantry userInf4;
    Infantry userMI1;
    Infantry userMI2;
	Infantry scptInf1;
	Infantry scptInf2;
	Infantry scptInf3;
    Infantry scptMI1;
    Infantry scptMI2;
    Infantry scptMI3;

	Unit userHvyTnk1;
	Unit scptHvyTnk1;
	Unit scptHvyTnk2;

	Unit userLgtTnk1;
	Unit scptLgtTnk1;
	Unit scptLgtTnk2;

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

    userInf1.setAttr(1,1,"Alpha Coy. 1st Plt.");
    userInf1.setPos(12,8);
    // cout << "\nunit: " << masterArray[12][8][0] << "\nFlag: " << masterArray[12][8][1] << endl;
    userInf2.setAttr(1,1,"Alpha Coy. 2nd Plt.");
    userInf2.setPos(9,10);
    userInf3.setAttr(1,1,"Delta Coy. 1st Plt.");
    userInf3.setPos(6,13);
    userInf4.setAttr(1,1,"Delta Coy. 2nd Plt.");
    userInf4.setPos(10,1);
    userMI1.setAttr(2,1,"3rd Mech. Rifles Btn.");
    userMI1.setPos(9,9);
    userMI2.setAttr(3,1,"66th Air Defence Btn.");
    userMI2.setPos(10,4);

    scptInf1.setAttr(1,2,"Shark Brig. 1st Det.");
    scptInf1.setPos(0,1);
    scptInf2.setAttr(1,2,"Shark Brig. 2nd Det.");
    scptInf2.setPos(0,2);
    scptInf3.setAttr(1,2,"Eagle Brig. 4th Det.");
    scptInf3.setPos(0,10);
    scptMI1.setAttr(2,2,"1st Dragon Det.");
    scptMI1.setPos(1,1);
    scptMI2.setAttr(2,2,"2nd Dragon Det");
    scptMI2.setPos(1,10);

    int gridSize = GRID_SIZE + 1;
    int it = 0;
    
    while (runStat == 1)
    {   
        system("clear");
        it = it + 1;
        int arr[32][32];
        for (int k = 0; k < gridSize - 1; k++) 
        {
            printf(" --------");
        }
        printf("\n");
        for (int i = 0; i < gridSize - 1; i++) 
        {
            for (int l = 0; l < 3; l++)
            {
                for (int j = 0; j < gridSize; j++) 
                {
                    
                    if (j == gridSize - 1) 
                    {
                        printf("|\n");
                    } else 
                    {
                        switch(l)
                        {
                            case 0:
                                printf("|   %2d,%2d",j, i);
                                break;

                            case 1:
                                if (masterArray[j][i][0] != 0)
                                {
                                    switch (masterArray[j][i][0])
                                        {
                                            case 1:
                                                cout << "|INF.    ";
                                                break;
                                            case 2:
                                                cout << "|M.INF-AT";
                                                break;
                                            case 3:
                                                cout << "|M.INF-AA";
                                                break;
                                            case 4:
                                                cout << "|L.TANK  ";
                                                break;
                                            case 5:
                                                cout << "|H.TANK  ";
                                                break;
                                            case 6:
                                                cout << "|ART.    ";
                                                break;
                                            case 7:
                                                cout << "|AIRCRAFT";
                                                break;
                                            case 8:
                                                cout << "|SAMs    ";
                                                break;
                                            default:
                                                cout << "|Unknown ";
                                                break;
                                        }
                                } else
                                {
                                    printf("|        ");
                                }
                                break;

                            case 2:
                                if (masterArray[j][i][1] != 0)
                                {
                                    if (masterArray[j][i][1] == 1)
                                    {
                                        printf("|\033[1;32m PLAYER \033[1;0m");
                                    } else
                                    {
                                        printf("|\033[1;31m SCRIPT \033[1;0m");
                                    }

                                } else
                                {
                                    printf("|        ");
                                }
                                break;
                            
                            default:
                                printf("|        ");
                                break;
                        }
                    }
                }
            }

            for (int k = 0; k < gridSize - 1; k++) 
            {
                printf(" --------");
            }
            printf("\n");
        }
        cout << "\n" << it << ": run again? enter 1 to run again, enter 0 to stop\n";
        cin >> runStat;
    }

    return 0;
}