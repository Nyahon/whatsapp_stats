// reading a text file

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>

#include "conv.h"
using namespace std;

const uint NAME_WIDTH_MAX = 10;
int main () {
    conv c("../anna.txt");
    /*
    string line;
    ifstream myfile ("../anna.txt");
    string user1 = "Yohann";
    string user2 = "Annaline";
    uint numMessUser1 = 0;
    uint numMessUser2 = 0;

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            //cout << line << '\n';
            if (line.find(user1) != string::npos) {
                numMessUser1++;
            }
            if (line.find(user2) != string::npos) {
                numMessUser2++;
            }

        }
        myfile.close();

        cout << setw(NAME_WIDTH_MAX) << left << user1 << ": " << numMessUser1 << " msgs /"
             << (double)numMessUser1/(numMessUser1+numMessUser2)*100  << "%" << endl;
        cout << setw(NAME_WIDTH_MAX) <<         user2 << ": " << numMessUser2 << " msgs /"
             << (double)numMessUser2/(numMessUser1+numMessUser2)*100  << "%" << endl;


    }

    else cout << "Unable to open file";
*/
    return 0;
}