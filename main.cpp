#include "sentence.h"

#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include <fstream>

using namespace std;

string previousWord(int position, int wordCount);
string nextWord(int position, int wordCount);
bool endOfSentence(int periodIndex);

void sentenceInitializer();

string gMainPara;

vector <sentence> sentenceArr;

int main() {

        ifstream input("./text.txt");

        string tempString;
        while (!getline(input, tempString).eof()) {
            gMainPara += tempString;
        };
        input.close();


    sentenceInitializer();

    for (int x=0; x<sentenceArr.size(); x++) {
        cout << "SENTENCE " << x << ":\t" << gMainPara.substr(sentenceArr[x].getBeginIndex(), (sentenceArr[x].getEndIndex()-sentenceArr[x].getBeginIndex() + 1)) << endl << endl;
    };

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

bool endOfSentence(int periodIndex) {
    if (gMainPara[periodIndex] == '.') {
        if (true /*gMainPara[periodIndex+1] == ' ' || gMainPara[periodIndex+1] == '\n'*/) {
            if (gMainPara[periodIndex-1] != ' ') {
                if (previousWord(periodIndex) != "Dr." && previousWord(periodIndex) != "Mr.") {
                    return true;
                }
            }
        }
    }

    return false;
}

void sentenceInitializer() {
    int index = 0;
    int sentenceIndex = 0;
    int beginIndex = 0;

    while(index < gMainPara.length()) {
        while (gMainPara[index] != '.') {index++;};

        if (endOfSentence(index)) {
            sentence tempSentence;
            tempSentence.setBeginIndex(beginIndex);
            tempSentence.setEndIndex(index);
            tempSentence.setSentenceIndex(sentenceIndex);

            sentenceArr.push_back(tempSentence);

            sentenceIndex++;
            beginIndex = ++index;
        };
    };
};
