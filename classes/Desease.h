// ========================== //
// === DESEASE DEFINITION === //
// ========================== //

#include <iostream>
#include <string>


#ifndef DESEASE_H_
#define DESEASE_H_

class Desease {
  public:
    std::string _name;
    // Duration of desease
    int _incubation;
    // Chance of death
    double _lethalis;
    // New infected by day
    double _spread;
}

namespace dsesetters {
  void set_name(vector<Desease>& desease, std::string& name);
  void set_incubation(vector<Desease>& desease, int incubation);
  void set_lethalis(vector<Desease>& desease, double lethalis);
  void set_spread(vector<Desease>& desease, double spread);
}

namespace dsegetters {
  std::string get_name(vector<Desease>& desease);
  int get_incubation(vector<Desease>& desease);
  double get_lethalis(vector<Desease>& desease);
  double get_spread(vector<Desease>& desease);
}

#endif // DESEASE_H_