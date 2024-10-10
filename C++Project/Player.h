#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <graphics.h>


class Player : public GameObject
{

 public:

	Player(GameState* gs, const std::string& name, int x, int y) : GameObject(gs,name) {//x,y σε ποια θεση θα ειναι αρχικα ο player

		this->x = x;
		this->y = y;
	}


	void init() {//οταν ανοιγεις το game ή κανεις try again ο Player αρχικοποιειται σε αυτην εδω την θεση
		x = 100;
		y = 500;
	}

	void update(float dt)
	{
		if (graphics::getKeyState( graphics::SCANCODE_UP ) == true) { //UP
			
				y = y - 2;
				
				if (y < 50) { //Ελεγχος να μην βγει πανω απο το canvas
					y = 50;
				}
		
		}
		if (graphics::getKeyState(graphics::SCANCODE_DOWN) == true) { //DOWN
			
				y = y + 2;
				
				if (y > 950) {//Ελεγχος να μην βγει κατω απο το canvas
					y = 950;
				}
		}

		if (graphics::getKeyState(graphics::SCANCODE_RIGHT) == true) { //RIGHT
			
		     x = x + 2; 
			
			if (x > 950) {//Ελεγχος να μην βγει δεξια απο το canvas
				x = 950;
			}
		}

		if (graphics::getKeyState(graphics::SCANCODE_LEFT) == true) { //LEFT
			 
			x = x - 2;

			if (x < 50) {//Ελεγχος να μην βγει αριστερα απο το canvas
				x = 50;
			}
			 
		}
	}


	void draw()
	{
		graphics::Brush br;

		br.texture = "assets/me.png";
		br.outline_opacity = 0.0f;//για να μη βγαζει το ασπρο τετραγωνακι γυρω - γυρω
		graphics::drawRect(x, y, 100, 100, br);
	}
};