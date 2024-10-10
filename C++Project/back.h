#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <graphics.h>


class back : public GameObject
{

public:

	back(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name) {

		this->x = x;
		this->y = y;
	}

	void update(float dt)
	{
		
	}

	void init()
	{

	}

	void draw()
	{
		graphics::Brush br;

		br.texture = "assets/back.png";
		br.fill_opacity = 0.6;

		graphics::drawRect(x, y, 1000.0, 1000.0, br);
	}
};