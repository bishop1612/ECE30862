#include "Game.h"

int main(void)
{
	cout << "Using sample.xml" << endl;
	string filename = "samples/sample.xml";

	Game * game = new Game(filename);
	if(game->Ready) {
		game->start();
	}

	delete game;
	return 0;
}
