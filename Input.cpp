#include "Input.h"//Подключение HeaderFile с вводом данных с консоли
#include <iostream>//Библиотека ввода и вывода
#include "Checks.h"//Подключение HeaderFile с проверками пользовательского ввода
#include "MainMenu.h"//Подключение HeaderFile с Enum menu
#include "Herbivores.h"//Подключение HeaderFile с  классом Herbivores

std::vector<Herbivores> ConsoleIput()
{
	std::vector<Herbivores> herbivores;//Объявления вектора объектов Herbivores
	std::cout << "Добавление млекопитающих" << std::endl;
	int userChoice = 0;//Объявление переменной пользовательского ввода
	while(true)
	{
		std::cout << "Животное:" << std::endl;
		std::cout << "Введите название:" << std::endl;
		std::string name = GetString();//Ввод переменной имени
		std::cout << "Введите способ питания:" << std::endl;
		std::string methodOfNutrition = GetString();//Ввод переменной способа питания
		std::cout << "Введите вес животного:" << std::endl;
		double weight = GetPositiveDoubleMoreThen0();//Ввод переменной веса животного
		std::cout << "Введите среду обитания животного:" << std::endl;
		std::string livingEnvironment = GetString();//Ввод переменной среды обитания
		std::cout << "Животное ядовито:" << std::endl;
		std::cout << "1) Да" << std::endl;
		std::cout << "2) Нет" << std::endl;
		bool poisonous = GetTrueOrFalse();//Ввод переменной ядовитости
		std::cout << "Введите среднюю продолжительность жизни:" << std::endl;
		int averageLifeExpectancy = GetPositiveIntMoreThen0();//Ввод переменной средней продолжительности жизни
		Herbivores herbivore(methodOfNutrition,weight,livingEnvironment,name,poisonous,averageLifeExpectancy);//Создание объекта типа Herbivores
		herbivores.push_back(herbivore);//Добавление в конец вектора обекта
		std::cout << "Хотите добавить ещё животное"<<std::endl;
		std::cout << "1) Да" << std::endl;
		std::cout << "2) Нет" << std::endl;
		userChoice = GetChoise();//Ввод пользовательского решения
		if(userChoice == Yes)
		{
			continue;
		}
		else
		{
			return herbivores;
		}
	}
}
