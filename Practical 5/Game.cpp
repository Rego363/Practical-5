#include "Game.h"
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
using namespace sf;
using namespace std;
Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0); 
	glMatrixMode(GL_MODELVIEW);
	vec1 = MyVector3(0, 2, -5);
	vec2 = MyVector3(-2, -2, -5);
	vec3 = MyVector3(2, -2, -5);
	mat.setMatrix(vec1, vec2, vec3);
}

void Game::update()
{
	
}

void Game::draw()
{
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glBegin(GL_TRIANGLES);
	{ 
		//Draw using vectors
		//glVertex3f((GLfloat)vec1.getX(), (GLfloat)vec1.getY(), (GLfloat)vec1.getZ());
		//glVertex3f((GLfloat)vec2.getX(), (GLfloat)vec2.getY(), (GLfloat)vec2.getZ());
		//glVertex3f((GLfloat)vec3.getX(), (GLfloat)vec3.getY(), (GLfloat)vec3.getZ());

		//Draw using matrix
		glVertex3f((GLfloat)mat.row(0).getX(), (GLfloat)mat.row(0).getY(), (GLfloat)mat.row(0).getZ());
		glVertex3f((GLfloat)mat.row(1).getX(), (GLfloat)mat.row(1).getY(), (GLfloat)mat.row(1).getZ());
		glVertex3f((GLfloat)mat.row(2).getX(), (GLfloat)mat.row(2).getY(), (GLfloat)mat.row(2).getZ());
	}
	glEnd();
	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

