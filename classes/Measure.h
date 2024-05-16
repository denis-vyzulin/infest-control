// =========================== //
// == КЛАСС ПРОТИВОДЕЙСТВИЙ == //
// =========================== //

#include <iostream>
#include <vector>

#ifndef MEASURES_H_
#define MEASURES_H_

class Measure {
private:
	bool _status;
	std::vector<int> _rates;
	std::vector<int> _sesonality;
};
namespace Measure_set {
	// Status of activity (active or inactive)
	void setStatus(const bool status);
	int getStatus();
	// Rates ???
	void setRates(std::vector<int>& rates);
	void getRates(std::vector<int>& rates);
	// Seasonality (Winter, Spring, Summer, Autumn)
	void setSeasonality(std::vector<int>& sesonality);
	void getSeasonality(std::vector<int>& sesonality);
}

namespace Measure_data {
	// Redaction data of measures
	void redRates(std::vector<int>& rates, unsigned int mod);
	void redSesonality(std::vector<int>& sesonality, unsigned int mod);
	// Output to the console data of measures
	void outRates(std::vector<int>& rates);
	void outSesonality(std::vector<int>& sesonality);
}

#endif

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
