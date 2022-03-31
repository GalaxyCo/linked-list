#include "eintrag.h"

Eintrag::Eintrag() {
    for(int i = 0; i < 6; i++) {
        this->wasSet[i] = false;
    }
}

Eintrag* Eintrag::getNext() {
    return this->next;
}

void Eintrag::setNext(Eintrag* next) {
    this->next = next;
}

void Eintrag::setNumberT4(int index, int value) {
    this->wasSet[index] = true;
    this->numbers[index] = value;
}

void Eintrag::setNumber5(unsigned int value) {
    this->n5 = value;
    this->wasSet[5] = true;
}

int Eintrag::getNumberT4(int index) {
    return this->numbers[index];
}

unsigned int Eintrag::getNumber5() {
    return this->n5;
}

bool Eintrag::getWasSet(int index) {
    return this->wasSet[index];
}
