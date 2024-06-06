#include "FileInput.h"//Подключение HeaderFile с вводом данных из фаила
#include <fstream>//Библеотека ввода и вывода из фаила
#include <iostream>//Библеотека ввода и вывода
#include "CheckExeption.h"//Подключение HeaderFile с пользовательским классом ошибок ввода
#include "Checks.h"//Подключение HeaderFile с обработкой ошибок пользовательского ввода
#include <filesystem>//Подключение библеотеки для проверки состояния фаила

std::vector<Herbivores> FileDataInput()//Функция ввода списка квартир из фаила
{
	std::vector<Herbivores> herbivores;//Объявления вектора объектов Herbivores
	std::string fileName;//Объявление переменной имени фаила
	std::ifstream file;//Создание потока для чтения из фаила
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);//Установка побитовых флагов ошибок файлового взаимодействия
	while (true)
	{
		std::cout << "Введите имя фаила (в разрешении .txt): " << std::endl;
		std::cin >> fileName;//Ввод пути к файлу

		
		try
		{
			if (fileName.find(".txt") == std::string::npos)//Поиск в имени фаила части .txt, если указатель не указывает на элемент строки, происходит повторный запрос
			{
				std::cout << "Не верное разрешение у файла. Повторитие попытку. " << std::endl;
				continue;
			}
			file.open(fileName);
			if (std::filesystem::is_regular_file(fileName)) { //Проверка на системные фаилы
				std::cout << "Фаил открыт успешно. " << std::endl;
			}
		}
		catch (const std::exception&)//Обработка ошибки при чтении из файла
		{
			std::cout << " Произошла ошибка при открытии файла. Повторите попытку:" << std::endl;
			continue;

		}
		try {
			
			int objectCount = CheckLineI(file);//Считывание количества объектов
			if(objectCount==0)
			{
				throw std::exception();
			}
			for (int i = 0; i < objectCount; i++) {
				std::string name = CheckLineS(file);//Ввод переменной имени
				std::string methodOfNutrition = CheckLineS(file);//Ввод переменной способа питания
				double weight = CheckLineD(file);//Ввод переменной веса животного
				std::string livingEnvironment = CheckLineS(file);//Ввод переменной среды обитания
				bool poisonous = CheckLineB(file);//Ввод переменной ядовитости
				int averageLifeExpectancy = CheckLineI(file);//Ввод переменной средней продолжительности жизни
				Herbivores herbivore(methodOfNutrition, weight, livingEnvironment, name, poisonous, averageLifeExpectancy);//Создание объекта типа Herbivores
				herbivores.push_back(herbivore);//Добавление в конец вектора обекта
			}
		}
		catch (const std::exception) {//Обработка ошибки
			std::cout << "Произошла ошибка при чтении информации. Повторите попытку:" << std::endl;
			herbivores.clear();
			file.close();//закрытие потока
			continue;
		}
		catch (const CheckException err) {//Обработка ошибки пользовательского ввода  
			std::cout << err.GetMessage() << std::endl;//Вывод сообщения об ошибки
			herbivores.clear();
			file.close();//закрытие потока
			continue;
		}
		file.close();//закрытие потока
		return  herbivores;
	}
}
