#pragma once
//���ƣ�ֽ�Ƽ���
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

//���캯��
Hand::Hand() {
	//�趨�ܿռ��СΪ7
	m_Cards.reserve(7);
}

//��������
Hand::~Hand() {
	Clear();
}

//���һ��ֽ��
void Hand::Add(Card* pCard) {
	m_Cards.push_back(pCard);
}

//������ƿռ�
void Hand::Clear() {
	//���ÿһ��ֽ��
	vector<Card*>::iterator iter;
	for (iter = m_Cards.begin();
		iter != m_Cards.end(); ++iter) {
		delete *iter;
		*iter = 0;
	}
	m_Cards.clear();
}

//���㵱ǰ���Ƶ���
int Hand::GetTotal() const {
	//���ƣ���Ϊ0
	if (m_Cards.empty()) {
		return 0;
	}
	//��һ��ֽ�Ƴ��£���Ϊ0
	if (m_Cards[0]->GetValue() == 0) {
		return 0;
	}
	//��ʼ����(��ACE����1)
	int total = 0;
	vector<Card*>::const_iterator iter;
	for (iter = m_Cards.begin();
		iter != m_Cards.end(); ++iter) {
		total += (*iter)->GetValue();
	}
	//ACE������񣬽�����Ϊ1��11
	bool containsACE = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
		if ((*iter)->GetValue() == Card::ACE) {
			containsACE = true;
		}
	}
	//����ACE����ACEΪ11�󲻳���21
	if (containsACE&&total <= 11) {
		total += 10;
	}
	return total;
}