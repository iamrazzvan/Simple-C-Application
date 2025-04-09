#ifndef LABORATOR_2_4_DOMAIN_H
#define LABORATOR_2_4_DOMAIN_H

typedef struct
{
    int id;
    char* type;
    char* destination;
    char* departureDate;
    int price;
} Offer;

/*
    Functie care creeaza un obiect de tip Offer
    Input: id - integer, type - string, destination - string, departureDate - string, price - float
    Output: Offer
 */
Offer createOffer(int id, char type[], char destination[], char departureDate[], int price);

/*
    Functie care valideaza un obiect de tip Offer
    Input: Offer
    Output: integer
 */
int validator(Offer off);

/*
    Functie care returneaza id-ul unui obiect de tip Offer
    Input: Offer
    Output: integer
 */
int get_id(Offer off);

/*
    Functie care returneaza tipul unui obiect de tip Offer
    Input: Offer
    Output: string
 */
char *get_type(Offer off);

/*
    Functie care returneaza destinatia unui obiect de tip Offer
    Input: Offer
    Output: string
 */
char *get_destination(Offer off);

/*
    Functie care returneaza data plecarii unui obiect de tip Offer
    Input: Offer
    Output: string
 */
char *get_departureDate(Offer off);

/*
    Functie care returneaza pretul unui obiect de tip Offer
    Input: Offer
    Output: float
 */
int get_price(Offer off);

/*
    Functie care elibereaza memoria alocata pentru un obiect de tip Offer
    Input: Offer
    Output: -
 */
void destroyOffer(Offer *off);

#endif //LABORATOR_2_4_DOMAIN_H
