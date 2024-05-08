// ====================== //
// == ФАЙЛ НА УДАЛЕНИЕ == //
// ====================== //

#include <vector>
#include <iostream>
#include <string>



//==> КЛАСС USER
class User {
  private:
    std::string password; 
    std::string path_to_folder; 
    int progress_day; 

  public:
    std::string username; 

  User(const std::string& name, const std::string& path, const std::string& pass, int day): 
    username(name), path_to_folder(path), password(pass), progress_day(day) {}

  void setUserName(const std::string& name) {
    username = name;
  }

  void setPassword(const std::string& pass) {
    password = pass;
  }

  std::string getPassword() {
    return password;
  }

  void setPathToFolder(const std::string& path) {
    path_to_folder = path;
  }

  std::string getPathToFolder() {
    return path_to_folder;
  }

  void setProgressDay(int day) {
    progress_day = day;
  }

  int getProgressDay() {
    return progress_day;
  }
};
//==> end of КЛАСС USER



//==> КЛАСС EPIDEMIC
#include "headings/Epidemic.h"

class Epidemic{
  unsigned long int _infected;
  unsigned long int _deseased;
  unsigned long int _cured;
  unsigned int _day_of_ep;

  public:
    Epidemic(){
      _infected = 0;
      _deseased = 0;
      _cured = 0;
      _day_of_ep = 0;
    }

  int getinfected() const{
    return _infected;
  }

  int getdeseased() const{
    return _deseased;
  }

  int getcured() const{
    return _cured;
  }

  int getday_of_ep() const{
    return _day_of_ep;
  }

  void setinfected(const unsigned long int &infected){
    _infected = infected;
  }

  void setdeseased(const unsigned long int &deseased){
    _deseased = deseased;
  }

  void setcured(const unsigned long int &cured){
    _cured = cured;
  }

  void setday_of_ep(const unsigned long int &day_of_ep){
    _day_of_ep = day_of_ep;
  }

  void print_status_of_ep(){
    std::cout << "Day of epidemic - " << _day_of_ep << "\n Infected - " << _infected << "\n Deseased - " << _deseased << "\n Cured - " << _cured << std::endl;
  }
};
//==> end of КЛАСС EPIDEMIC
