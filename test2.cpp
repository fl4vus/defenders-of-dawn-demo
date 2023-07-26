#include <iostream>
#include <string.h> 
#include "functions.h"

int main()
{   
    int armr1, hp1, num1;
    int antiArmr2, dmg2;

    armr1 = 9;
    hp1 = 5;
    num1 = 3;

    antiArmr2 = 6;
    dmg2 = 8;

    //cout << checkHit(armr1, antiArmr2) << "\n";
    switch(checkHit(armr1, antiArmr2))
    {
        case 1:
            cout << "\nEnemy suffered " << poolDmgHP(&num1, 5, 8) << " casualties!" << endl;
            break;

        case 0:
            cout << "\nAttack Repulsed!" << endl;
            break;
        
        default:
            cout << "\nAttack Repulsed!" << endl;
            break;
    }

    cout << num1 << endl; 

    return 0;
}