// L1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct pipe                                        
{
	int id;                               
	float length;                                 
	int diameter;                         
	bool work;                                   
};

struct CS                         
{
	int id;
	string name;
	int manufactory;                      
	int manufactory_in_use;                     
	float efficiency;                              
};

template <typename T>

T CheckNumber(T left, T right)
{
	T x;
	while (((cin >> x)).fail() || x<left || x>right)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Ошибка при вводе" << endl << "Введите команду: ";
	}
	return x;
}
void Menu()
{
	system("CLS");
	cout << "1. Добавить трубу" << endl
		<< "2. Добавить КС" << endl
		<< "3. Просмотр всех объектов" << endl
		<< "4. Редактировать трубу" << endl
		<< "5. Редактировать КС" << endl
		<< "6. Сохранить" << endl
		<< "7. Загрузить" << endl
		<< "0. Выход" << endl << endl;
}

pipe PlusPipe()
{
	pipe pipecreated;
	cout << "Введите id - ";
	pipecreated.id = CheckNumber(0, 25000);
	cout << "Введите длину(м) - ";
	pipecreated.length = CheckNumber(0, 1000);
	cout << "Введите диаметр(мм) - ";
	pipecreated.diameter = CheckNumber(0, 500);
	cout << "Введите 1, если труба работает или 0 - если труба находится в ремонте -";
	pipecreated.work = CheckNumber(-1, 2);
	return pipecreated;
};

CS PlusCS()
{
	CS CScreated;
	cout << "Введите id - ";
	CScreated.id = CheckNumber(0, 25000);
	cout << "Введите название - ";
	cin.ignore();
	getline(cin, CScreated.name);
	cout << "Введите количество цехов - ";
	CScreated.manufactory = CheckNumber(0, 10000);
	cout << "Введите количество рабочих цехов - ";
	CScreated.manufactory_in_use = CheckNumber(0, 10000);
	cout << "Введите эффективность - ";
	CScreated.efficiency = CheckNumber(0, 1);
	return CScreated;
};

void View(const pipe& pipecreated, const CS& CScreated)
{
	if (pipecreated.id != 0) {
		cout << "Труба:" << endl;
		cout << "Идентификатор - " << pipecreated.id << endl;
		cout << "Длина(м) - " << pipecreated.length << endl;
		cout << "Диаметр(мм) - " << pipecreated.diameter << endl;
		cout << (pipecreated.work ? "Работает" : "Не работает") << endl << endl;
	}
	else {
		cout << "Нет данных по трубам" << endl << endl;
	}
	if (CScreated.id != 0) {
		cout << "Компрессорная станция:" << endl;
		cout << "Идентификатор - " << CScreated.id << endl;
		cout << "Название - " << CScreated.name << endl;
		cout << "Количество цехов - " << CScreated.manufactory << endl;
		cout << "Количество рабочих цехов - " << CScreated.manufactory_in_use << endl;
		cout << "Эффективность - " << CScreated.efficiency << endl;
	}
	else {
		cout << "Нет данных по компрессорным станциям" << endl << endl;
	}
};

void EditPipe(pipe& pipecreated)
{
	cout << "Изменить работу трубы?  " << endl << "да - 1, нет - 0";
	bool i = CheckNumber(-1, 2);
	if (i == 1) {
		pipecreated.work = !pipecreated.work;
	}
}

void EditCS(CS& CScreated)
{
	cout << "Добавить рабочую КС?(да - 1, нет - 0): ";
	bool i = CheckNumber(-1, 2);
	if (i == 1 && CScreated.manufactory > CScreated.manufactory_in_use) {
		CScreated.manufactory_in_use++;
	}
	cout << "Убрать рабочую КС?(да - 1, нет - 0): ";
	i = CheckNumber(-1, 2);
	if (i == 1 && CScreated.manufactory > CScreated.manufactory_in_use) {
		CScreated.manufactory_in_use++;
	}
}

void VivodTrub(const pipe& pipecreated)
{
	ofstream OutFile;
	OutFile.open("вывод трубы.txt", ios::out);
	if (pipecreated.diameter != 0) {
		OutFile << "Труба:" << endl;
		OutFile << "Идентификатор - " << pipecreated.id << endl;
		OutFile << "Длина(м) - " << pipecreated.length << endl;
		OutFile << "Диаметр(мм) - " << pipecreated.diameter << endl;
		OutFile << (pipecreated.work ? "Работает" : "Не работает") << endl << endl;
	}
	else {
		OutFile << "Нет введенной трубы!" << endl << endl;
	};
	OutFile.close();
}

void VivodCS(const CS& CScreated)
{
	ofstream OutFile;
	OutFile.open("вывод КС.txt", ios::out);
	if (CScreated.id != 0) {
		OutFile << "Компрессорная станция:" << endl;
		OutFile << "Идентификатор - " << CScreated.id << endl;
		OutFile << "Название - " << CScreated.name << endl;
		OutFile << "Количество цехов - " << CScreated.manufactory << endl;
		OutFile << "Количество рабочих цехов - " << CScreated.manufactory_in_use << endl;
		OutFile << "Эффективность - " << CScreated.efficiency << endl;
	}
	else {
	OutFile << "Нет введенной КС" << endl << endl;
}
OutFile.close();
};

pipe VvodTrub()
{
	pipe pipecreated;
	ifstream InFile;
	InFile.open("ввод трубы.txt", ios::in);
	if (!InFile.is_open())
		cout << "Файл не может быть открыт\n";
	else {
		InFile >> pipecreated.id >> pipecreated.length >> pipecreated.diameter >> pipecreated.work;
	}
	InFile.close();
	return pipecreated;
};
CS VvodCS()
{
	CS CScreated;
	ifstream InFile;
	InFile.open("ввод КС.txt", ios::in);
	if (!InFile.is_open())
		cout << "Файл не может быть открыт\n";
	else {
		InFile >> CScreated.id >> CScreated.name >> CScreated.manufactory >> CScreated.manufactory_in_use >> CScreated.efficiency;
	}
	InFile.close();
	return CScreated;
};


int main()
{
	pipe P;
	CS CSt;
	bool Pcheck = 0;
	bool CScheck = 0;
	setlocale(LC_ALL, "Russian");
	while (true) {
		Menu();
		switch (CheckNumber(-1, 8))
		{
			 case 1:
				 P = PlusPipe();
				 Pcheck = 1;
				 break;
			 case 2:
				 CSt = PlusCS();
				 CScheck = 1;
				 break;
			 case 3:
				 if (Pcheck==1 && CScheck==1) { View(P,CSt); system("pause"); }			
				 else { cout << "Неполные данные"; }
				 break;
			 case 4:
				 EditPipe(P);
				 break;
			 case 5:
				 EditCS(CSt);
				 break;
			 case 6:
				 VivodTrub(P);
				 VivodCS(CSt);
				 break;
			 case 7:
				 VvodTrub();
				 VvodCS();
				 break;
			 case 0:
				 exit(0);
				 break;
			 default:
				 cout << "Введите верное число" << endl;
				 system("pause");
				 break;
		}
	}
}
