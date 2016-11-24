#include <iostream>
#include <SFML/Window.hpp>

#include "Vector3.h"
#include "Matrix3.h"
#include "Quaternion.h"

using namespace std;


class Game
{
public:
	Game();
	~Game();
	void run();
private:
	sf::Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();
	MyVector3 vec1;
	MyVector3 vec2;
	MyVector3 vec3;
	Matrix3 mat;
	Quaternion quat;
};