#include <iostream>
#include <string>
using namespace std;

struct Country {
    string name;
    double flightPrice;
    int duration;
    string*favSights;

    ~Country(){
        if (favSights)
            delete[] favSights;
            favSights= nullptr;
        }
    };

void getCountry(Country* cptr, int num);
void displayCountry(Country* cptr, int num);

int main (){
    
}
