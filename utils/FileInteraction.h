// =============================== //
// === INTERACTIONS WITH FILES === //
// =============================== //

#include <iostream>
#include <fstream>

#include "../classes/Measure.h"
#include "../classes/Desease.h"


#ifndef FILEINTERACTION_H_
#define FILEINTERACTION_H_

namespace File {
	// Get/save Desease from file system
	bool get_desease(vector<Desease>& desease, int end_of_vector); // (вектор заболеваний, nameofvector.size())
	bool set_desease(vector<Desease>& desease);
	// Get/save measure from file system
	bool get_measure(vector<Measure>& measure, int end_of_vector);	// (вектор противодействий, nameofvector.size())
	bool set_measure(vector<Measure>& measure);
}

#endif // FILEINTERACTION_H_