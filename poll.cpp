#include <iostream>
#include <cassert>
#include <string>
using namespace std;


bool isValidUppercaseStateCode(string stateCode)
{
    const string codes =
        "AL.AK.AZ.AR.CA.CO.CT.DE.DC.FL.GA.HI.ID.IL.IN.IA.KS."
        "KY.LA.ME.MD.MA.MI.MN.MS.MO.MT.NE.NV.NJ.NH.NM.NY.NC."
        "ND.OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
    return (stateCode.size() == 2  &&
            stateCode.find('.') == string::npos  &&  // no '.' in stateCode
            codes.find(stateCode) != string::npos);  // match found
}

bool hasRightSyntax(string pollData) {
    if (pollData == "") {
        return true; }

    
    for (int i=0; i < pollData.length(); i++){
        //check if the 0 character is a letter
        if (isalpha(pollData[i])){
            i++;
            //check if 1 character is a digit
            if (isdigit(pollData[i])){
                i++;
                //check if 2rd character is a digit
                if (isdigit(pollData[i])){
                    i++;
                    pollData.at(i) = toupper(pollData.at(i));
                    pollData.at(i+1) = toupper(pollData.at(i+1));
                    if (isValidUppercaseStateCode(pollData.substr(i,2))){
                        i++;
                       //let it fall through
                    }
                    else {
                        return false;
                    }
                    
                }
                else {
                    pollData.at(i) = toupper(pollData.at(i));
                    pollData.at(i+1) = toupper(pollData.at(i+1));
                    
                    if (isValidUppercaseStateCode(pollData.substr(i,2))){
                        i++;
                       //let it fall through
                    }
                    else {
                        return false;
                    }
                }
            }// if not character return false
            else{
                return false;
            }
        }// if not letter return false
        else {
            return false;
        }
   }
    return true;
}

int computeVotes(string pollData, char party, int& voteCount){
    if (hasRightSyntax(pollData)){
        voteCount=2;
        return 0;
    }
    else {
        return 3;
    }
}

int main() {
    cout << "Enter poll data string: " << endl;
    string pollData;
    getline(cin, pollData);
    if (hasRightSyntax(pollData)) {
        cout << "Correct" << endl;
    }
        else {
        cout << "Incorrect" << endl;
    }
}\
