/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();
	checkGamestartorNo(wnd.kbd);
	if(gameStart)
		UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	PlayerA.PlayerA(wnd.kbd);
	PlayerB.PlayerB(wnd.kbd);
	PlayerA.clampScreen(Graphics::topleft, Graphics::bottomright - Player::res);
	PlayerB.clampScreen(Graphics::topleft, Graphics::bottomright - Player::res);
	for(int i = 0 ; i < numPoo; i++)
	{	
		if (!poo[i].geteatenorNot())
		{
			poo[i].move();
			poo[i].bounceAndclamp();
			poo[i].panduancollied(PlayerA);
			if (!poo[i].geteatenorNot())
				poo[i].panduancollied(PlayerB);
			
			PlayerA.scoring(poo[i]);
			PlayerB.scoring(poo[i]);
		}
		
		
	}

}







void Game::ComposeFrame()
{
	if(!gameStart)//����Ϸû��ʼ
		derawTitle(Graphics::center.x - titleRes.x*0.5, Graphics::center.y - titleRes.y*0.5); // ���Ʒ���
	else
	{
		for (int i = 0; i < numPoo; i++)
		{
			if (!poo[i].geteatenorNot())
				poo[i].draw(gfx);
		}
		/*for (int i = 0; i < PlayerA.getScore(); ++i)
		gfx.drawRect(5, 593, 10, 3, Colors::Yellow);
		for (int i = 0; i < PlayerA.getScore(); ++i)
		gfx.drawRect(16, 593, 10, 3, Colors::Cyan);*/
		PlayerA.drawAscore(gfx);//������
		PlayerB.drawBscore(gfx);
		PlayerA.drawPlayerA(gfx);//��ҵ���
		PlayerB.drawPlayerB(gfx);
	}
	bool allDie = 1;
	for (int i = 0; i < numPoo; i++)
	{
		allDie = allDie && poo[i].geteatenorNot();//���߶�Ϊ�棬�����Ϊ�棬ֻ��һ���������ߵ��߼�����Ͳ�Ϊ��
		gameOver = allDie;
		if (!poo[i].geteatenorNot())
			poo[i].draw(gfx);
	}			//�����б�㱻�Ե����ͻ�õ�gameover=1��
	
	if(gameOver)//����Ϸ������
	derawEnd(Graphics::center.x - endRes.x*0.5, Graphics::center.y - endRes.y*0.5); // ���Ʒ���///052D
	
	
	
	
	
	

}