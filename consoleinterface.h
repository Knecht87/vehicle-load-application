#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H
#include "vehicleload.h"

class ConsoleInterface
{
public:
    ConsoleInterface();
    void header();
    void footer();
    void clearScreen();
    void echoTrip(VehicleLoad object);
    void echoReference(VehicleLoad object);
    void echoSSCC(VehicleLoad object);
};

#endif // CONSOLEINTERFACE_H
