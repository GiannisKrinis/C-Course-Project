#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <graphics.h>

//class GameState;
//ΠΟΣΕΣ ΖΩΕΣ ΜΟΥ ΜΕΝΟΥΝ
class Hearts : public GameObject
{
	int zwes;

public:

	Hearts(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name) {

		this->x = x;
		this->y = y;
		zwes = 5;
	}

	void update(float dt){}

	void init()
	{
		zwes = 5; // Οταν γινεται αρχικοποιηση οι ζωες γινονται παλι 5
	}

	void draw()
	{
		string text = "Lifes:  " + to_string(zwes);
		graphics::Brush br;

		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 0.0f;
		br.fill_color[2] = 0.0f;
		br.fill_opacity = 0.7;
		graphics::drawText(x, y, 40, text, br);
	}

	void zwesMinus() {
		if (zwes >= 1) {
			 zwes-=1;
		}
	}

	void zwesPlus() {
		if (zwes >= 1 && zwes < 5) {
			zwes += 1;
		}
	}

	int getZwes() {
		return zwes;
	}
};