#ifndef ATTRIBUTES_PRIMARY_H_INCLUDED
#define ATTRIBUTES_PRIMARY_H_INCLUDED

#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <iostream>
#include <map>
#include <math.h>
#include <string>

void setPrimaryAtts()
{
    using namespace  std;

    map <string, int> primaryAtts;

    primaryAtts["STR"]=0;
    primaryAtts["DEX"]=0;
    primaryAtts["CON"]=0;
    primaryAtts["CHR"]=0;
    primaryAtts["INT"]=0;
    primaryAtts["WIS"]=0;

    int attIndex = 6;
    int minSeedValue = 80;
    int maxSeedValue = 90;
    int minAttVariance = 80;
    int maxAttVariance = 120;

    srand(time(0));

    int primaryAttSeed = rand() % (maxSeedValue - minSeedValue) + minSeedValue;
    cout << "inital attribute seed = " << primaryAttSeed << endl;

    int pointsTotal = primaryAttSeed * attIndex;
    int pointsRemaining = pointsTotal;

    map <string, int>::iterator it;
    int i = attIndex;
    for ( it = primaryAtts.begin(); it != primaryAtts.end(); ++it )
    {
        cout << it->first << endl;
        int attSeed = pointsRemaining / i;
        float attVariance = rand() % (maxAttVariance - minAttVariance) + minAttVariance;
        it->second = round(attSeed * attVariance / 100);
        cout << it->second << "\nattribute seed: " << attSeed << ", variant: " << attVariance << endl;
        pointsRemaining = pointsRemaining - it->second;
    }
/*
    {
        if (aAttValues[i] < attFloor)
            attFloor = aAttValues[i];
        else if (aAttValues[i] > attCeiling)
            attCeiling = aAttValues[i];
        cout << aAttNames[i] << "=" << aAttValues[i] << endl;
        attFile << aAttNames[i] << "=" << aAttValues[i] << endl;
    }


  */


}

#endif // ATTRIBUTES_PRIMARY_H_INCLUDED
