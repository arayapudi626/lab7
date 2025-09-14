#include <iostream>

using namespace std;
const int SIZE = 5;

string*reverseArray(string * arr, const int size);
void displayArray(string * arr, const int size);

int main (){

}

string*reverseArray(string * arr, const int size){


}

void displayArray(string * arr, const int size){
    for (int i =0; i < size; i++){
        cout << *(arr + i) << " ";
    }
    cout << endl;
}