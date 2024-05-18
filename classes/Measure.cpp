// ========================= //
// === MEASURE FUNCTIONS === //
// ========================= //

#include <iostream>
#include <string>

#include "Measure.h"


// SETTER > NAME
void msrsetters::set_name(vector<Measure>& measure, std::string& name) {
  measure::_name = name;
}

// SETTER > EFFECTIVENESS
void msrsetters::set_effectiveness(vector<Measure>& measure, double effectiveness) {
  measure::_effectiveness = effectiveness;
}


// GETTER > NAME
std::string msrgetters::get_name(vector<Measure>& measure) {
  return measure::_name;
}

// GETTER > EFFECTIVENESS
double msrgetters::get_effectiveness(vector<Measure>& measure) {
  return measure::_effectiveness;
}
