#include <iostream>
#include "cow.h"
using namespace std;
void cow:: recordYield() 
{
    cout << "Enter the yield (in litres) for each milking (twice a day): \n";
    for (int i = 0; i < MAX_DAYS * MILKINGS_PER_DAY; ++i) 
    {
        cout << "Day " << (i / 2) + 1 << ", Milking " << (i % 2) + 1 << ": ";
        cin >> yield[i];
    }
}

float cow::calculateTotalYield()
{
    float total = 0.0;
    for (int i = 0; i < MAX_DAYS * MILKINGS_PER_DAY; ++i) 
    {
        total =total + yield[i];
    }
    return total;
}

bool cow::LowYeildCows()
{
    int lowDays = 0;
    for (int i = 0; i < MAX_DAYS * MILKINGS_PER_DAY; ++i) 
    {
        if (yield[i] < 12.0) 
        {
            lowDays++;
        }
    }
    return lowDays >= 4;
}