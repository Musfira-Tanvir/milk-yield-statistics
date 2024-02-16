#pragma once
#include "cow.h"
class herd
{
    cow *C;
    int totalCows;
    int findCowIndex(int cowId);
    public:
    herd(int initialTotalCows);  // Constructor to set initial totalCows
    ~herd();
    void identifyCows();
    void recordYield();
    void calculateStats();
};