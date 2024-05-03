#include <vector>


//==> КЛАСС EPIDEMIC SYSTEM
#ifndef EPIDEMIC_SYSTEM_H
#define EPIDEMIC_SYSTEM_H

class EpidemicSystem {
  private:
    std::vector<Epidemic> active_epidemics;
    std::vector<Measure> measures_list;

  public:
    void addVirusFromConsole();
    void addMeasuresFromConsole();
    void simulateEpidemic();
};

#endif
//==> end of КЛАСС EPIDEMIC SYSTEM
