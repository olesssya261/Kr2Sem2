#include <vector>//���������� ����������� �������
#include "Herbivores.h"//����������� HeaderFile � ������� Herbivores
#include "ConsoleOutput.h"//����������� HeaderFile � ������� ������ �� �������
#include <iostream>//���������� ����� � ������


void ConsoleOutput(std::vector<Herbivores> herbivores)
{
	std::cout << "���������� ��������:" << herbivores.size() << std::endl;
	std::cout << "������ ��������:" << std::endl;
	int counter = 1;
	for (auto i = herbivores.begin(); i < herbivores.end(); ++i)//������� ������� ���������� ��� ������ ��������� 
	{
		std::cout << "�������� �" << counter << ":" << std::endl;
		i->ShowFullIformation(); // ����� ������ �� ���������
		counter++;
	}
}
