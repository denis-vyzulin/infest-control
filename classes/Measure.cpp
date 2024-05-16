// =========================== //
// == КЛАСС ПРОТИВОДЕЙСТВИЙ РЕАЛИЗАЦИЯ == //
// =========================== //
#include "measure.h"

#include "Measures.h"

void Measure_set::setStatus(const bool status) {

	_status = status;
}

void Measure_set::setRates(std::vector<int>& rates) {

	_rates.assign(rates.begin(), rates.end());
}

void Measure_set::setSeasonality(std::vector<int>& seasonality) {

	_sesonality.assign(seasonality.begin(), seasonality.end())
}

int Measure_set::getStatus() {

	return _status;
}

void Measure::getRates(std::vector<int>& rates) {

	rates.assign(_rates.begin(), _rates.end());
}

void Measure::getSeasonality(std::vector<int>& seasonality) {

	seasonality.assign(_seasonality.begin(), _seasonality.end())
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

void Measure_data::redSeasonality(std::vector<int>& seasonality, unsigned int mod) {

	int getdat, getdat_v;
	switch (mod) {
	case 1:
		cout << "print new modifier for new seson" << endl;
		cin >> getdat;
		seasonality.push_back(getdat);
		cout << "new list of modifiers: " << endl;
		Measure_data::outSeasonality(&seasonality);
		break;
	case 2:
		cout << " select the modifier, that you want delete";
		Measure_data::outSeasonality(&seasonality);
		cin >> getdat;
		seasonality.erase(getdat);
		cout << "new list of modifiers: " << endl;
		Measure_data::outSeasonality(&seasonality);
		break;
	case 3:
		cout << "select the modifier, that you wand change";
		Measure_data::outSeasonality(&seasonality);
		cin >> getdat;
		cout << "print new value of modifier";
		cin >> getdat_v;
		seasonality.at(getdat) = getdat_v;
		cout << "new list of modifiers: " << endl;
		Measure_data::outSeasonality(&seasonality);
		break;
	}

	Measure::setSeasonality(&sesonality);
}

void Measure_data::outRates(std::vector<int>& rates) {

	for (int i = 0; i < rates.size(); i++)
		cout << i << ". " << rates.at(i) << ' ';
	cout << endl;
}


void Measure_data::outSeasonality(std::vector<int>& seasonality) {

	for (int i = 0; i < seasonality.size(); i++)
		cout << i << ". " << seasonality.at(i) << ' ';
	cout << endl;
}

void Measure::setStatus(const bool status) {
    _status = status;
}

int Measure::getStatus() {
    return _status;
}

void Measure::setRates(const std::vector<int>& rates) {
    _rates = rates;
}

void Measure::getRates(std::vector<int>& rates) {
    rates = _rates;
}

void Measure::setSeasonality(const std::vector<int>& seasonality) {
    _seasonality = seasonality;
}

void Measure::getSeasonality(std::vector<int>& seasonality) {
    seasonality = _seasonality;
}
#include <iostream>
