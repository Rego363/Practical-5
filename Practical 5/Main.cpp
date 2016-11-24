#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Game.h"

int main(void)
{
	Game& game = Game();
	GL_POINTS;
	GL_LINES;
	GL_LINE_STRIP;
	GL_TRIANGLES;
	GL_TRIANGLE_STRIP;
	GL_TRIANGLE_FAN;
	GL_QUADS;
	GL_QUAD_STRIP;
	GL_POLYGON;
	game.run();
}