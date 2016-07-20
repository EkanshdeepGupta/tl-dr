#include "sentence.h"

sentence::sentence()
{
    //ctor
}

sentence::~sentence()
{
    //dtor
}

int sentence::getBeginIndex() {
    return beginIndex;
};

int sentence::getEndIndex() {
    return endIndex;
};

int sentence::getSentenceIndex() {
    return sentenceIndex;
}

void sentence::setBeginIndex(int x) {
    beginIndex = x;
}

void sentence::setEndIndex(int x) {
    endIndex = x;
};

void sentence::setSentenceIndex(int x) {
    sentenceIndex = x;
}
