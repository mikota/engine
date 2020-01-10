//Basic Common Renderers

class TextRenderer: public Renderer {
	public:
		char* str;
		TextRenderer(char* ptr) {
			str = ptr;
		}
		void render() {
			outtextxy(x,y,str);
		}
}

class CircleRenderer : public Renderer {
	public:
		int radius;
		CircleRenderer(int rad) {
			radius = rad;
		}
		void render(){
			circle(x,y,radius);
		}
};