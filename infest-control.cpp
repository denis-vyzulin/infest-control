// ========================= //
// === MAIN PROGRAM FILE === //
// ========================= //

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

//==> INCLUDE APPLICATION CLASSES
#include "classes/Desease.h"
#include "classes/Measure.h"
#include "classes/Epidemic.h"
#include "classes/EpidemicSimulation.h"

//==> INCLUDE APPLICATION FUNCTIONS
#include "utils/FileInteraction.h"

using namespace std;


//==> CONSOLE MENU FUNCTION
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
            EpidemicSimulation::simulate();
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
            File::set_desease();
            break;
          case 2: // Add/change Measure
            system("cls");
            File::set_measure();
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
          // case 1: // Import Deseases
          //   system("cls");
          //   OOOoutEpidemic(epidemic, end_of_vector);
          //   break;
          // case 2: // Export Deseases
          //   system("cls");
          //   OOOgetEpidemic(epidemic);
          //   break;
          case 3: // Import Measures
            system("cls");
            File::get_measure(measure, end_of_vector);
            break;
          case 4: // Export Measures
            system("cls");
            File::set_measure(measure);
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


//==> MAIN FUNCTION
int main() {
  console_menu();
  return 0;
}
