/*
 * Author: S. Peters
 * Date: 9-2-2018
 * Class: CSC-2710
 * File location: ~/CSC2710/quickSort
 * This program is using quick sort to alphabetically sort a list of names
 */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

//This is the class that holds the first and last name and age
class data{
    public:
        string first;
        string last;
        int age;
};

//Declares the pointer
typedef data * holdD_ptr;

//Functions Prototypes
    //The load function loads the persons info into the class file
void load(holdD_ptr[], int &, int max);
    //The print function prints out the information of all the people in the data filled when called
void print(holdD_ptr[], int n);
    //This quicksort algorithm sorts the last names alphabetically
void quickSort(holdD_ptr holdD[], int low, int high);
    //This partition function is called within quicksort to assist in sorting
void partition(holdD_ptr holdD[], int low, int high, int &pivotPoint);
    //This exchange function is used to exchange two elements that need to be sorted
void exchange(holdD_ptr &a, holdD_ptr &b);



//Main of the file that calls all the functions
int main() {
    holdD_ptr test[25];
    int n;
    load(test,n,3);
    int high = n - 1;
    int low = 0;
    quickSort(test, low, high);
    print(test,n);
    return 0;
}

//This function loads the data in from a file, the holdD[] will be holding the first name, last name, and age, n is refrenced to main and holds the amount
//of people in the list, max sets a limit to the names
void load(holdD_ptr holdD[], int &n, int max) {
    string first;
    string last;
    int age;
    n = 0;
    max = 100000;
    //Runs through the while loop until it has reached max
    while(n < max && cin >> first) {
        cin >> last;
        cin >> age;
        //Loads the class with the data
        holdD[n] = new data;
        holdD[n]->first = first;
        holdD[n]->last = last;
        holdD[n]->age = age;
        //N is used as a counter variable to keep track of how many people are added
        n++;
    }

}

//Print is a simple functions that uses holdD[] to access the data and n to know how many times to print
void print(holdD_ptr holdD[], int n) {
    for (int i = 0; i < n; i++) {
        cout << holdD[i] -> last << ", ";
        cout << holdD[i] -> first << " - ";
        cout << holdD[i] -> age << endl;
        
    }
}

//Quick sort is a recursive function calling itself twice and partition in order to properly sort the elements.
//low is the first element in the list, high is the last element in the list
void quickSort(holdD_ptr holdD[], int low, int high) {
    int pivotP;

    if (high > low) {
        partition(holdD, low, high, pivotP);
        quickSort(holdD, low, pivotP-1);
        quickSort(holdD, pivotP+1, high);
    }
}

//This function is used to the the comparisons in quick sort to decide how to sort the elements
//low is the first element in the list, high is the last element in the list, pivitPoint is the pivot point needed to complete quick sort
void partition(holdD_ptr holdD[], int low, int high, int &pivotPoint) {
    int i, j;
    j = low;
    //pLast and pFirst being assigned pivot from the first element in the list
    string pLast = holdD[low]-> last;
    string pFirst = holdD[low]->first;

    for(i=low+1; i<=high; i++) {
        if(holdD[i]->last < pLast) {
            j++;
            //Sends the elements to exchange to swap
            exchange(holdD[i], holdD[j]);
        }
        //This else if is incase the last names are equal it will go against the first names to decide
        else if (holdD[i]->last == pLast &&
                 holdD[i]->first < pFirst){
            j++;
            //Sends the elements to exchange to swap
            exchange(holdD[i], holdD[j]);
        }
    }
    pivotPoint = j;
    exchange(holdD[pivotPoint], holdD[low]);
}

//This function exchanged the information held in the class using the reference variables
//element1 and 2 are used to reference the names that need to be swapped
void exchange(holdD_ptr &element1, holdD_ptr &element2) {
    holdD_ptr temp;
    temp = element1;
    element1 = element2;
    element2 = temp;
}