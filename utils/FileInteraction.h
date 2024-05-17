// ============================= //
// == INTERACTIONS WITH FILES == //
// ============================= //

#ifndef FILEINTERACTION_H_
#define FILEINTERACTION_H_

#include <iostream>
#include <fstream>

#include "Measure.h"
#include "Desease.h"


// File
namespace File {
	// Get/save Desease from file system
	bool out_desease(vector<Desease>& desease, int end_of_vector); // (вектор заболеваний, nameofvector.size())
	bool get_desease(vector<Desease>& desease);
	// Get/save measure from file system
	bool out_measure(vector<Measure>& measure, int end_of_vector);	// (вектор противодействий, nameofvector.size())
	bool get_measure(vector<Measure>& measure);
}

#endif // FILEINTERACTION_H_
