// ===================== //
// == КОНСОЛЬНОЕ МЕНЮ == //
// ===================== //

#include <iostream>
#include <stdlib.h>
#include <cstdlib>

#include "Saving.h"
#include "RewindTime.h"

using namespace std;

void console_menu(){
    cout << "1. Start simulating epedemic" << "\n2. Adding/changing viruses and measures" <<
            "\n3. Export/import viruses and measures" << "\n4. Finish" << endl;
    bool work = true;
    while(work){
        int key1, key2, key3, key4;
        cin >> key1;
        switch(key1){
        case 1:
            system("cls");
            cout << "5. Load process" << "\n6. Select virus to simulate epidemic" << "\n7. Select measure to simulate epidemic" <<
                 "\n8. Simulate epidemic" << "\n9. Rewind time" << "\n10. Save process" << "\n11. Pause"<< endl;
            cin >> key2;
            switch(key2){
            case 5:
                system("cls");
                loadProcess(); //???
                break;
            case 6:
                system("cls");

                break;
            case 7:
                system("cls");

                break;
            case 8:
                system("cls");
                simulateEpidemic();
                break;
            case 9:
                if (/*булевая переменная*/ == True)
                    cout << "RewindTime is currently in progress. Please wait until it's completed." << endl;
                else{
                    system("cls");
                    RewindTime();
                }
                break;
            case 10:
                system("cls");
                saveProcess(); //???
                break;
            case 11:
                cout << "Choose an option and enter its number two times" << endl;
                system("pause");
                break;
            }
            break;
        case 2:
            system("cls");
            cout << "What do you want to add?" << "\n12. Virus" << "\n13. Measure" << endl;
            cin >> key3;
            switch(key3){
            case 12:
                system("cls");
                addVirusFromConsole();
                save(); //???
                break;
            case 13:
                system("cls");
                addMeasuresFromConsole();
                redRates(rates, mod);
                redSesonality(sesonality, mod);
                save(); //???
                break;
            }
            break;
        case 3:
            system("cls");
            cout << "14. Export viruses" << "\n15. Import viruses" <<
                 "\n16. Export measures" << "\n17. Import measures" << endl;
            cin >> key4;
            switch(key4){
            case 14:
                system("cls");

                break;
            case 15:
                system("cls");

                break;
            case 16:
                system("cls");
                outRates(rates);
                outSesonality(sesonality);
                break;
            case 17:
                system("cls");

                break;
            }
            break;
        case 4:
            system("cls");
            cout << "Press enter" << endl;
            exit(0);
            break;
        default:
            system("cls");
            cout << "Error" << endl;
            work = false;
            break;
        }
    }
}
