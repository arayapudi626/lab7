//COMSC-210 | Lab 3A | Anisha Rayapudi
//IDE used: Visual Studio Code
//Defining a Restaurant struct, get input about restaurant information,
//print in format and create four objects


#include <iostream>
#include <string>

using namespace std;

//function prototypes
struct Restaurant;
Restaurant getInfo();
void printInfo(const Restaurant& r);

struct Restaurant {
    string name;
    string address;
    double starRating;
    string cuisine;
    string hours;
};

//gets user input of restaurant information
//argument: none
//returns: returns the restaurant object for user input
Restaurant getInfo() {
    Restaurant r;

    cout << "Name of restaurant: ";
    getline(cin, r.name);

    cout << "Address: ";
    getline(cin, r.address);

    cout << "Star rating: ";
    cin >> r.starRating;
    cin.ignore();

    cout << "Restaurant cuisine: ";
    getline(cin, r.cuisine);

    cout <<"Restaurant hours: ";
    getline(cin, r.hours);

    return r;
}

//formats user info about restaurant
//argument: const Restaurant& r
//return: none
void printInfo(const Restaurant& r){
    cout << r.name << " (" << r.cuisine << ")\n";
    cout << "Located on: " << r.address << "\n";
    cout << r.starRating <<" out of 5 stars\n";
    cout << "Open from " << r.hours << "\n";
}

int main() {
    cout << "Enter first restaurant information\n";
    Restaurant one = getInfo();

    cout << "Enter second restaurant information\n";
    Restaurant two = getInfo();

    cout << "Enter third restaurant information\n";
    Restaurant three = getInfo();

    cout << "Enter fourth restaurant information\n";
    Restaurant fourth = getInfo();

    cout << "Here is your list of restaurants: \n";
    cout << "Restaurant 1: \n";
    printInfo(one);
    cout << "Restaurant 2: \n";
    printInfo(two);
    cout << "Restaurant 3: \n";
    printInfo(three);
    cout << "Restaurant 4: \n";
    printInfo(fourth);
    


    return 0;
}