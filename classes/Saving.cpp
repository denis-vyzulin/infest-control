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

// Применение противодействий к вирусу
// ...
}
}

void EpidemicSimulation::updateEpidemic(Epidemic& epidemic, const Virus& virus) {
// Обновление статистики эпидемии
// ...
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
