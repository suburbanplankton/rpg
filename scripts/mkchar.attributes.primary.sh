#!/bin/bash

# must have bc package

initialSeed=$((80+RANDOM%10))                              # Initial seed value between 80 and 90
pointsTotal=$((initialSeed*6))                             # Total of 6 attributes to calculate
pointsUsed=0
attIndex=6
pointsRemaining=$pointsTotal

attFile=$PWD/Char.attributes.primary
cat /dev/null > $attFile

attFloor=200
attCeiling=0
echo

# potential stats
# endurance, education, social standing
# agility, alertness, vitality, willpower
# quickness
# power, finesse, resistance
# luck
# magic
#
#
#
#
#
#
#
#

for attribute in STR DEX CON CHA INT WIS; do
    attSeed=$(($pointsRemaining/$attIndex))                # Attribute seed recalculated for each attribute
    variant=$((80+RANDOM%40))                              # Each attribute set to +/- 20% of seed value
    attVal=$(( ($attSeed*$variant)/100 ))
echo "$attribute - attribute seed: $attSeed, variant: $(($variant-100))%"
    pointsRemaining=$(($pointsRemaining-$attVal))
    attIndex=$(($attIndex-1))
    pointsUsed=$(($pointsUsed+$attVal))

    if [ "$attVal" -lt "$attFloor" ]; then
        attFloor=$attVal
    fi
    if [ "$attVal" -gt "$attCeiling" ]; then
        attCeiling=$attVal
    fi
    echo "$attribute=$attVal" >> $attFile
    atts[$attIndex]=$attVal
done

HT=$((80+RANDOM%40))
echo "HT=$HT" >> $attFile

#WT=$HT                                                     # Weight directly proportionate to Height
#WT=$(echo "$WT*${atts[5]}/85"|bc)                          # weight directly proportionate to Strength
#WT=$(echo "$WT*85/${atts[4]}"|bc)                          # weight inversely proportionate to Dexterity
#WT=$(echo "$HT*${atts[5]}/${atts[4]}"|bc)
#echo "WT=$WT" >> $attFile

echo
echo "initial seed: $initialSeed, total points: $pointsTotal"
echo "floor=$attFloor, ceiling=$attCeiling"
echo
cat $attFile

# MAX value for any attribute = 147
# MIN value for any attribute = 44

