#include <iostream>
#include <stdexcept>
#include <string>
#include "anisha_rayapudi_Array.h"
using namespace std;
int main()
{
    Array<int>intArray(5) ; 
    Array<string> strArray(5); 

    cout<<"Enter "<<intArray.getSize()<<" integer values: "<<endl;
    cin>>intArray; 
    cout<<endl<<"The values in the integer Array are:"<<endl<<intArray;
    cout<<endl<<"Enter "<<strArray.getSize()<<" string values: "<<endl;
    cin.ignore(100,'\n'); 
    for(int i=0;i<strArray.getSize();i++)
    {
        getline(cin,strArray[i]);
    }
    cout<<endl<<"The values in the string Array are: "<<endl<<strArray;

    return 0;
}

 