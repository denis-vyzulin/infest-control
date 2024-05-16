// ========================= //
// == CLASS GENERAL STATS == //
// ========================= //

#ifndef EPIDEMIC_H_
#define EPIDEMIC_H_

#include <iostream>

#include "Desease.h"


// EPIDEMIC
struct Epidemic {
    Desease desease;
    long int total_infected;
    long int total_dead;
    long int total_recovered;

    Epidemic(const Desease& v) : desease(v), total_infected(1), total_dead(0), total_recovered(0) {}
};

#endif // EPIDEMIC_H_
