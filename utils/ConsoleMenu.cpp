// ================== //
// == CONSOLE MENU == //
// ================== //

#include <iostream>
#include <stdlib.h>
#include <cstdlib>

//==> IMPORT OPTIONAL FUNCTIONS
#include "FileInteraction.h"
#include "RewindTime.h"
#include "ConsoleMenu.h"

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
        cout << "1. Simulate... | "
              << "2. Rewind time | "
              << "3. Pause\n" << endl;
        cout << "Enter number >>" << endl;

        // Second level (for 1st case)
        int k_sim;
        cin >> k_sim;
        switch (k_sim) {
          case 1: // Simulation
            system("cls");
            simulate();
            break;
          case 2: // Rewind time
            if (/*булевая переменная*/ == True) {
              cout << "RewindTime is currently in progress. Please wait until it's completed." << endl;
            } else {
              system("cls");
              RewindTime();
            }
            break;
          case 3: // Pause
            cout << "Choose an option and enter its number two times" << endl;
            system("pause");
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
            break;
          case 2: // Add/change Measure
            system("cls");
            addMeasuresFromConsole();
            redRates(rates, mod);
            redSesonality(sesonality, mod);
            break;
        }
        break;

      // For "Import/export Desease or Measure"
      case 3:
        system("cls");
        cout << "1. Import Deseases | "
              << "2. Export Deseases\n"
              << "3. Import Measures | "
              << "4. Export Measures" << endl;
        cout << "Enter number >>" << endl;
        
        // Second level (for 3rd case)
        int k_exp_imp;
        cin >> k_exp_imp;
        switch (k_exp_imp) {
          case 1: // Import Deseases
            system("cls");
            outEpidemic(epidemic, end_of_vector);
            break;
          case 2: // Export Deseases
            system("cls");
            getEpidemic(epidemic);
            break;
          case 3: // Import Measures
            system("cls");
            outMeasure(measure, end_of_vector);
            break;
          case 4: // Export Measures
            system("cls");
            getMeasure(measure);
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
