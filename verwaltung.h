#include "eintrag.h"
#include <iostream>

class Verwaltung {
    private:
        static Eintrag *listBegin;
        static unsigned int listLength;

        //ui stuff
        static void inputLoop();
        static void showTutorial();
        static void listAll();
        static void addEntry();
        static void displayEntry(Eintrag* value);

        static std::string lower(std::string value);

        static Eintrag *getAt(int index);
        static void insert(Eintrag *value);
        static void insertBack(Eintrag *value);
        static void insertFront(Eintrag *value);

    public:
        static void init();
};  