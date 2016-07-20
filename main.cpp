#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

string previousWord(int position, int wordCount);
string nextWord(int position, int wordCount);

string gMainPara;

int main() {
    getline(cin, gMainPara);
    int x;
    cout << "x?: ";
    cin >> x;
    cout << "x: " << x << endl;
    int y;
    cout << "y?: ";
    cin >> y;
    cout << nextWord(x, y);
}

string previousWord(int position, int wordCount=1) {
    if (position >= gMainPara.length()) {
        return "LengthOverflow";
    };

    int x=0;

    int firstChar = -1;
    int lastChar = position;

    while (x<wordCount) {
        do {
            if (position > 0) {position--;}
            else {break;};
        } while (gMainPara[position] != ' ');

        if(position == 0) {break;};

        x++;
    };

    firstChar = position;
    if (gMainPara[firstChar] == ' ') {firstChar++;};

    return (gMainPara).substr(firstChar, lastChar-firstChar+1);
}

string nextWord(int position, int wordCount=1) {
    if (position >= gMainPara.length()) {
        return "LengthOverflow";
    };

    int x=0;

    int firstChar = position;
    int lastChar = -1;

    while (x<wordCount) {
        do {
            if (position < (gMainPara.length()-1)) {position++;}
            else {break;};
        } while (gMainPara[position] != ' ');

        if (position == (gMainPara.length()-1)) {break;};

        x++;
    };

    lastChar = position;
    if (gMainPara[lastChar] == ' ') {lastChar--;};

    return gMainPara.substr(firstChar, lastChar-firstChar+1);
};
