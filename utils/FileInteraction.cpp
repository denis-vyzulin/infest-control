// ============================= //
// == INTERACTIONS WITH FILES == //
// ============================= //

#include <iostream>
#include <fstream>
#include <vector>

#include "Desease.h"
#include "Measure.h"
#include "FileInteraction.h"

using namespace std;


// GETTER > DESEASE
bool File::get_desease(vector<Desease>& desease, int end_of_vector) {
	// Open file with saved deseases
	ofstream output("db/Deseases.txt");
	if (output.is_open() != false)
		return false;
	// Print values
	for (int i = 0; i < end_of_vector; i++) {
		output << virus[i].get_name() << " ";
		output << virus[i].get_duration() << " ";
		output << virus[i].get_lethalis() << " ";
		output << virus[i].get_seasonality() << '\n';
	}
	// Close it
	input.close();
	return true;
}


// SETTER > DESEASE
bool File::set_desease(vector<Desease>& desease) {
	string name;
	int lethalis, duration;
	vector<int> seasonality;
	// Open file with saved deseases
	ifstream input("db/Epidemic.txt");
	if (intput.is_open() != false)
		return false;
	// Set deseases
	int i = 0;
	while (input.eof()!=false){
		input >> name >> lethalis >> duration >> seasonality;
		virus[i].set_name(name);
		virus[i].set_duration(duration);
		virus[i].set_lethalis(lethalis);
		virus[i].set_seasonality(seasonality);
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
	bool status; 
	vector<int> seasonality;
	// Get measure data
	status = msrgetters::get_status();
	msrgetters::get_seasonality(&seasonality);
	// Open file with all measures
	ofstream output("db/Measure.txt");
	if (output.is_open() != false)
		return false;
	// Print measures
	for (int i = 0; i < end_of_vector; i++) {
		output << status << " ";
		output << "I " << seasonality.size();
		for (int i2 = 0; i2 < seasonality.size(); i2++)
			output << seasonality[i2] << " ";
		output << '\n';
	}
	// Close it
	output.close();
	return true;
}


// SETTER > MEASURE
bool File::set_measure(vector<Measure>& measure) {
	bool status;
	vector<int> seasonality;
	// Open file with all measures
	ifstream input("db/Measures.txt");
	if (input.is_open() != false)
		return false;
	// Set new measure
	while (input.eof() != false) {					
		input >> status;
		for (int i = 0; i < 4; i++)
			input >> seasonality[i];
		measure[i2].msrsetters::set_status(&status);
		measure[i2].msrsetters::set_seasonality(&seasonality);
	}
	// Close it
	input.close();
	return true;
}
