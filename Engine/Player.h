#pragma once
#include "vec2.h"
#include "Keyboard.h"
#include "Graphics.h"
#include "pool.h"
#include <random>
class poo;
class Graphics;

class Player
{
public:
	Player();
	
	/***********��Ա����*************/
	void clampScreen(const Vec2&min, const Vec2&max);
	void PlayerA(const Keyboard& kbd);
	void PlayerB(const Keyboard& kbd);
	void scoring(const poo& poo);//���ʺ�ĳ���id�����ҵ�ID�Ҿ͵÷��ˡ�

	

	void drawPlayerA(Graphics& gfx)const;
	void drawPlayerB(Graphics& gfx)const;
	void drawAscore(Graphics& gfx)const;
	void drawBscore(Graphics& gfx)const;


	Vec2 getPos()const { return pos + res * 0.5; }	//��ȡ�������λ��
	static constexpr Vec2 res = { 20,20 };//������ķֱ���
	int getPlayerId() const { return id; }//��ȡ���ID
	int getScore() const { return score; }//��ȡ��ҷ���
	


private:
	std::random_device seed;
	std::mt19937 random;
	std::uniform_int_distribution <int> fitx;
	std::uniform_int_distribution <int> fity;
	Vec2 pos = { 400,300 };
	Vec2 v = { 2,2 };
	int score = 0;
	int id;
	 


};



