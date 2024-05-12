// =========================== //
// == КЛАСС ПРОТИВОДЕЙСТВИЙ РЕАЛИЗАЦИЯ == //
// =========================== //
#include "measure.h"

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
