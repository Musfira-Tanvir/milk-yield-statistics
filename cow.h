#pragma once
const int MAX_DAYS=7;
const int MILKINGS_PER_DAY=2;
class cow
{
    float yield[MAX_DAYS * MILKINGS_PER_DAY];
    public:
    int id;
    cow()
    {
        id=0;
        for (int i = 0; i < MAX_DAYS * MILKINGS_PER_DAY; ++i)
        yield[i]=0.0;
    }
    bool LowYeildCows();
    void recordYield();
    float calculateTotalYield();
};