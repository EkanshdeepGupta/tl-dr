#ifndef SENTENCE_H
#define SENTENCE_H


class sentence
{
    public:
        sentence();
        virtual ~sentence();

        int getEndIndex();
        int getBeginIndex();
        int getSentenceIndex();

        void setBeginIndex(int);
        void setEndIndex(int);
        void setSentenceIndex(int);

    protected:

    private:
        int beginIndex;
        int endIndex;
        int sentenceIndex;

};

#endif // SENTENCE_H
