class Eintrag {
    private:
        int numbers[4]; //eintrag 1 - 4
        bool wasSet[5];
        unsigned int n5; //eintrag 5
        Eintrag* next;

    public:
        Eintrag();

        int getNumberT4(int index);
        unsigned int getNumber5();
        void setNumberT4(int index, int value);
        void setNumber5(unsigned int value);
        bool getWasSet(int index);

        Eintrag* getNext();
        void setNext(Eintrag* newNext);
};