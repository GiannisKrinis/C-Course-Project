#pragma once


#include "GameObject.h"
#include "GameState.h"
#include <graphics.h>


class Nemo : public GameObject
{

public:

	Nemo(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name) {//x,y �� ���� ���� ����� ������ o Nemo

		this->x = x;
		this->y = y;
	}

	void init() {
		x = 1100; //���������� ���� init �� x ���� ���� �� �������� ���� �������������� �� ������������ ���� �
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

		br.texture = "assets/Nemo.png";
		br.outline_opacity = 0.0f;//��� �� �� ������ �� ����� ����������� ���� - ����
		graphics::drawRect(x, y, 50, 50, br);
	}
};
