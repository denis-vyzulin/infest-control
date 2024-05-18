// ========================= //
// === DESEASE FUNCTIONS === //
// ========================= //

#include <iostream>
#include <string>

#include "Desease.h"


// SETTER > NAME
void dsesetters::set_name(vector<Desease>& desease, std::string& name) {
  desease::_name = name;
}

// SETTER > EFFECTIVENESS
void dsesetters::set_incubation(vector<Desease>& desease, int incubation) {
  desease::_incubation = incubation;
}

// SETTER > NAME
void dsesetters::set_lethalis(vector<Desease>& desease, double lethalis) {
  desease::_lethalis = lethalis;
}

// SETTER > EFFECTIVENESS
void dsesetters::set_spread(vector<Desease>& desease, double spread) {
  desease::_spread = spread;
}


// GETTER > NAME
void dsegetters::get_name(vector<Desease>& desease) {
  return desease::_name;
}

// GETTER > EFFECTIVENESS
void dsegetters::get_incubation(vector<Desease>& desease) {
  return desease::_incubation;
}

// GETTER > NAME
void dsegetters::get_lethalis(vector<Desease>& desease) {
  return desease::_lethalis;
}

// GETTER > EFFECTIVENESS
void dsegetters::get_spread(vector<Desease>& desease) {
  return desease::_spread;
}
