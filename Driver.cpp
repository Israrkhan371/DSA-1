#include "House.h"
#include <iostream>
using namespace std;

int main() {
    House available[100];  
    int count = 0;         
    char another = 'Y';    

    while (another == 'Y' || another == 'y') {
        cout << "Entering house " << count + 1 << endl;
        available[count].readInput();  
        count++;

        cout << "Enter another house? (Y/N): ";
        cin >> another;
        cin.ignore();  

        cout << "\nCurrent houses available:\n";
        cout << "Owner\tAddress\t\tBedrooms\tPrice" << endl;
        for (int i = 0; i < count; i++) {
            available[i].display();  
        }
        cout << endl;
    }

    char want;
    cout << "Do you want to search for a house? (Y/N): ";
    cin >> want;

    if (want == 'Y' || want == 'y') {

        char searchOption;
        cout << "\nChoose search option:\n";
        cout << "1. Search by price\n2. Search by number of bedrooms\n3. Find house with lowest price\n";
        cout << "4. Find largest house\n5. Search by city\n6. Find best price per bedroom ratio\n";
        cin >> searchOption;

        if (searchOption == '1') {
            float maxPrice;
            cout << "Enter maximum price: ";
            cin >> maxPrice;

            cout << "\nHouses with price <= " << maxPrice << ":\n";
            cout << "\nOwner\tAddress\t\tBedrooms\tPrice" << endl;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (available[i].getPrice() <= maxPrice) {
                    available[i].display(); 
                    found = true;
                }
            }

            if (!found) {
                cout << "No houses found matching the price criteria." << endl;
            }
        }
        else if (searchOption == '2') {
            int minBedrooms;
            cout << "Enter minimum number of bedrooms: ";
            cin >> minBedrooms;

            cout << "\nHouses with at least " << minBedrooms << " bedrooms:\n";
            cout << "\nOwner\tAddress\t\tBedrooms\tPrice" << endl;

            bool found = false; 
            for (int i = 0; i < count; i++) {
                if (available[i].getBedrooms() >= minBedrooms) {
                    available[i].display();
                    found = true;
                }
            }

            if (!found) {
                cout << "No houses found matching the bedrooms criteria." << endl;
            }
        }
        else if (searchOption == '3') {
            if (count == 0) {
                cout << "No houses available." << endl;
                return 0;
            }

            int minIndex = 0;
            for (int i = 1; i < count; i++) {
                if (available[i].getPrice() < available[minIndex].getPrice()) {
                    minIndex = i;
                }
            }

            cout << "\nHouse with lowest price:\n";
            cout << "\nOwner\tAddress\t\tBedrooms\tPrice" << endl;
            available[minIndex].display();
        }
        else if (searchOption == '4') {
            if (count == 0) {
                cout << "No houses available." << endl;
                return 0;
            }

            int maxIndex = 0;
            for (int i = 1; i < count; i++) {
                if (available[i].getBedrooms() > available[maxIndex].getBedrooms()) {
                    maxIndex = i;
                }
            }

            cout << "\nLargest house:\n";
            cout << "\nOwner\tAddress\t\tBedrooms\tPrice" << endl;
            available[maxIndex].display();
        }
        else if (searchOption == '5') {
            string city;
            cout << "Enter city: ";
            cin >> city;

            cout << "\nHouses in " << city << ":\n";
            cout << "\nOwner\tAddress\t\tBedrooms\tPrice" << endl;

            bool found = false;  // Flag to check if any house matches the criteria
            for (int i = 0; i < count; i++) {
                if (available[i].getAddress().find(city) != string::npos) {
                    available[i].display();
                    found = true;
                }
            }

            if (!found) {
                cout << "No houses found in " << city << "." << endl;
            }
        }
        else if (searchOption == '6') {
            if (count == 0) {
                cout << "No houses available." << endl;
                return 0;
            }

            int bestIndex = 0;
            float bestRatio = available[0].getPrice() / available[0].getBedrooms();

            for (int i = 1; i < count; i++) {
                float ratio = available[i].getPrice() / available[i].getBedrooms();
                if (ratio < bestRatio) {
                    bestRatio = ratio;
                    bestIndex = i;
                }
            }

            cout << "\nHouse with best price per bedroom ratio:\n";
            cout << "\nOwner\tAddress\t\tBedrooms\tPrice" << endl;
            available[bestIndex].display();
        }
        else {
            cout << "Invalid option" << endl;
        }
    }
    else {
        cout << "No search selected.\n";
    }

    return 0;
}
