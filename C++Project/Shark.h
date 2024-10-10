#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <graphics.h>


class Shark : public GameObject
{

public:

	Shark(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name) {//x,y σε ποια θεση ειναι αρχικα o Shark 

		this->x = x;
		this->y = y;
	}

	void init() {
		x = 1150; //αρχικοποιω στην init το x ετσι ωστε να ξεκιναει οταν αρχικοποιειται σε συγκεκριμενη θεση χ
	}


	void update(float dt)
	{
		x = x - 1;

		if (x < 0) {
			x = 1000;
			y = rand() % 950; // Έρχεται προς τα αριστερά, με το που φτάσεις στο τέρμα ξεκίνα ξανά απο δεξιά σε τυχαιο Y (υψος)
		}
	}

	
	void draw()
	{
		graphics::Brush br;

		br.texture = "assets/Shark.png";
		br.outline_opacity = 0.0f;//για να μη βγαζει το ασπρο τετραγωνακι γυρω - γυρω
		graphics::drawRect(x, y, 90, 90, br);
	}
};


