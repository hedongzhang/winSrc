#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct pos
{
	pos()
	{
		this->x = 0;
		this->y = 0;
	}

	pos(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int x;
	int y;

	bool check(pos other)
	{
		if (abs(other.x - this->x) == abs(other.y - this->y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	static bool judge(vector<pos> l_currPoss, pos posOther)
	{
		for (pos posTemp : l_currPoss)
		{
			if (posTemp.check(posOther))
				return false;
		}
		return true;
	}

	void print()
	{
		cout << "[" << this->x << "," << this->y << "]";
	}
};

int countNum = 0;

void bahuanghou(vector<int> xs, vector<int> ys, vector<pos> l_currPoss)
{
	if (xs.size()==0)
	{
		cout << ++countNum << ":\t";
		for (pos posTemp : l_currPoss)
		{
			posTemp.print();
			cout << "\t";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i<ys.size(); i++)
	{
		pos currPos(*xs.begin(), ys[i]);

		if (pos::judge(l_currPoss, currPos))
		{
			l_currPoss.push_back(currPos);
			vector<int> ysTemp(ys);
			vector<int> xsTemp(xs);
			xsTemp.erase(xsTemp.begin());
			ysTemp.erase(ysTemp.begin() + i);

			bahuanghou(xsTemp, ysTemp, l_currPoss);

			l_currPoss.pop_back();
		}
	}
}



int main(int argc, char *argv[])
{
    vector<int> xs={0,1,2,3,4,5,6,7,8};
    vector<int> ys={0,1,2,3,4,5,6,7,8};
	vector<pos> l_currPoss;
	l_currPoss.clear();
    bahuanghou(xs,ys,l_currPoss);

	system("pause");
    return 1;
}