// =================== //
// == CLASS DESEASE == //
// =================== //

#ifndef DESEASE_H
#define DESEASE_H

#include <string>
#include <vector>


// DESEASE
class Desease {
  private:
    std::string _name;
    bool _status; // Cured or not
    int _duration;
    int _lethalis; // Dead by day
    std::vector<int> _seasonality;

  public:
    Desease(const std::string& n, bool st, int lt, int dt, const std::vector<int>& sn);
};

// SETTERS
namespace dsesetters {
  void set_name(std::string& _name);
  void set_status(bool _status);
  void set_duration(int _duration);
  void set_lethalis(int _lethalis);
  void set_seasonality(std::vector<int>& _seasonality);
}

// GETTERS
namespace dsegetters {
  const std::string get_name(std::string& _name);
  bool get_status(bool _status);
  int get_duration(int _duration);
  int get_lethalis(int _lethalis);
  const std::vector<int> get_seasonality(std::vector<int>& _seasonality);
}


#endif // DESEASE_H
