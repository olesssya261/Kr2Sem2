#include <iostream>//���������� ����� � ������
#include <windows.h>//���������� ������������� �� ������� ����������� �������
#include <conio.h>//���������� ������������� �� ������� getch
#include <vector>//���������� ����������� �������
#include "Herbivores.h"//����������� HeaderFile � ������� Herbivore
#include "MainMenu.h"//����������� HeaderFile � Enum-����
#include "Checks.h"//����������� HeaderFile � ���������� ����������������� �����
#include "ConsoleOutput.h"//����������� HeaderFile � ������� ������ �������� �� �������
#include "FileInput.h"//����������� HeaderFile � �������� ������
#include "FileOutput.h"//����������� HeaderFile � �������� �������
#include "Input.h"//����������� HeaderFile � ������ � �������
#include "Algoritm.h"//����������� HeaderFile � ������ � �������
#include "PersonalInterface.h"//����������� HeaderFile ����������������� ����������
#define QUIT 27//������ ������������ Esc �������� 27

int main()
{
	setlocale(LC_CTYPE, "RU"); //�����������
	SetConsoleCP(1251); //������� ��� ��������� ����������� � ��������� ���������� ��� �����
	SetConsoleOutputCP(1251); //������� ��� ��������� ����������� � ��������� ���������� ��� ������
	int userChoice = 0; //���������� ����������������� �����
	std::vector<Herbivores> herbivores; //������ ������� ��������
	ShowGreetings(); //����� �����������
	ShowTask(); //����� �������
	do
	{
		ShowInputOption(); //����� ���� ������
		userChoice = GetChoise(); //���� ����������������� �������
		switch (userChoice) //switch ������ ����������� ����� ��� ���������
		{
		case (ConsoleInput):
			herbivores = ConsoleIput(); //���� ������ �� ������������ � ������� 
			break;
		case (FileInput):
			herbivores = FileDataInput(); //���� ������ �� ������������ �� �����
			break;
		}
		std::cout << std::endl;
		ConsoleOutput(herbivores); //����� ��������� ������� �� �������
		std::cout << std::endl;
		bool flag = true;
		while (flag)
		{
			if (herbivores.empty())//�������� ��� ������ �� ����
			{
				std::cout << "��� ������ �������� ����." << std::endl;
				std::cout << std::endl;
				break;
			}
			ShowMenu();//����� ���� ��������������
			userChoice = GetMenuPoint();//���������������� ���� ������� ����
			std::cout << std::endl;
			switch (userChoice) //switch ������ ������� ���� ��������������
			{
			case Add:
				AddHerbivore(herbivores);//���������� ����� ��������
				break;
			case Remove:
				RemoveHerbivore(herbivores);//�������� �������� �� ������
				break;
			case Change:
				ChangeHerbivore(herbivores);//��������� ������ � ��������
				break;
			case Exit:
				flag = false;
				break;//����� �� ����
			}
		}
		if (!herbivores.empty())//�������� ��� ������ �� ����
		{
			ShowOutputType(); //����� ��������� �� ���������� ��������� ������ � ����
			userChoice = GetChoise(); // ���� ����������������� �������
			if (userChoice == Yes)
			{
				FileOutput(herbivores); //���������� ��������� ������� � ����
			}
		}
		herbivores.clear(); //������ ������� ��������
		std::cout << "������� Esc ����� ��������� ������ ���������." << std::endl;
		std::cout << "������� Enter ����� ����������." << std::endl;
		userChoice = _getch(); //���� ���� ������� ��������� � ����������
	} while (userChoice != QUIT); //�������� ��� ��� ������� ����� ���� ������� Quit
}
