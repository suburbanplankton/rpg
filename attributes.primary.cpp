#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <iostream>
#include <map>
#include <string>
//#include "attributes.primary.h"


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

    int minAttValue = 80;
    int maxAttValue = 90;
    int minAttVariance = 80;
    int maxAttVariance = 120;

    srand(time(0));

    int primaryAttSeed = rand() %(maxAttValue - minAttValue) + minAttValue;
    cout << "inital attribute seed = " << primaryAttSeed << endl;


}
