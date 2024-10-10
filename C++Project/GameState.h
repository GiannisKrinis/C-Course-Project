#pragma once

#include <vector>
#include <graphics.h>
#include "GameObject.h"
#include "Player.h"
#include "Jelly.h"
#include "Nemo.h"
#include "Octapus.h"
#include "Shark.h"
#include "Rat.h"
#include "back.h"
#include "Life.h"
#include "Score.h"
#include "Hearts.h"


using namespace std;

class GameState
{
	private:
		//Εδώ έφτιαξα τον vector που θα μπουν αντικείμενα τύπου GameObject*
		vector <GameObject*> entities;
		GameObject* zwes;
		GameObject* score;
		GameObject* P;
		

	public:

		GameState() {

			GameObject* b = new back(this, "back", 500, 500);
			entities.push_back(b);

			//Εναπομειναντες ζωες (Πάνω Δεξιά)
			zwes = new Hearts(this, "Lives", 850, 30);
			entities.push_back(zwes);

			//Score(Πάνω Αριστερά)
			score = new Score(this, "Score", 30, 30);
			entities.push_back(score);

			
			P = new Player(this, "Player", 200, 500);
			entities.push_back(P);

			GameObject* J = new Jelly(this, "Jelly", 700, 400);
			entities.push_back(J);

			GameObject* N = new Nemo(this, "Nemo", 600, 650);
			entities.push_back(N);

			GameObject* O = new Octapus(this, "Octapus", 750, 400);
			entities.push_back(O);
			
			GameObject* S = new Shark(this, "Shark", 600, 350);
			entities.push_back(S);

			GameObject* R= new Rat(this, "Rat", 800, 200);
			entities.push_back(R);

			GameObject* L = new Life(this, "Life", 1000, 890);
			entities.push_back(L);
		}

		//init, draw, update 

		
		void init() {//καλω init καθε στοιχειου απο vector (αρχικοποιηση)

			for (int i = 0; i < entities.size(); i++) {
				entities[i]->init();
			}
		}

		void draw()
		{	
			for (int i = 0; i < entities.size(); i++) {//καλω Draw καθε στοιχειου απο vector
				entities[i]->draw();
			}
			//HELP / Instructions
			graphics::Brush br;
			br.fill_color[0] = 0.3f;
			br.fill_color[1] = 0.3f;
			br.fill_color[2] = 0.3f; 

			graphics::drawText(400, 25, 30, "HOLD 'P' for Pause ", br);

			// Menu σε περίπτωση που χάσει, επιλέγει να ξαναπαίξει ή να βγει από το game
			Hearts* z = dynamic_cast<Hearts*>(zwes);
			if (z->getZwes() == 0) {
				graphics::Brush br;

				br.fill_color[0] = 1.0f;
				br.fill_color[1] = 0.0f;
				br.fill_color[2] = 0.0f;

				
				graphics::drawText(400, 400, 50, "GAME OVER", br);
				graphics::drawText(400, 450, 50, "(T)RY AGAIN", br);
				graphics::drawText(400, 500, 50, "(Q)UIT", br);
			}
		}

