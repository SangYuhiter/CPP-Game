// HangMan.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//挑选单词猜测字母
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
using namespace std;

int main()
{
    //游戏设置
	const int MAX_WRONG = 8;	//最大错误次数
	vector<string> words;
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");
	//打乱words排列
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];
	int wrong = 0;
	string soFar(THE_WORD.size(), '-');	//目前猜到的词，未猜到部分用短横线代替
	string used = "";
	cout << "\tWelcome to HangMan!\n";

	//进入游戏
	while (wrong < MAX_WRONG && soFar != THE_WORD) {
		//输出信息
		cout << "你还剩下" << MAX_WRONG - wrong << "次犯错机会"<<endl;
		cout << "你使用了这些字母：" << used << endl;
		cout << "目前为止，单词表示为：" << soFar << endl;

		//接受输入并猜测
		char guess;
		cout << "输入你的猜测字母：" << endl;
		cin >> guess;
		guess = toupper(guess);
		//去除重复猜测的情况
		while (used.find(guess) != string::npos) {
			cout << "你已经猜过这个字母：" << guess << endl;
			cout << "输入你的猜测字母：";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;
		if (THE_WORD.find(guess) != string::npos) {
			cout << "字母：" << guess << "在单词中" << endl;
			for (int i = 0; i < THE_WORD.length(); ++i) {
				if (THE_WORD[i] == guess) {
					soFar[i] = guess;
				}
			}
		}
		else {
			cout << "字母：" << guess << "不在词中" << endl;
			++wrong;
		}
	}
	//游戏结束
	if (wrong == MAX_WRONG) {
		cout << "对不起，你被绞死了！" << endl;
	}
	else {
		cout << "你猜对了！" << endl;
	}
	cout << "这个词是：" << THE_WORD << endl;
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
