#include "domain.h"
#include "repository.h"
#include "service.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

void test_createOffer()
{
    // Arrange
    int id = 1;
    char type[] = "munte";
    char destination[] = "Brasov";
    char departureDate[] = "01-05-2023";
    int price = 1000;

    // Act
    Offer off = createOffer(id, type, destination, departureDate, price);

    // Assert
    assert(off.id == id);
    assert(strcmp(off.type, type) == 0);
    assert(strcmp(off.destination, destination) == 0);
    assert(strcmp(off.departureDate, departureDate) == 0);
    assert(off.price == price);

    // Cleanup
    destroyOffer(&off);
}

void test_validator()
{
    // Test case 1: Valid offer
    Offer off1 = createOffer(1, "city break", "Paris", "01-05-2023", 1000);
    assert(validator(off1) == 1);
    destroyOffer(&off1);

    // Test case 2: Invalid offer with negative id
    Offer off2 = createOffer(-1, "city break", "Paris", "01-05-2023", 1000);
    assert(validator(off2) == 0);
    destroyOffer(&off2);

    // Test case 3: Invalid offer with negative price
    Offer off3 = createOffer(1, "city break", "Paris", "01-05-2023", -1000);
    assert(validator(off3) == 0);
    destroyOffer(&off3);

    // Test case 4: Invalid offer with empty type
    Offer off4 = createOffer(1, "", "Paris", "01-05-2023", 1000);
    assert(validator(off4) == 0);
    destroyOffer(&off4);

    // Test case 5: Invalid offer with invalid type
    Offer off5 = createOffer(1, "invalid type", "Paris", "01-05-2023", 1000);
    assert(validator(off5) == 0);
    destroyOffer(&off5);

    // Test case 6: Invalid offer with invalid date format
    Offer off6 = createOffer(1, "city break", "Paris", "01052023", 1000);
    assert(validator(off6) == 0);
    destroyOffer(&off6);
}

void test_get_id()
{
    // Arrange
    int id = 1;
    char type[] = "mare";
    char destination[] = "Mamaia";
    char departureDate[] = "01-05-2023";
    int price = 1000;
    Offer off = createOffer(id, type, destination, departureDate, price);

    // Act
    int result = get_id(off);

    // Assert
    assert(result == id);

    // Cleanup
    destroyOffer(&off);
}

void test_get_type()
{
    // Arrange
    int id = 1;
    char type[] = "mare";
    char destination[] = "Mamaia";
    char departureDate[] = "01-05-2023";
    int price = 1000;
    Offer off = createOffer(id, type, destination, departureDate, price);

    // Act
    char* result = get_type(off);

    // Assert
    assert(strcmp(result, type) == 0);

    // Cleanup
    destroyOffer(&off);
}

void test_get_destination()
{
    // Arrange
    int id = 1;
    char type[] = "mare";
    char destination[] = "Mamaia";
    char departureDate[] = "01-05-2023";
    int price = 1000;
    Offer off = createOffer(id, type, destination, departureDate, price);

    // Act
    char* result = get_destination(off);

    // Assert
    assert(strcmp(result, destination) == 0);

    // Cleanup
    destroyOffer(&off);
}

void test_get_departureDate()
{
    // Arrange
    int id = 1;
    char type[] = "mare";
    char destination[] = "Mamaia";
    char departureDate[] = "01-05-2023";
    int price = 1000;
    Offer off = createOffer(id, type, destination, departureDate, price);

    // Act
    char* result = get_departureDate(off);

    // Assert
    assert(strcmp(result, departureDate) == 0);

    // Cleanup
    destroyOffer(&off);
}

void test_get_price()
{
    // Arrange
    int id = 1;
    char type[] = "mare";
    char destination[] = "Mamaia";
    char departureDate[] = "01-05-2023";
    int price = 1000;
    Offer off = createOffer(id, type, destination, departureDate, price);

    // Act
    int result = get_price(off);

    // Assert
    assert(result == price);

    // Cleanup
    destroyOffer(&off);
}

void test_destroyOffer()
{
    // Arrange
    int id = 1;
    char type[] = "mare";
    char destination[] = "Mamaia";
    char departureDate[] = "01-05-2023";
    int price = 1000;
    Offer off = createOffer(id, type, destination, departureDate, price);

    // Act
    destroyOffer(&off);
}

void test_createOfferList()
{
    // Act
    OfferList list = createOfferList();

    // Assert
    assert(list.offers != NULL);
    assert(list.length == 0);
    assert(list.capacity == InitialCapacity);

    // Cleanup
    free(list.offers);
}

