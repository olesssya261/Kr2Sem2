#include "FileInput.h"//����������� HeaderFile � ������ ������ �� �����
#include <fstream>//���������� ����� � ������ �� �����
#include <iostream>//���������� ����� � ������
#include "CheckExeption.h"//����������� HeaderFile � ���������������� ������� ������ �����
#include "Checks.h"//����������� HeaderFile � ���������� ������ ����������������� �����
#include <filesystem>//����������� ���������� ��� �������� ��������� �����

std::vector<Herbivores> FileDataInput()//������� ����� ������ ������� �� �����
{
	std::vector<Herbivores> herbivores;//���������� ������� �������� Herbivores
	std::string fileName;//���������� ���������� ����� �����
	std::ifstream file;//�������� ������ ��� ������ �� �����
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);//��������� ��������� ������ ������ ��������� ��������������
	while (true)
	{
		std::cout << "������� ��� ����� (� ���������� .txt): " << std::endl;
		std::cin >> fileName;//���� ���� � �����

		
		try
		{
			if (fileName.find(".txt") == std::string::npos)//����� � ����� ����� ����� .txt, ���� ��������� �� ��������� �� ������� ������, ���������� ��������� ������
			{
				std::cout << "�� ������ ���������� � �����. ���������� �������. " << std::endl;
				continue;
			}
			file.open(fileName);
			if (std::filesystem::is_regular_file(fileName)) { //�������� �� ��������� �����
				std::cout << "���� ������ �������. " << std::endl;
			}
		}
		catch (const std::exception&)//��������� ������ ��� ������ �� �����
		{
			std::cout << " ��������� ������ ��� �������� �����. ��������� �������:" << std::endl;
			continue;

		}
		try {
			
			int objectCount = CheckLineI(file);//���������� ���������� ��������
			if(objectCount==0)
			{
				throw std::exception();
			}
			for (int i = 0; i < objectCount; i++) {
				std::string name = CheckLineS(file);//���� ���������� �����
				std::string methodOfNutrition = CheckLineS(file);//���� ���������� ������� �������
				double weight = CheckLineD(file);//���� ���������� ���� ���������
				std::string livingEnvironment = CheckLineS(file);//���� ���������� ����� ��������
				bool poisonous = CheckLineB(file);//���� ���������� ����������
				int averageLifeExpectancy = CheckLineI(file);//���� ���������� ������� ����������������� �����
				Herbivores herbivore(methodOfNutrition, weight, livingEnvironment, name, poisonous, averageLifeExpectancy);//�������� ������� ���� Herbivores
				herbivores.push_back(herbivore);//���������� � ����� ������� ������
			}
		}
		catch (const std::exception) {//��������� ������
			std::cout << "��������� ������ ��� ������ ����������. ��������� �������:" << std::endl;
			herbivores.clear();
			file.close();//�������� ������
			continue;
		}
		catch (const CheckException err) {//��������� ������ ����������������� �����  
			std::cout << err.GetMessage() << std::endl;//����� ��������� �� ������
			herbivores.clear();
			file.close();//�������� ������
			continue;
		}
		file.close();//�������� ������
		return  herbivores;
	}
}
