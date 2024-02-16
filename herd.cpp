#include <iostream>
#include "herd.h"
using namespace std;

herd::herd(int initialTotalCows)
{
    totalCows=initialTotalCows;
    C = new cow[totalCows];
}
void herd:: identifyCows() 
{
    if (totalCows == 0) 
    {
        cout << "No data available. Please record yields first.\n";
        return;
    }
    int maxCowIndex = 0;
    for (int i = 0; i < totalCows; ++i) 
    {
        if (C[i].calculateTotalYield() > C[maxCowIndex].calculateTotalYield()) 
        {
            maxCowIndex = i;
        }
    }
    cout << "Most productive cow this week: Cow " << C[maxCowIndex].id<< " with a total yield of " << static_cast<int>(C[maxCowIndex].calculateTotalYield()) << " litres\n";
    cout << "Cows with less than 12 litres on four or more days:\n";
    for (int i = 0; i < totalCows; ++i) 
    {
        if (C[i].LowYeildCows()) 
        {
            cout << "Cow " << C[i].id << " - Low yield\n";
        }
    }
}
void herd::calculateStats() 
{
    float totalVolume = 0.0;
    for (int i = 0; i < totalCows; ++i) 
    {
        totalVolume =totalVolume+ C[i].calculateTotalYield();
    }

    float averageYield = (totalCows != 0) ? totalVolume / totalCows : 0.0;
    cout << "Total weekly volume of milk for the herd: " << static_cast<int>(totalVolume) << " litres\n";
    cout << "Average yield per cow in a week: " << static_cast<int>(averageYield) << " litres\n";
}

void herd::recordYield() 
{
    for (int i = 0; i < totalCows; ++i) {
        int cowId;
        cout << "Enter the 3-digit identity code of the cow: ";
        cin >> cowId;

        int cowIndex = findCowIndex(cowId);

        if (cowIndex == -1) {
            // Cow doesn't exist, add a new cow to the herd
            cowIndex = i;
            C[cowIndex].id = cowId;
        }

        C[cowIndex].recordYield();
    }
}


herd::~herd() {
    delete[] C;  // Destructor to deallocate memory
}

int herd::findCowIndex(int cowId) {
    for (int i = 0; i < totalCows; ++i) {
        if (C[i].id == cowId) {
            return i;
        }
    }
    return -1;
}

