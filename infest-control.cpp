// ============================== //
// == ГЛАВНЫЙ ПРОГРАММНЫЙ ФАЙЛ == //
// ============================== //

#include <iostream>

//==> ИМПОРТ ВСЕХ КЛАССОВ
#include <classes/Saving.h> // Сохранения
#include <classes/Desease.h> // Болезни
#include <classes/Measure.h> // Противодействия

//==> ИМПОРТ ВСЕХ ДОП.ФУНКЦИЙ
#include <utils/FileInteraction.h> // Взаимодействие с файлами
#include <utils/RewindTime.h> // Перемотка времени

using namespace std;



//==> PROGRAM'S CODE
void main(void) {
    //==> Loading Databases
    //==> Console Menu
}

/* 1. Открытие консольного меню. Пункты меню:
    – Начало моделирования (переход к сохранениям)
    – Добавление/Изменение вирусов, противодействий
    – Экспорт/Импорт вирусов, противодействий
    – Выход из программы

    Работает через очистку консоли после нажатия
    на подходящую клавишу через switch cases
*/

/* 2. Моделирование
    – Менюшка (добавление/изменение вирусов, противодействий;
        перемотка времени с выбором скорости; сохранить и выйти)
        + запрещать взаимодействовать с менюшкой во время перемотки
    – Перемотка времени через изменение параметров раз в 3-5 секунд
        на определенное количество дней, недель, месяцев (1x,2x,3x скорости)
    – Перемотка должна влиять на текущий сезон. Зима, Весна, Лето, Осень.
        Соответственно это 0-90, 91-180, 181-270, 271-360 дней.
        Формула вычисления сезона (сброс счетчика дней, после смены сезона):
          if (curr_day == 90):
            curr_season = (curr_season + 1) % 4
            curr_day = 0
*/

/* 3. Добавление вируса, противодействия
    – Выбор добавления: Вирус / Противодействие
    – 
*/