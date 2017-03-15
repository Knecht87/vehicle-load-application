#ifndef VEHICLELOAD_H
#define VEHICLELOAD_H
#include <string>
#include <iostream>
using namespace std;

class VehicleLoad
{
private:
    string tripNR;
    string reference;
    string sscc;
    string timestamp;

public:
    VehicleLoad();
    void setTripNR(string str);
    string getTripNR();
    void setReference(string str);
    string getReference();
    void setSSCC(string str);
    string getSSCC();
    void writeToBaseTripNR();
    void writeToBaseReference();
    void writeToBaseSSCC();
    void writeToBaseTripNREndOfCicle();
    void setTimeStamp();
    string getTimeStamp();
};

#endif // VEHICLELOAD_H
