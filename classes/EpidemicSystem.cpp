// ================================ //
// == CLASS GENERAL OF EPIDEMICS == //
// ================================ //

#include <iostream>

#include "Desease.h"
#include "EpidemicSystem.h"


void EpidemicSystem::addDeseaseFromConsole() {
    std::string name;
    double lethal_rate;
    int incubation_period;
    double reproduction_rate;

    std::cout << "Введите название вируса: ";
    std::cin >> name;
    std::cout << "Введите летальность: ";
    std::cin >> lethal_rate;
    std::cout << "Введите период инкубации: ";
    std::cin >> incubation_period;
    std::cout << "Введите скорость распространения: ";
    std::cin >> reproduction_rate;

    Desease new_desease(name, lethal_rate, incubation_period, reproduction_rate);
    active_epidemics.emplace_back(new_desease);
}
