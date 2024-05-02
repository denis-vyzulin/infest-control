#include "EpidemicSystem.h"
#include <iostream>

void EpidemicSystem::addVirusFromConsole() {
    std::string name;
    double lethal_rate;
    int incubation_period;
    double reproduction_rate;

    std::cout << "Enter virus name: ";
    std::cin >> name;
    std::cout << "Enter lethal rate: ";
    std::cin >> lethal_rate ;
    std::cout << "Enter incubation period: ";
    std::cin >> incubation_period;
    std::cout << "Enter reproduction rate: ";
    std::cin >> reproduction_rate;

    Virus new_virus(name, lethal_rate, incubation_period, reproduction_rate);
    active_epidemics.emplace_back(new_virus);
}

void EpidemicSystem::addMeasuresFromConsole() {
    std::string name;
    double effectiveness;

    std::cout << "Enter measure name: ";
    std::cin >> name;
    std::cout << "Enter measure effectiveness: ";
    std::cin >> effectiveness;

    Measures new_measure(name, effectiveness);
    measures_list.emplace_back(new_measure);
}

void EpidemicSystem::simulateEpidemic() {
    if (active_epidemics.empty()) {
        std::cout << "No active epidemics to simulate." << std::endl;
        return;
    }

    Epidemic& epidemic = active_epidemics.back();
    double population = 7e9; // Население Земли

    // Симуляция распространения эпидемии
    for (int day = 1; epidemic.total_infected < population; ++day) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Задержка один день

        epidemic.total_infected = epidemic.virus.reproduction_rate * epidemic.total_infected;
        if (epidemic.total_infected > population) {
            epidemic.total_infected = population;
        }

        epidemic.total_dead = 0.3 * epidemic.virus.lethal_rate * epidemic.total_infected; // ШАНС ПОМЕРЕТЬ 30 ПРОЦЕНТОВ
        epidemic.total_recovered = (epidemic.total_infected - (epidemic.total_infected * 0.7)) - epidemic.total_dead; // ШАНС ИСЦЕЛИТЬСЯ 70 ПРОЦЕНТОВ

        // Применение мероприятий

        std::cout << "Day " << day << ": Infected - " << epidemic.total_infected << std::endl;
    }
}
