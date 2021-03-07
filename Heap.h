#ifndef _HEAP_H_
#define _HEAP_H_

#include <queue>
#include <vector>
#include "Customer.h"

class Heap {

    public:

        int pqSize();

        bool isEmpty();
        bool pqEmpty();

        Customer getNextCustomer();
        //void addCustomerToFIFO(Customer cust);
        //Customer getCustomerFromFIFO();
        
        void showpq();
        void insertpq(Customer cust);
        void insertpq(Customer *cust);
    private:



        //std::vector <Customer> FIFO;
        struct CustomerComp {

            bool operator()( Customer& c1,  Customer& c2)  {

                
                    return c1.getArrivalTime() > c2.getArrivalTime();
            }

        };
        std::priority_queue<Customer , std::vector<Customer>, CustomerComp> customers;

};

#endif
