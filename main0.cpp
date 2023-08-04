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
	Unit scptSAM1;
	Unit scptSAM2;

	Unit userAir1;
	Unit userAir2;
	Unit scptAir1;
	Unit scptAir2;

    Unit *ctrlUnit;
    Unit *tarUnit;
    
    Unit *userArray[16] = {&userInf1, &userInf2, &userInf3, &userInf4, &userMI1, &userMI2, &userArt1, &userArt2, &userLgtTnk1, &userHvyTnk1, &userAir1, &userAir2, &userSAM1, &userSAM2};
    Unit *scriptArray[14] = {&scptInf1, &scptInf2, &scptInf3, &scptMI1, &scptMI2, &scptMI3, &scptLgtTnk1, &scptLgtTnk2, &scptHvyTnk1, &scptHvyTnk2, &scptAir1, &scptAir2, &scptSAM1, &scptSAM2};

    userInf1.setAttr(1,1,"Alpha Coy. 1st Plt.",1);
    userArray[0] = &userInf1;
    userInf1.setPos(12,8);
    // cout << "\nunit: " << masterArray[12][8][0] << "\nFlag: " << masterArray[12][8][1] << endl;
    userInf2.setAttr(1,1,"Alpha Coy. 2nd Plt.",2);
    userInf2.setPos(9,10);
    userInf3.setAttr(1,1,"Delta Coy. 1st Plt.",3);
    userInf3.setPos(6,13);
    userInf4.setAttr(1,1,"Delta Coy. 2nd Plt.",4);
    userInf4.setPos(10,1);
    userMI1.setAttr(2,1,"3rd Mech. Rifles Btn.",5);
    userMI1.setPos(9,9);
    userMI2.setAttr(3,1,"66th Air Defence Btn.",6);
    userMI2.setPos(10,4);
    userArt1.setAttr(6,1,"Northern Artillery Rgmt.",7);
    userArt1.setPos(10,6);
    userArt2.setAttr(6,1,"5th Seperate Artillery Rgmt.",8);
    userArt2.setPos(10,13);
    userLgtTnk1.setAttr(4,1,"4th Light Cavalry",9);
    userLgtTnk1.setPos(6,12);
    userHvyTnk1.setAttr(5,1,"Northern Armoured Btn.",10);
    userHvyTnk1.setPos(10,13);
    userAir1.setAttr(7,1,"190 Wildcat Sqn.",11);
    userAir1.setPos(14,13);
    userAir2.setAttr(7,1,"109 Cerberus Sqn.",12);
    userAir2.setPos(13,13);
    userSAM1.setAttr(8,1,"66th Air Defence Battery 1",13);
    userSAM1.setPos(15,14);
    userSAM2.setAttr(8,1,"66th Air Defence Battery 2",14);
    userSAM2.setPos(12,11);
    //int dubski = userArray[0]->unitStrength;
    //cout << dubski << " ayoooo"<< endl;
    
    scptInf1.setAttr(1,2,"Shark Brig. 1st Det.",7);
    scptInf1.setPos(0,1);
    scptInf2.setAttr(1,2,"Shark Brig. 2nd Det.",8);
    scptInf2.setPos(0,2);
    scptInf3.setAttr(1,2,"Eagle Brig. 4th Det.",9);
    scptInf3.setPos(0,10);
    scptMI1.setAttr(2,2,"1st Dragon Det.",10);
    scptMI1.setPos(1,1);
    scptMI2.setAttr(2,2,"2nd Dragon Det",11);
    scptMI2.setPos(1,10);

    int gridSize = GRID_SIZE + 1;
    int turn = 0;
    
    while (runStat == 1)
    {   

        turn = turn + 1;
        //int arr[32][32];
        int selectUnit = 0;
        int selectAction = 0;
        int selectTarget = 0;

        drawmap:
        system("clear");

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
        /*cout << "\n" << it << ": run again? enter 1 to run again, enter 0 to stop\n";
        cin >> runStat;*/
        cout << "\nTurn: "<< turn << endl;
        if (selectUnit == 0)
        {
            cout << "Select Unit:" << endl;
            for (int i = 0; i < 14; i++)
            {
                printf("\033[1;32m%d. %s \033[1;0m(%d, %d)\n", userArray[i]->arrayID, userArray[i]->unitName.c_str(), userArray[i]->getPosX(), userArray[i]->getPosY());
            }
            cout << "\n(input no. next to item)" << endl;
            cin >> selectUnit;
            if (selectUnit < 15 && selectUnit > 0)
            {
                ctrlUnit = userArray[selectUnit - 1];
                goto drawmap;
            } else
            {
                cout << "\nInvalid input!"<< endl;
                selectUnit = 0;
                goto drawmap;
            }
        } else 
        {
            if (selectAction == 0)
            {   
                printf("Selected Unit: \033[1;32m%s \033[1;0m\n\n", ctrlUnit->unitName.c_str());
                cout << "Select Action: " << endl;
                cout << "1. Move\n2. Engage\n3. Change Unit" << endl;
                cout << "\n(input no. next to item)" << endl;
                cin >> selectAction;
                
                switch (selectAction)
                {
                    case 1:
                        int Xer, Yer;

                        cout << "\nEnter new X co-ordinate: ";
                        cin >> Xer;
                        cout << "\nEnter new Y co-ordinate: ";
                        cin >> Yer;
                        if (ctrlUnit->move(Xer, Yer) == 1)
                        {
                            ctrlUnit->setPos(Xer, Yer);
                        } else
                        {
                            cout << "\nInvalid Move!";
                        }
                        goto drawmap;
                        break;
                    case 2:
                        goto drawmap;
                        break;
                    case 3:
                        selectAction = 0;
                        selectUnit = 0;
                        goto drawmap;
                        break;
                    default:
                        cout << "\nInvalid input!" << endl;
                        selectAction = 0;
                        goto drawmap;
                        break;
                }
            }
        }
    }

    return 0;
}