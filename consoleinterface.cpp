#include "consoleinterface.h"
#include "vehicleload.h"

ConsoleInterface::ConsoleInterface()
{

}

void ConsoleInterface::header()
{
    system("printf \ec");
    cout << "        === METRO BBXD ===\n";
}

void ConsoleInterface::footer()
{
    cout << "__________________________________\n'k' than Enter - new trip\n\'q\' than Enter - exit application\n";
}

void ConsoleInterface::echoTrip(VehicleLoad object)
{
    int counter = 0;
    string tripNR;
    tripNR = object.getTripNR();
    cout << "TRIP #: ";
    while (tripNR[counter] != '\0') {
        cout << tripNR[counter];
        counter++;
    }
    cout << endl;
}

void ConsoleInterface::echoReference(VehicleLoad object)
{
    int counter = 0;
    string reference;
    reference = object.getReference();
    cout << "Reference #: ";
    while (reference[counter] != '\0') {
        cout << reference[counter];
        counter++;
    }
    cout << "\nadded to base.";
    cout << endl;
}

void ConsoleInterface::echoSSCC(VehicleLoad object)
{
    int counter = 0;
    string sscc;
    sscc = object.getSSCC();
    cout << "SSCC #: ";
    while (sscc[counter] != '\0') {
        cout << sscc[counter];
        counter++;
    }
    cout << "\nadded to base.";
    cout << endl;
}

void ConsoleInterface::clearScreen()
{
    system("printf \ec");
}
