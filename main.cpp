#include "vehicleload.h"
#include "consoleinterface.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Creating VehicleLoad object and interface for application
    VehicleLoad metro;
    ConsoleInterface interface;
    string logout = "";
    bool endOfCicle;
    string str;

    // Initiating main loop
    while (logout != "logout")
    {
        endOfCicle = false;
        interface.header();
        cout << "Scan a TRIP\n";
        interface.footer();

        // Trip Scanning Loop
        while (cin >> str && str[0] != '\0')
        {
            interface.header();
            if (str[0] == 'q')   // Exit application
            {
                return 0;
            }
            else if (str[0] == 'k')
            {
                cout << "Scan the whole cicle\nTrip->Reference->SSCC\nthan press 'k'";
                continue;
            }
            else if (str[0] == '8' &&
                     str[1] == '0' &&
                     str[2] == '4' &&
                    (str[5] == '3' ||
                     str[5] == '6'))
            {
                metro.setTripNR(str);      // Setting up trip
                metro.setTimeStamp();      // Setting up timestamp
                metro.writeToBaseTripNR(); // Writing trip & timestamp to base
                break;
            }
            else cout << "(!) Trip is INCORRECT (!)\n";
            interface.footer();
        }


        // Reference & SSCC scanning Loop
        while (str[0] != '\0')
        {
            // Reference Loop
            interface.header();
            interface.echoTrip(metro);
            cout << "Scan a Reference\n";
            interface.footer();
            while (cin >> str && str[0] != '\0')
            {
                interface.header();
                interface.echoTrip(metro);
                interface.echoReference(metro);
                if (str[0] == 'k') // Ending up the trip cicle & get ready to scan a new trip
                {
                    metro.writeToBaseTripNREndOfCicle(); // Writing the end of cicle with marker
                    endOfCicle = true;
                    break;
                }
                else if (str[0] == 'q')  // Exit application
                    return 0;
                else if (str[0] == '8' &&
                         str[1] == '0' &&
                         str[2] == '4' &&
                        (str[5] == '1' ||
                         str[5] == '2'))
                {
                    metro.setReference(str);      // Setting up reference
                    metro.setTimeStamp();         // SSetting up timestamp
                    metro.writeToBaseReference(); // Writing reference & timestamp to base
                    break;
                }
                else
                {
                    cout << "(!) Reference is INCORRECT (!)\n";
                    interface.footer();
                    continue;
                }
                interface.footer();
            }

            // Preventing continuous input after the end of scanning cicle
            if (endOfCicle == true)
                break;

            // SSCC Loop
            interface.header();
            interface.echoTrip(metro);
            interface.echoReference(metro);
            cout << "Scan a SSCC\n";
            interface.footer();
            while (cin >> str && str[0] != '\0')
            {
                interface.header();
                interface.echoTrip(metro);
                interface.echoReference(metro);
                if (str[0] == 'q')   // Exit application
                    return 0;
                else if (str[0] == 'k')
                {
                    cout << "Scan SSCC before new cicle first!\n";
                    continue;
                }
                else if (str[3] == '8' &&
                         str[4] == '2' &&
                         str[5] == '3' &&
                         str[6] == '6' &&
                         str[7] == '5' &&
                         str[8] == '2' &&
                         str[9] == '9' &&
                         str[10] == '9' &&
                         str[11] == '9')
                {
                    metro.setSSCC(str);      // Setting up SSCC
                    metro.setTimeStamp();    // Setting up timestamp
                    metro.writeToBaseSSCC(); // Writing SSCC & timestamp to base
                    break;
                }
                else
                {
                    cout << "(!) SSCC is INCORRECT (!)\n";
                    interface.footer();
                    continue;
                }
           }
        }
     }
     return 0;
}
