#include "Simulation.h"
#include "Customer.h"
#include "Heap.h"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <vector>
void Simulation::runSimulation() {

    long double runningTime = 0;
    int Arrivals, AverageArrivals, AverageNumberServed, NumberOfChannels;

    std::cout << "Welcome to the the Service Simulation. Please select the values youd like to simulate." << std::endl;
    std::cout << "How many arrivals would you like to simulate (between 1000 and 5000): " << std::endl;
    std::cin >> Arrivals;
    setArrivalsToSimulate(Arrivals);
    
    std:: cout << "What is the average number of arrivals: " << std::endl;
    std::cin >> AverageArrivals;
    setAverageArrivals(AverageArrivals);

    std::cout << "What is the average number of customers served: " << std::endl;
    std::cin >> AverageNumberServed;
    setAverageNumberServed(AverageNumberServed);

    std::cout << "Number of channels open (between 1 and 10): " << std::endl;
    std::cin >> NumberOfChannels;
    setNumberOfChannels(NumberOfChannels);


    // Initial load for priority queue
    for(int i= 0; i < 200; i++) {
        runningTime += getRandomInterval(getAverageArrivals());
        Customer* cust = new Customer();
        cust->setArrivalTime(runningTime);
        heap->insertpq(cust);
        incArrivalCount();
    }

    setServerAvailableCount(NumberOfChannels);
    while(heap->pqEmpty() != 1) {

        processNextEvent(); 

        if(heap->pqSize() <= getNumberOfChannels() && arrivalCount < arrivalsToSimulate) {
            for(int i= 0; i < 200 || arrivalCount == arrivalsToSimulate; i++) {
                runningTime += getRandomInterval(getAverageArrivals());
                Customer* cust = new Customer();
                cust->setArrivalTime(runningTime);
                heap->insertpq(cust);
                incArrivalCount();
            }

        std::cout << arrivalCount << std::endl;
        }

        //ShowSimResults();
    }


}

int Simulation::getArrivalsToSimulate() {

    return arrivalsToSimulate;

}

int Simulation::getAverageArrivals() {
    return averageArrivals;

}

int Simulation::getAverageNumberServed() {

    return averageNumberServed;

}

int Simulation::getNumberOfChannels() {

    return numberOfChannels;
}

int Simulation::getServerAvailableCount() {
    return serversAvailable;
}

void Simulation::setServerAvailableCount(int serversAvailable) {
    this->serversAvailable = serversAvailable;

}

void Simulation::incArrivalCount() {
    ++arrivalCount;

}
void Simulation::decServerAvailableCount() {

    --serversAvailable;

}


void Simulation::incServerAvailableCount() {

    ++serversAvailable;

}


void Simulation::setArrivalsToSimulate(int arrivals) {

    this->arrivalsToSimulate = arrivals;

}

void Simulation::setAverageArrivals(int averageArrivals) {

    this->averageArrivals = averageArrivals;

}

void Simulation::setAverageNumberServed(int averageNumberServed) {

    this->averageNumberServed = averageNumberServed;

}

void Simulation::setNumberOfChannels(int numberOfChannels) {

    this->numberOfChannels = numberOfChannels;

}

void Simulation::processNextEvent() {

    Customer *customer = new Customer();
    Customer cust =  heap->getNextCustomer();
    if(cust.getHasBeenHelped() == 0) {

        if(getServerAvailableCount() > 0) {
          //switch departure time with arrival time due to the way pq works  new departuretime = arrivaltime; old arrival time will be placed in departure time. kind of confusing but its a quick fix
            decServerAvailableCount();
            cust.setStartOfServiceTime(cust.getArrivalTime());
            float interval = getRandomInterval(getAverageNumberServed());
            customer->setDepartureTime(cust.getArrivalTime()); //remember this is arrival time
            customer->setArrivalTime(cust.getArrivalTime() + interval); //now the departure time technically
            customer->setHasBeenHelped();
            heap->insertpq(customer);

        } else {
            FIFO.push_back(cust);
        }

        //delete customer;
    } else {

        incServerAvailableCount();
        
        //ProcessStatistics();
        if(FIFO.empty() != 1) {

            Customer FIFOcust = FIFO.back();
            Customer *FIFOcustomer = new Customer();
            
            FIFO.pop_back();
            FIFOcustomer->setStartOfServiceTime(cust.getArrivalTime()/*departuretime*/);
            float interval = getRandomInterval(getAverageNumberServed());
            FIFOcustomer->setArrivalTime(FIFOcust.getDepartureTime() + interval);
            heap->insertpq(FIFOcustomer);
            decServerAvailableCount();

        }


    }
   

}

float Simulation::getRandomInterval(int avg) {

    int max = 10000;
    float denom = 10000.0;
 
    float random =  (rand()%max)/denom;
    float interval = -1 * (1.0/avg) * log(random);

    return interval;

}


























