#include "SDL.h"
#include <vector>
#include <map>
#include <random>
#include <time.h>
#include <math.h>
using namespace std;

class Snake {
	public:
		void MoveSnake(int xpos, int ypos, vector<pair<int, int>>& snakebody);
		bool InputCollision(int xpos, int ypos);
		bool TakeInput(int& snakelength);
		bool RenderGrid(int xpos, int ypos, vector<pair<int, int>>& snakebody);
		void FoodGenerator(vector<pair<int, int>>& snakebody, bool clearfood);
		void PrintSnake(vector<pair<int, int>>& snakebody);
		void Run();
	private:
		vector <pair<int, int>> snakebody;
		int length = snakebody.size();
		int headposx;
		int headposy;
		int foodcount = 0;
		int oldheadposx;
		int oldheadposy;
		int headposvelx = 3;
		int headposvely = 3;
		int width = 800;
		int height = 600;
		SDL_Window* gWindow = NULL;
		SDL_Renderer* renderer = NULL;


};


bool InputCollision() {
	if (foodposx == headposx && foodposy == headposy) {
		snakebody.push_back(make_pair(snakebody[i].first , ));



	}
	else if ((headposx <= 0 || headposx >= width) || (headposy <= 0 || headposy >= length) {
		return true;
	}
	else {
		for (int i = 0; i < snakebody.size() && i + 1 < snakebody.size() - 1; i++) {
			if (headposx == snakebody[i + 1].first && headposy == snakebody[i + 1].second) {
				return true;
			}
		}
		return false;
	}



}


void FoodGenerator(vector<pair<int, int>>& snakebody, bool clearfood) {
	SDL_Rect food;
	int foodposx;
	int foodposy;
	srand(time(NULL));
	if (foodcount == 0) {
		++foodcount;
		foodposx = rand % width;
		foodposy = rand % height;
		food.w = 10;
		food.h = 10;
		food.x = foodposx;
		food.y = foodposy;
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, rect);
		return;
	}
	else {
		return;
	}

}

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
	
}


void Snake::MoveSnake(int xpos, int ypos, vector<pair<int, int>>& snakebody) {
	int oldposx;
	int oldposy;
	int tempx;
	int tempy;
	int head = 0;
	for (int i = 0; i < snakebody.size() && i + 1 < snakebody.size() - 1; ++i) {
		if (head == 0) {
			oldposx = snakebody[head].first;
			oldposy = snakebody[head].second;
			snakebody[head].first = headposx;
			snakebody[head].second = headposy;
		}
		else {
			if (i > head + 1) {
				snakebody[i].first = tempx;
				snakebody[i].second = tempy;
				tempx = snakebody[i + 1].first;
				tempy = snakebody[i + 1].second;

			}
			else {
				tempx = snakebody[i].first;
				tempy = snakebody[i].second;
				snakebody[i].first = oldposx;
				snakebody[i].second = oldposy;
			}
		}
	}
}

void Snake::PrintSnake(vector<pair<int, int>>& snakebody, SDL_Rect *) {
	SDL_RenderClear(renderer);
	int x;
	int y;
	for (int i = 0; i < snakebody.size(); i++) {
		x = snakebody.first;
		y = snakebody.second;

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
	while (SDL_PollEvent(&event)) {
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
}

int main(int argc, char* argv[])
{
	


	return 0;
}
