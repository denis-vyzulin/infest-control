// ====================== //
// == ФАЙЛ НА УДАЛЕНИЕ == //
// ====================== //

#include <iostream>


//==> ФУНКЦИИ КЛАССА EPIDEMIC SYSTEM
#include "headings/EpidemicSystem.h"

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



void Measure_data::redRates(std::vector<int>& rates, unsigned int mod) {
	
	int getdat, getdat_v;
	switch (mod) {
	case 1:
		cout << "print new modifier for new measure" << endl;
		cin >> getdat;
		rates.push_back(getdat);
		cout << "new list of modifiers: " << endl;
		Measure_data::outRates(&rates);
		break;
	case 2:
		cout << " select the modifier, that you want delete";
		Measure_data::outRates(&rates);
			cin >> getdat;
		rates.erase(getdat);
		cout << "new list of modifiers: " << endl;
		Measure_data::outRates(&rates);
		break;
	case 3:
		cout << "select the modifier, that you wand change";
		Measure_data::outRates(&rates);
		cin >> getdat;
		cout << "print new value of modifier";
		cin >> getdat_v;
		rates.at(getdat) = getdat_v;
		cout << "new list of modifiers: " << endl;
		Measure_data::outRates(&rates);
		break;
	}

	Measure::setRates(&rates);
}

void Measure_data::redSesonality(std::vector<int>& sesonality, unsigned int mod){
	
	int getdat, getdat_v;
	switch (mod) {
	case 1:
		cout << "print new modifier for new seson" << endl;
		cin >> getdat;
		sesonality.push_back(getdat);
		cout << "new list of modifiers: " << endl;
		Measure_data::outSesonality(&sesonality);
		break;
	case 2:
		cout << " select the modifier, that you want delete";
		Measure_data::outSesonality(&sesonality);
		cin >> getdat;
		sesonality.erase(getdat);
		cout << "new list of modifiers: " << endl;
		Measure_data::outSesonality(&sesonality);
		break;
	case 3:
		cout << "select the modifier, that you wand change";
		Measure_data::outSesonality(&sesonality);
		cin >> getdat;
		cout << "print new value of modifier";
		cin >> getdat_v;
		sesonality.at(getdat) = getdat_v;
		cout << "new list of modifiers: " << endl;
		Measure_data::outSesonality(&sesonality);
		break;
	}

	Measure::setSesonality(&sesonality);
}

void Measure_data::outRates(std::vector<int>& rates) {
	
	for (int i = 0;i < rates.size(); i++)
		cout << i << ". " << rates.at(i) << ' ';
	cout << endl;
}

void Measure_data::outSesonality(std::vector<int>& sesonality) {

	for (int i = 0;i < sesonality.size(); i++)
		cout << i << ". " << sesonality.at(i) << ' ';
	cout << endl;
}
