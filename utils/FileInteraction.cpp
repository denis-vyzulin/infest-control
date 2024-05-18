// ============================= //
// == INTERACTIONS WITH FILES == //
// ============================= //

#include <iostream>
#include <fstream>
#include <vector>

#include "FileInteraction.h"
#include "classes/Desease.h"
#include "classes/Measure.h"

using namespace std;


// GETTER > DESEASE
bool File::get_desease(vector<Desease>& desease, int end_of_vector) {
	// Open file with saved deseases
	ofstream output("db/Deseases.txt");
	if (output.is_open() != false)
		return false;
	// Print values
	for (int i = 0; i < end_of_vector; i++) {
		output << desease[i].get_name() << " ";
		output << desease[i].get_incubation() << " ";
		output << desease[i].get_lethalis() << " ";
		output << desease[i].get_spread() << '\n';
	}
	// Close it
	input.close();
	return true;
}


// SETTER > DESEASE
bool File::set_desease(vector<Desease>& desease) {
	string name;
	int incubation;
	double lethalis, spread;
	// Open file with saved deseases
	ifstream input("db/Deseases.txt");
	if (intput.is_open() != false)
		return false;
	// Set deseases
	int i = 0;
	while (input.eof()!=false){
		input >> name >> incubation >> lethalis >> spread;
		desease[i].set_name(name);
		desease[i].set_incubation(incubation);
		desease[i].set_lethalis(lethalis);
		desease[i].set_spread(spread);
		// Enter key == close
		char c;
		if (input.get(c) == '\n')
			i++;
	}
	// Close it
	input.close();
	return true;
}


// GETTER > MEASURE
bool File::get_measure(vector<Measure>& measure, int end_of_vector) {
	string name;
	double effectiveness;
	// Get measure data
	name = msrgetters::get_name();
	effectiveness = msrgetters::get_effectiveness();
	// Open file with all measures
	ofstream output("db/Measures.txt");
	if (output.is_open() != false)
		return false;
	// Print measures
  for (int i = 0; i < end_of_vector; i++) {
		output << name << " ";
	  output << effectiveness << " ";
	}
	// Close it
	output.close();
	return true;
}


// SETTER > MEASURE
bool File::set_measure(vector<Measure>& measure) {
	string name;
	double effectiveness;
	// Open file with all measures
	ifstream input("db/Measures.txt");
	if (input.is_open() != false)
		return false;
	// Set new measure
	while (input.eof() != false) {					
		input >> name;
		input >> effectiveness;
	}
	// Close it
	input.close();
	return true;
}
