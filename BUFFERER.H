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
