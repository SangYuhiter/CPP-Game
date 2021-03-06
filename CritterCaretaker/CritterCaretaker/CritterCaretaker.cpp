// CritterCaretaker.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

//虚拟宠物类
class Critter {
public:
	Critter(int hunger = 0, int boredom = 0);
	void Talk();
	void Eat(int food = 4);
	void Play(int fun = 4);
private:
	int m_Hunger;
	int m_Boredom;
	int GetMood() const;
	void ShowDetail() const;
	void PassTime(int time = 1);
};

//构造函数，可默认初始化
Critter::Critter(int hunger,int boredom):
	m_Hunger(hunger),
	m_Boredom(boredom)
{}

//获取动物情绪值（内联）
inline int Critter::GetMood() const {
	return (m_Hunger + m_Boredom);
}

inline void Critter::ShowDetail() const {
	cout << "当前饥饿值：" << m_Hunger << " 厌倦值：" << m_Boredom << endl;
}

//增加饥饿、厌倦程度
void Critter::PassTime(int time) {
	m_Hunger += time;
	m_Boredom += time;
}

//交谈函数，输出情绪值，并推移时间
void Critter::Talk() {
	cout << "我是一个宠物，我感到";
	int mood = GetMood();
	if (mood > 15) {
		cout << "难过\n";
	}
	else if (mood > 10) {
		cout << "沮丧\n";
	}
	else if (mood > 5) {
		cout << "不错\n";
	}
	else {
		cout << "开心\n";
	}
	ShowDetail();
	PassTime();
}

//喂食函数，降低饥饿值
void Critter::Eat(int food) {
	cout << "开始喂食，喂食"<<food<<"食物\n";
	m_Hunger -= food;
	if (m_Hunger < 0) {
		m_Hunger = 0;
	}
	cout << "饥饿值变为：" << m_Hunger << endl;
	PassTime();
}

//玩耍函数，降低厌倦值
void Critter::Play(int fun) {
	cout << "开始玩耍，降低"<<fun<<"厌倦值\n";
	m_Boredom -= fun;
	if (m_Boredom < 0) {
		m_Boredom = 0;
	}
	cout << "厌倦值变为：" << m_Boredom << endl;
	PassTime();
}

int main()
{
	cout << "\tCritter Caretaker\n";
	cout << "0-退出\n";
	cout << "1-听宠物说话\n";
	cout << "2-喂食宠物\n";
	cout << "3-和宠物玩耍\n\n";
	Critter crit;
	crit.Talk();
	int choice;
	do {
		cout << "你的选择：";
		cin >> choice;
		switch (choice) {
		case 0:
			cout << "再见！\n";
			break;
		case 1:
			crit.Talk();
			break;
		case 2:
			crit.Eat();
			break;
		case 3:
			crit.Play();
			break;
		default:
			cout << "选择" << choice << "是不存在的！\n";
		}
	} while (choice != 0);
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
