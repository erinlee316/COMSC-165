//************************************************************************************************************
//      Author: Erin Lee
//  Assignment: Assignment 11A
//        Date: 5/16/2023
// Description: This is the header file, which contains class specification for 11A.cpp
//************************************************************************************************************

#ifndef NUMBERARRAY_HPP_INCLUDED
#define NUMBERARRAY_HPP_INCLUDED

class NumberArray
{
    private:
        double *arrayPointer;
        int size;

    public:
        // constructor
        NumberArray(int);

        // destructor
        ~NumberArray();

        // mutator
        void setCell(int, double);

        // accessor
        int getCell(int);

        // getAverage function
        double getAverage();

        // getHighest function
        double getHighest();

        // getLowest function
        double getLowest();
};

#endif // NUMBERARRAY_HPP_INCLUDED