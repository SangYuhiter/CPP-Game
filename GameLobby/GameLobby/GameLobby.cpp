// GameLobby.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//游戏大厅

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

//玩家类
class Player {
	friend ostream& operator<<(ostream& os, const Player aPlayer);
public:
	Player(const string& name = "");
	string GetName() const;
	Player* GetNext() const;
	void SetNext(Player* next);
private:
	string m_Name;
	Player* m_pNext;	//指向下一个玩家
};

//构造函数
Player::Player(const string & name):
	m_Name(name),
	m_pNext(0)
{}

//GetName
string Player::GetName() const{
	return m_Name;
}

//GetNext
Player * Player::GetNext() const{
	return m_pNext;
}

//SetNext
void Player::SetNext(Player * next){
	m_pNext = next;
}

//重载输出符
ostream & operator<<(ostream & os, const Player aPlayer)
{
	os << aPlayer.GetName() << endl;
	return os;
}

//玩家大厅类
class Lobby {
	friend ostream& operator<<(ostream& os, const Lobby& aLobby);
public:
	Lobby();
	~Lobby();
	void AddPlayer();
	void RemovePlayer();
	void Clear();
private:
	Player* m_pHead;
	Player* m_pTail;
};

//构造函数
Lobby::Lobby() :
	m_pHead(0),
	m_pTail(0)
{}

//析构函数
Lobby::~Lobby() {
	Clear();
}

//添加玩家
void Lobby::AddPlayer(){
	cout << "输入新玩家名字：";
	string name;
	cin >> name;
	Player* pNewPlayer = new Player(name);
	//队列为空，该玩家为第一个
	if (m_pHead == 0) {
		m_pHead = pNewPlayer;
	}
	//找到队列尾，添加玩家
	else {
		m_pTail->SetNext(pNewPlayer);
	}
	//修改尾部指针
	m_pTail = pNewPlayer;
}

//移除玩家
void Lobby::RemovePlayer(){
	if (m_pHead == 0) {
		cout << "游戏大厅为空\n";
	}
	else {
		Player* pTemp = m_pHead;
		m_pHead = m_pHead->GetNext();
		delete pTemp;
	}
}

//移除所有玩家
void Lobby::Clear(){
	while (m_pHead != 0) {
		RemovePlayer();
	}
}

ostream & operator<<(ostream & os, const Lobby & aLobby){
	Player* pIter = aLobby.m_pHead;
	os << "\n大厅中的人数情况：\n";
	if (pIter == 0) {
		os << "大厅是空的！\n";
	}
	else {
		while (pIter != 0) {
			//os << pIter->GetName() << endl;
			os << *pIter;
			pIter = pIter->GetNext();
		}

	}
	return os;
}


int main()
{
	cout << "\tGame Lobby\n";
	cout << "0-退出游戏大厅！\n";
	cout << "1-添加一个玩家！\n";
	cout << "2-移除一个玩家！\n";
	cout << "3-清除所有玩家！\n";
	Lobby myLobby;
	int choice;
	do {
		cout << myLobby;
		cout << "输入选择：";
		cin >> choice;
		switch (choice) {
		case 0:
			cout << "再见！\n";
			break;
		case 1:
			myLobby.AddPlayer();
			break;
		case 2:
			myLobby.RemovePlayer();
			break;
		case 3:
			myLobby.Clear();
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


