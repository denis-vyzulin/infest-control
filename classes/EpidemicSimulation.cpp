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
void EpidemicSimulation::simulate(const Desease& desease, const Measure& measure, int duration) {
  std::vector<Epidemic> epidemics;
  Epidemic epidemic(desease);
  epidemics.push_back(epidemic);
  // Simulate logic
  while (day < duration) {
    std::cout << "День " << day << std::endl;
    for (auto& epidemic : epidemics) {
      double infected = epidemic.total_infected;
      double dead = epidemic.total_dead;
      double recovered = epidemic.total_recovered;
      // Utilizing measures to deseases
      apply_measures(desease, measure);
      // Change stat of epidemic
      update_epidemic(epidemic, desease);
      // Print statistic
      std::cout << "Болезнь: " << epidemic.desease.get_name() << std::endl;
      std::cout << "Infected: " << epidemic.total_infected - infected << std::endl;
      std::cout << "Dead: " << epidemic.total_dead - dead << std::endl;
      std::cout << "Recovered: " << epidemic.total_recovered - recovered << std::endl;
    }
    day++;
  }
  // Save changes
  saveSimulation(epidemics);
}


// Use all measures to deseases
void EpidemicSimulation::apply_measures(const Desease& desease, const Measure& measure) {
  bool status = measure.get_status();
  if (status) {
    std::cout << "Utilizing measures..." << std::endl;
    // Decrease infectivity
    double duration = desease.get_duration();
    double reduced_duration = duration * measure.get_seasonality( (EpidemicSimulation::day / 90 + 1) % 4 );
    desease.set_duration(reduced_duration);
    // Decrease deads
    double lethalis = desease.get_lethalis();
    double reduced_lethalis = lethalis * measure.get_seasonality( (EpidemicSimulation::day / 90 + 1) % 4 );
    desease.set_lethalis(reduced_lethalis);
  }
}


// Update epidemics
void EpidemicSimulation::update_epidemic(Epidemic& epidemic, const Desease& desease) {
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
