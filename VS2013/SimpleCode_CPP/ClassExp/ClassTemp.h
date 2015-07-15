#pragma once
class ClassTemp
{
public:
	ClassTemp();
	virtual ~ClassTemp();

	friend class FirendClass;

	void print();

private:
	int value=0;

};

class FirendClass
{
public:
	void setValue(ClassTemp& classTemp, int value);
};