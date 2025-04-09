#ifndef LABORATOR_2_4_UI_H
#define LABORATOR_2_4_UI_H

#include "domain.h"
#include "repository.h"
#include "service.h"

/*
    Functie care adauga o oferta in service
    Input: srvOffer
    Output: -
*/
void addOffer_ui(srvOffer* srv);

/*
    Functie care actualizeaza o oferta din service
    Input: srvOffer
    Output: -
*/
void updateOffer_ui(srvOffer* srv);

/*
    Functie care sterge o oferta din service
    Input: srvOffer
    Output: -
*/
void deleteOffer_ui(srvOffer* srv);

/*
    Functie care sorteaza ofertele din service dupa pret si destinatie
    Input: srvOffer
    Output: -
*/
void sortOfferbyPriceandDestination_ui(srvOffer* srv);

/*
    Functie care sorteaza ofertele din service dupa pret si destinatie in ordine descrescatoare
    Input: srvOffer
    Output: -
*/
void sortOfferbyPriceandDestinationDesc_ui(srvOffer* srv);

/*
    Functie care filtreaza ofertele din service dupa tip
    Input: srvOffer
    Output: -
*/
void filterByType_ui(srvOffer* srv);

/*
    Functie care filtreaza ofertele din service dupa destinatie
    Input: srvOffer
    Output: -
*/
void filterByDestination_ui(srvOffer* srv);

/*
    Functie care filtreaza ofertele din service dupa pret
    Input: srvOffer
    Output: -
*/
void filterByPrice_ui(srvOffer* srv);

void start_ui();

#endif //LABORATOR_2_4_UI_H
