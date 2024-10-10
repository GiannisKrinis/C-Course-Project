#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <graphics.h>

//class GameState;

class Score : public GameObject
{
	int score;

public:

	Score(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name) {

		this->x = x;
		this->y = y;
		score = 0;
	}

	void update(float dt){} 

	void init()
	{
		score = 0;//���� ������� ������������, �� score ������� ���� 0 
	}

	void draw()
	{
		string text = "Score:  " + to_string(score);
		graphics::Brush br;

		br.fill_color[0] = 0.0f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 0.0f;
		br.fill_opacity = 0.7;
		graphics::drawText(x, y, 40, text, br);
	}

	//���� ��� ��� ������ ���� �� ��� ����� ������������� ������� ���� ��� �� �������� �������
										
	//������ OCTAPUS
	void octaPointsPlus() {
		 score+=10;
	}
	//������ NEMO
	void nemoPointsPlus() {
		score += 5;
	}
	//������ RAT
	void ratPointsPlus() {
		score += 3;
	}


};