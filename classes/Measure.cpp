// =================== //
// == CLASS MEASURE == //
// =================== //

#include <iostream>
#include <string>
#include <vector>

#include "Measure.h"



// SETTER > MEASURE STATUS
void msrsetters::set_status(const bool status) {
	Measure::_status = status;
}


// SETTTER > MEASURE SEASONALITY
void msrsetters::set_seasonality(std::vector<int>& seasonality, unsigned int type) {
	// Receive changes
	switch (type) {
		// New seasonality ratio for Measure
		case 1:
			std::cout << "Enter seasonality ratio for Measure: " << std::endl;
			// Get new seasonality ratio
			int seasonality_ratio_new;
			std::cin >> seasonality_ratio_new;
			// Save it
			seasonality.push_back(seasonality_ratio_new);
			// Print changes
			std::cout << "Current seasonality ratios: " << std::endl;
			msrgetters::get_seasonality(&seasonality);
			break;
		
		// Delete Measure seasonality ratio
		case 2:
			std::cout << "Enter seasonality ratio for delete: ";
			msrgetters::get_seasonality(&seasonality);
			// Get seasonality ratio
			int seasonality_ratio_delete;
			std::cin >> seasonality_ratio_delete;
			// Delete it
			seasonality.erase(seasonality_ratio_delete);
			// Print changes
			std::cout << "Current seasonality ratios: " << std::endl;
			msrgetters::get_seasonality(&seasonality);
			break;

		// Change Measure seasonality ratio
		case 3:
			std::cout << "Select seasonality ratio for change: ";
			msrgetters::get_seasonality(&sesonality);
			// Get old seasonality ratio
			int seasonality_ratio_old;
			std::cin >> seasonality_ratio_old;
			std::cout << "Enter new ratio: ";
			// Get new seasonality ratio
			int seasonality_ratio_new;
			std::cin >> seasonality_ratio_new;
			// Save new seasonality ratio
			sesonality.at(seasonality_ratio_old) = seasonality_ratio_new;
			// Print changes
			std::cout << "Current seasonality ratios: " << std::endl;
			msrgetters::get_seasonality(&seasonality);
			break;
	}

	// Save changes
	Measure::set_seasonality(&seasonality);
}


// GETTER > STATUS
bool msrgetters::get_status() {
	return Measure::_status;
}


// GETTER > SEASONALITY
std::vector<int> msrgetters::get_seasonality() {
	for (int i = 0; i < _seasonality.size(); i++) {
		std::cout << i << ". " << _seasonality.at(i) << ' ';
	}
	std::cout << std::endl;
	return Measure::_seasonality;
}
