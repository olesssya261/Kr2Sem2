#pragma once
#include <vector>//���������� ����������� �������
#include <iostream>//���������� ����� � ������
#include "Herbivores.h"//����������� HeaderFile � ������� Herbivores
#include "Algoritm.h"//����������� HeaderFile � ������� ����������
#include "Checks.h"//����������� HeaderFile � ���������� ����������������� �����
#include "ConsoleOutput.h"//����������� HeaderFile � �������� ������ ������ �������� �� �������
#include "Input.h"//����������� HeaderFile � �������� ����� ������ �������� �� �������
#include "MainMenu.h"//����������� HeaderFile � �������� ����
void RemoveFunc(std::vector<Herbivores>& herbivores, int userChoice) {
	auto iter = herbivores.begin(); // ��������� �� ������ �������
	herbivores.erase(iter + userChoice - 1);//�������� �������� �� ������� � �������� userChoice
	return;
}
void RemoveHerbivore(std::vector<Herbivores>& herbivores)//������� �������� �������� �� ������
{
	while (true) {
		if (herbivores.size() == 1) {
			auto iter = herbivores.begin();
			herbivores.erase(iter);
			std::cout << "�������� �������." << std::endl;
			break;
		}
		std::cout << "������� ����� ���������, �������� ������ �������" << std::endl;
		std::cout << "����: ";
		int userChoice = GetPositiveIntMoreThen0();//���� ������� ��������� � ������
		std::cout << std::endl;
		if (herbivores.size() < userChoice) {//��������, ��� ������ ��������� � �������� ����������
			std::cout<<"��������� ��� ����� ������� �� ����������. ��������� �������" << std::endl;
			continue;
		}
		std::cout << "�������� ��� ������� �"<< userChoice << " �������"<< std::endl;
		RemoveFunc(herbivores, userChoice);
		std::cout << "���������� ������" << std::endl;
		ConsoleOutput(herbivores);//����� ������������������ ������ ��������
			std::cout << "������ ������� ��� ��������?" << std::endl;
			std::cout << "1) ��" << std::endl;
			std::cout << "2) ���" << std::endl;
			std::cout << "����: ";
			userChoice = GetChoise();//���� ����������������� ������
			std::cout << std::endl;
			if (userChoice == Yes) {
				continue;
			}
			return;
	}

}

void AddFunc(std::vector<Herbivores>& herbivores, std::vector<Herbivores> tmpHerbivores) {
	herbivores.insert(herbivores.end(), tmpHerbivores.begin(), tmpHerbivores.end());//���������� ������� � ������ ������� (����� ������ ����������� � �����)
	return;
}
void AddHerbivore(std::vector<Herbivores>& herbivores)//������� ���������� ����� �������� � ������ (�������� ������ �� ���������)
{
	std::vector<Herbivores> tmpHerbivores = ConsoleIput();//���� ������� ����������� ��������
	AddFunc(herbivores, tmpHerbivores);
	std::cout << "�������� ������� ���������" << std::endl;
	ConsoleOutput(herbivores);;//����� ������������������ ������ ��������
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
void ChangeHerbivore(std::vector<Herbivores>& herbivores)//������� ������� ������ �������� � ������
{
	while (true) {
		std::cout << "������� ����� ���������, ������ �������� ������ �������������" << std::endl;
		std::cout << "����: ";
		int userChoice = GetPositiveIntMoreThen0();//���� ������� ��������� � ������
		std::cout << std::endl;
		if (herbivores.size() < userChoice) {//��������, ��� ������ ��������� � �������� ����������
			std::cout << "��������� ��� ����� ������� �� ����������. ��������� �������." << std::endl;
			continue;
		}
		std::cout << "������� ��������:" << std::endl;
		std::string name = GetString();
		std::cout << "������� ������ �������:" << std::endl;
		std::string methodOfNutrition= GetString();
		std::cout << "������� ��� ���������:" << std::endl;
		double weight = GetPositiveDoubleMoreThen0();
		std::cout << "������� ����� �������� ���������:" << std::endl;
		std::string livingEnviroment= GetString();
		std::cout << "�������� �������:" << std::endl;
		std::cout << "1) ��" << std::endl;
		std::cout << "2) ���" << std::endl;
		bool poisionous = GetTrueOrFalse();
		std::cout << "������� ������� ����������������� �����:" << std::endl;
		int averageLifeExpectancy = GetPositiveIntMoreThen0();
		ChangeFunc(herbivores, userChoice, methodOfNutrition, weight, livingEnviroment, name, poisionous, averageLifeExpectancy);
		std::cout << "�������� ��� ������� �" << userChoice << " ��������" << std::endl;
		std::cout << std::endl;
		std::cout << "���������� ������" << std::endl;
		ConsoleOutput(herbivores);//����� ������������������ ������ ��������
		std::cout << std::endl;
		std::cout << "������ �������� ��� ��������?" << std::endl;
		std::cout << "1) ��" << std::endl;
		std::cout << "2) ���" << std::endl;
		std::cout << "����: ";
		userChoice = GetChoise();//���� ����������������� ������
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
	
