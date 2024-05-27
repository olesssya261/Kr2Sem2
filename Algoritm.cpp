#pragma once
#include <vector>//Библиотека подключения вектора
#include <iostream>//Библиотека ввода и вывода
#include "Herbivores.h"//Подключение HeaderFile с классом Herbivores
#include "Algoritm.h"//Подключение HeaderFile с списком алгоритмов
#include "Checks.h"//Подключение HeaderFile с проверками пользовательского ввода
#include "ConsoleOutput.h"//Подключение HeaderFile с функцией вывода списка животных на консоль
#include "Input.h"//Подключение HeaderFile с функцией ввода списка животных на консоль
#include "MainMenu.h"//Подключение HeaderFile с пунктами меню
void RemoveHerbivore(std::vector<Herbivores>& herbivores)//Функция удаления животных из списка
{
	while (true) {
		std::cout << "Введите номер животного которого хотите удалить" << std::endl;
		std::cout << "Ввод: ";
		int userChoice = GetPositiveIntMoreThen0();//Ввод индекса животного в списке
		std::cout << std::endl;
		if (herbivores.size() < userChoice) {//Проверка что индекс находится в пределах возможных
			std::cout<<"Животного под таким номером не существует. Повторите попытку" << std::endl;
			continue;
		}
		auto iter = herbivores.cbegin(); // указатель на первый элемент
		herbivores.erase(iter + userChoice-1);//Удаление элемента из вектора с индексом userChoice
		std::cout << "Животное под номером №"<< userChoice << " удалено"<< std::endl;
		if (!herbivores.empty()) {//Проверка что вектор не пуст
		std::cout << "Полученный список" << std::endl;
		ConsoleOutput(herbivores);//Вывод отредактированного списка животных
			std::cout << "Хотите удалить ещё животное?" << std::endl;
			std::cout << "1)Да" << std::endl;
			std::cout << "2)Нет" << std::endl;
			std::cout << "Ввод: ";
			userChoice = GetChoise();//Ввод пользовательского выбора
			std::cout << std::endl;
			if (userChoice == Yes) {
				continue;
			}
		}
		return;
	}
}
void AddHerbivore(std::vector<Herbivores>& herbivores)//Функция добавления новых животных в список
{
	std::vector<Herbivores> tmpHerbivores = ConsoleIput();//Ввод вектора добавляемых животных
	herbivores.insert(herbivores.end(), tmpHerbivores.begin(), tmpHerbivores.end());//Соединение старого и нового вектора (новый вектор добавляется в конец)
	std::cout << "Животные успешно добавлены" << std::endl;
	ConsoleOutput(herbivores);;//Вывод отредактированного списка животных
	std::cout << std::endl;
	return;
}
void ChangeHerbivore(std::vector<Herbivores>& herbivores)//Функция измений данных животных в списке
{
	while (true) {
		std::cout << "Введите номер животного данные которого хотите редактировать" << std::endl;
		std::cout << "Ввод: ";
		int userChoice = GetPositiveIntMoreThen0();//Ввод индекса животного в списке
		std::cout << std::endl;
		if (herbivores.size() < userChoice) {//Проверка что индекс находится в пределах возможных
			std::cout << "Животного под таким номером не существует. Повторите попытку" << std::endl;
			continue;
		}
		std::cout << "Введите название:" << std::endl;
		herbivores[userChoice-1].SetName(GetString());//Ввод переменной имени
		std::cout << "Введите способ питания:" << std::endl;
		herbivores[userChoice - 1].SetMethodOfNutrition(GetString());//Ввод переменной способа питания
		std::cout << "Введите вес животного:" << std::endl;
		herbivores[userChoice - 1].SetWeight(GetPositiveDoubleMoreThen0());//Ввод переменной веса животного
		std::cout << "Введите среду обитания животного:" << std::endl;
		herbivores[userChoice - 1].SetLivingEnvironment(GetString());//Ввод переменной среды обитания
		std::cout << "Животное ядовито:" << std::endl;
		std::cout << "1)Да" << std::endl;
		std::cout << "2)Нет" << std::endl;
		herbivores[userChoice - 1].SetPoisonous(GetTrueOrFalse());//Ввод переменной ядовитости
		std::cout << "Введите среднюю продолжительность жизни:" << std::endl;
		herbivores[userChoice - 1].SetAverageLifeExpectancy(GetPositiveIntMoreThen0());//Ввод переменной средней продолжительности жизни
		std::cout << "Животное под номером №" << userChoice << " изменено" << std::endl;
		std::cout << std::endl;
		std::cout << "Полученный список" << std::endl;
		ConsoleOutput(herbivores);//Вывод отредактированного списка животных
		std::cout << std::endl;
		std::cout << "Хотите изменить ещё животное?" << std::endl;
		std::cout << "1)Да" << std::endl;
		std::cout << "2)Нет" << std::endl;
		std::cout << "Ввод: ";
		userChoice = GetChoise();//Ввод пользовательского выбора
		std::cout << std::endl;
		if (userChoice == Yes) {
				continue;
		}
		return;
	}

}