//The Common Basic Actors

class TextObjectRotating : public Actor {
	private:
		float angle;
		int radius, counter;
		char* str;
		TextRenderer* textRenderer;
	public:
		TextObjectRotating(char* ptr) : Actor() {
			str = ptr;
		}
		void create() {
			angle =  pi * 3/2;
			radius = 0;
			counter = 0;
			textRenderer = new TextRenderer(str);

		}
		void step() {
			angle += 2 * pi / 100;
			radius++;
		}
		void render() {
			int rx = CENTER_X + 0.5*radius*cos(angle);
			int ry = CENTER_Y + 0.5*radius*sin(angle);
			textRenderer.render();
		}
};

