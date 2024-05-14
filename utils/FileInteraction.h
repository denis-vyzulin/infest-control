<<<<<<< HEAD
#include <iostream>
=======
// ============================== //
// == ВЗАИМОДЕЙСТВИЕ С ФАЙЛАМИ == //
// ============================== //

#include <iostream>
#include <fstream>
#include "Measure.h"
#include "Epidemic.h"


#ifndef FILEINTERACTION_H_
#define FILEINTERACTION_H_
namespace File {
	// Get epidemic from file system / save to the file system
	bool outEpidemic(vector<Epidemic>& epidemic, int end_of_vector); // (вектор заболеваний, nameofvector.size())
	bool getEpidemic(vector<Epidemic>& epidemic);
	// Get measure from file system / save to the file system
	bool outMeasure(vector<Measure>& measure, int end_of_vector);	// (вектор противодействий, nameofvector.size())
	bool getMeasure(vector<Measure>& measure);
}
#endif
>>>>>>> db4cd2304f8232e043036ec15920e33de1d23268
