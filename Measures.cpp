#include "Measures.h"

void Measure::setStatus(const bool status) {

	_status = status;
}

void Measure::setRates(std::vector<int>&rates) {

	_rates.assign(rates.begin(), rates.end());
}

void Measure::setSesonality(std::vector<int>&sesonality) {

	_sesonality.assign(sesonality.begin(), sesonality.end())
}

int Measure::getStatus() {

	return _status;
}

void Measure::getRates(std::vector<int>&rates) {

	rates.assign(_rates.begin(), _rates.end());
}

void Measure::getSesonality(std::vector<int>&sesonality) {

	sesonality.assign(_sesonality.begin(), _sesonality.end())
}

void Measure_data::redRates(std::vector<int>& rates, unsigned int mod) {
	
	int getdat, getdat_v;
	switch (mod) {
	case 1:
		cout << "print new modifier for new measure" << endl;
		cin >> getdat;
		rates.push_back(getdat);
		cout << "new list of modifiers: " << endl;
		Measure_data::outRates(&rates);
		break;
	case 2:
		cout << " select the modifier, that you want delete";
		Measure_data::outRates(&rates);
			cin >> getdat;
		rates.erase(getdat);
		cout << "new list of modifiers: " << endl;
		Measure_data::outRates(&rates);
		break;
	case 3:
		cout << "select the modifier, that you wand change";
		Measure_data::outRates(&rates);
		cin >> getdat;
		cout << "print new value of modifier";
		cin >> getdat_v;
		rates.at(getdat) = getdat_v;
		cout << "new list of modifiers: " << endl;
		Measure_data::outRates(&rates);
		break;
	}

	Measure::setRates(&rates);
}

void Measure_data::redSesonality(std::vector<int>& sesonality, unsigned int mod){
	
	int getdat, getdat_v;
	switch (mod) {
	case 1:
		cout << "print new modifier for new seson" << endl;
		cin >> getdat;
		sesonality.push_back(getdat);
		cout << "new list of modifiers: " << endl;
		Measure_data::outSesonality(&sesonality);
		break;
	case 2:
		cout << " select the modifier, that you want delete";
		Measure_data::outSesonality(&sesonality);
		cin >> getdat;
		sesonality.erase(getdat);
		cout << "new list of modifiers: " << endl;
		Measure_data::outSesonality(&sesonality);
		break;
	case 3:
		cout << "select the modifier, that you wand change";
		Measure_data::outSesonality(&sesonality);
		cin >> getdat;
		cout << "print new value of modifier";
		cin >> getdat_v;
		sesonality.at(getdat) = getdat_v;
		cout << "new list of modifiers: " << endl;
		Measure_data::outSesonality(&sesonality);
		break;
	}

	Measure::setSesonality(&sesonality);
}

void Measure_data::outRates(std::vector<int>& rates) {
	
	for (int i = 0;i < rates.size(); i++)
		cout << i << ". " << rates.at(i) << ' ';
	cout << endl;
}

void Measure_data::outSesonality(std::vector<int>& sesonality) {

	for (int i = 0;i < sesonality.size(); i++)
		cout << i << ". " << sesonality.at(i) << ' ';
	cout << endl;
}