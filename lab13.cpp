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

void readFile(const string& filename, vector<double>& all50_records); // create a function to read the external file and move the data in it into the array
void extractTop15(const vector<double>& all50_records, vector<double>& top15_records); 
void print_top15(const vector<double>& top15_records);

int main() {

    vector<double> top15_records{}; // we use this array to store the final top15 records
    vector<double> all50_records{};
    vector<double> temp_top15_records{};

    // ---- 2000 ----
    readFile("2000top50.txt", all50_records);
    // ------------------------All this part is just copy and paste from my lab12----------------------------------------------------==================
    for (double score: top15_records){
        cout << score <<endl; // we can see the original 15 elements are all 0
    }

    for (double score: all50_records){
        cout << score <<endl; // we can see what's in the all50_records array now. (all elements from the 2020top50 file)
    }

    cout << "Then, sort the 50 records and add the top15 into our top15_records array." << endl;
    extractTop15(all50_records, top15_records);

    cout << "Up to the year 2000, the top 15 all-time performances in the 100m race are as follows: " <<endl;
    for (double score: top15_records){
        cout << score <<" ";
    }
    cout <<endl;
    // ---- 2010 ----
    readFile("2010top50.txt", all50_records);
    extractTop15(all50_records, top15_records);

    cout << "So up to the year 2010, the new top 15 all-time performances in the 100m race are as follows: ";
    print_top15(top15_records);

    // ---- 2020 -----
    readFile("2020top50.txt", all50_records);
    extractTop15(all50_records, top15_records);

    cout << "Finally up to the year 2020, the new top 15 all-time performances in the 100m race are as follows: ";
    print_top15(top15_records);
    cout << "The top 1's record in this world is: " << top15_records.front() <<endl;
    cout << "The top 15's record in this world is: " << top15_records.back() <<endl;
    cout << "The top 1's record in this world is: " << *min_element(top15_records.begin(), top15_records.end()) << " = " <<*min_element(top15_records.rbegin(), top15_records.rend())<<endl;
    cout << "The top 15's record in this world is: " << *max_element(top15_records.begin(), top15_records.end()) <<endl;
// ------------------------------------------------------------------------------------------------------------------------------------------------------

    return 0;
}

void readFile(const string& filename, vector<double>& all50_records){ 
    ifstream fin(filename); // this function reads 50 marks from a text file into all50_records
    double mark;
    int i = 0;
    while (fin >> mark) {
        all50_records.push_back(mark);  // bounds-checked
        i++;
    }
    fin.close();
}

// This function sorts the copy of the 50 marks and copy the first 15 (fastest) into top15_records
void extractTop15(const vector<double>& all50_records, vector<double>& top15_records) {
    top15_records.clear(); // every time call this function, clear the rank(which means all elements in it) first
    vector<double> temp = all50_records;   // copy the all50_records
    sort(temp.begin(), temp.end());                   
    for (int i = 0; i < 15; i++) {
        top15_records.push_back(temp.at(i));
    }
}

void print_top15(const vector<double>& top15_records){
    for (int i = 0; i < 15; ++i) {
    cout << (i+1) << ". " << top15_records[i] <<endl;
}
    cout <<endl;
}