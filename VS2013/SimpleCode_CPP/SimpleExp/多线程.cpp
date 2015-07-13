#include<thread>
#include<iostream>
#include<vector>

using namespace std;
using namespace std::this_thread;

void met()
{
	auto id=get_id();
	cout << "´ËÏß³ÌID:" << id << endl;
}

void mainDXC()
{
	vector<thread*> threads;

	for (size_t i = 0; i < 5; i++)
	{
		threads.push_back(new thread(met));
	}

	for (auto t : threads)
	{
		t->join();
	}

	system("pause");
}
