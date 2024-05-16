// =================== //
// == CLASS DESEASE == //
// =================== //

#include <iostream>
#include <string>
#include <vector>

#include "Desease.h"



Desease::Desease(const std::string& n, bool st, int lt, int dt, const std::vector<int>& sn)
    : name(n), status(st), lethalis(lt), duration(dt), seasonality(sn) {}

// Добавить описание самих функций
