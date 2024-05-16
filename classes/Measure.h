// =================== //
// == CLASS MEASURE == //
// =================== //

#ifndef MEASURE_H_
#define MEASURE_H_

#include <iostream>
#include <vector>


// MEASURE
class Measure {
	private:
		// Status of activity (active or inactive)
		bool _status;
		// Seasonality (Winter, Spring, Summer, Autumn)
		std::vector<int> _seasonality;
};

// SETTERS
namespace msrsetters {
	void set_status(bool _status);
	void set_seasonality(std::vector<int>& _seasonality);
}

// GETTERS
namespace msrgetters {
	bool get_status(const bool _status);
	std::vector<int> msrgetters::get_seasonality(std::vector<int>& _seasonality);
}


#endif // MEASURE_H