void test_addOffer()
{
    // Arrange
    OfferList list = createOfferList();
    int id = 1;
    char type[] = "mare";
    char destination[] = "Mamaia";
    char departureDate[] = "01-05-2023";
    int price = 1000;
    Offer off = createOffer(id, type, destination, departureDate, price);

    // Act
    addOffer(&list, &off);

    // Assert
    assert(list.length == 1);
    assert(list.capacity == InitialCapacity);
    assert(list.offers[0] != NULL);
    assert(list.offers[0]->id == id);
    assert(strcmp(list.offers[0]->type, type) == 0);
    assert(strcmp(list.offers[0]->destination, destination) == 0);
    assert(strcmp(list.offers[0]->departureDate, departureDate) == 0);
    assert(list.offers[0]->price == price);

    // Cleanup
    for(int i = 0; i < list.length; i++)
    {
        destroyOffer(list.offers[i]);
    }
    free(list.offers);
}

void test_updateOffer()
{
    // Arrange
    OfferList list = createOfferList();
    int id = 1;
    char type[] = "munte";
    char destination[] = "Brasov";
    char departureDate[] = "01-05-2023";
    int price = 1000;
    Offer off1 = createOffer(id, type, destination, departureDate, price);

    addOffer(&list, &off1);

    int new_id = 2;
    char new_type[] = "mare";
    char new_destination[] = "Mamaia";
    char new_departureDate[] = "01-06-2023";
    int new_price = 2000;
    Offer new_off = createOffer(new_id, new_type, new_destination, new_departureDate, new_price);

    // Act
    Offer* newOff = list.offers[0];
    destroyOffer(newOff);
    updateOffer(&list, 0, &new_off);

    // Assert
    assert(list.length == 1);
    assert(list.capacity == InitialCapacity);
    assert(list.offers[0] != NULL);
    assert(list.offers[0]->id == new_id);
    assert(strcmp(list.offers[0]->type, new_type) == 0);
    assert(strcmp(list.offers[0]->destination, new_destination) == 0);
    assert(strcmp(list.offers[0]->departureDate, new_departureDate) == 0);
    assert(list.offers[0]->price == new_price);

    // Cleanup
    for(int i = 0; i < list.length; i++) {
        destroyOffer(list.offers[i]);
    }
    free(list.offers);
}

void test_deleteOffer()
{
    // Arrange
    OfferList list = createOfferList();
    int id = 1;
    char type[] = "munte";
    char destination[] = "Brasov";
    char departureDate[] = "01-05-2023";
    int price = 1000;
    Offer off1 = createOffer(id, type, destination, departureDate, price);
    Offer off2 = createOffer(2, "mare", "Mamaia", "01-06-2023", 500);
    addOffer(&list, &off1);
    addOffer(&list, &off2);

    // Act
    int pos_to_delete = 0;
    destroyOffer(list.offers[pos_to_delete]);
    deleteOffer(&list, pos_to_delete);

    // Assert
    assert(list.length == 1);
    assert(list.capacity == InitialCapacity+1);

    // Cleanup
    for(int i = 0; i < list.length; i++)
    {
        destroyOffer(list.offers[i]);
    }
    free(list.offers);
}

void test_getOfferIndex()
{
    // Arrange
    OfferList list = createOfferList();
    int id = 1;
    char type[] = "munte";
    char destination[] = "Brasov";
    char departureDate[] = "01-05-2023";
    int price = 1000;
    Offer off = createOffer(id, type, destination, departureDate, price);
    addOffer(&list, &off);

    // Act
    Offer result = getOfferIndex(&list, 0);

    // Assert
    assert(result.id == id);
    assert(strcmp(result.type, type) == 0);
    assert(strcmp(result.destination, destination) == 0);
    assert(strcmp(result.departureDate, departureDate) == 0);
    assert(result.price == price);

    // Cleanup
    destroyOffer(&off);
    destroyOffer(list.offers[0]);
    destroyOffer(&result);
    free(list.offers);
}

void test_getLengthList()
{
    // Arrange
    OfferList list = createOfferList();
    int id = 1;
    char type[] = "munte";
    char destination[] = "Brasov";
    char departureDate[] = "01-05-2023";
    int price = 1000;
    Offer off = createOffer(id, type, destination, departureDate, price);
    addOffer(&list, &off);

    // Act
    int result = getLengthList(&list);

    // Assert
    assert(result == 1);

    // Cleanup
    for(int i = 0; i < list.length; i++)
    {
        destroyOffer(list.offers[i]);
    }
    free(list.offers);
}

