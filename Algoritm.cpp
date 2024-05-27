#pragma once
#include <vector>//���������� ����������� �������
#include <iostream>//���������� ����� � ������
#include "Herbivores.h"//����������� HeaderFile � ������� Herbivores
#include "Algoritm.h"//����������� HeaderFile � ������� ����������
#include "Checks.h"//����������� HeaderFile � ���������� ����������������� �����
#include "ConsoleOutput.h"//����������� HeaderFile � �������� ������ ������ �������� �� �������
#include "Input.h"//����������� HeaderFile � �������� ����� ������ �������� �� �������
#include "MainMenu.h"//����������� HeaderFile � �������� ����
void RemoveHerbivore(std::vector<Herbivores>& herbivores)//������� �������� �������� �� ������
{
	while (true) {
		std::cout << "������� ����� ��������� �������� ������ �������" << std::endl;
		std::cout << "����: ";
		int userChoice = GetPositiveIntMoreThen0();//���� ������� ��������� � ������
		std::cout << std::endl;
		if (herbivores.size() < userChoice) {//�������� ��� ������ ��������� � �������� ���������
			std::cout<<"��������� ��� ����� ������� �� ����������. ��������� �������" << std::endl;
			continue;
		}
		auto iter = herbivores.cbegin(); // ��������� �� ������ �������
		herbivores.erase(iter + userChoice-1);//�������� �������� �� ������� � �������� userChoice
		std::cout << "�������� ��� ������� �"<< userChoice << " �������"<< std::endl;
		if (!herbivores.empty()) {//�������� ��� ������ �� ����
		std::cout << "���������� ������" << std::endl;
		ConsoleOutput(herbivores);//����� ������������������ ������ ��������
			std::cout << "������ ������� ��� ��������?" << std::endl;
			std::cout << "1)��" << std::endl;
			std::cout << "2)���" << std::endl;
			std::cout << "����: ";
			userChoice = GetChoise();//���� ����������������� ������
			std::cout << std::endl;
			if (userChoice == Yes) {
				continue;
			}
		}
		return;
	}
}
void AddHerbivore(std::vector<Herbivores>& herbivores)//������� ���������� ����� �������� � ������
{
	std::vector<Herbivores> tmpHerbivores = ConsoleIput();//���� ������� ����������� ��������
	herbivores.insert(herbivores.end(), tmpHerbivores.begin(), tmpHerbivores.end());//���������� ������� � ������ ������� (����� ������ ����������� � �����)
	std::cout << "�������� ������� ���������" << std::endl;
	ConsoleOutput(herbivores);;//����� ������������������ ������ ��������
	std::cout << std::endl;
	return;
}
void ChangeHerbivore(std::vector<Herbivores>& herbivores)//������� ������� ������ �������� � ������
{
	while (true) {
		std::cout << "������� ����� ��������� ������ �������� ������ �������������" << std::endl;
		std::cout << "����: ";
		int userChoice = GetPositiveIntMoreThen0();//���� ������� ��������� � ������
		std::cout << std::endl;
		if (herbivores.size() < userChoice) {//�������� ��� ������ ��������� � �������� ���������
			std::cout << "��������� ��� ����� ������� �� ����������. ��������� �������" << std::endl;
			continue;
		}
		std::cout << "������� ��������:" << std::endl;
		herbivores[userChoice-1].SetName(GetString());//���� ���������� �����
		std::cout << "������� ������ �������:" << std::endl;
		herbivores[userChoice - 1].SetMethodOfNutrition(GetString());//���� ���������� ������� �������
		std::cout << "������� ��� ���������:" << std::endl;
		herbivores[userChoice - 1].SetWeight(GetPositiveDoubleMoreThen0());//���� ���������� ���� ���������
		std::cout << "������� ����� �������� ���������:" << std::endl;
		herbivores[userChoice - 1].SetLivingEnvironment(GetString());//���� ���������� ����� ��������
		std::cout << "�������� �������:" << std::endl;
		std::cout << "1)��" << std::endl;
		std::cout << "2)���" << std::endl;
		herbivores[userChoice - 1].SetPoisonous(GetTrueOrFalse());//���� ���������� ����������
		std::cout << "������� ������� ����������������� �����:" << std::endl;
		herbivores[userChoice - 1].SetAverageLifeExpectancy(GetPositiveIntMoreThen0());//���� ���������� ������� ����������������� �����
		std::cout << "�������� ��� ������� �" << userChoice << " ��������" << std::endl;
		std::cout << std::endl;
		std::cout << "���������� ������" << std::endl;
		ConsoleOutput(herbivores);//����� ������������������ ������ ��������
		std::cout << std::endl;
		std::cout << "������ �������� ��� ��������?" << std::endl;
		std::cout << "1)��" << std::endl;
		std::cout << "2)���" << std::endl;
		std::cout << "����: ";
		userChoice = GetChoise();//���� ����������������� ������
		std::cout << std::endl;
		if (userChoice == Yes) {
				continue;
		}
		return;
	}

}