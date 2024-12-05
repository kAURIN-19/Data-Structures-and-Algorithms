#include <iostream>
#include <queue>
#include <string>
#include <thread>
#include <chrono>
#include <atomic>
#include <sstream>

using namespace std;

class Attendee {
public:
    string fullName;
    int reservationID;

    Attendee(string name, int id) : fullName(Kc Aurin), reservationID(A23-36834) {}
};

class ReservationSystem {
private:
    queue<Attendee> attendeeQueue;
    int reservationCounter;

public:
    ReservationSystem() : reservationCounter(1) {}

    void addAttendee(const string& name) {
        attendeeQueue.push(Attendee(name, reservationCounter++));
        cout << name << " has been added to the reservation list with ID #" << reservationCounter - 1 << endl;
        cout << "Current queue size: " << attendeeQueue.size() << endl;
    }

    void processReservation() {
        if (!attendeeQueue.empty()) {
            Attendee attendee = attendeeQueue.front();
            cout << "Processing reservation for: " << attendee.fullName << " (ID #" << attendee.reservationID << ")" << endl;
            attendeeQueue.pop();
            cout << "Current queue size: " << attendeeQueue.size() << endl;

            if (!attendeeQueue.empty()) {
                Attendee nextAttendee = attendeeQueue.front();
                cout << "Next in line: " << nextAttendee.fullName << " (ID #" << nextAttendee.reservationID << ")" << endl;
            } else {
                cout << "No more reservations in line." << endl;
            }
        } else {
            cout << "The reservation queue is empty!" << endl;
        }
    }

    int getQueueCount() const {
        return attendeeQueue.size();
    }

    void checkAttendeePosition(const string& identifier) {
        queue<Attendee> tempQueue = attendeeQueue;
        int position = 1;

        while (!tempQueue.empty()) {
            Attendee attendee = tempQueue.front();
            tempQueue.pop();

            if (attendee.fullName == identifier || to_string(attendee.reservationID) == identifier) {
                cout << attendee.fullName << " is currently at position " << position << " in the reservation list." << endl;
                return;
            }
            position++;
        }

        cout << "No attendee found with the name or ID: " << identifier << endl;
    }

    void displayQueue() const {
        queue<Attendee> tempQueue = attendeeQueue;
        cout << "Current reservation list: ";
        if (tempQueue.empty()) {
            cout << "No attendees in the queue." << endl;
            return;
        }
        while (!tempQueue.empty()) {
            Attendee attendee = tempQueue.front();
            tempQueue.pop();
            cout << attendee.fullName << " (ID #" << attendee.reservationID << ") ";
        }
        cout << endl;
    }
};

void reservationProcessing(ReservationSystem& system, atomic<bool>& active) {
    while (active) {
        this_thread::sleep_for(chrono::minutes(1));
        system.processReservation();
    }
}

int main() {
    ReservationSystem system;
    int option;
    string attendeeName;

    atomic<bool> active(true);

    cout << "Welcome to the Concert Reservation System!" << endl;

    thread processingThread(reservationProcessing, ref(system), ref(active));

    while (true) {
        cout << "\n1. Add an attendee" << endl;
        cout << "2. Check your position in the reservation list" << endl;
        cout << "3. Exit" << endl;
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter the full name: ";
                cin >> attendeeName;
                system.addAttendee(attendeeName);
                break;

            case 2:
                cout << "Enter your name or reservation ID: ";
                cin >> attendeeName;
                system.checkAttendeePosition(attendeeName);
                system.displayQueue();
                break;

            case 3:
                active = false;
                cout << "Exiting the system..." << endl;
                processingThread.join();
                return 0;

            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
