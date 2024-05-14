#include "FileInteraction.h"

bool File::outEpidemic(vector<Epidemic>& epidemic, int end_of_vector) {
	ofstream output("db/Epidemic.txt");
	if (output.is_open() != false)
		return false;
	for (int i = 0; i < end_of_vector; i++) {
		output << epidemic[i].total_infected << " ";
		output << epidemic[i].total_dead << " ";
		output << epidemic[i].total_recovered << '\n';
	}
	
	return true;
}
bool File::getEpidemic(vector<Epidemic>& epidemic) {
	char c;
	int i = 0;
	ifstream intput("db/Epidemic.txt");
	if (intput.is_open() != false)
		return false;

	while (input.eof()!=false){
		intput >> epidemic[i].total_infected;
		intput >> epidemic[i].total_dead;
		intput >> epidemic[i].total_recovered;
		if (input.get(c) == '\n')
			i++;
	}

	return true;
}
bool File::outMeasure(vector<Measure>& measure, int end_of_vector) {
	
	bool status; 
	vector<int> rates;
	vector<int> sesonality;

	status = Measure_set::getStatus();
	Measure_set:::getRates(&rates);
	Measure_set::getSesonality(&sesonality);

	ofstream output("db/Measure.txt");
	if (output.is_open() != false)
		return false;
	for (int i = 0; i < end_of_vector; i++) {
		output << status << " ";
		for (int i2 = 0; i2<rates.size();i2++)
			output << rates[i2] << " ";
		for (int i2 = 0; i2 < sesonality.size(); i2++)
			output << sesonality[i2] << " ";
		output << '\n';
	}
	
	return true;
}
bool File::getMeasure(vector<Measure>& measure) {
	char c;
	int i = 0;
	ifstream intput("db/Measure.txt");
	if (intput.is_open() != false)
		return false;

	while (input.eof() != false) {					
		//intput >> measure[i].total_infected;
		//intput >> measure[i].rates;
		//intput >> measure[i].sesonality;
		//if (input.get(c) == '\n')
		//	i++;  
		// пока не сделано работать не будет 
	}

	return true;
}