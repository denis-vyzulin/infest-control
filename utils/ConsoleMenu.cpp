// ===================== //
// == КОНСОЛЬНОЕ МЕНЮ == //
// ===================== //

#include <iostream>
#include <stdlib.h>
#include <cstdlib>

//==> ИМПОРТ ДОП.ФУНКЦИЙ
#include "Saving.h"
#include "RewindTime.h"

using namespace std;



void console_menu() {
  // Output all options
  cout << "1. Start simulation\n"
        << "2. Add/change Desease or Measure\n"
        << "3. Export/import Desease or Measure\n"
        << "4. Exit\n" << endl;
  cout << "Enter number >>" << endl;
  
  // Getting started
  bool work = true;
  while (work) {
    // First level
    int k_menu;
    cin >> k_menu;
    switch (k_menu) {
      // For "Start simulation"
      case 1:
        system("cls");
        cout << "1. Select saving\n"
              << "2. Select Desease for simulation\n"
              << "3. Select Measure for simulation\n"
              << "4. Simulate... | "
              << "5. Rewind time | "
              << "6. Pause\n"
              << "7. Save progress" << endl;
        cout << "Enter number >>" << endl;

        // Second level (for 1st case)
        int k_sim;
        cin >> k_sim;
        switch (k_sim) {
          case 1: // Load process
            system("cls");
            loadProcess();
            break;
          case 2: // Select Desease
            system("cls");
            break;
          case 3: // Select Measure
            system("cls");
            break;
          case 4: // Simulation
            system("cls");
            simulateEpidemic();
            break;
          case 5: // Rewind time
            if (/*булевая переменная*/ == True) {
              cout << "RewindTime is currently in progress. Please wait until it's completed." << endl;
            } else {
              system("cls");
              RewindTime();
            }
            break;
          case 6: // Pause
            cout << "Choose an option and enter its number two times" << endl;
            system("pause");
            break;
          case 7: // Save progress
            system("cls");
            saveProcess(); //???
            break;
        }
        break;

      // For "Add/change Desease or Measure"
      case 2:
        system("cls");
        cout << "What do you want to add?\n"
              << "1. Desease | "
              << "2. Measure" << endl;
        cout << "Enter number >>" << endl;

        // Second level (for 2nd case)
        int k_new;
        cin >> k_new;
        switch (k_new) {
          case 1: // Add/change Desease
            system("cls");
            addVirusFromConsole();
            save(); //???
            break;
          case 2: // Add/change Measure
            system("cls");
            addMeasuresFromConsole();
            redRates(rates, mod);
            redSesonality(sesonality, mod);
            save(); //???
            break;
        }
        break;

      // For "Export/import Desease or Measure"
      case 3:
        system("cls");
        cout << "1. Export Deseases | "
              << "2. Import Deseases\n"
              << "3. Export Measures | "
              << "4. Import Measures" << endl;
        cout << "Enter number >>" << endl;
        
        // Second level (for 3rd case)
        int k_exp_imp;
        cin >> k_exp_imp;
        switch (k_exp_imp) {
          case 1: // Export Deseases
            system("cls");
            break;
          case 2: // Import Deseases
            system("cls");
            break;
          case 3: // Export Measures
            system("cls");
            outRates(rates);
            outSesonality(sesonality);
            break;
          case 4: // Import Measures
            system("cls");
            break;
        }
        break;

      // For "Exit"
      case 4:
        system("cls");
        cout << "Are you sure? Press enter..." << endl;
        if ( getch() == 13 ) {
          exit(0);
          work = false;
        }
        break;
      
      // Wrong option
      default:
        system("cls");
        cout << "Something goes wrong..." << endl;
        work = false;
        break;
    }
  }
}
