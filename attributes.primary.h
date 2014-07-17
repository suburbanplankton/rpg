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

    primaryAtts["CHR"]=0;
    primaryAtts["CON"]=0;
    primaryAtts["DEX"]=0;
    primaryAtts["INT"]=0;
    primaryAtts["STR"]=0;
    primaryAtts["WIS"]=0;

    int primaryAttIndex = 6;
    int minAttSeed = 80;
    int maxAttSeed = 90;
    int minAttVariance = 80;
    int maxAttVariance = 120;
    int minHeightSeed = 60;
    int maxHeightSeed = 140;
    int raceHeightModifier = 1;
    int attFloor = 200;
    int attCeiling = 0;

    srand(time(0));

    int primaryAttSeed = rand() % (maxAttSeed - minAttSeed) + minAttSeed;
    cout << "inital attribute seed = " << primaryAttSeed << "\n" << endl;

    int pointsTotal = primaryAttSeed * primaryAttIndex;
    int pointsRemaining = pointsTotal;

    map <string, int>::iterator it;
    int i = primaryAttIndex;
    for ( it = primaryAtts.begin(); it != primaryAtts.end(); ++it )
    {
        cout << "points remaining: " << pointsRemaining << endl;
        cout << it->first << "=";
        int attSeed = pointsRemaining / i;
        float attVariance = rand() % (maxAttVariance - minAttVariance) + minAttVariance;
        it->second = round(attSeed * attVariance / 100);
        cout << it->second << " (attribute seed: " << attSeed << ", variant: " << attVariance << ")" << endl;
        pointsRemaining = pointsRemaining - it->second;
        if ( it->second < attFloor)
            attFloor = it->second;
        if ( it->second > attCeiling)
            attCeiling = it->second;
        i--;
    }
    int heightSeed = (rand() % (maxHeightSeed - minHeightSeed) + minHeightSeed);
    primaryAtts["HT"] = heightSeed * raceHeightModifier;
    cout << "HT=" << primaryAtts["HT"] <<  " (height seed: " << heightSeed << ", race modifier: " << raceHeightModifier << ")" << endl;
    cout << "\nattribute floor: " << attFloor << "\nattribute ceiling: " << attCeiling << endl;
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
