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
	poo();//默认的构造函数没有参数
	void move();
	void bounceAndclamp();
	void draw(Graphics& gfx)const;
	void panduancollied( Player& a);//不会改变玩家参数
	
	static constexpr Vec2 MbottomRight{799-24,599-24 };//屎的分辨率
	bool geteatenorNot()const { return eaten; }//判断是否被吃掉
	int getEaterId() const {return eaterId;}//获取玩家ID
	
	static constexpr Vec2 res{ 24,24 };//屎的分辨率
	int getNumPoos()const { return numPoos; }//返回存活的便便

private:
	
	std::random_device seed;
	std::mt19937 random;
	std::uniform_int_distribution <int> fitx;
	std::uniform_int_distribution <int> fity;
	std::uniform_int_distribution <int> fitVx;
	std::uniform_int_distribution <int> fitVy;



	Vec2 pos ;
	Vec2 v = { 2,2 };
	bool eaten = 0;//吃掉了么,默认没有
	int eaterId = -1;
	static int numPoos;//便便总数
};

