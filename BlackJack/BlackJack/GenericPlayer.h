#pragma once
//һ������࣬�������������ҵĻ���
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

//���캯��
GenericPlayer::GenericPlayer(const string& name) :
	m_Name(name)
{}

//��������
GenericPlayer::~GenericPlayer()
{}

//�ж�����Ƿ񳬳�21��
bool GenericPlayer::IsBusted() const {
	return (GetTotal() > 21);
}


//�����ҳ���21��
void GenericPlayer::Bust() const {
	cout << m_Name << "����21��\n";
}

//�����������
ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer) {
	os << aGenericPlayer.m_Name << ":\t";
	vector<Card*>::const_iterator pCard;
	if (!aGenericPlayer.m_Cards.empty()) {
		//�������
		for (pCard = aGenericPlayer.m_Cards.begin();
			pCard != aGenericPlayer.m_Cards.end();
			++pCard) {
			os << *(*pCard) << "\t";
		}
		//�������
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