void test_createSrvOffer() {
    // Arrange
    OfferList list = createOfferList();

    // Act
    srvOffer* srv = createSrvOffer(list);

    // Assert
    assert(srv != NULL);
    assert(srv->lista.length == list.length);
    assert(srv->lista.offers == list.offers);

    // Cleanup
    for(int i = 0; i < srv->lista.length; i++)
    {
        destroyOffer(srv->lista.offers[i]);
    }
    free(srv->lista.offers);
    free(srv);
}

void test_compare()
{
    // Arrange
    Offer off1 = createOffer(1, "munte", "Alpi", "01-05-2023", 1000);
    Offer off2 = createOffer(2, "mare", "Mamaia", "01-06-2023", 2000);
    Offer off3 = createOffer(3, "munte", "Brasov", "01-07-2023", 1500);
    Offer off4 = createOffer(4, "mare", "Thasos", "01-08-2023", 2000);

    // Act
    int result1 = compare(&off1, &off2);
    int result2 = compare(&off2, &off3);
    int result3 = compare(&off1, &off3);
    int result4 = compare(&off2, &off4);

    // Assert
    assert(result1 == -1);
    assert(result2 == 1);
    assert(result3 == -1);
    assert(result4 == 0);

    // Cleanup
    destroyOffer(&off1);
    destroyOffer(&off2);
    destroyOffer(&off3);
    destroyOffer(&off4);
}

void test_sort()
{
    // Arrange
    OfferList list = createOfferList();
    Offer off1 = createOffer(1, "mare", "Thasos", "01-05-2023", 1000);
    Offer off2 = createOffer(2, "mare", "Mamaia", "01-06-2023", 2000);
    Offer off3 = createOffer(3, "munte", "Brasov", "01-07-2023", 1500);
    addOffer(&list, &off1);
    addOffer(&list, &off2);
    addOffer(&list, &off3);

    // Act
    sort(&list, compare);

    // Assert
    assert(list.offers[0]->id == 1);
    assert(strcmp(list.offers[0]->type, "mare") == 0);
    assert(strcmp(list.offers[0]->destination, "Thasos") == 0);
    assert(strcmp(list.offers[0]->departureDate, "01-05-2023") == 0);
    assert(list.offers[0]->price == 1000);

    assert(list.offers[1]->id == 3);
    assert(strcmp(list.offers[1]->type, "munte") == 0);
    assert(strcmp(list.offers[1]->destination, "Brasov") == 0);
    assert(strcmp(list.offers[1]->departureDate, "01-07-2023") == 0);
    assert(list.offers[1]->price == 1500);

    assert(list.offers[2]->id == 2);
    assert(strcmp(list.offers[2]->type, "mare") == 0);
    assert(strcmp(list.offers[2]->destination, "Mamaia") == 0);
    assert(strcmp(list.offers[2]->departureDate, "01-06-2023") == 0);
    assert(list.offers[2]->price == 2000);

    // Cleanup
    for(int i = 0; i < list.length; i++)
    {
        destroyOffer(list.offers[i]);
    }
    free(list.offers);
}

void test_addOfferSrv()
{
    // Arrange
    OfferList list = createOfferList();
    srvOffer* srv = createSrvOffer(list);

    // Act
    int result = addOfferSrv(srv, 1, "excursie", "Paris", "01-05-2023", 1000);
    int result1 = addOfferSrv(srv, -1, "", "", "", -1000);

    // Assert
    assert(result1 == 1); // Expect the function to return 1 (failure)

    assert(result == 0); // Expect the function to return 0 (success)
    assert(srv->lista.length == 1); // Expect the list to have one offer
    assert(srv->lista.offers[0]->id == 1);
    assert(strcmp(srv->lista.offers[0]->type, "excursie") == 0);
    assert(strcmp(srv->lista.offers[0]->destination, "Paris") == 0);
    assert(strcmp(srv->lista.offers[0]->departureDate, "01-05-2023") == 0);
    assert(srv->lista.offers[0]->price == 1000);

    // Cleanup
    destroySrvOffer(&srv);
}

