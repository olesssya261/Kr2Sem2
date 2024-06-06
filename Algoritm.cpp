#pragma once
#include <vector>//Библиотека подключения вектора
#include <iostream>//Библиотека ввода и вывода
#include "Herbivores.h"//Подключение HeaderFile с классом Herbivores
#include "Algoritm.h"//Подключение HeaderFile с списком алгоритмов
#include "Checks.h"//Подключение HeaderFile с проверками пользовательского ввода
#include "ConsoleOutput.h"//Подключение HeaderFile с функцией вывода списка животных на консоль
#include "Input.h"//Подключение HeaderFile с функцией ввода списка животных на консоль
#include "MainMenu.h"//Подключение HeaderFile с пунктами меню
void RemoveFunc(std::vector<Herbivores>& herbivores, int userChoice) {
	auto iter = herbivores.begin(); // указатель на первый элемент
	herbivores.erase(iter + userChoice - 1);//Удаление элемента из вектора с индексом userChoice
	return;
}
void RemoveHerbivore(std::vector<Herbivores>& herbivores)//Функция удаления животных из списка
{
	while (true) {
		if (herbivores.size() == 1) {
			auto iter = herbivores.begin();
			herbivores.erase(iter);
			std::cout << "Животное удалено." << std::endl;
			break;
		}
		std::cout << "Введите номер животного, которого хотите удалить" << std::endl;
		std::cout << "Ввод: ";
		int userChoice = GetPositiveIntMoreThen0();//Ввод индекса животного в списке
		std::cout << std::endl;
		if (herbivores.size() < userChoice) {//Проверка, что индекс находится в пределах возможного
			std::cout<<"Животного под таким номером не существует. Повторите попытку" << std::endl;
			continue;
		}
		std::cout << "Животное под номером №"<< userChoice << " удалено"<< std::endl;
		RemoveFunc(herbivores, userChoice);
		std::cout << "Полученный список" << std::endl;
		ConsoleOutput(herbivores);//Вывод отредактированного списка животных
			std::cout << "Хотите удалить ещё животное?" << std::endl;
			std::cout << "1) Да" << std::endl;
			std::cout << "2) Нет" << std::endl;
			std::cout << "Ввод: ";
			userChoice = GetChoise();//Ввод пользовательского выбора
			std::cout << std::endl;
			if (userChoice == Yes) {
				continue;
			}
			return;
	}

}

void AddFunc(std::vector<Herbivores>& herbivores, std::vector<Herbivores> tmpHerbivores) {
	herbivores.insert(herbivores.end(), tmpHerbivores.begin(), tmpHerbivores.end());//Соединение старого и нового вектора (новый вектор добавляется в конец)
	return;
}
void AddHerbivore(std::vector<Herbivores>& herbivores)//Функция добавления новых животных в список (получаем вектор по указателю)
{
	std::vector<Herbivores> tmpHerbivores = ConsoleIput();//Ввод вектора добавляемых животных
	AddFunc(herbivores, tmpHerbivores);
	std::cout << "Животные успешно добавлены" << std::endl;
	ConsoleOutput(herbivores);;//Вывод отредактированного списка животных
	std::cout << std::endl;
	return;
}

void ChangeFunc(std::vector<Herbivores>& herbivores, int userChoise, std::string methodOfNutrition, double weight, std::string livingEnvironment,
	std::string name, bool poisonous, int averageLifeExpectancy) {
	herbivores[userChoise - 1].SetMethodOfNutrition(methodOfNutrition);
	herbivores[userChoise - 1].SetWeight(weight);
	herbivores[userChoise - 1].SetLivingEnvironment(livingEnvironment);
	herbivores[userChoise - 1].SetName(name);
	herbivores[userChoise - 1].SetPoisonous(poisonous);
	herbivores[userChoise - 1].SetAverageLifeExpectancy(averageLifeExpectancy);
	return;
}
void ChangeHerbivore(std::vector<Herbivores>& herbivores)//Функция измений данных животных в списке
{
	while (true) {
		std::cout << "Введите номер животного, данные которого хотите редактировать" << std::endl;
		std::cout << "Ввод: ";
		int userChoice = GetPositiveIntMoreThen0();//Ввод индекса животного в списке
		std::cout << std::endl;
		if (herbivores.size() < userChoice) {//Проверка, что индекс находится в пределах возможного
			std::cout << "Животного под таким номером не существует. Повторите попытку." << std::endl;
			continue;
		}
		std::cout << "Введите название:" << std::endl;
		std::string name = GetString();
		std::cout << "Введите способ питания:" << std::endl;
		std::string methodOfNutrition= GetString();
		std::cout << "Введите вес животного:" << std::endl;
		double weight = GetPositiveDoubleMoreThen0();
		std::cout << "Введите среду обитания животного:" << std::endl;
		std::string livingEnviroment= GetString();
		std::cout << "Животное ядовито:" << std::endl;
		std::cout << "1) Да" << std::endl;
		std::cout << "2) Нет" << std::endl;
		bool poisionous = GetTrueOrFalse();
		std::cout << "Введите среднюю продолжительность жизни:" << std::endl;
		int averageLifeExpectancy = GetPositiveIntMoreThen0();
		ChangeFunc(herbivores, userChoice, methodOfNutrition, weight, livingEnviroment, name, poisionous, averageLifeExpectancy);
		std::cout << "Животное под номером №" << userChoice << " изменено" << std::endl;
		std::cout << std::endl;
		std::cout << "Полученный список" << std::endl;
		ConsoleOutput(herbivores);//Вывод отредактированного списка животных
		std::cout << std::endl;
		std::cout << "Хотите изменить ещё животное?" << std::endl;
		std::cout << "1) Да" << std::endl;
		std::cout << "2) Нет" << std::endl;
		std::cout << "Ввод: ";
		userChoice = GetChoise();//Ввод пользовательского выбора
		std::cout << std::endl;
		if (userChoice == Yes) {
			continue;
		}
		return;
	}
}
bool operator == (Herbivores& herb1, Herbivores& herb2) {
	return herb1.GetFullInformation() == herb2.GetFullInformation();
}
	
