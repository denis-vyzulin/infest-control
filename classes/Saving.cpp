// ================================ //
// == КЛАСС СИМУЛЯЦИИ ПРОГРЕССА == //
// ================================ //

#include "Saving.h"

EpidemicSimulation::EpidemicSimulation() {
day = 0;
}

void EpidemicSimulation::simulate(const Virus& virus, const Measure& measure, int duration) {
std::vector<Epidemic> epidemics;
Epidemic epidemic(virus);
epidemics.push_back(epidemic);

while (day < duration) {
std::cout « "День " « day « std::endl;

for (auto& epidemic : epidemics) {
double infected = epidemic.total_infected;
double dead = epidemic.total_dead;
double recovered = epidemic.total_recovered;

// Применение противодействий
applyMeasures(virus, measure);

// Обновление статистики эпидемии
updateEpidemic(epidemic, virus);

std::cout « "Вирус: " « epidemic.virus.getName() « std::endl;
std::cout « "Зараженных: " « epidemic.total_infected - infected « std::endl;
std::cout « "Умерших: " « epidemic.total_dead - dead « std::endl;
std::cout « "Выздоровевших: " « epidemic.total_recovered - recovered « std::endl;
}

day++;
}

saveSimulation(epidemics);
}

void EpidemicSimulation::applyMeasures(const Virus& virus, const Measure& measure) {
bool status = measure.getStatus();

if (status) {
std::cout « "Применение противодействий" « std::endl;

// Уменьшение инфекционности вируса
double infectivity = virus.getInfectivity();
double reducedInfectivity = infectivity * measure.getInfectionReduction();
virus.setInfectivity(reducedInfectivity);

// Уменьшение смертности вируса
double mortality = virus.getMortality();
double reducedMortality = mortality * measure.getMortalityReduction();
virus.setMortality(reducedMortality);
}
}

void EpidemicSimulation::updateEpidemic(Epidemic& epidemic, const Virus& virus) {
// Обновление статистики эпидемии
double infectivity = virus.getInfectivity();
double newInfected = infectivity * epidemic.total_infected;
epidemic.total_infected += newInfected;

double mortality = virus.getMortality();
double newDeaths = mortality * epidemic.total_infected;
epidemic.total_dead += newDeaths;

double recovery = virus.getRecovery();
double newRecoveries = recovery * epidemic.total_infected;
epidemic.total_recovered += newRecoveries;
}

void EpidemicSimulation::saveSimulation(const std::vector<Epidemic>& epidemics) {
std::ofstream file("simulation.txt");

if (file.is_open()) {
for (const auto& epidemic : epidemics) {
file « "Вирус: " « epidemic.virus.getName() « std::endl;
file « "Зараженных: " « epidemic.total_infected « std::endl;
file « "Умерших: " « epidemic.total_dead « std::endl;
file « "Выздоровевших: " « epidemic.total_recovered « std::endl;
file « std::endl;
}

file.close();
std::cout « "Симуляция сохранена в файле simulation.txt" « std::endl;
} else {
std::cout « "Ошибка при сохранении симуляции" « std::endl;
}
}
