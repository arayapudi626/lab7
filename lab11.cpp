#include <iostream>
#include <string>
using namespace std;

const int COUNTRIES = 3;

struct Country {
    string name;
    double flightPrice;
    int duration;
    string*favSights;
    int numSights;

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

void getCountry(Country* cptr, int num){
    cout << "Country #" << num << "\n";
    cout << "Name: ";
    getline(cin, cptr->name);
    cout << "Flight price from US: ";
    cin >> cptr->flightPrice;
    cout << "Duration in days: ";
    cin >> cptr->duration;
    cout <<"How many favorite sights? ";
    cin >> cptr->numSights;

    cptr -> favSights = new string[cptr->numSights];
    for (int i = 0; i < cptr->numSights; i++){
        cout <<"Favorite sight #"<<(i+1)<<": ";
        getline(cin, *(cptr->favSights+i));
    }
    }

