#ifndef CONTROLER_H
#define CONTROLER_H

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <stdlib.h>

class Mouse;


class Controler
{
    public:
        static Controler* Instance();
        void Run();
    private:
        Controler();
        ~Controler(){};
        Controler(const Controler&){}
		Controler& operator= (const Controler X){}
		static Controler* pinstance;

		void KeyDown(SDL_keysym* keysym);
		void KeyPressed();
		void MouseMotion(SDL_MouseMotionEvent* motion);
};

#endif // CONTROLER_H
