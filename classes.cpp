#include <iostream>
#include <string>

class User {
private:
    std::string password; 
    std::string path_to_folder; 
    int progress_day; 

public:
    std::string username; 

    User(const std::string& name, const std::string& path, const std::string& pass, int day) : 
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
