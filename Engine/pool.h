#pragma once
#include"vec2.h"
#include"Graphics.h"
#include"Player.h"
#include <random>
class Player;
class Graphics;


class poo
{
public:
	poo();//Ĭ�ϵĹ��캯��û�в���
	void move();
	void bounceAndclamp();
	void draw(Graphics& gfx)const;
	void panduancollied( Player& a);//����ı���Ҳ���
	
	static constexpr Vec2 MbottomRight{799-24,599-24 };//ʺ�ķֱ���
	bool geteatenorNot()const { return eaten; }//�ж��Ƿ񱻳Ե�
	int getEaterId() const {return eaterId;}//��ȡ���ID
	
	static constexpr Vec2 res{ 24,24 };//ʺ�ķֱ���
	int getNumPoos()const { return numPoos; }//���ش��ı��

private:
	
	std::random_device seed;
	std::mt19937 random;
	std::uniform_int_distribution <int> fitx;
	std::uniform_int_distribution <int> fity;
	std::uniform_int_distribution <int> fitVx;
	std::uniform_int_distribution <int> fitVy;



	Vec2 pos ;
	Vec2 v = { 2,2 };
	bool eaten = 0;//�Ե���ô,Ĭ��û��
	int eaterId = -1;
	static int numPoos;//�������
};

