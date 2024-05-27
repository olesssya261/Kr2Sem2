#include <iostream>//Подключение библеотеки ввода и вывода
#include "PersonalInterface.h"

void ShowTask() {
	std::cout << "Необходимо разработать поля и методы, наследуемые из базового класса, а также собственные" << std::endl;
	std::cout << "компоненты производных классов." << std::endl;
	std::cout << "Базовый класс – млекопитающие; поля – способ питания, вес, среда" << std::endl;
	std::cout << "обитания. Производный класс – травоядные." << std::endl;
	}
void ShowMenu() {
	std::cout << "Меню редактирования:" << std::endl;
	std::cout << "1)Удалить запись" << std::endl;
	std::cout << "2)Добавить запись" << std::endl;
	std::cout << "3)Редактировать запись" << std::endl;
	std::cout << "4)Выйти" << std::endl;
	std::cout << "Ввод:";
}
void ShowOutputDataOption()
{
	std::cout << "Вы хотите сохранить исходные данные в файл?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Нет" << std::endl;
	std::cout << "Ввод:";
}
void ShowInputOption()
{
	std::cout << "Какой вид ввода данных вы хотите использовать?" << std::endl;
	std::cout << "1)Фаиловый" << std::endl;
	std::cout << "2)Консольный" << std::endl;
	std::cout << "Ввод:";
}

void ShowGreetings()
{
	std::cout << "Контрольная работа №2 Кутькина Олеся 4304г" << std::endl;
}

void ShowOutputType()
{
	std::cout << "Вы хотите записать данные в файл?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Нет" << std::endl;
	std::cout << "Ввод:";
}


void ShowOutputChoise()
{
	std::cout << "Вы хотите перезаписать данный фаил?" << std::endl;
	std::cout << "1)Да" << std::endl;
	std::cout << "2)Ввести новое имя(путь к фаилу)" << std::endl;
	std::cout << "Ввод:";
}
