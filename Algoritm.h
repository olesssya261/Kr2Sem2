#pragma once
#include <vector>//Библиотека подключения вектора
#include "Herbivores.h"//Подключение HeaderFile с классом Herbivores
void RemoveHerbivore(std::vector<Herbivores>& herbivores);//Функция удаления животных из списка
void AddHerbivore(std::vector<Herbivores>& herbivores);//Функция добавления новых животных в список
void ChangeHerbivore(std::vector<Herbivores>& herbivores);//Функция измений данных животных в списке