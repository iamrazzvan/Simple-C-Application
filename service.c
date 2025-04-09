#include <stdlib.h>
#include <string.h>

#include "service.h"

srvOffer* createSrvOffer(OfferList lst)
{
    srvOffer* srv = (srvOffer*)malloc(sizeof(srvOffer));
    srv->lista = lst;
    return srv;
}

int compare(Offer* off1, Offer* off2)
{
    if (off1->price > off2->price)
        return 1;
    if (off1->price < off2->price)
        return -1;
    return 0;
}

void sort(OfferList* list, int (*compare)(Offer*, Offer*))
{
    for (int i = 0; i < list->length - 1; i++)
    {
        for (int j = i + 1; j < list->length; j++)
        {
            if (compare(list->offers[i], list->offers[j]) > 0)
            {
                Offer* aux = list->offers[i];
                list->offers[i] = list->offers[j];
                list->offers[j] = aux;
            }
        }
    }
}

int addOfferSrv(srvOffer* srv, int id, char type[], char destination[], char departureDate[], int price)
{
    Offer* off = (Offer*)malloc(sizeof(Offer));
    *off = createOffer(id, type, destination, departureDate, price);

    int vld = validator(*off);
    if (vld == 0)
    {
        destroyOffer(off);
        free(off);
        return 1;
    }

    addOffer(&srv->lista, off);
    return 0;
}

int updateOfferSrv(srvOffer* srv, int id, char type[], char destination[], char departureDate[], int price)
{
    Offer off = createOffer(id, type, destination, departureDate, price);

    int vld = validator(off);

    destroyOffer(&off);

    if (vld == 0)
        return 1;

    int l = getLengthList(&srv->lista);
    for (int i = 0; i < l; i++)
    {
        Offer off = getOfferIndex(&srv->lista, i);
        if (id == get_id(off))
        {
            Offer* newOff = (Offer*)malloc(sizeof(Offer));
            *newOff = createOffer(id, type, destination, departureDate, price);
            destroyOffer(srv->lista.offers[i]);
            free(srv->lista.offers[i]);
            updateOffer(&srv->lista, i, newOff);
            destroyOffer(&off);
            return 0;
        }
    }
    return 1;
}

int deleteOfferSrv(srvOffer* srv, int id)
{
    int l = getLengthList(&srv->lista);
    for (int i = 0; i < l; i++)
    {
        Offer off = getOfferIndex(&srv->lista, i);
        if (id == get_id(off))
        {
            Offer* offerToDelete = srv->lista.offers[i];
            deleteOffer(&srv->lista, i);
            destroyOffer(offerToDelete);
            destroyOffer(&off);
            free(offerToDelete);

            return 0;
        }
    }
    return 1;
}

void sortOfferbyPrice(srvOffer* srv)
{
    for (int i = 0; i < srv->lista.length - 1; i++)
    {
        for (int j = i + 1; j < srv->lista.length; j++)
        {
            if (srv->lista.offers[i]->price > srv->lista.offers[j]->price)
            {
                Offer* aux = srv->lista.offers[i];
                srv->lista.offers[i] = srv->lista.offers[j];
                srv->lista.offers[j] = aux;
            }
        }
    }
}

void filterOfferbyType(srvOffer* srv, char* type, OfferList* filtered)
{
    for (int i = 0; i < srv->lista.length; i++)
    {
        if (strcmp(srv->lista.offers[i]->type, type) == 0)
        {
            addOffer(filtered, srv->lista.offers[i]);
        }
    }
}

void filterOfferByDestination(srvOffer* srv, char* destination, OfferList* filtered)
{
    for (int i = 0; i < srv->lista.length; i++)
    {
        if (strcmp(srv->lista.offers[i]->destination, destination) == 0)
        {
            addOffer(filtered, srv->lista.offers[i]);
        }
    }
}

void filterOfferByPrice(srvOffer* srv, int price, OfferList* filtered)
{
    for (int i = 0; i < srv->lista.length; i++)
    {
        if (srv->lista.offers[i]->price <= price)
        {
            addOffer(filtered, srv->lista.offers[i]);
        }
    }
}

void destroySrvOffer(srvOffer** srv)
{
    for (int i = 0; i < (*srv)->lista.length; i++)
    {
        destroyOffer((*srv)->lista.offers[i]);
        free((*srv)->lista.offers[i]);

    }
    free((*srv)->lista.offers);
    //free(&((*srv)->lista));
    free(*srv);
    //*srv = NULL;
}