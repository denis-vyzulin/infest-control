// ================================== //
// == CLASS SIMULATION OF EPIDEMIC == //
// ================================== //

#ifndef EPIDEMIC_SIMULATION_H
#define EPIDEMIC_SIMULATION_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Desease.h"
#include "Measure.h"



class EpidemicSimulation {
  private:
    int day;
    void applyMeasures(const Virus& virus, const Measure& measure);
    void updateEpidemic(Epidemic& epidemic, const Virus& virus);
    void saveSimulation(const std::vector<Epidemic>& epidemics);

  public:
    void EpidemicSimulation();
    void simulate(const Virus& virus, const Measure& measure, int duration);
};

#endif // EPIDEMIC_SIMULATION_H
