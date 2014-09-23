#include <iostream>
#include <string>

using namespace std;

struct tStudent{
private:
	int age;
public:
	string name;
	int group;
	
	//конструктор класса
	tStudent(string _name, int _group, int _age)
			:age(_age),
			 name(_name),
			 group(_group)
	{
		cout << "Новый студент в группе " << group
			 << ", зовут " << name << endl;
	}

	void print() const
	{
		cout << "name: " << name;
		cout << ", group: " << group;
		cout << ", age: " << age << endl;
	}
	void aging()
	{
		age++;
		cout << "Happy Birthday! New age = " << age << endl;
	}
	void setAge(int newAge)
	{
		age = newAge;
	}
	int getAge() const
	{
		return age;
	}
};	

int main()
{
	tStudent s("Вася", 343, 17);
	s.print();
	s.aging();
	s.print();
	s.age = 12;
	
	return 0;
}
