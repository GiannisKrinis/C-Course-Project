#include <iostream>
#include <graphics.h>//sgg
#include "GameState.h"
using namespace std;


GameState game;

void update(float ms)
{
	game.update(ms);//Καλώ την update του game που έφτιαξα απο GameState
}

void draw()
{
	game.draw();//Καλώ την draw του game που έφτιαξα απο GameState
}

int main()
{	
	graphics::createWindow(1000, 1000, "Deep Waters");//Μέγεθος ΟΛΟΚΛΗΡΟΥ του παραθύρου και ονομασία game (1000χ1000)
	

	game.init();//αρχικοποιηση
	

	graphics::Brush br;
	br.fill_color[0] = 0.5f;//red
	br.fill_color[1] = 0.4f;//green
	br.fill_color[2] = 0.5f;//blue

	graphics::setWindowBackground(br);

	graphics::playMusic("assets/music.ogg", 0.2, true, 0);//καλυτερα OGG απο mp3

	graphics::setUserData( &game );//sgg

	graphics::setDrawFunction(draw);//sgg

	graphics::setUpdateFunction(update);//sgg

	graphics::setCanvasSize(1000.0, 1000.0);//Ελέγχω το canvas πόσο μεγάλο είναι 

	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);// Πως να ειναι το canvas
	graphics::setFont("assets/all.ttf"); //Font για ολα τα γραμματακια στην οθονη
	graphics::startMessageLoop();//sgg
	graphics::destroyWindow();//sgg
	


	return 0;
}
