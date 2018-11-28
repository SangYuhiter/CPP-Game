#pragma once
//ׯ����
#include "GenericPlayer.h"
class House :public GenericPlayer {
public:
	House(const string& name = "House");
	virtual ~House();
	virtual bool IsHitting() const;
	void FlipFirstCard();
};

//���캯��
House::House(const string& name) :
	GenericPlayer(name)
{}

//��������
House::~House()
{}

//ׯ���Ƿ����
bool House::IsHitting() const {
	return (GetTotal() <= 16);
}

//����ׯ�ҵĵ�һ����
void House::FlipFirstCard() {
	if (!(m_Cards.empty())) {
		m_Cards[0]->Flip();
	}
	else {
		cout << "û��δ�������ƣ�\n";
	}
}