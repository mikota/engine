#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>

#define SCREEN_W 640
#define SCREEN_H 360
#define CENTER_X 320
#define CENTER_Y 180
#define f 16
#define pi 3.14
#define dt 50
#define bool short
#define true 1
#define false 0

#include<actor.h>
#include<basicact.h>
#include<renderer.h>
#include<basicren.h>

class Bufferer {
	private:
		int page;
	public:
		Bufferer() { page = 0; };
		void startframe(){
			setactivepage(page);
			setvisualpage(1-page);
			cleardevice();
		}
		void endframe(){
			page = 1-page;
			delay(f);
		}

};

class Game {
	private:
		static int MAX_SIZE;
		static Actor** actors;
		static int* create_actors;
		static int size;
		static Bufferer bufferer;
	public:
		static bool addactor(Actor* actor){
			if (size >= MAX_SIZE) return false;
			actors[size++] = actor;
			actor->create();
			return true;
		}
		static bool step() {
			for(int i=0; i<size; i++) {
				(actors[i])->step();
			}
		}
		static bool render() {
			bufferer.startframe();
			for(int i=0; i<size; i++) (actors[i])->render();
			bufferer.endframe();
		}
};

int Game::MAX_SIZE = 64;
Actor** Game::actors = new Actor*[64];
int Game::size = 0;
Bufferer Game::bufferer;

void drawcircles(int n) {
	int rad_diff = CENTER_X/n;
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	int page = 0;
	Bufferer b;
	for(int i=0;i<n;i++){
		b.startframe();
		circle(CENTER_X,CENTER_Y,rad_diff * (n-i)-10);
		outtextxy(CENTER_X,CENTER_Y,"cxz");
		b.endframe();
	}
};

int main() {
	int gd= EGA, gm = EGAHI;
	initgraph(&gd,&gm,"C:/tc/bgi");
	//drawcircles(100);
	delay(f);
	//create some actor
	TextObjectRotating textObject("Seb");
	Game::addactor(&textObject);

	for(int i=0;i<60*5;i++){
		Game::step();
		Game::render();
	}
	getch();
	closegraph();
	restorecrtmode();
	return 0;
}