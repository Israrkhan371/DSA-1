#include <iostream>
#include <string>
using namespace std;

class House {
private:
    string owner;
    string address;
    int bedrooms;
    float price;

public:
    House();
    void readInput();
    void display() const;
    string getOwner() const;
    string getAddress() const;
    int getBedrooms() const;
    float getPrice() const;
};
