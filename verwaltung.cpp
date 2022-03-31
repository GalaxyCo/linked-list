#include "verwaltung.h"
#include <algorithm>

//init static members

unsigned int Verwaltung::listLength = 0;
Eintrag* Verwaltung::listBegin = 0;

void Verwaltung::init() {
    inputLoop();    
}

void Verwaltung::inputLoop() {
    bool run = true;
    showTutorial();

    while(run) {
        std::string inp;
        std::cin >> inp;
        
        inp = lower(inp);
    
        if(inp == "exit") {
            std::cout << "bye :)" << std::endl;
            run = false;
        }
           
        if(inp == "help") {
            showTutorial();
        }

        if(inp == "add") {
            addEntry();
        }

        if(inp == "list") {
            for(int i = 0; i < listLength; i++) {
                displayEntry(getAt(i));
            }
        }

        if(inp == "search") {
            std::cout << "Bitte geben sie an welche Zahl gesucht werden soll!" << std::endl;

            std::string searchStr;

            std::cin >> searchStr;
            //long to be able to search the unsigned int
            long searchTerm = atol(searchStr.c_str());
            bool foundSomething = false;

            for (int i = 0; i < listLength; i++) {
                Eintrag* entry = getAt(i);
                bool contains = false;
                for(int i = 0; i < 5; i++) {
                    if(entry->getWasSet(i)) {
                        if (entry->getNumberT4(i) == (int)searchTerm) {
                            contains = true;
                            break;
                        }
                    }
                }
                if(entry->getWasSet(5)) {
                    if (entry->getNumber5() == (unsigned int)searchTerm)
                    {
                        contains = true;
                    }
                }
                if(contains) {
                    displayEntry(entry);
                    foundSomething = true;
                }
            }
            if(!foundSomething) {
                std::cout << "Die gesuchte Zahl wurde nicht gefunden :(" << std::endl;
            }
        }
    }
}



void Verwaltung::displayEntry(Eintrag* value) {
    std::cout 
    << ">-----------------------<" << std::endl;
    for(int i = 0; i < 4; i++) {
        if(value->getWasSet(i)) {
            std::cout << "- num " << i << " => " << value->getNumberT4(i) << std::endl;
        }
    }
    if (value->getWasSet(5)) {
        std::cout << "- num 5 => " << value->getNumber5() << std::endl;
    }   
}

void Verwaltung::insert(Eintrag *value) {
    //mix between front and back insert
    if (Verwaltung::listLength % 2 == 0)
    {
        insertFront(value);
    }
    else
    {
        insertBack(value);
    }
}

void Verwaltung::addEntry() {
    Eintrag* entry = new Eintrag();
    bool run = true;
    while(run) {
        std::cout
        << "Um einen Eintrag hinzuzufügen wählen sie bitte aus welche Zahl sie setzten wollen (1-5)" << std::endl
        << "Um den Eintrag einzufügen tippen sie bitte \"finish\"" << std::endl
        << "(Die fünfte Zahl muss größer als null sein)" << std::endl;

        std::string inp;
        std::cin >> inp;
        
        inp = lower(inp);

        if(inp == "finish") {
            //add the entry
            insert(entry);
            run = false;
            break;
        }

        int index = atoi(inp.c_str());

        if(index > 0 && index < 6) {
            std::cout << "Jetzt bitte eine Zahl angeben:" << std::endl;
            if(index == 5) {
                unsigned int inNum = 0;
                std::cin >> inNum;
                entry->setNumber5(inNum);
            } else {
                int inNum = 0;
                std::cin >> inNum;
                entry->setNumberT4(index - 1, inNum);
            }
            std::cout << "-> Der Eintrag wurde gespeichert!" << std::endl;
        } else {
            std::cout << "Der Index muss zwischen 1 und 5 liegen!" << std::endl;
        }
    }
}

Eintrag* Verwaltung::getAt(int index) {
    if(index >= listLength)
        return 0;
    Eintrag* at = listBegin;
    for(int i = 0; i < index; i++) {
        at = at->getNext();
    }
    return at;
}

void Verwaltung::insertFront(Eintrag* value) {
    value->setNext(listBegin);
    listBegin = value;
    listLength++;
}

void Verwaltung::insertBack(Eintrag* value) {
    if(listLength == 0)
        listBegin = value;
    else {
        Eintrag *at = listBegin;
        for (int i = 0; i < listLength - 1; i++)
        {
            at = at->getNext();
        }
        at->setNext(value);
    } 
    listLength++;
}

void Verwaltung::showTutorial()
{
    std::cout 
    << "Hallo zur Zahlenverwaltung!" << std::endl
    << "=> \"add\" um einen Eintrag hinzuzufügen" << std::endl
    << "=> \"search\" um nach einer Zahl zu suchen" << std::endl
    << "=> \"list\" listet alle Elemente auf" << std::endl
    << "=> \"help\" um dieses tutorial zu öffnen" << std::endl
    << "=> \"exit\" um zu beenden" << std::endl;
}

std::string Verwaltung::lower(std::string value) {
    std::string out = value;
    //stolen from the internet (converts string to lower)
    transform(out.begin(), out.end(), out.begin(), ::tolower);
    return out;
}