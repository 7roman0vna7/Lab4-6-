#include <iostream>
using namespace std;

class Person {
private:
	static int count;
protected:
	int id;
	int age;
	string name;
	float height;

public:                                        
	static int GetCount() {return count;}      //Кол-во человек
	Person(const int& id, const string& name, const int& age, const float& height) : id(id), name(name), age(age), height(height)
	{
		count++;
	}

	void FullPrint()                        //Полная информация
	{
		cout << id << ' ' << name << ' ' << age << ' ' << height << endl;
	}

	void ShortPrint()           //Краткая информация
	{
		cout << id << ' ' << name << endl;
	}
};

int Person::count = 0;
int main() {
	setlocale(0, "");
	int input, age, n = 1, count;
	const int N = 2;
	Person* pers[N];
	string name;
	float height;
	while (n == 1)
	{
		cout << "Выберите действие (введите цифру):" << endl;             //Меню
		cout << "1) Ввод массива людей;" << endl;
		cout << "2) Редактировать информацию о человеке;" << endl;
		cout << "3) Посмотреть полную информацию о людях;" << endl;
		cout << "4) Посмотреть краткую информацию о людях." << endl;
		cin >> input;

		switch (input) {                   //Действия
		case 1:
			cout << "Введите данные " << N << " человек" << endl;
			for (int i = 0; i < N; i++)
			{
				int id = i + 1;
				cout << "Введите имя, возраст и рост:" << endl;
				cin >> name >> age >> height;
				pers[i] = new Person(id, name, age, height);           //Запись данных
				cout << "Вы ввели данные " << pers[i]->GetCount() << " человек." << endl;   //Вывод кол-ва людей
			}
			break;
		case 2:                 //Изменение данных
		{
			cout << "Введите id человека, данные которого нужно изменить" << endl;
			int id;
			cin >> id;
			int i = id - 1;
			cout << "Введите имя, возраст и рост:" << endl;
			cin >> name >> age >> height;
			pers[i] = new Person(id, name, age, height);
			break;
		}
		case 3:                      //Полная информация
			cout << "В системе записаны следующие пользователи (id, имя, возраст, рост):" << endl;
			for (int i = 0; i < N; i++)
				pers[i]->FullPrint();
			break;
		case 4:                      //Краткая информация
			cout << "В системе записаны следующие пользователи (id, имя):" << endl;
			for (int i = 0; i < N; i++)
				pers[i]->ShortPrint();
			break;
		default:                     //Ошибка
			cout << "Введите цифру строго от 1 до 4." << endl;
		}
		cout << " " << endl;             //Вернуть в меню
		n = 1;
	}
}