void test_updateOfferSrv()
{
    // Arrange
    OfferList list = createOfferList();
    srvOffer* srv = createSrvOffer(list);

    int result3 = updateOfferSrv(srv, 1, "munte", "Brasov", "01-06-2023", 500);
    assert(result3 == 1); // Expect the function to return 1 (failure)

    int id = 1;
    char type[] = "mare";
    char destination[] = "Thasos";
    char departureDate[] = "01-05-2023";
    int price = 1000;
    addOfferSrv(srv, id, type, destination, departureDate, price);

    // Act
    int result2 = updateOfferSrv(srv, id, "munte", "Brasov", "01-06-2023", -500);
    int result = updateOfferSrv(srv, id, "munte", "Brasov", "01-06-2023", 500);

    // Assert
    assert(result2 == 1); // Expect the function to return 1 (failure)

    assert(result == 0); // Expect the function to return 0 (success)
    assert(srv->lista.length == 1); // Expect the list to have one offer
    assert(srv->lista.offers[0]->id == id);
    assert(strcmp(srv->lista.offers[0]->type, "munte") == 0);
    assert(strcmp(srv->lista.offers[0]->destination, "Brasov") == 0);
    assert(strcmp(srv->lista.offers[0]->departureDate, "01-06-2023") == 0);
    assert(srv->lista.offers[0]->price == 500);

    // Cleanup
    destroySrvOffer(&srv);
}

void test_deleteOfferSrv()
{
    // Arrange
    OfferList list = createOfferList();
    srvOffer* srv = createSrvOffer(list);

    int result1 = deleteOfferSrv(srv, 1);
    assert(result1 == 1); // Expect the function to return 1 (failure)

    int id = 1;
    char type[] = "munte";
    char destination[] = "Alpi";
    char departureDate[] = "01-05-2023";
    int price = 1000;
    addOfferSrv(srv, id, type, destination, departureDate, price);
    addOfferSrv(srv, 2, "mare", "Mamaia", "01-06-2023", 500);

    // Act
    int result = deleteOfferSrv(srv, id);

    // Assert
    assert(result == 0); // Expect the function to return 0 (success)
    assert(srv->lista.length == 1); // Expect the list to have one offer left

    // Check that the offer with ID 1 is no longer in the service
    int l = getLengthList(&srv->lista);
    for (int i = 0; i < l; i++)
    {
        Offer off = getOfferIndex(&srv->lista, i);
        assert(get_id(off) != id);
        destroyOffer(&off);
    }

    // Cleanup
    destroySrvOffer(&srv);
}

void test_sortOfferbyPrice()
{
    // Arrange
    OfferList list = createOfferList();
    srvOffer* srv = createSrvOffer(list);

    addOfferSrv(srv, 1, "mare", "Thasos", "01-05-2023", 1000);
    addOfferSrv(srv, 2, "mare", "Mamaia", "01-06-2023", 2000);
    addOfferSrv(srv, 3, "munte", "Brasov", "01-07-2023", 1500);

    // Act
    sortOfferbyPrice(srv);

    // Assert
    assert(srv->lista.offers[0]->id == 1);
    assert(strcmp(srv->lista.offers[0]->type, "mare") == 0);
    assert(strcmp(srv->lista.offers[0]->destination, "Thasos") == 0);
    assert(strcmp(srv->lista.offers[0]->departureDate, "01-05-2023") == 0);
    assert(srv->lista.offers[0]->price == 1000);

    assert(srv->lista.offers[1]->id == 3);
    assert(strcmp(srv->lista.offers[1]->type, "munte") == 0);
    assert(strcmp(srv->lista.offers[1]->destination, "Brasov") == 0);
    assert(strcmp(srv->lista.offers[1]->departureDate, "01-07-2023") == 0);
    assert(srv->lista.offers[1]->price == 1500);

    assert(srv->lista.offers[2]->id == 2);
    assert(strcmp(srv->lista.offers[2]->type, "mare") == 0);
    assert(strcmp(srv->lista.offers[2]->destination, "Mamaia") == 0);
    assert(strcmp(srv->lista.offers[2]->departureDate, "01-06-2023") == 0);
    assert(srv->lista.offers[2]->price == 2000);

    // Cleanup
    destroySrvOffer(&srv);
}

