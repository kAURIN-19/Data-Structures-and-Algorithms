#include <iostream>

#include <queue>

#include <string>

#include <thread>

#include <chrono>

#include <atomic>

#include <sstream>

 

using namespace std;

 

class Person {

public:

    string fullName;

    int reservationID;

 

    Person(string name, int id) : fullName(name), reservationID(id) {}

};

 

class Queue {

private:

    queue<Person> personQueue;

    int reservationCounter;

 

public:

    Queue() : reservationCounter(1) {}

 

    void addPerson(const string& name) {

        personQueue.push(Person(name, reservationCounter++));

        cout << name << " has been added to the reservation list with ID #" << reservationCounter - 1 << endl;

        cout << "Current queue size: " << personQueue.size() << endl;

    }

 

    void processReservation() {

        if (!personQueue.empty()) {

            Person person = personQueue.front();

            cout << "Processing reservation for: " << person.fullName << " (ID #" << person.reservationID << ")" << endl;

            personQueue.pop();

            cout << "Current queue size: " << personQueue.size() << endl;

 

            if (!personQueue.empty()) {

                Person nextPerson = personQueue.front();

                cout << "Next in line: " << nextPerson.fullName << " (ID #" << nextPerson.reservationID << ")" << endl;

            } else {

                cout << "No more reservations in line." << endl;

            }

        } else {

            cout << "The reservation queue is empty!" << endl;

        }

    }

 

    int getQueueCount() const {

        return personQueue.size();

    }

 

    void checkPersonPosition(const string& identifier) {

        queue<Person> tempQueue = personQueue;

        int position = 1;

 

        while (!tempQueue.empty()) {

            Person person = tempQueue.front();

            tempQueue.pop();

 

            if (person.fullName == identifier || to_string(person.reservationID) == identifier) {

                cout << person.fullName << " is currently at position " << position << " in the reservation list." << endl;

                return;

            }

            position++;

        }

 

        cout << "No person found with the name or ID: " << identifier << endl;

    }

 

    void displayQueue() const {

        queue<Person> tempQueue = personQueue;

        cout << "Current reservation list: ";

        if (tempQueue.empty()) {

            cout << "No persons in the queue." << endl;

            return;

        }

        while (!tempQueue.empty()) {

            Person person = tempQueue.front();

            tempQueue.pop();

            cout << person.fullName << " (ID #" << person.reservationID << ") ";

        }

        cout << endl;

    }

};

 

void reservationProcessing(Queue& queue, atomic<bool>& active) {

    while (active) {

        this_thread::sleep_for(chrono::minutes(1));

        queue.processReservation();

    }

}
