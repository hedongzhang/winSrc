#include<iostream>
using namespace std;

class ClassTemp
{
public:
	ClassTemp();
	virtual ~ClassTemp();

	friend class FirendClass;
	int print();
	friend ostream& operator<<(ostream&, ClassTemp);
	ClassTemp& operator+(ClassTemp& tempclass1);
private:
	int value=0;
};


class FirendClass
{
public:
	void setValue(ClassTemp& classTemp, int value);

	void setValue(int value);
	int printf();
private:
	int value=0;
};

FirendClass& operator+(ClassTemp& tempclass, FirendClass& firendclass);