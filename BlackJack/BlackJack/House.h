#pragma once
//庄家类
#include "GenericPlayer.h"
class House :public GenericPlayer {
public:
	House(const string& name = "House");
	virtual ~House();
	virtual bool IsHitting() const;
	void FlipFirstCard();
};

//构造函数
House::House(const string& name) :
	GenericPlayer(name)
{}

//析构函数
House::~House()
{}

//庄家是否跟牌
bool House::IsHitting() const {
	return (GetTotal() <= 16);
}

//翻开庄家的第一张牌
void House::FlipFirstCard() {
	if (!(m_Cards.empty())) {
		m_Cards[0]->Flip();
	}
	else {
		cout << "没有未翻开的牌！\n";
	}
}