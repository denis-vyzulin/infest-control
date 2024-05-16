// ================================ //
// == CLASS GENERAL OF EPIDEMICS == //
// ================================ //

#ifndef EPIDEMIC_SYSTEM_H_
#define EPIDEMIC_SYSTEM_H_

#include <iostream>
#include <vector>

#include "Desease.h"


// EPIDEMIC SYSTEM
class EpidemicSystem {
  public:
    void addVirusFromConsole();
    // Другие методы, связанные с эпидемиологической системой

  private:
    std::vector<Desease> active_epidemics;
};

#endif // EPIDEMIC_SYSTEM_H_
