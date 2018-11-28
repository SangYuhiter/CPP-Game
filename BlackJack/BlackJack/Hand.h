#pragma once
//手牌：纸牌集合
#include "Card.h"
#include <vector>
using namespace std;

class Hand {
public:
	Hand();
	virtual ~Hand();
	void Add(Card* pCard);
	void Clear();
	int GetTotal() const;
protected:
	vector<Card*> m_Cards;
};

//构造函数
Hand::Hand() {
	//设定总空间大小为7
	m_Cards.reserve(7);
}

//析构函数
Hand::~Hand() {
	Clear();
}

//添加一张纸牌
void Hand::Add(Card* pCard) {
	m_Cards.push_back(pCard);
}

//清空手牌空间
void Hand::Clear() {
	//清空每一张纸牌
	vector<Card*>::iterator iter;
	for (iter = m_Cards.begin();
		iter != m_Cards.end(); ++iter) {
		delete *iter;
		*iter = 0;
	}
	m_Cards.clear();
}

//计算当前手牌点数
int Hand::GetTotal() const {
	//无牌，记为0
	if (m_Cards.empty()) {
		return 0;
	}
	//第一张纸牌朝下，记为0
	if (m_Cards[0]->GetValue() == 0) {
		return 0;
	}
	//开始计算(将ACE当成1)
	int total = 0;
	vector<Card*>::const_iterator iter;
	for (iter = m_Cards.begin();
		iter != m_Cards.end(); ++iter) {
		total += (*iter)->GetValue();
	}
	//ACE存在与否，将其视为1或11
	bool containsACE = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
		if ((*iter)->GetValue() == Card::ACE) {
			containsACE = true;
		}
	}
	//若有ACE且视ACE为11后不超出21
	if (containsACE&&total <= 11) {
		total += 10;
	}
	return total;
}