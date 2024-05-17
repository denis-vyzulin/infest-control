// ====================== //
// == ФАЙЛ НА УДАЛЕНИЕ == //
// ====================== //

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

// Структура вируса
struct Virus {
    std::string name;
    double lethal_rate;
    int incubation_period;
    double reproduction_rate;

    Virus(const std::string& n, double lr, int ip, double rr) : name(n), lethal_rate(lr), incubation_period(ip), reproduction_rate(rr) {}
};

// Структура эпидемии
struct Epidemic {
    Virus virus;
    double total_infected;
    double total_dead;
    double total_recovered;

    Epidemic(const Virus& v) : virus(v), total_infected(1.0), total_dead(0.0), total_recovered(0.0) {}
};

// Структура мероприятия
struct Measures {
    std::string name;
    double effectiveness;

    Measures(const std::string& n, double e) : name(n), effectiveness(e) {}
};

class EpidemicSystem {
private:
    std::vector<Epidemic> active_epidemics;
    std::vector<Measures> measures_list;

public:
    void addVirusFromConsole() {
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

    void addMeasuresFromConsole() {
        std::string name;
        double effectiveness;

        std::cout << "Enter measure name: ";
        std::cin >> name;
        std::cout << "Enter measure effectiveness: ";
        std::cin >> effectiveness;

        Measures new_measure(name, effectiveness);
        measures_list.emplace_back(new_measure);
    }

    void simulateEpidemic() {
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

            epidemic.total_dead = 0,3*epidemic.virus.lethal_rate* epidemic.total_infected; //ШАНС ПОМЕРЕТЬ 30 ПРОЦЕНТОВ
            epidemic.total_recovered = (epidemic.total_infected - (epidemic.total_infected*0,7)) - epidemic.total_dead; //ШАНС ИСЦЕЛИТЬСЯ 70 ПРОЦЕНТОВ

            // Применение мероприятий

            std::cout << "Day " << day << ": Infected - " << epidemic.total_infected
                << ", Dead - " << epidemic.total_dead << ", Recovered - " << epidemic.total_recovered << std::endl;
        }
    }
};

int main() {
    EpidemicSystem system;
    system.addVirusFromConsole();
    system.addMeasuresFromConsole();
    system.simulateEpidemic();

    return 0;
}
