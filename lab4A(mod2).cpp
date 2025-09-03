//COMSC 210 | Lab 4A | Anisha Rayapudi
//IDE used: Visual Studio
//This program generates random number between 25-50 of structs,
//pushes into vector and prints color values in formatted table

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Color {
    int red;
    int green;
    int blue;
};

int main (){
    //generate random number between 25 and 50
    srand(static_cast<unsigned>(time(0)));
    int n = rand()%26 + 25;

    vector<Color> colors;

    // store colors vector with n random colors
    for (int i = 0; i < n; i++){
        Color temp;
        temp.red = rand() % 256;
        temp.green = rand() % 256;
        temp.blue = rand() % 256;
        colors.push_back(temp);
    }
    // table with color values
    cout << left << setw(8) << "Color#"
    << setw(8) << "R value"
    << setw(8) << "G value" 
    << setw(8) << "B value" << "\n";

    for (int j = 0; j < 4; j++){
        cout << setw(8) << string(6,'-');
    }
    cout << "\n";
    
    for (int i = 0; i < colors.size(); i++){
        cout << left << setw(8) << (i+1) << setw(8) << colors[i].red
        << setw(8) << colors[i].green << setw(8) << colors[i].blue << "\n";
    }
    return 0;
}