#pragma once
struct Vec2
{
	int x = 0 ;
	int y = 0 ;
	Vec2 operator += (const Vec2& b);
	Vec2 operator -= (const Vec2& b);
	void clamp(const Vec2& min, const Vec2& max);//��Ա���������棬��Ա����������
	friend Vec2 operator +  (const Vec2& a, const Vec2& b);
	friend Vec2 operator -  (const Vec2& a, const Vec2& b);
	friend Vec2 operator *  (const Vec2& a, float b);//����
	
}; 