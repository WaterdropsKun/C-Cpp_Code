#include <string>
#include <iostream>
#include <vector>

class Person
{
public:
	Person() {}

	Person(std::string name_, int age_, float weight_, float height_)
	{
		name = name_;
		age = age_;
		weight = weight_;
		height = height_;
	}

	void showMysef()
	{
		std::cout << name << " " << age << " years old " << weight << "kg, " << height << "m." << std::endl;
	}

public:
	std::string name;
	int age;
	float weight;
	float height;
};


class ICompare
{
public:
	ICompare() {}
	virtual ~ICompare() {}

	int compareble(Person person1, Person person2)
	{
		return 0;
	}
};

class CompareByAge : public ICompare
{
public: 
	CompareByAge() {}
	virtual ~CompareByAge() {}

	int compareble(Person person1, Person person2)
	{
		return person1.age - person2.age;
	}
};

class CompareByHeight : public ICompare
{
public:
	CompareByHeight() {}
	virtual ~CompareByHeight() {}

	int compareble(Person person1, Person person2)
	{
		return person1.height - person2.height;
	}
};

class SortPerson
{
public:
	SortPerson(ICompare compare_) : compare(compare_) {}

	void sort(std::vector<Person> personList)
	{
		int n = personList.size();

		Person tmp;
		for (int i = n - 1; i > 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (compare.compareble(personList[j], personList[j + 1]))
				{
					tmp = personList[j];
					personList[j] = personList[j + 1];
					personList[j + 1] = tmp;
				}
			}
		}
	}

private:
	ICompare compare;
};

int main_strategy()
{
	std::vector<Person> personList;	

	personList.push_back(Person("Tony", 2, 54.5, 0.82));
	personList.push_back(Person("Jack", 31, 74.5, 0.82));
	personList.push_back(Person("Nick", 54, 44.5, 0.82));
	personList.push_back(Person("Eric", 23, 62.5, 0.82));
	personList.push_back(Person("Helen", 16, 45.5, 0.82));

	SortPerson sorter0 = SortPerson(CompareByAge());
	sorter0.sort(personList);

	for (std::vector<Person>::iterator it = personList.begin(); it != personList.end(); it++)
	{
		it->showMysef();
	}

	return 0;

}

