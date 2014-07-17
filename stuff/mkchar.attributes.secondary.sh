i=0
while read line
do
    attName[$i]=`echo "$line"|awk -F'=' '{print $1}'`
    attVal[$i]=`echo "$line"|awk -F'=' '{print $2}'`
#echo "${attName[$i]}: ${attVal[$i]}"
    i=$i+1
done < $1

for (( i=0; i<${#attName[@]}; i++ ));
do
    case ${attName[$i]} in
    STR)
        STR=${attVal[i]};;
    DEX)
        DEX=${attVal[i]};;
    CON)
        CON=${attVal[i]};;
    CHA)
        CHA=${attVal[i]};;     
    INT)
        INT=${attVal[i]};;
    WIS)
        WIS=${attVal[i]};;
    HT)
        HT=${attVal[i]};;
    esac
done

cSTR=$STR
cDEX=$DEX
cCON=$CON
cCHA=$CHA
cINT=$INT
cWIS=$WIS
cHT=$HT

#WT=$HT                                                     # Weight directly proportionate to Height
#WT=$(echo "$WT*${atts[5]}/85"|bc)                          # weight directly proportionate to Strength
#WT=$(echo "$WT*85/${atts[4]}"|bc)                          # weight inversely proportionate to Dexterity
cWT=$(echo "$cHT*$cSTR/$cDEX"|bc)

echo "current strength = $cSTR"
echo "current dexterity = $cDEX"
echo "current constituition = $cCON"
echo "current charisma = $cCHA"
echo "current wisdom = $cWIS"
echo "current intelligence = $cINT"
echo "current height = $cHT"
echo
echo "current weight = $cWT:"