#ifndef LABORATOR_2_4_SERVICE_H
#define LABORATOR_2_4_SERVICE_H

#include "domain.h"
#include "repository.h"

typedef struct
{
    OfferList lista;
} srvOffer;

/*
    Functie care creeaza un service de oferte
    Input: OfferList
    Output: srvOffer
*/
srvOffer* createSrvOffer(OfferList lst);

/*
    Functie care compara doua oferte
    Input: Offer, Offer
    Output: integer
*/
int compare(Offer* off1, Offer* off2);

/*
    Functie care sorteaza o lista de oferte
    Input: OfferList, integer
    Output: -
*/
void sort(OfferList* list, int (*compare)(Offer*, Offer*));

/*
    Functie care adauga o oferta in service
    Input: srvOffer, integer, string, string, string, float
    Output: integer
*/
int addOfferSrv(srvOffer* srv, int id, char type[], char destination[], char departureDate[], int price);

/*
    Functie care actualizeaza o oferta din service
    Input: srvOffer, integer, string, string, string, float
    Output: integer
*/
int updateOfferSrv(srvOffer* srv, int id, char type[], char destination[], char departureDate[], int price);

/*
    Functie care sterge o oferta din service
    Input: srvOffer, integer
    Output: integer
*/
int deleteOfferSrv(srvOffer* srv, int id);

/*
    Functie care sorteaza ofertele din service dupa pret si destinatie in ordine descrescatoare
    Input: srvOffer
    Output: -
*/
void sortOfferbyPrice(srvOffer* srv);

/*
    Functie care filtreaza ofertele din service dupa tip
    Input: srvOffer, string
    Output: -
*/
void filterOfferbyType(srvOffer* srv, char* type, OfferList* filtered);

/*
    Functie care filtreaza ofertele din service dupa destinatie
    Input: srvOffer, string
    Output: -
*/
void filterOfferByDestination(srvOffer* srv, char* destination, OfferList* filtered);

/*
    Functie care filtreaza ofertele din service dupa pret
    Input: srvOffer, integer
    Output: -
*/
void filterOfferByPrice(srvOffer* srv, int price, OfferList* filtered);

/*
    Functie care distruge un service de oferte
    Input: srvOffer
    Output: -
*/
void destroySrvOffer(srvOffer** srv);

#endif //LABORATOR_2_4_SERVICE_H
