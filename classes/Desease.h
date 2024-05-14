// =========================== //
// == КЛАСС болезни == //
// =========================== //

#ifndef VIRUS_H
#define VIRUS_H

#include <string>
#include <vector>

class Virus {
private:
    std::string name;
    double lethal_rate;
    int incubation_period;
    double reproduction_rate;

public:
    Virus(const std::string& n, double lr, int ip, double rr);

    // Геттеры и сеттеры (если необходимо)
    const std::string& getName() const { return name; }
    double getLethalRate() const { return lethal_rate; }
    int getIncubationPeriod() const { return incubation_period; }
    double getReproductionRate() const { return reproduction_rate; }
};

class EpidemicSystem {
public:
    void addVirusFromConsole();
    // Другие методы, связанные с эпидемиологической системой

private:
    std::vector<Virus> active_epidemics;
};

#endif // VIRUS_H

#include <iostream>
