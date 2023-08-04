#include <iostream>
#include <string.h> 
#include <time.h>
using namespace std;

float rando()
{  
    srand( (unsigned)time( NULL ) );
    float bro;
    bro = (float) rand()/RAND_MAX;
    cout <<"random = "<< bro << endl;
    return bro;
}

float poolArmr(int armr, int antiArmr, int antiAir, int tarType)
{   
    float prob;
    if (tarType != 7)
    {
        if (armr >= antiArmr)
        {
            prob = (10.0 - ((float)armr - (float)antiArmr))/10.0;
            cout << "probility of hit = "<< prob << endl;
        }
        if (armr < antiArmr)
        {
            prob = 1.000;
        }
    }
    
    if (tarType == 7)
    {   
        cout << "\nSwitching to Anti-Air Mode" << endl;
        float prob0 = (float)antiAir/10.000;
        cout << "anti-air capability = " << prob0 << endl;
        if (armr >= antiArmr)
        {
            prob = prob0*((10.0 - ((float)armr - (float)antiArmr))/10.0);
            cout << "probility of hit = "<< prob << endl;
        }
        if (armr < antiArmr)
        {
            prob = 1.000 * prob0;
            cout << "probility of hit = "<< prob << endl;
        }

    }
    return prob;
}

int checkHit(int armr, int antiArmr, int antiAir, int tarType)
{
    float random = rando();
    float armrCoeff = poolArmr(armr, antiArmr, antiAir, tarType);
    int ok;
    if (random <= armrCoeff)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int poolDmgHP(int *defendNo, int defHP, int attDmg) //to be called only when return from checkHit is 0
{   
    int buffer = *defendNo;
    int totalDamage = (*defendNo * defHP) - attDmg;
    *defendNo = totalDamage / defHP;
    int casualties = buffer - *defendNo;
    return casualties;
}
