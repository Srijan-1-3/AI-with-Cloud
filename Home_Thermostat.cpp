#include <iostream>
using namespace std;
int main() {
   float currentTemp;
   float desiredTemp;
   char mode;
   // Get current temperature from sensor
   cout << "Enter current temperature: ";
   cin >> currentTemp;
   // Get desired temperature from user
   cout << "Enter desired temperature: ";
   cin >> desiredTemp;
   // Determine whether to heat or cool
   if (currentTemp < desiredTemp) {
       mode = 'H'; // Heat
   } else if (currentTemp > desiredTemp) {
       mode = 'C'; // Cool
   } else {
       mode = 'N'; // No action needed
   }
   // Display mode and take action
   switch (mode) {
       case 'H':
           cout << "Heating...\n";
           // Code to turn on heating system goes here
           break;
       case 'C':
           cout << "Cooling...\n";
           // Code to turn on cooling system goes here
           break;
       case 'N':
           cout << "No action needed.\n";
           // Code to turn off heating and cooling systems goes here
           break;
       default:
           cout << "Invalid mode.\n";
           break;
   }
   return 0;
}
