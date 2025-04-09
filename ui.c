#include "ui.h"
#include "service.h"
#include "repository.h"
#include "domain.h"

#include <stdio.h>
void print_menu()
{
    printf("1. Adauga o oferta.\n");
    printf("2. Actualizeaza o oferta.\n");
    printf("3. Sterge o oferta.\n");
    printf("4. Oferte ordonarte dupa pret si destinatie crescator.\n");
    printf("5. Oferte filtrate dupa tip.\n");
    printf("6. Oferte filtrate dupa destinatie.\n");
    printf("7. Oferte filtrate dupa pret.\n");
    printf("8. Afiseaza toate ofertele.\n");
    printf("0. Iesire.\n");
    printf("> ");
}

void printOffers(OfferList* list) {
    // Iterate through the list and print each offer
    for (int i = 0; i < list->length; i++) {
        Offer* offer = list->offers[i];
        // Print the offer details
        printf("Offer ID: %d\n", offer->id);
        printf("Offer Type: %s\n", offer->type);
        printf("Offer Destination: %s\n", offer->destination);
        printf("Offer Departure Date: %s\n", offer->departureDate);
        printf("Offer Price: %d\n", offer->price);
        printf("\n");
    }
}

void addOffer_ui(srvOffer* srv)
{
    int id;
    char type[20], destination[50], departureDate[11];
    int price;
    printf("\nIntroduceti id-ul ofertei:");
    if (scanf("%d", &id) != 1)
    {
        printf("Acesta nu este un numar!\n\n");
        scanf("%*[^\n]");
        return;
    }
    printf("Introduceti tipul ofertei (mare, munte, excursie):");
    scanf("%s", type, 20);
    printf("Introduceti destinatia:");
    scanf("%s", destination, 50);
    printf("Introduceti data plecarii (de tipul dd-mm-yyyy):");
    scanf("%s", departureDate, 11);
    printf("Introduceti pretul:");
    if (scanf("%d", &price) != 1)
    {
        printf("Acesta nu este un numar!\n\n");
        scanf("%*[^\n]");
        return;
    }
    int error = addOfferSrv(srv, id, type, destination, departureDate, price);
    if (error == 1)
    {
        printf("Tipul ofertei este invalid (city break, mare, munte, excursie)!\n\n");
        return;
    }
    printf("Oferta a fost adaugata cu succes!\n\n");
    return;
}

void updateOffer_ui(srvOffer* srv)
{
    int id;
    char type[20], destination[50], departureDate[11];
    int price;
    printf("\nIntroduceti id-ul ofertei:");
    if (scanf("%d", &id) != 1)
    {
        printf("Acesta nu este un numar!\n\n");
        scanf("%*[^\n]");
        return;
    }
    printf("Introduceti tipul ofertei:");
    scanf("%s", type, 20);
    printf("Introduceti destinatia:");
    scanf("%s", destination, 50);
    printf("Introduceti data plecarii:");
    scanf("%s", departureDate, 11);
    printf("Introduceti pretul:");
    if (scanf("%d", &price) != 1)
    {
        printf("Acesta nu este un numar!\n\n");
        scanf("%*[^\n]");
        return;
    }
    int error = updateOfferSrv(srv, id, type, destination, departureDate, price);
    if (error == 1)
    {
        printf("Nu exista nicio oferta cu acest id!\n\n");
        return;
    }
    printf("Oferta a fost actualizata cu succes!\n\n");
    return;
}

void deleteOffer_ui(srvOffer* srv)
{
    int id;
    printf("\nIntroduceti id-ul ofertei:");
    if (scanf("%d", &id) != 1)
    {
        printf("Acesta nu este un numar!\n\n");
        scanf("%*[^\n]");
        return;
    }
    int error = deleteOfferSrv(srv, id);
    if (error == 1)
    {
        printf("Nu exista nicio oferta cu acest id!\n\n");
        return;
    }
    printf("Oferta a fost stearsa cu succes!\n\n");
    return;
}

void sortOfferbyPrice_ui(srvOffer* srv)
{
    sortOfferbyPrice(&srv->lista);
    printf("Ofertele sortate dupa pret sunt:\n");
    printOffers(&srv->lista);
}

void filterByType_ui(srvOffer* srv)
{
    char type[20];
    printf("\nIntroduceti tipul ofertei:");
    scanf("%s", type, 20);

    OfferList filtered = createOfferList();
    filterOfferbyType(srv, type, &filtered);

    printf("Ofertele filtrate dupa tip sunt:\n");
    for (int i = 0; i < filtered.length; i++)
    {
        printf("Oferta %d: %s, %s, %s, %d\n", filtered.offers[i]->id, filtered.offers[i]->type, filtered.offers[i]->destination, filtered.offers[i]->departureDate, filtered.offers[i]->price);
    }
    printf("\n");
}

void filterByDestination_ui(srvOffer* srv)
{
    char destination[50];
    printf("\nIntroduceti destinatia:");
    scanf("%s", destination, 50);

    OfferList filtered = createOfferList();
    filterOfferByDestination(srv, destination, &filtered);

    printf("Ofertele filtrate dupa destinatie sunt:\n");
    for (int i = 0; i < filtered.length; i++)
    {
        printf("Oferta %d: %s, %s, %s, %d\n", filtered.offers[i]->id, filtered.offers[i]->type, filtered.offers[i]->destination, filtered.offers[i]->departureDate, filtered.offers[i]->price);
    }
    printf("\n");
}

void filterByPrice_ui(srvOffer* srv)
{
    int price;
    printf("\nIntroduceti pretul:");
    if (scanf("%d", &price) != 1)
    {
        printf("Acesta nu este un numar!\n\n");
        scanf("%*[^\n]");
        return;
    }

    OfferList filtered = createOfferList();
    filterOfferByPrice(srv, price, &filtered);

    printf("Ofertele filtrate dupa pret sunt:\n");
    for (int i = 0; i < filtered.length; i++)
    {
        printf("Oferta %d: %s, %s, %s, %d\n", filtered.offers[i]->id, filtered.offers[i]->type, filtered.offers[i]->destination, filtered.offers[i]->departureDate, filtered.offers[i]->price);
    }
    printf("\n");
}

void start_ui()
{
    OfferList lst = createOfferList();
    srvOffer* srv = createSrvOffer(lst); // dynamically allocate memory for srvOffer
    int cmd;
    while (1)
    {
        print_menu();
        if (scanf("%d", &cmd) != 1)
        {
            printf("Acesta nu este un numar!\n\n");
            scanf("%*[^\n]");
            continue;
        }
        switch (cmd)
        {
            case 1:
                addOffer_ui(srv);
                break;
            case 2:
                updateOffer_ui(srv);
                break;
            case 3:
                deleteOffer_ui(srv);
                break;
            case 4:
                sortOfferbyPrice_ui(srv);
                break;
            case 5:
                filterByType_ui(srv);
                break;
            case 6:
                filterByDestination_ui(srv);
                break;
            case 7:
                filterByPrice_ui(srv);
                break;
            case 8:
                printOffers(&srv->lista);
                break;
            case 0:
                destroySrvOffer(&srv); // free the dynamically allocated memory
                return;
            default:
                printf("Comanda invalida!\n\n");
                break;
        }
    }
}