		void update(float ms)
		{	//Αν πατησεις συνεχομενα το γραμμα H σου δινει instructions
			if (graphics::getKeyState(graphics::SCANCODE_P)) {

				graphics::Brush br;

				br.fill_color[0] = 0.7f;
				br.fill_color[1] = 1.0f;
				br.fill_color[2] = 1.0f;


				// Instructions
				graphics::drawText(150, 220, 30, "0. You  are  the  Dolphin !.", br);
				graphics::drawText(150, 250, 30, "1. You  move  your  player  with  the arrows (up ,down ,right ,left ).", br);
				graphics::drawText(150, 280, 30, "2. Avoid  Sharks ,  Jellys.", br);
				graphics::drawText(150, 310, 30, "3. Points: Shrimp (3pts),  Nemo  (5pts),  Octapus  (10pts).", br);
				graphics::drawText(150, 340, 30, "4. Life  up  with  potions  and  collect  points!!", br);
				

				return;    //Με αυτον τον τροπο κανω Pause to game
				
			}
			
			//Αν οι ζωές μηδενιστούν, τοτε ανάλογα με το τι θα πατήσει ο παίχτης στο μενού θα γινει και στο παιχνίδι
			Hearts* z = dynamic_cast<Hearts*>(zwes);
			if (z->getZwes() == 0) {
				
				//Σταματάει η μουσική
				 graphics::stopMusic(1);


				 //lose music
				 graphics::playSound("assets/YOULOST.ogg", 1.0, false);
				
				// Επιλέγει ο παίχτης τι θα πατήσει
				if (graphics::getKeyState(graphics::SCANCODE_T)) {//ΠΑΙΖΕΙ ΞΑΝΑ
					init();
					graphics::playMusic("assets/music.ogg", 0.7, true, 0);//Ξαναρχίζει η μουσική
				}
				else if (graphics::getKeyState(graphics::SCANCODE_Q)) {//ΒΓΑΙΝΕΙ ΑΠΟ ΤΟ ΠΑΙΧΝΙΔΙ
					graphics::stopMessageLoop();
				}

				return;
			}
			

			for (int i = 0; i < entities.size(); i++) {//καλω update καθε στοιχειου απο το vector
				entities[i]->update(ms);
			}


			/*BOOM BOOM WITH OBJECTS*/



			//BOOMBOOM LIFE UP
			for (int i = 0; i < entities.size(); i++) {// Πιάνω ολο τον vector και το τσεκάρω σε ποιες περιπτώσεις zwes+
				if (dynamic_cast<Life*>(entities[i]) != nullptr) {//LIFE
					if (P->boomboom(entities[i]) == true) {//Ανν ειναι true η συγκρουση
						graphics::playSound("assets/gainlife.ogg", 1.0, false);
						z->zwesPlus();//ΑΥΞΗΣΗ zwes

					}
				}
			}


			//BOOMBOOM LIFE DOWN
			for (int i = 0; i < entities.size(); i++) {//Πιάνω ολο τον vector και το τσεκάρω σε ποιες περιπτώσεις zwes-
				if (dynamic_cast<Shark*>(entities[i]) != nullptr) {//SHARK
					if (P->boomboom(entities[i]) == true) {
						graphics::playSound("assets/Loselife.ogg", 0.5, false);
						z->zwesMinus();
					}
				}
				else if (dynamic_cast<Jelly*>(entities[i]) != nullptr) {//JELLY
					if (P->boomboom(entities[i]) == true) {
						graphics::playSound("assets/Loselife.ogg", 0.5, false);
						z->zwesMinus();
					}
				}
			}

			//BOOMBOOM SCORE UP
			for (int i = 0; i < entities.size(); i++) {//Πιάνω ολο τον vector και το τσεκάρω σε ποιες περιπτώσεις points+
				
				Score* s = dynamic_cast<Score*>(score);

				//RAT
				if (dynamic_cast<Rat*>(entities[i]) != nullptr) {
					if (P->boomboom(entities[i]) == true) {//Ανν ειναι true η συγκρουση
						graphics::playSound("assets/3points.ogg", 1.0, false);
						s->ratPointsPlus();//ΑΥΞΗΣΗ score 
					}
				}

				//OCTAPUS
				else if (dynamic_cast<Octapus*>(entities[i]) != nullptr) {
					if (P->boomboom(entities[i]) == true) {
						graphics::playSound("assets/10points.ogg", 1.0, false);
						s->octaPointsPlus();
					}
				}
				//NEMO
				else if(dynamic_cast<Nemo*>(entities[i]) != nullptr){ 
					if (P->boomboom(entities[i]) == true) {
						graphics::playSound("assets/5points.ogg", 1.0, false);
						s->nemoPointsPlus();
					}
				}
			}

			
		}

		//Destructor, διαγράφει οτι εχει μεσα το vector
		~GameState() {

			for (int i = 0; i < entities.size(); i++) {
				delete entities[i];
			}

		}
};