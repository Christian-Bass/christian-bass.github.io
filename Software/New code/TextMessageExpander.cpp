
#include <iostream>
#include <string>
using namespace std;

void replaceText(string& str, const string& from, const string& to); //defining class for replacing the text

int main() { //main class including text translations, I plan to change this over to a text file later so that the user can add more.

    string inputStr; // input variable

    cout << "Enter text to be converted:" << endl;
    getline(cin, inputStr);; //asking user to input a string and getting user input.


    size_t found1 = inputStr.find("BBL"); //checks string for the shortened phrase and calls replaceText to replace it.
    if (found1 != string::npos) {
        replaceText(inputStr, "BBL", "Be back later");
        cout << inputStr << endl;
    }

    else {
        cout << "No instance of BBL found in text" << endl;
    }

    size_t found2 = inputStr.find("TTYL");
    if (found2 != string::npos) {
        replaceText(inputStr, "TTYL", "Talk to you later.");
        cout << inputStr << endl;
    }

    else {
        cout << "No instance of TTYL found in text" << endl;
    }

    size_t found3 = inputStr.find("BRB");
    if (found3 != string::npos) {
        replaceText(inputStr, "BRB", "Be right back");
        cout << inputStr << endl;
    }

    else {
        cout << "No instance of BRB found in text" << endl;
    }

    size_t found4 = inputStr.find("OTW");
    if (found4 != string::npos) {
        replaceText(inputStr, "OTW", "On the way");
        cout << inputStr << endl;
    }

    else {
        cout << "No instance of OTW found in text" << endl;
    }


    return 0;
}


void replaceText(string& str, const string& from, const string& to) { // Class to replace the text within strings

    if (from.empty())
        return;

    size_t startP = 0;

    while ((startP = str.find(from, startP)) != string::npos) { //While loop to replace all instances of the abbreviation instead of just one.
        str.replace(startP, from.length(), to);
        startP += to.length();
    }
}