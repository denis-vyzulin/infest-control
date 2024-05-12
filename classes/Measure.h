// =========================== //
// == КЛАСС ПРОТИВОДЕЙСТВИЙ == //
// =========================== //

#ifndef MEASURE_H
#define MEASURE_H

#include <vector>

class Measure {
public:
    void setStatus(const bool status);
    int getStatus();

    void setRates(const std::vector<int>& rates);
    void getRates(std::vector<int>& rates);

    void setSeasonality(const std::vector<int>& seasonality);
    void getSeasonality(std::vector<int>& seasonality);

private:
    bool _status;
    std::vector<int> _rates;
    std::vector<int> _seasonality;
};

#endif // MEASURE_H
