#include <iostream>
#include "Customer.h"
#include "Heap.h"
#include "Simulation.h"
#include <cstdlib>
#include <math.h>

float getRandomInterval();
int main() {

    Simulation * sim = new Simulation();
    sim->runSimulation();
    /*long double runningTime = 0;

    Heap *heap = new Heap();


     std::cout << heap->isEmpty() << std::endl;
    for(int i= 0; i <10; i++) {


    
        runningTime += getRandomInterval();
        Customer* cust = new Customer();
        cust->setArrivalTime(runningTime);

        heap->insertpq(cust);

        delete cust;
    }

    
    std::cout << heap->isEmpty() << std::endl;

    heap->showpq();

    std::cout << heap->isEmpty() << std::endl;
*/
}



// -----------functions main----------------



float getRandomInterval() {

    int max = 10000;
    float denom = 10000.0;
 
    float random =  (rand()%max)/denom;
    float interval = -1 * (1.0/3) * log(random);

    return interval;

}


