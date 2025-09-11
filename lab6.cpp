//COMSC 210 | Lab 6 | Anisha Rayapudi
//IDE used: VS 2022

#include <iostream>
using namespace std;

const int SIZE = 5;

//function prototypes
void enterArrayData(double * arr, const int size);
void outputArrayData(double * arr, const int size);
double sumArray(double * arr, const int size);

int main () {
    //initializing pointer
    double * arr = nullptr;
    arr = new double[SIZE];

    enterArrayData(arr, SIZE);

    cout << "Outputting array elements: ";
    outputArrayData(arr, SIZE);
    cout << endl;

    cout << "Sum of values: " << sumArray(arr, SIZE);

}
// gets user input of double elements
//arguments: double * arr (pointer to the array) and const int size
// return: none
void enterArrayData(double * arr, const int size){
    cout << "Data entry for the array: \n";
    for (int i = 0; i < size; i++) {
        cout << " > Element #" << i+1 << ": ";
        cin >> *(arr+i);
    }
    cout << "Data entry complete." << endl;
}

// outputs double elements
//arguments: double * arr (pointer to the array) and const int size
// return: none
void outputArrayData(double * arr, const int size){
    for (int i = 0; i < size; i++) {
        cout << *(arr+i) << " ";
    }
}

// totals sum of the elements
//arguments: double * arr (pointer to the array) and const int size
// return: sum
double sumArray (double * arr, const int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++){
        sum += *(arr+i);
    }
    return sum;
}