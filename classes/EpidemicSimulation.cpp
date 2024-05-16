// ================================== //
// == CLASS SIMULATION OF EPIDEMIC == //
// ================================== //

#include <iostream>

#include "EpidemicSimulation.h"
#include "Epidemic.h"



// Save now day
EpidemicSimulation::EpidemicSimulation() {
  day = 0;
}


// Simulate progress
void EpidemicSimulation::simulate(const Virus& virus, const Measure& measure, int duration) {
  std::vector<Epidemic> epidemics;
  Epidemic epidemic(virus);
  epidemics.push_back(epidemic);

  while (day < duration) {
    std::cout << "День " << day << std::endl;
    for (auto& epidemic : epidemics) {
      double infected = epidemic.total_infected;
      double dead = epidemic.total_dead;
      double recovered = epidemic.total_recovered;
      // Utilizing measures to deseases
      applyMeasures(virus, measure);
      // Change stat of epidemic
      updateEpidemic(epidemic, virus);
      // Print statistic
      std::cout << "Вирус: " << epidemic.virus.getName() << std::endl;
      std::cout << "Зараженных: " << epidemic.total_infected - infected << std::endl;
      std::cout << "Умерших: " << epidemic.total_dead - dead << std::endl;
      std::cout << "Выздоровевших: " << epidemic.total_recovered - recovered << std::endl;
    }
    day++;
  }

  saveSimulation(epidemics);
}


// Use all measures to deseases
void EpidemicSimulation::applyMeasures(const Desease& desease, const Measure& measure) {
  bool status = measure.getStatus();

  if (status) {
    std::cout << "Применение противодействий" << std::endl;
    // Decrease infectivity
    double infectivity = desease.getInfectivity();
    double reducedInfectivity = infectivity * measure.getInfectionReduction();
    desease.setInfectivity(reducedInfectivity);
    // Decrease deads
    double mortality = desease.getMortality();
    double reducedMortality = mortality * measure.getMortalityReduction();
    desease.setMortality(reducedMortality);
  }
}

void EpidemicSimulation::updateEpidemic(Epidemic& epidemic, const Virus& desease) {
// Обновление статистики эпидемии
double infectivity = desease.getInfectivity();
double newInfected = infectivity * epidemic.total_infected;
epidemic.total_infected += newInfected;

double mortality = desease.getMortality();
double newDeaths = mortality * epidemic.total_infected;
epidemic.total_dead += newDeaths;

double recovery = desease.getRecovery();
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
