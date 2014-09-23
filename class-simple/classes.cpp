#include <iostream>
#include <string>

using namespace std;

struct tStudent{
	string name;
	int age;
	int group;

	void print() const
	{
		cout << "name: " << name;
		cout << ", group: " << group;
		cout << ", age: " << age << endl;
	}
};	

int main()
{
	tStudent s;
	s.name = "Vasya";
	s.age = 17;
	s.group = 343;
	s.print();
	
	return 0;
}
