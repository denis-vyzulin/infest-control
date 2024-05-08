// =========================== //
// == КЛАСС ПРОТИВОДЕЙСТВИЙ == //
// =========================== //

#include <iostream>


// Status of activity (active or inactive)
void Measure::setStatus(const bool status) {
	_status = status;
}

int Measure::getStatus() {
	return _status;
}

// Rates ???
void Measure::setRates(std::vector<int>&rates) {
	_rates.assign(rates.begin(), rates.end());
}

void Measure::getRates(std::vector<int>&rates) {
	rates.assign(_rates.begin(), _rates.end());
}

// Seasonality (Winter, Spring, Summer, Autumn)
void Measure::setSesonality(std::vector<int>&sesonality) {
	_sesonality.assign(sesonality.begin(), sesonality.end())
}

void Measure::getSesonality(std::vector<int>&sesonality) {
	sesonality.assign(_sesonality.begin(), _sesonality.end())
}
