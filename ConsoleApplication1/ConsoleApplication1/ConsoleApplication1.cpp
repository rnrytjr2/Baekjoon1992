// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <math.h>
#define collection cin.tie(NULL);ios_base::sync_with_stdio(false);
using namespace std;
int tree[64][64];
string Quadtree(int startx, int starty, int size)
{
	int samedata = tree[starty][startx];
	bool samecheck = true;
	if (size == 1)
	{
		return to_string(tree[starty][startx]);
	}
	for (int i = starty; i < starty + size; i++)
	{
		for (int j = startx; j < startx + size; j++)
		{
			if (samedata != tree[i][j])
			{
				samecheck = false;
				break;
			}
		}
		if (!samecheck)
		{
			break;
		}
	}
	if (samecheck)
	{
		return to_string(samedata);
	}
	else
	{
		return "(" + Quadtree(startx, starty, size / 2) + Quadtree(startx + size / 2, starty, size / 2) + Quadtree(startx, starty + size / 2, size / 2) + Quadtree(startx + size / 2, starty + size / 2, size / 2) + ")";
	}
}
int main()
{
	int size;
	cin >> size;
	string templine;
	for (int i = 0; i < size; i++)
	{
		cin >> templine;
		for (int j = 0; j < size; j++)
		{

			tree[i][j] = templine[j] - '0';
		}
	}
	cout << Quadtree(0, 0, size);
}
