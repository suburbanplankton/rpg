#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <math.h>

using namespace std;

int main()
{

// Initial seed value between 80 and 90
srand(time(0));
int initialSeed = rand() %10 + 80;
// Total of 6 attributes to calculate
int pointsTotal = initialSeed * 6;
int attIndex = 6;
int pointsRemaining = pointsTotal;
float variant = 100.0;
int attSeed = 0;
/*
attFile=$PWD/Char.attributes.primary
cat /dev/null > $attFile
*/

int attFloor=200;
int attCeiling=0;
//echo

/*
# potential stats
# endurance, education, social standing
# agility, alertness, vitality, willpower
# quickness
# power, finesse, resistance
# luck
# magic
*/

string aAttNames[7] = {"HT", "WIS", "INT", "CHA", "CON", "DEX", "STR"};
int aAttValues[7] = {0, 0, 0, 0, 0, 0, 0};

//for attribute in STR DEX CON CHA INT WIS; do
for ( int i=attIndex; i>0; i--)
{
    attSeed = pointsRemaining / i  ;            // Attribute seed recalculated for each attribute
    variant = rand() % 40 + 80      ;                // Each attribute set to 80-120% of seed value
    aAttValues[i] = round(attSeed * variant / 100);
    cout << aAttNames[i] << ": attribute seed: " << attSeed << ", variant: " << variant << endl;
    pointsRemaining = pointsRemaining - aAttValues[i];

    if (aAttValues[i] < attFloor)
        attFloor = aAttValues[i];
    else if (aAttValues[i] > attCeiling)
        attCeiling = aAttValues[i];
     cout << aAttNames[i] << "=" << aAttValues[i] << endl;
}
aAttValues[0]= round(rand() %40 + 80);
cout << "HT=" << aAttValues[0] << endl;

/*
#WT=$HT                                                     # Weight directly proportionate to Height
#WT=$(echo "$WT*${atts[5]}/85"|bc)                          # weight directly proportionate to Strength
#WT=$(echo "$WT*85/${atts[4]}"|bc)                          # weight inversely proportionate to Dexterity
#WT=$(echo "$HT*${atts[5]}/${atts[4]}"|bc)
#echo "WT=$WT" >> $attFile
*/

cout << "\ninitial seed: " << initialSeed << ", total points: " << pointsTotal << endl;
cout << "floor=" << attFloor << ", ceiling=" << attCeiling<< endl;
//cat $attFile
/*
# MAX value for any attribute = 147
# MIN value for any attribute = 44
*/
}
