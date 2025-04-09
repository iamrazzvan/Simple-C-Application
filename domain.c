#include "domain.h"
#include <stdlib.h>
#include <string.h>

Offer createOffer(int id, char type[], char destination[], char departureDate[], int price)
{
    Offer off;
    off.id = id;
    off.type = malloc(strlen(type) + 1);
    strcpy(off.type, type);
    off.destination = malloc(strlen(destination) + 1);
    strcpy(off.destination, destination);
    off.departureDate = malloc(strlen(departureDate) + 1);
    strcpy(off.departureDate, departureDate);
    off.price = price;
    return off;
}

int validator(Offer off)
{
    if (off.id < 0 || off.price < 0)
        return 0;

    if (strlen(off.type) == 0 || strlen(off.destination) == 0 || strlen(off.departureDate) == 0)
        return 0;

    if (strcmp(off.type, "city break") != 0 && strcmp(off.type, "mare") != 0 && strcmp(off.type, "munte") != 0 && strcmp(off.type, "excursie") != 0)
        return 0;

    if (off.departureDate[2] != '-' || off.departureDate[5] != '-')
        return 0;

    return 1;
}

int get_id(Offer off)
{
    return off.id;
}

char* get_type(Offer off)
{
    return off.type;
}

char* get_destination(Offer off)
{
    return off.destination;
}

char* get_departureDate(Offer off)
{
    return off.departureDate;
}

int get_price(Offer off)
{
    return off.price;
}



void destroyOffer(Offer* off)
{
    free(off->type);
    off->type = NULL;
    free(off->destination);
    off->destination = NULL;
    free(off->departureDate);
    off->departureDate = NULL;
}
