#include <vector>//Библиотека подключения вектора
#include "Herbivores.h"//Подключение HeaderFile с классом Herbivores
#include "ConsoleOutput.h"//Подключение HeaderFile с выводом данных на консоль
#include <iostream>//Библиотека ввода и вывода


void ConsoleOutput(std::vector<Herbivores> herbivores)
{
	std::cout << "Количество животных:" << herbivores.size() << std::endl;
	std::cout << "Список животных:" << std::endl;
	int counter = 1;
	for (auto i = herbivores.begin(); i < herbivores.end(); ++i)//Перебор вектора травоядных при помощи итератора 
	{
		std::cout << "Животное №" << counter << ":" << std::endl;
		i->ShowFullIformation(); // Вызов метода по указателю
		counter++;
	}
}
