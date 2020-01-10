
class Actor {
	public:
		int x,y,visible;
		Actor() {
			x=0;y=0;visible=1;
		}
		Actor(int x,int y) {
			this->x=x; this->y=y; visible=1;
		}
		virtual void create() 	= 0;
		virtual void step()	= 0;
		virtual void render() 	= 0;
};
