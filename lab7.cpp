//COMSC 210 | Lab 7 | Anisha Rayapudi
//IDE used: VS 2022

#include <iostream>

using namespace std;
const int SIZE = 5;

string*reverseArray(string * arr, const int size);
void displayArray(string * arr, const int size);

int main (){
    string * names = nullptr;
    names = new string[SIZE];
    *(names + 0) = "Janet";
    *(names + 1) = "Jeffe";
    *(names + 2) = "Jin";
    *(names + 3) = "Joe";
    *(names + 4) = "Junio";

    cout << "Original array: ";
    displayArray(names, SIZE);
    names = reverseArray(names,SIZE);
    cout << "Reversed array: ";
    displayArray(names, SIZE);

    return 0;
}
//reverses the array of names
//argument: pointer to array elements string and const int size
//returns: pointer to modified array
string*reverseArray(string * arr, const int size){
    for (int i = 0; i < size/2; i++){
        string temp = *(arr + i);
        *(arr + i) = *(arr+(size - 1 - i));
        *(arr + (size - 1 - i)) = temp;
    }
    return arr;
}

//displays the array of names
//argument: pointer to array elements string and const int size
//returns: none
void displayArray(string * arr, const int size){
    for (int i =0; i < size; i++){
        cout << *(arr + i) << " ";
    }
    cout << endl;
}