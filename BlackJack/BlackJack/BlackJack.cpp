// BlackJack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include "Game.h"

int main()
{
	cout << "\tWelcome to BlackJack!\n";
	//玩家数量
	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers>7) {
		cout << "玩家数目：";
		cin >> numPlayers;
	}
	//玩家姓名
	vector<string> names;
	string name;
	for (int i = 0; i < numPlayers; ++i) {
		cout << "输入玩家姓名：";
		cin >> name;
		names.push_back(name);
	}
	cout << endl;
	//进入游戏循环
	Game aGame(names);
	char again = 'y';
	while (again != 'n'&&again != 'N') {
		aGame.Play();
		cout << "\n再来一次？(y/n):";
		cin >> again;
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
