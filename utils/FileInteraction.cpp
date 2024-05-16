#include "FileInteraction.h"

bool File::outVirus(vector<Virus>& virus, int end_of_vector) {
	ofstream output("db/Disease.txt");
	if (output.is_open() != false)
		return false;
	for (int i = 0; i < end_of_vector; i++) {
		output << virus[i].getName() << " ";
		output << virus[i].getLethalRate() << " ";
		output << virus[i].getIncubationPeriod() << " ";
		output << virus[i].getReproductionRate() << '\n';
	}
	input.close();
	return true;
}
bool File::getVirus(vector<Virus>& virus) {
	char c;
	int i = 0;
	std::string name;
	double lethal_rate, reproduction_rate;
	int incubation_period;

	ifstream intput("db/Epidemic.txt");
	if (intput.is_open() != false)
		return false;

	while (input.eof()!=false){
		input >> name >> lethal_rate >> incubation_period >> reproduction_rate;
		virus[i].setName(name);
		virus[i].setLethalRate(lethal_rate);
		virus[i].setIncubationPeriod(incubation_period);
		virus[i].setReproductionRate(reproduction_rate);
		if (input.get(c) == '\n')
			i++;
	}
	input.close();
	return true;
}
bool File::outMeasure(vector<Measure>& measure, int end_of_vector) {
	
	bool status; 
	vector<int> rates;
	vector<int> seasonality;

	status = Measure_set::getStatus();
	Measure_set:::getRates(&rates);
	Measure_set::getSeasonality(&seasonality);

	ofstream output("db/Measure.txt");
	if (output.is_open() != false)
		return false;
	for (int i = 0; i < end_of_vector; i++) {
		output << status << " ";
		for (int i2 = 0; i2<rates.size();i2++)
			output << rates[i2] << " ";
		output << "I " << seasonality.size();
		for (int i2 = 0; i2 < seasonality.size(); i2++)
			output << seasonality[i2] << " ";
		output << '\n';
	}
	output.close();
	return true;
}
bool File::getMeasure(vector<Measure>& measure) {
	char c;
	int i = 0,i2 = 0, end;
	bool status;
	vector<int> rates;
	vector<int> seasonality;

	ifstream intput("db/Measure.txt");
	if (intput.is_open() != false)
		return false;

	while (input.eof() != false) {					
		input >> status;
		while (input.get(c) != 'I') {
			input >> rates[i];
			i++;
		}
		input >> end;
		for (i = 0; i < end; i++)
			input >> seasonality[i];
		measure[i2].Measure_set::setStatus(&status);
		measure[i2].Measure_set::setRates(&rates);
		measure[i2].Measure_set::setSeasonality(&seasonality);
		i2++;
	}

	input.close();
	return true;
}