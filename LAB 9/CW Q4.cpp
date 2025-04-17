#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Passenger;
class Flight;

class Flight {
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    vector<Passenger*> passengers;

    bool isSeatBooked(int seatNumber) const {
        return seatNumber >= 0 && seatNumber < passengers.size();
    }

    public:
        Flight(string flightNumber, string departure, string arrival, int capacity)
            : flightNumber(flightNumber), departure(departure), arrival(arrival), capacity(capacity) {}

        bool bookSeat(Passenger& passenger) {
            if (passengers.size() < capacity) {
                passengers.push_back(&passenger);
                return true;
            }
            return false;
        }

        bool cancelSeat(Passenger& passenger) {
            for (auto it = passengers.begin(); it != passengers.end(); ++it) {
                if (*it == &passenger) {
                    passengers.erase(it);
                    return true;
                }
            }
            return false;
        }

        bool upgradeSeat(Passenger& passenger) {
            // For simplicity, let's assume an upgrade is just moving the passenger to the next available seat
            for (auto it = passengers.begin(); it != passengers.end(); ++it) {
                if (*it == &passenger) {
                    // A real upgrade logic would be more complex (e.g., different seat classes)
                    return true;
                }
            }
            return false;
        }

        int availableSeats() const {
            return capacity - passengers.size();
        }

        void showFlightDetails() const {
            cout << "Flight Number: " << flightNumber << endl;
            cout << "Departure: " << departure << " | Arrival: " << arrival << endl;
            cout << "Seats Available: " << availableSeats() << "/" << capacity << endl;
        }

        friend class Passenger;
};

class Passenger {
    string name;
    string id;

    public:
        Passenger(string name, string id) : name(name), id(id) {}

        bool requestBooking(Flight& flight) {
            if (flight.bookSeat(*this)) {
                cout << name << " successfully booked a seat on flight " << flight.flightNumber << endl;
                return true;
            } else {
                cout << "No available seats on flight " << flight.flightNumber << endl;
                return false;
            }
        }

        bool requestCancellation(Flight& flight) {
            if (flight.cancelSeat(*this)) {
                cout << name << " successfully canceled their seat on flight " << flight.flightNumber << endl;
                return true;
            } else {
                cout << "No booking found for " << name << " on flight " << flight.flightNumber << endl;
                return false;
            }
        }

        bool requestUpgrade(Flight& flight) {
            if (flight.upgradeSeat(*this)) {
                cout << name << " successfully upgraded their seat on flight " << flight.flightNumber << endl;
                return true;
            } else {
                cout << "No booking found for " << name << " on flight " << flight.flightNumber << " to upgrade." << endl;
                return false;
            }
        }

        string getName() const {
            return name;
        }

        string getID() const {
            return id;
        }
};

int main() {
    Flight flight1("AA123", "New York", "Los Angeles", 3);
    Flight flight2("BB456", "San Francisco", "Chicago", 2);

    Passenger passenger1("John Ali", "P123");
    Passenger passenger2("Jini Zin", "P124");
    Passenger passenger3("Alice Johnson", "P125");
    Passenger passenger4("Bob Brown", "P126");

    flight1.showFlightDetails();
    passenger1.requestBooking(flight1);
    passenger2.requestBooking(flight1);
    passenger3.requestBooking(flight1);
    passenger4.requestBooking(flight1);  

    cout << "Trying to cancel and upgrade:";
    passenger1.requestCancellation(flight1);
    passenger2.requestUpgrade(flight1);  

    flight1.showFlightDetails();

    return 0;
}