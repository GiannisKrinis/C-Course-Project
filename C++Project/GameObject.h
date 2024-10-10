#pragma once

#include <string>
#include "GameState.h"
#include <cmath>

using namespace std;


class GameObject
{
	static int m_next_id;
protected:

	class GameState* m_state;
	std::string m_name;
	int m_id = 0;
	bool m_active = true;
	int orginalX, orginalY;//�� ������ x,y ���� ���� ��� ������� �� ���������� �� �� ����� ���� ���� ���� ���� ���� �������� �� ��������
	int x, y;
	


public:

	//constructor
	GameObject(GameState* gs, const std::string& name = "") {

		m_state = gs;
		m_name = name;
		orginalX = x;
		orginalY = y;
	}
	

	virtual void init() {
		//�� �� ��� ������� ������������ ( Try Again ) �������� �� ������ �,y ��� �����
		x = orginalX;
		y = orginalY;
	}

	virtual void update(float dt) {}

	virtual void draw() {}//��� ��������� ���� ��� ;) :)

	//������� ����������
	bool boomboom(GameObject* k) { //k �����: ������ / ��� / ������
		if (sqrt(pow(x - k->x, 2) + pow(y - k->y, 2)) < 30) {
			//�� �� ��� �� ��������� ���� ���� ��� ��� ����
			k->x = 1000;
			k->y = rand() % 1000;
			//true
			return true;
		}
		else {
			return false;
		}
	}

	//bool isActive() { return m_active; }
	//void setActive(bool a) { m_active = a; }

	//Destructor
	virtual ~GameObject() {}

};