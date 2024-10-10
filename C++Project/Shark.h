#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <graphics.h>


class Shark : public GameObject
{

public:

	Shark(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name) {//x,y �� ���� ���� ����� ������ o Shark 

		this->x = x;
		this->y = y;
	}

	void init() {
		x = 1150; //���������� ���� init �� x ���� ���� �� �������� ���� �������������� �� ������������ ���� �
	}


	void update(float dt)
	{
		x = x - 1;

		if (x < 0) {
			x = 1000;
			y = rand() % 950; // ������� ���� �� ��������, �� �� ��� ������� ��� ����� ������ ���� ��� ����� �� ������ Y (����)
		}
	}

	
	void draw()
	{
		graphics::Brush br;

		br.texture = "assets/Shark.png";
		br.outline_opacity = 0.0f;//��� �� �� ������ �� ����� ����������� ���� - ����
		graphics::drawRect(x, y, 90, 90, br);
	}
};


