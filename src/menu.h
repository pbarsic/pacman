#ifndef MENU_H
#define MENU_H
#include "screen.h"
#include "platform.h"
#include <SDL/SDL_ttf.h>
#include <vector>
#include "menu_item.h"

using namespace std;

class Menu {
	public:
		Menu(Screen *screen, const char* title = NULL);
		virtual ~Menu();
		virtual void draw();
		virtual int show();
		void drawTitle();
		void addMenuItem(const char* menuItem, const char* menuItemAlt = NULL);
		void menuItemUp();
		void menuItemDown();
	private:
		static const int MIN_FRAME_DURATION = 30;
		virtual int eventloop();
		vector<MenuItem*> menuItems;
		int selection;
	protected:
		Screen *screen;
		SDL_Surface *menuTitle;
		SDL_Color textwhite = {255, 255, 255, 0};
		SDL_Color textgray    = {191, 191, 191, 0};
		SDL_Color textyellow  = {255, 255,   0, 0};
		SDL_Color textred     = {255,   0,   0, 0};
		SDL_Color textmagenta = {255,   0, 255, 0};
		SDL_Color textcyan    = {  0, 255, 255, 0};
		SDL_Color textorange  = {255, 127,   0, 0};
		TTF_Font *font, *smallFont, *largeFont, *veryLargeFont, *hugeFont;
		void drawMenuItems();
};
#endif