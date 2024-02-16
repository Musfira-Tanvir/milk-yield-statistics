#include <iostream>
#include "herd.h"
using namespace std;
int main()
{
    int initialTotalCows;
    cout << "Enter the initial total number of cows in the herd: ";
    cin >> initialTotalCows;

    herd myHerd(initialTotalCows);
    myHerd.recordYield();
    myHerd.calculateStats();
    myHerd.identifyCows();

    return 0;
}