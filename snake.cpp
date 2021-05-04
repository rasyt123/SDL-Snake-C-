#include "SDL.h"
#include <vector>
#include <map>
using namespace std;

class Snake {
	public:
		void MoveSnake(int xpos, int ypos, vector<pair<int, int>>& snakebody);
		bool InputCollision(int xpos, int ypos);
		bool TakeInput(int& snakelength);
		bool RenderGrid(int xpos, int ypos, vector<pair<int, int>>& snakebody);
		bool FoodGenerator();
		void Run();
	private:
		vector <pair<int, int>> snakebody;
		int length = 1;
		int headposx;
		int headposy;
		int oldheadposx;
		int oldheadposy;
		int headposvelx = 5;
		int headposvely = 5;
		int width = 800;
		int height = 600;
		SDL_Window* gWindow = NULL;
		SDL_Renderer* renderer = NULL;


};

bool Snake::RenderGrid(vector<pair<int, int>>& snakebody) {
	bool success = true;
	SDL_Rect snakehead;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		gWindow = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
		SDL_Renderer* renderer = SDL_CreateRenderer(gWindow, -1, 0);
		if (GWindow == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return false;
		}
		snakehead.w = 10;
		snakehead.h = 10;
		snakehead.x = width / 2;
		snakehead.y = height / 2;
		headposx = snakehead.x;
		headposy = snakehead.y;
		SDL_SetRenderDrawColor(renderer, 200, 0, 200, 255);
		SDL_RenderFillRect(renderer, rect);
		snakebody.push_back(make_pair(headposx, headposy));
		SDL_RenderPresent(renderer);
	}

}

void Snake::Run() {
	bool gameover = false;
	while (!gameover) {
		TakeInput(length);


	}
}


void Snake::MoveSnake(int xpos, int ypos, vector<pair<int, int>>& snakebody) {
	int oldposx;
	int oldposy;
	int head = 0;
	for (int i = 0; i < snakebody.size(); ++i) {
		if (snakebody[head]) {
			oldposx = snakebody[head].first;
			oldposy = snakebody[head].second;
			snakebody[head].first = headposx;
			snakebody[head].second = headposy;
		}
		else {
			snakebody[i].first = oldposx;
			snakebody[i].second = oldposy;
			oldposx = snakebody[i + 1].first;
			oldposy = snakebody[i + 1].second;
		}
	}
}




void Snake::TakeInput(int& snakelength) {
	SDL_Event event;
	int oldposx;
	int oldposy;
	for (int i = 0; i < snakelength; i++) {
		headposvelx += 2;
		headposvely += 2;
	}
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysm.sym) {
					case SDLK_a:
						headposx += headposvelx;
						break;
					case SDLK_d:
						headposx -= headposvelx;
						break;
					case SDLK_w:
						headposy += headposvely;
						break;
					case SDLK_s:
						headposy -= headposvely;
						break;
			}
		}

	}
 

}

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);

	SDL_Delay(3000);


	return 0;
}
