/*
 * BankSimApp.cpp
 *
 * Description: An event-driven Bank Simulation application.
 *
 * Author: Zhengxuan Song
 * Date: November 11, 2022
 */

#include <iostream>
#include "EmptyDataCollectionException.h"
#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"

using std::cout;
using std::endl;
using std::getline;
using std::cin;

int main() {
    unsigned int totalCustomer = 0;
    unsigned int totalArrivalTime = 0;
    unsigned int totalDepartureTime = 0;
    unsigned int totalLength = 0;
    double averageWait = 0;

    Queue<Event>* bankLine = new Queue<Event>();
    PriorityQueue<Event>* eventPriorityQueue = new PriorityQueue<Event>();

    bool tellerAvailable = true;

    // inserting customers into Priority Queue
    int num1, num2;
    while (cin >> num1 >> num2) {
        Event e('A', num1, num2);
        eventPriorityQueue->enqueue(e);
        totalCustomer++;    // calculate statistics
    }

    // test eventPriorityQueue order
//    while (!eventPriorityQueue->isEmpty()) {
//        cout << eventPriorityQueue->peek().getTime() << " " << eventPriorityQueue->peek().getLength()
//                << endl;
//        eventPriorityQueue->dequeue();
//    }

    cout << "Simulation Begins" << endl;

    // event loop
    while (!eventPriorityQueue->isEmpty()) {
        Event newEvent = eventPriorityQueue->peek();

        // get current time
        unsigned int currentTime = newEvent.getTime();

        // if new event is an arrival event
        if (newEvent.getType() == 'A') {

            /* Arrival Event */
            // remove this event from the event queue
            eventPriorityQueue->dequeue();

            // process the arrival event
            Event customer = newEvent;
            if (bankLine->isEmpty() && tellerAvailable) {
                unsigned int departureTime = currentTime + newEvent.getLength();
                Event newDepartureEvent('D', departureTime);
                eventPriorityQueue->enqueue(newDepartureEvent);
                tellerAvailable = false;
            } else {
                bankLine->enqueue(customer);

                // testing queue order
//                cout << "\tQueue: ";
//                bankLine->printQueue();
//                cout << endl;
            }

            // output prompt to terminal
            cout << "Processing an arrival event at time:    ";
            if (customer.getTime() < 10)
                cout << " ";
            cout << customer.getTime() << endl;

            // calculate statistics
            totalArrivalTime += customer.getTime();
            totalLength += customer.getLength();

        } else {

            /* Departure Event */
            // remove this event from the event queue
            eventPriorityQueue->dequeue();

            // process the departure event
            if (!bankLine->isEmpty()) {

                // customer at front of line begins transaction
                Event customer = bankLine->peek();

                bankLine->dequeue();
                int departureTime = currentTime + customer.getLength();
                Event newDepartureEvent('D', departureTime);

//                cout << "\tInsert " << newDepartureEvent.getType() << " "
//                        << newDepartureEvent.getTime() << " "
//                        << newDepartureEvent.getLength() << endl;

                eventPriorityQueue->enqueue(newDepartureEvent);
            } else {
                tellerAvailable = true;
            }

            // output prompt to terminal
            cout << "Processing a departure event at time:   ";
            if (currentTime < 10)
                cout << " ";
            cout << currentTime << endl;

            // calculate statistics
            totalDepartureTime += currentTime;
        }
    }

    cout << "Simulation Ends" << endl << endl;

    // final statistics
    averageWait = (double) (totalDepartureTime - totalLength - totalArrivalTime)
            / totalCustomer;

    cout << "Final Statistics:" << endl << endl;
    cout << "\tTotal number of people processed: " << totalCustomer << endl;
    cout << "\tAverage amount of time spent waiting: " << averageWait << endl;

    delete bankLine;
    delete eventPriorityQueue;

    return 0;
}
