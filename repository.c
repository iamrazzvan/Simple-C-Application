#include "repository.h"
#include <stdlib.h>

OfferList createOfferList()
{
    OfferList list;
    list.offers = malloc(InitialCapacity * sizeof(Offer*));
    list.length = 0;
    list.capacity = InitialCapacity;
    return list;
}

void addOffer(OfferList* list, Offer* off)
{
    if (list->length == list->capacity)
    {
        list->capacity *= 2;
        Offer** newOffers = malloc(list->capacity * sizeof(Offer*));
        for (int i = 0; i < list->length; i++)
        {
            newOffers[i] = list->offers[i];
        }
        free(list->offers);
        list->offers = newOffers;
    }
    list->offers[list->length] = off;
    list->length++;
}

void updateOffer(OfferList* list, int index, Offer* off)
{
    list->offers[index] = off;
}

void deleteOffer(OfferList* list, int index)
{
    for (int i = index; i < list->length - 1; i++)
        list->offers[i] = list->offers[i + 1];
    list->length--;
}

Offer getOfferIndex(OfferList* list, int index)
{
    Offer off = createOffer(get_id(*list->offers[index]), get_type(*list->offers[index]), get_destination(*list->offers[index]), get_departureDate(*list->offers[index]), get_price(*list->offers[index]));
    return off;
}

int getLengthList(OfferList* list)
{
    return list->length;
}
