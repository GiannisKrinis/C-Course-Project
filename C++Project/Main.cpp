#include <iostream>
#include <graphics.h>//sgg
#include "GameState.h"
using namespace std;


GameState game;

void update(float ms)
{
	game.update(ms);//���� ��� update ��� game ��� ������� ��� GameState
}

void draw()
{
	game.draw();//���� ��� draw ��� game ��� ������� ��� GameState
}

int main()
{	
	graphics::createWindow(1000, 1000, "Deep Waters");//������� ��������� ��� ��������� ��� �������� game (1000�1000)
	

	game.init();//������������
	

	graphics::Brush br;
	br.fill_color[0] = 0.5f;//red
	br.fill_color[1] = 0.4f;//green
	br.fill_color[2] = 0.5f;//blue

	graphics::setWindowBackground(br);

	graphics::playMusic("assets/music.ogg", 0.2, true, 0);//�������� OGG ��� mp3

	graphics::setUserData( &game );//sgg

	graphics::setDrawFunction(draw);//sgg

	graphics::setUpdateFunction(update);//sgg

	graphics::setCanvasSize(1000.0, 1000.0);//������ �� canvas ���� ������ ����� 

	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);// ��� �� ����� �� canvas
	graphics::setFont("assets/all.ttf"); //Font ��� ��� �� ����������� ���� �����
	graphics::startMessageLoop();//sgg
	graphics::destroyWindow();//sgg
	


	return 0;
}
