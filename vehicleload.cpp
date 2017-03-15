#include "vehicleload.h"
using namespace std;

VehicleLoad::VehicleLoad()
{

}

void VehicleLoad::setTripNR(string str)
{
    this->tripNR = str;
}

string VehicleLoad::getTripNR()
{
    return this->tripNR;
}

void VehicleLoad::setReference(string str)
{
    this->reference = str;
}

string VehicleLoad::getReference()
{
    return this->reference;
}

void VehicleLoad::setSSCC(string str)
{
    this->sscc = str;
}

string VehicleLoad::getSSCC()
{
    return this->sscc;
}

void VehicleLoad::writeToBaseTripNR()
{
    string markerStart = "-- Start of trip --";
    string markerVoidReference = "-- VOID --";
    string commandWriteTrip = "echo \"INSERT INTO SSCConTrip (TRIP, SSCC, TimeSt) VALUES ('"+ this->tripNR +"', '" + markerStart +"' , STR_TO_DATE('"+ this->timestamp +"','%Y-%m-%d:%H:%i:%s'),'"+ markerVoidReference +"');\" | mysql --user=root --password=root rabendb";
    system(commandWriteTrip.c_str());
}

void VehicleLoad::writeToBaseReference()
{
    string markerVoidSSCC = "-- VOID --";
    string commandWriteReference = "echo \"INSERT INTO SSCConTrip (TRIP, SSCC, TimeSt, REF) VALUES ('"+ this->tripNR +"', '" + markerVoidSSCC +"' , STR_TO_DATE('"+ this->timestamp +"','%Y-%m-%d:%H:%i:%s'),'"+ this->reference +"');\" | mysql --user=root --password=root rabendb";
    system(commandWriteReference.c_str());
}

void VehicleLoad::writeToBaseSSCC()
{
    string commandWriteSSCC = "echo \"INSERT INTO SSCConTrip (TRIP, SSCC, TimeSt, REF) VALUES ('"+ this->tripNR +"', '" + this->sscc +"' , STR_TO_DATE('"+ this->timestamp +"','%Y-%m-%d:%H:%i:%s'),'"+ this->reference +"');\" | mysql --user=root --password=root rabendb";
    system(commandWriteSSCC.c_str());
}

void VehicleLoad::writeToBaseTripNREndOfCicle()
{
    string markerFinish = "-- End of trip --";
    string commandWriteTrip = "echo \"INSERT INTO SSCConTrip (TRIP, SSCC, TimeSt) VALUES ('"+ this->tripNR +"', '" + markerFinish +"' , STR_TO_DATE('"+ this->timestamp +"','%Y-%m-%d:%H:%i:%s'));\" | mysql --user=root --password=root rabendb";
    system(commandWriteTrip.c_str());
}

string VehicleLoad::getTimeStamp()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer1 [80];
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer1,80,"%Y-%m-%d:%H:%M:%S.",timeinfo);
    return buffer1;
}

void VehicleLoad::setTimeStamp()
{
    this->timestamp = VehicleLoad::getTimeStamp();
}
