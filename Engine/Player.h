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
	
	/***********成员函数*************/
	void clampScreen(const Vec2&min, const Vec2&max);
	void PlayerA(const Keyboard& kbd);
	void PlayerB(const Keyboard& kbd);
	void scoring(const poo& poo);//如果屎的吃者id等于我的ID我就得分了。

	

	void drawPlayerA(Graphics& gfx)const;
	void drawPlayerB(Graphics& gfx)const;
	void drawAscore(Graphics& gfx)const;
	void drawBscore(Graphics& gfx)const;


	Vec2 getPos()const { return pos + res * 0.5; }	//获取玩家中心位置
	static constexpr Vec2 res = { 20,20 };//玩家脸的分辨率
	int getPlayerId() const { return id; }//获取玩家ID
	int getScore() const { return score; }//获取玩家分数
	


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



