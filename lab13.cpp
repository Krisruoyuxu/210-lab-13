#include <iostream>
#include <algorithm>  // for sort(), find()
#include <numeric>    // for accumulate()
#include <vector>
#include <fstream>
using namespace std;

/*
Review: Our lab 12 program reads 100m sprint records respectively from files (2000, 2010, 2020), sorts them, 
and extracts the top 15 performances.It uses arrays and functions for reading data, selecting the fastest results, 
and printing them. Additional operations include finding min/max times, swapping arrays, calculating averages, 
filling arrays, and searching for specific values. In our lab13, we will implement the same functionality, but using vector instead.
*/ 

void readFile(); // create a function to read the external file and move the data in it into the array
void extractTop15(); 
void print_top15();

int main() {

    vector<double> top15_records{}; // we use this array to store the final top15 records
    vector<double> all50_records{};
    vector<double> temp_top15_records{};

    return 0;
}

void readFile(){

}

void extractTop15(){

}

void print_top15(){
    
}