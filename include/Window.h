#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <fstream>
#include <iostream>

using namespace std;

class Window
{
    public:
		static Window* Instance();

        unsigned int width;
        unsigned int height;

    private:
        Window();
        ~Window();
        Window(const Window&){}
		Window& operator= (const Window){}
		static Window* pinstance;

        int bpp;
        int flags;
        void SetUpSDL();
        void SetUpGL();
};

#endif // WINDOW_H
