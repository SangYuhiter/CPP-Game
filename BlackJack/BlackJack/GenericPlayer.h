#pragma once
//一般玩家类，计算机和人类玩家的基类
#include "Hand.h"

class GenericPlayer :public Hand {
	friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
public:
	GenericPlayer(const string& name = "");
	virtual ~GenericPlayer();
	virtual bool IsHitting() const = 0;
	bool IsBusted()const;
	void Bust() const;
protected:
	string m_Name;
};

//构造函数
GenericPlayer::GenericPlayer(const string& name) :
	m_Name(name)
{}

//析构函数
GenericPlayer::~GenericPlayer()
{}

//判断玩家是否超出21点
bool GenericPlayer::IsBusted() const {
	return (GetTotal() > 21);
}


//输出玩家超出21点
void GenericPlayer::Bust() const {
	cout << m_Name << "超出21点\n";
}

//重载输出函数
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer) {
	os << aGenericPlayer.m_Name << ":\t";
	vector<Card*>::const_iterator pCard;
	if (!aGenericPlayer.m_Cards.empty()) {
		//输出手牌
		for (pCard = aGenericPlayer.m_Cards.begin();
			pCard != aGenericPlayer.m_Cards.end();
			++pCard) {
			os << *(*pCard) << "\t";
		}
		//输出点数
		if (aGenericPlayer.GetTotal() != 0)
		{
			cout << "(" << aGenericPlayer.GetTotal() << ")";
		}
	}
	else {
		os << "<enpty>";
	}
	return os;
}