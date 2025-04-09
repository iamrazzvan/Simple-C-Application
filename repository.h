#ifndef LABORATOR_2_4_REPOSITORY_H
#define LABORATOR_2_4_REPOSITORY_H

#include "domain.h"

#define InitialCapacity 1

typedef struct
{
    Offer** offers;
    int length;
    int capacity;
} OfferList;

/*
    Functie care creeaza o lista de oferte
*/
OfferList createOfferList();

/*
    Functie care adauga o oferta in lista de oferte
    Input: OfferList, Offer
    Output: -
*/
void addOffer(OfferList* list, Offer* off);

/*
    Functie care actualizeaza o oferta din lista de oferte
    Input: OfferList, integer, Offer
    Output: -
*/
void updateOffer(OfferList* list, int index, Offer* off);

/*
    Functie care sterge o oferta din lista de oferte
    Input: OfferList, integer
    Output: -
*/
void deleteOffer(OfferList* list, int index);

/*
    Functie care returneaza o oferta din lista de oferte
    Input: OfferList, integer
    Output: Offer
*/
Offer getOfferIndex(OfferList* list, int index);

/*
    Functie care returneaza lungimea listei de oferte
    Input: OfferList
    Output: integer
*/
int getLengthList(OfferList* list);


#endif //LABORATOR_2_4_REPOSITORY_H
