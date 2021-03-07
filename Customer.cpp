#include "Customer.h"

void Customer::setArrivalTime(float arrivalTime) {

    this->arrivalTime = arrivalTime;

}

void Customer::setStartOfServiceTime(float serviceTime) {

    this->startOfServiceTime = startOfServiceTime;

}

void Customer::setDepartureTime(float departureTime) {

    this->departureTime = departureTime;
}

void Customer::setNextCustomer(Customer *nextCust) {

    this->nextCust = nextCust;

}
void Customer::setHasBeenHelped() {

    this->helped = 1;
}
float Customer::getArrivalTime() {

    return arrivalTime;
}

float Customer::getStartOfServiceTime() {

    return startOfServiceTime;

}

float Customer::getDepartureTime() {

    return departureTime;

}

bool Customer::getHasBeenHelped() {

    return helped;

}

Customer* Customer::getNextCustomer() {

    return nextCust;

}
