// ============================== //
// == ВЗАИМОДЕЙСТВИЕ С ФАЙЛАМИ == //
// ============================== //

#include <iostream>
#include <fstream>
#include "Measure.h"
#include "Disease.h"


#ifndef FILEINTERACTION_H_
#define FILEINTERACTION_H_
namespace File {
	// Get Virus from file system / save to the file system
	bool outVirus(vector<Virus>& virus, int end_of_vector); // (вектор заболеваний, nameofvector.size())
	bool getVirus(vector<Virus>& virus);
	// Get measure from file system / save to the file system
	bool outMeasure(vector<Measure>& measure, int end_of_vector);	// (вектор противодействий, nameofvector.size())
	bool getMeasure(vector<Measure>& measure);
}
#endif
