#include "Heap.h"
#include "Simulation.h"
#include "Customer.h"
#include <iostream>

int Heap::pqSize() {

    return customers.size();
}

void Heap::showpq() {

    while(!customers.empty()) {

        Customer cust =  customers.top();
        std::cout << cust.getArrivalTime() << std::endl;

        customers.pop();
    }

}

/*void Heap::addCustomerToFIFO(Customer cust) {

    Customer *customer = cust;
    FIFO.insert(customer);
}
*/
bool Heap::isEmpty() {

    if(customers.size() == 0)
        return 1;
    else {
        return 0;
    }
    
}

/*Customer Heap::getCustomerFromFIFO() {

    Customer cust = FIFO.back();
    FIFO.pop_back();
    return cust;

}*/
Customer Heap::getNextCustomer() {

    Customer cust = customers.top();
    customers.pop();

    return cust;
}
bool Heap::pqEmpty() {

    if(customers.empty() == 1) {
        return true;
    } else {

        return false;
    }

}
void Heap::insertpq(Customer cust) {
    customers.push(cust);
}
void Heap::insertpq(Customer* cust) {

    customers.push(*cust);
}
