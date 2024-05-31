#include <iostream>//Библеотека ввода и вывода
#include <windows.h>//Библеотека ответственная за русскую локализацию консоли
#include <conio.h>//Библеотека ответственная за функцию getch
#include <vector>//Библеотека подключения вектора
#include "Herbivores.h"//Подключение HeaderFile с классом Herbivore
#include "MainMenu.h"//Подключение HeaderFile с Enum-меню
#include "Checks.h"//Подключение HeaderFile с проверками пользовательского ввода
#include "ConsoleOutput.h"//Подключение HeaderFile с выводом списка животных на консоль
#include "FileInput.h"//Подключение HeaderFile с файловым вводом
#include "FileOutput.h"//Подключение HeaderFile с файловым выводом
#include "Input.h"//Подключение HeaderFile с вводом с консоли
#include "Algoritm.h"//Подключение HeaderFile с вводом с консоли
#include "PersonalInterface.h"//Подключение HeaderFile пользовательского интерфейса
#define QUIT 27//Макрос присваивания Esc значение 27

int main()
{
	setlocale(LC_CTYPE, "RU"); //Локализация
	SetConsoleCP(1251); //функции для настройки локализации в строковых переменных при вводе
	SetConsoleOutputCP(1251); //функции для настройки локализации в строковых переменных при выводе
	int userChoice = 0; //Переменная пользовательского ввода
	std::vector<Herbivores> herbivores; //Вектор вводных животных
	ShowGreetings(); //Вывод приветствия
	ShowTask(); //Вывод задания
	do
	{
		ShowInputOption(); //Вывод типа вввода
		userChoice = GetChoise(); //Ввод пользовательского решения
		switch (userChoice) //switch выбора консольного ввода или файлового
		{
		case (ConsoleInput):
			herbivores = ConsoleIput(); //Ввод данных об апартаментов с консоли 
			break;
		case (FileInput):
			herbivores = FileDataInput(); //Ввод данных об апартаментов из файла
			break;
		}
		std::cout << std::endl;
		ConsoleOutput(herbivores); //Вывод итогового массива на консоль
		std::cout << std::endl;
		bool flag = true;
		while (flag)
		{
			if (herbivores.empty())//Проверка что вектор не пуст
			{
				std::cout << "Ваш список животных пуст." << std::endl;
				std::cout << std::endl;
				break;
			}
			ShowMenu();//Вывод меню редактирования
			userChoice = GetMenuPoint();//Пользовательский ввод пунктов меню
			std::cout << std::endl;
			switch (userChoice) //switch выбора пунктов меню редактирования
			{
			case Add:
				AddHerbivore(herbivores);//Добавление новых животных
				break;
			case Remove:
				RemoveHerbivore(herbivores);//Удаление животных из списка
				break;
			case Change:
				ChangeHerbivore(herbivores);//Изменение данных о животных
				break;
			case Exit:
				flag = false;
				break;//Выход из меню
			}
		}
		if (!herbivores.empty())//Проверка что вектор не пуст
		{
			ShowOutputType(); //Вывод сообщения об сохранении выбранных данных в файл
			userChoice = GetChoise(); // Ввод пользовательского решения
			if (userChoice == Yes)
			{
				FileOutput(herbivores); //Сохранение итогового массива в фаил
			}
		}
		herbivores.clear(); //Чистка вектора животных
		std::cout << "Нажмите Esc чтобы завершить работу программы." << std::endl;
		std::cout << "Нажмите Enter чтобы продолжить." << std::endl;
		userChoice = _getch(); //Ввод кода символа введённого с клавиатуры
	} while (userChoice != QUIT); //Проверка что код символа равен коду макроса Quit
}