void test_filterOfferbyType()
{
    // Arrange
    OfferList list = createOfferList();
    srvOffer* srv = createSrvOffer(list);

    addOfferSrv(srv, 1, "excursie", "Paris", "01-05-2023", 1000);
    addOfferSrv(srv, 2, "mare", "Mamaia", "01-06-2023", 2000);
    addOfferSrv(srv, 3, "excursie", "Berlin", "01-07-2023", 1500);

    // Act
    OfferList filtered = createOfferList();
    filterOfferbyType(srv, "excursie", &filtered);

    // Assert
    assert(filtered.length == 2);
    assert(filtered.offers[0]->id == 1);
    assert(strcmp(filtered.offers[0]->type, "excursie") == 0);
    assert(strcmp(filtered.offers[0]->destination, "Paris") == 0);
    assert(strcmp(filtered.offers[0]->departureDate, "01-05-2023") == 0);
    assert(filtered.offers[0]->price == 1000);

    assert(filtered.offers[1]->id == 3);
    assert(strcmp(filtered.offers[1]->type, "excursie") == 0);
    assert(strcmp(filtered.offers[1]->destination, "Berlin") == 0);
    assert(strcmp(filtered.offers[1]->departureDate, "01-07-2023") == 0);
    assert(filtered.offers[1]->price == 1500);

    // Cleanup
    destroyOffer(filtered.offers[0]);
    destroyOffer(filtered.offers[1]);
    free(filtered.offers);
    destroySrvOffer(&srv);
}

void test_filterOfferbyDestination()
{
    // Arrange
    OfferList list = createOfferList();
    srvOffer* srv = createSrvOffer(list);

    addOfferSrv(srv, 1, "excursie", "Paris", "01-05-2023", 1000);
    addOfferSrv(srv, 2, "mare", "Mamaia", "01-06-2023", 2000);
    addOfferSrv(srv, 3, "excursie", "Berlin", "01-07-2023", 1500);

    // Act
    OfferList filtered = createOfferList();
    filterOfferByDestination(srv, "Paris", &filtered);

    // Assert
    assert(filtered.length == 1);
    assert(filtered.offers[0]->id == 1);
    assert(strcmp(filtered.offers[0]->type, "excursie") == 0);
    assert(strcmp(filtered.offers[0]->destination, "Paris") == 0);
    assert(strcmp(filtered.offers[0]->departureDate, "01-05-2023") == 0);
    assert(filtered.offers[0]->price == 1000);

    // Cleanup
    destroyOffer(filtered.offers[0]);
    free(filtered.offers);
    destroySrvOffer(&srv);
}

void test_filterOfferByPrice()
{
    // Arrange
    OfferList list = createOfferList();
    srvOffer* srv = createSrvOffer(list);

    addOfferSrv(srv, 1, "excursie", "Paris", "01-05-2023", 1000);
    addOfferSrv(srv, 2, "mare", "Mamaia", "01-06-2023", 2000);
    addOfferSrv(srv, 3, "excursie", "Berlin", "01-07-2023", 1500);

    // Act
    OfferList filtered = createOfferList();
    filterOfferByPrice(srv, 1500, &filtered);



    // Assert
    assert(filtered.length == 2);
    assert(filtered.offers[0]->id == 1);
    assert(strcmp(filtered.offers[0]->type, "excursie") == 0);
    assert(strcmp(filtered.offers[0]->destination, "Paris") == 0);
    assert(strcmp(filtered.offers[0]->departureDate, "01-05-2023") == 0);
    assert(filtered.offers[0]->price == 1000);

    assert(filtered.offers[1]->id == 3);
    assert(strcmp(filtered.offers[1]->type, "excursie") == 0);
    assert(strcmp(filtered.offers[1]->destination, "Berlin") == 0);
    assert(strcmp(filtered.offers[1]->departureDate, "01-07-2023") == 0);
    assert(filtered.offers[1]->price == 1500);

    // Cleanup
    destroyOffer(filtered.offers[0]);
    destroyOffer(filtered.offers[1]);
    free(filtered.offers);
    destroySrvOffer(&srv);
}

void test_destroySrvOffer()
{
    // Arrange
    OfferList list = createOfferList();
    srvOffer* srv = createSrvOffer(list);

    addOfferSrv(srv, 1, "excursie", "Paris", "01-05-2023", 1000);
    addOfferSrv(srv, 2, "mare", "Mamaia", "01-06-2023", 2000);
    addOfferSrv(srv, 3, "excursie", "Berlin", "01-07-2023", 1500);

    // Act
    destroySrvOffer(&srv);
}

void run_all_tests()
{
    test_createOffer();
    test_validator();
    test_get_id();
    test_get_type();
    test_get_destination();
    test_get_departureDate();
    test_get_price();
    test_destroyOffer();
    test_createOfferList();
    test_addOffer();
    test_updateOffer();
    test_deleteOffer();
    test_getOfferIndex();
    test_getLengthList();
    test_createSrvOffer();
    test_compare();
    test_sort();
    test_addOfferSrv();
    test_updateOfferSrv();
    test_deleteOfferSrv();
    test_sortOfferbyPrice();
    test_filterOfferbyType();
    test_filterOfferbyDestination();
    test_filterOfferByPrice();
    test_destroySrvOffer();
}