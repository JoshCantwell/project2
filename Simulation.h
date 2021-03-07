#ifndef _simulation_h_
#define _simulation_h_
#include "Heap.h"
class Simulation {

    public:




        Heap * heap = new Heap();
        
        int getArrivalsToSimulate();
        int getAverageArrivals();
        int getAverageNumberServed();
        int getNumberOfChannels();
        int getServerAvailableCount();
        
        void setServerAvailableCount(int serversAvailable);
        void decServerAvailableCount();
        void incServerAvailableCount();
        void incArrivalCount();

        void processNextEvent();
        void setArrivalsToSimulate(int arrivals);
        void setAverageArrivals(int averageArrivals);
        void setAverageNumberServed(int averageNumberServed);
        void setNumberOfChannels(int numberOfChannels);

        void runSimulation();
        float getRandomInterval(int avg);
       
    private:

    
        std::vector <Customer> FIFO;
        int serversAvailable;
        int arrivalsToSimulate;
        int averageArrivals;
        int averageNumberServed;
        int numberOfChannels;

        int arrivalCount = 0;

};

#endif
