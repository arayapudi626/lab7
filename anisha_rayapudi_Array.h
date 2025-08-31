#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;


template <typename T>
class Array
{
private:
        size_t size; // pointer-based array size
        T *ptr = NULL; // pointer to first element of pointer-based array

      template <typename U>
     friend std::ostream &operator<<( std::ostream &, const Array<U> & );
      template <typename U>
     friend std::istream &operator>>( std::istream &, Array<U> & );

public:
      explicit  Array( size_t arraySize= 10); // default constructor
      Array( const Array<T> & ); // copy constructor
     ~Array(); // destructor
     size_t getSize() const; // return size

     const Array &operator=( const Array<T> & ); // assignment operator
     bool operator==( const Array<T> & ) const; // equality operator
     // inequality operator; returns opposite of == operator
     bool operator!=( const Array<T> &right ) const
     {
         return ! ( *this == right ); // invokes Array::operator==
     } // end function operator!=

     // subscript operator for non-const objects returns modifiable lvalue
     T &operator[]( int );

     // subscript operator for const objects returns rvalue
        T operator[]( int ) const;


};

// default constructor for class Array (default size 10)
template <typename T>
 Array<T>::Array( size_t arraySize )
{

    if(arraySize > 0)
        size = arraySize;
    else
        throw invalid_argument( "Array size must be greater than 0");
    ptr = new T[size];

} // end Array default constructor

template <typename T>
// copy constructor for class Array;
// must receive a reference to an Array
Array<T>::Array( const Array<T> &arrayToCopy )
: size( arrayToCopy.size ),
ptr( new T[ size ] )
{
    for ( size_t i = 0; i < size; ++i )
        ptr[ i ] = arrayToCopy.ptr[ i ]; // copy into object
} // end Array copy constructor

// destructor for class Array
template <typename T>
Array<T>::~Array()
{
   delete [] ptr; // release pointer-based array space

} // end destructor


template <typename T>
// return number of elements of Array
size_t Array<T>::getSize() const
{
   return size; // number of elements in Array
} // end function getSize

template <typename T>
// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
const Array<T>& Array<T>::operator=( const Array &right )
{
   if ( &right != this ) // avoid self-assignment
   {
      // for Arrays of different sizes, deallocate original
      // left-side Array, then allocate new left-side Array
      if ( size != right.size )
      {
         delete [] ptr; // release space
         size = right.size; // resize this object
         ptr = new T[ size ]; // create space for Array copy
      } // end inner if

      for ( size_t i = 0; i < size; ++i )
         ptr[ i ] = right.ptr[ i ]; // copy array into object
   } // end outer if

   return *this; // enables x = y = z, for example
} // end function operator=


template <typename T>
// determine if two Arrays are equal and
// return true, otherwise return false
bool Array<T>::operator==( const Array &right ) const
{
   if ( size != right.size )
      return false; // arrays of different number of elements

   for ( size_t i = 0; i < size; ++i )
      if ( ptr[ i ] != right.ptr[ i ] )
         return false; // Array contents are not equal
   return true; // Arrays are equal
} // end function operator==

template <typename T>
// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
T& Array<T>::operator[]( int subscript )
{

    // check for subscript out-of-range error
    if ( subscript < 0 || subscript >= size )
        throw out_of_range( "Subscript out of range" );

    return ptr[ subscript ]; // reference return
} // end function operator[]

template <typename T>
// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
T Array<T>::operator[]( int subscript ) const
{
   // check for subscript out-of-range error
   if ( subscript < 0 || subscript >= size )
      throw out_of_range( "Subscript out of range" );
   return ptr[ subscript ]; // returns copy of this element
} // end function operator[]

template< typename T >
// overloaded input operator for class Array;
// inputs values for entire Array
istream &operator>>( istream &input, Array<T> &a )
{
   for ( size_t i = 0; i < a.size; ++i )
   {
       input>>a.ptr[i];
   }
   return input; // enables cin >> x >> y;
} // end function


template< typename T >
// overloaded output operator for class Array

ostream &operator<<( ostream &output, const Array<T> &a )
{
   // output private ptr-based array
    for ( size_t i = 0; i < a.size; ++i )
    {
        output<<a.ptr[i]<<" ";
    }

    output<<endl;
   return output; // enables cout << x << y;
} // end function operator<<


#endif