#include <iostream>
#include <algorithm>  // for sort(), find()
#include <numeric>    // for accumulate()
#include <array>
using namespace std;

const int SIZE = 8;

int main() {
    // declarations
    array<double, SIZE> rainfall = {3.2,4.6,9.4,3.1,6.2,6.7,5.5,3.8};

    // <array> objects can report their own size, unlike C-style arrays
    cout << "1.  Size: " << rainfall.size() << endl;

    // range loop to access elements
    cout << "2.  Values: ";
    for (double val : rainfall) cout << val << " "; cout << endl;

    // accessing individual elements
    cout << "3.  Element 2: " << rainfall.at(2) << endl;
    cout << "4.  Element 2: " << rainfall[2] << endl;
    cout << "5.  Front: " << rainfall.front() << endl;
    cout << "6.  Back: " << rainfall.back() << endl;
    cout << "7.  Empty? " << (rainfall.empty() == 0? "False" : "True") << endl;
    cout << "8.  Address? " << rainfall.data() << endl;

    // use iterators to sort
    sort(rainfall.begin(), rainfall.end());
    cout << "9.  Sorted: ";
    for (double val : rainfall) cout << val << " "; cout << endl;
    sort(rainfall.rbegin(), rainfall.rend());
    cout << "10. Reverse sorted: ";
    for (double val : rainfall) cout << val << " "; cout << endl;

    // find an element
    double target = 5.5;   // search target
    array<double, SIZE>::iterator it;  // declare iterator to point to the found element
    it = find(rainfall.begin(), rainfall.end(), target);
    cout << "11. Value " << target;
    if (it != rainfall.end())
        cout << " found in position " << it - rainfall.begin() << endl;
    else
        cout << " was not found.\n";
    cout << "    Value: " << *it << endl;

    // find max & min & sum
    cout << "12. Max: " << *max_element(rainfall.begin(), rainfall.end()) << endl;
    cout << "13. Min: " << *min_element(rainfall.begin(), rainfall.end()) << endl;
    cout << "14. Sum: " << accumulate(rainfall.begin(), rainfall.end(), 0) << endl;

    // create several empty <array> and fill with one value
    array<int, 4> fours;
    array<int, 4> fives;
    fill(fours.begin(), fours.end(), 4);  // also: fours.fill(4)
    fill(fives.begin(), fives.end(), 5);  // also: fives.fill(5)
    cout << "15. 4-element array of 4's: ";
    for (int val : fours) cout << val << " "; cout << endl;
    cout << "16. 4-element array of 5's: ";
    for (int val : fives) cout << val << " "; cout << endl;

    // swap arrays
    fours.swap(fives);
    cout << "17. Swapped; the fours array now holds: ";
    for (int val : fours) cout << val << " "; cout << endl;

    // a 2-D array
    array<int, 2> row1 = {1,2};
    array<int, 2> row2 = {3,4};
    array< array<int, 2>, 2 > master = {row1, row2};
    cout << master[1][1];
}
