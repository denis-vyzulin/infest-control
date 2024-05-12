// ============================= //
// == КЛАСС БОЛЕЗНЕЙ, ВИРУСОВ == //
// ============================= //
#include "Desease.h"

Virus::Virus(const std::string& n, double lr, int ip, double rr) : name(n), lethal_rate(lr), incubation_period(ip), reproduction_rate(rr) {}

void EpidemicSystem::addVirusFromConsole() {
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

    Virus new_virus(name, lethal_rate, incubation_period, reproduction_rate);
    active_epidemics.emplace_back(new_virus);
}
#include <iostream>
