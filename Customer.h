#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

class Customer {

    public:

        void setArrivalTime(float arrivalTime);
        void setStartOfServiceTime(float serviceTime);
        void setDepartureTime(float departureTime);
        void setNextCustomer(Customer* nextCust);

        void setHasBeenHelped();
        float getArrivalTime();
        float getStartOfServiceTime();
        float getDepartureTime();
       
        bool getHasBeenHelped();;

        Customer* getNextCustomer();


    private:


        float arrivalTime = 0;
        float startOfServiceTime = 0;
        float departureTime = 0;
        bool helped = 0;
        Customer * nextCust; // for linked FIFO

};


#endif
