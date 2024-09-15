#include "House.h"
#include <iostream>
using namespace std;

House::House() {
    owner = "";
    address = "";
    bedrooms = 0;
    price = 0.0;
}

void House::readInput() {
    cout << "Enter Owner: ";
    cin >> owner;

    cout << "Enter Address: ";
    cin >> address;

    cout << "Enter number of bedrooms : ";
    cin >> bedrooms;

    cout << "Enter price: ";
    cin >> price;

}

void House::display() const {
    cout << owner << "\t" << address << "\t\t" << bedrooms << "\t" << price << endl;
}

string House::getOwner() const {
    return owner;
}

string House::getAddress() const {
    return address;
}

int House::getBedrooms() const {
    return bedrooms;
}

float House::getPrice() const {
    return price;
}
