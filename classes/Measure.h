// ========================== //
// === MEASURE DEFINITION === //
// ========================== //

#include <iostream>
#include <string>


#ifndef MEASURE_H_
#define MEASURE_H_

class Measure {
  public:
    std::string _name;
    // Default effectiveness
    double _effectiveness;
    // Ratios for effectiveness by season
    // std::vector<int> _seasonality;
}

namespace msrsetters {
  void set_name(std::string& name);
  void set_effectiveness(double effectiveness);
}

namespace msrgetters {
  std::string get_name(vector<Measure>& measure);
  double get_effectiveness(vector<Measure>& measure);
}

#endif // MEASURE_H_
