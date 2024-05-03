#include <vector>


//==> КЛАСС MEASURE
#ifndef MEASURES_H_
#define MEASURES_H_

class Measure {
	private:
		bool _status;
		std::vector<int> _rates;
		std::vector<int> _sesonality;
};

namespace Measure {
	void setStatus(const bool status);
	void setRates(std::vector<int>&rates);
	void setSesonality(std::vector<int>& sesonality);

	int getStatus();
	void getRates(std::vector<int>& rates);
	void getSesonality(std::vector<int>& sesonality);
}

namespace Measure_data {
	void redRates(std::vector<int>& rates,unsigned int mod);
	void redSesonality(std::vector<int>& sesonality,unsigned int mod);
	void outRates(std::vector<int>& rates);
	void outSesonality(std::vector<int>& sesonality);
}

#endif
