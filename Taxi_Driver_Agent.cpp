#include <iostream>
using namespace std;

class TaxiDriver {
    private:
        string name;
        int currentLocation;
        int passengerDestination;
        bool isAvailable;

    public:
        TaxiDriver(string n, int l) {
            name = n;
            currentLocation = l;
            isAvailable = true;
        }

        void pickupPassenger(int dest) {
            passengerDestination = dest;
            isAvailable = false;
        }

        void dropOffPassenger() {
            currentLocation = passengerDestination;
            isAvailable = true;
        }

        void printStatus() {
            cout << "Taxi driver " << name << " is currently at location " << currentLocation << "." << endl;
            if (isAvailable) {
                cout << "Taxi driver " << name << " is available for pickup." << endl;
            } else {
                cout << "Taxi driver " << name << " has a passenger with a destination of " << passengerDestination << "." << endl;
            }
        }
};

int main() {
    TaxiDriver driver1("John", 1);
    driver1.printStatus();

    driver1.pickupPassenger(5);
    driver1.printStatus();

    driver1.dropOffPassenger();
    driver1.printStatus();

    return 0;
}
