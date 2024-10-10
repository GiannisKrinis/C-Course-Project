#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <graphics.h>


class Player : public GameObject
{

 public:

	Player(GameState* gs, const std::string& name, int x, int y) : GameObject(gs,name) {//x,y �� ���� ���� �� ����� ������ � player

		this->x = x;
		this->y = y;
	}


	void init() {//���� �������� �� game � ������ try again � Player �������������� �� ����� ��� ��� ����
		x = 100;
		y = 500;
	}

	void update(float dt)
	{
		if (graphics::getKeyState( graphics::SCANCODE_UP ) == true) { //UP
			
				y = y - 2;
				
				if (y < 50) { //������� �� ��� ���� ���� ��� �� canvas
					y = 50;
				}
		
		}
		if (graphics::getKeyState(graphics::SCANCODE_DOWN) == true) { //DOWN
			
				y = y + 2;
				
				if (y > 950) {//������� �� ��� ���� ���� ��� �� canvas
					y = 950;
				}
		}

		if (graphics::getKeyState(graphics::SCANCODE_RIGHT) == true) { //RIGHT
			
		     x = x + 2; 
			
			if (x > 950) {//������� �� ��� ���� ����� ��� �� canvas
				x = 950;
			}
		}

		if (graphics::getKeyState(graphics::SCANCODE_LEFT) == true) { //LEFT
			 
			x = x - 2;

			if (x < 50) {//������� �� ��� ���� �������� ��� �� canvas
				x = 50;
			}
			 
		}
	}


	void draw()
	{
		graphics::Brush br;

		br.texture = "assets/me.png";
		br.outline_opacity = 0.0f;//��� �� �� ������ �� ����� ����������� ���� - ����
		graphics::drawRect(x, y, 100, 100, br);
	}
};