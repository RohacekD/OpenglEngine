#ifndef MOUSE_H
#define MOUSE_H

#include <SDL/SDL.h>

class Window;

class Mouse
{
    public:
        static Mouse* Instance();
        inline void Lock(){lock=!lock;}
        inline void Grab(){grab=!grab; if(grab)SDL_WM_GrabInput( SDL_GRAB_ON );else SDL_WM_GrabInput( SDL_GRAB_OFF );}
        inline void Hide(){visible=!visible;SDL_ShowCursor(visible);}
        inline void MovePos(){SDL_WarpMouse(sx, sy);}
    private:
        Mouse();
        ~Mouse(){};
        Mouse(const Mouse&){}
		Mouse& operator= (const Mouse X){}
		static Mouse* pinstance;
		int sx, sy;//staticke souradnice x y
		bool lock,grab, visible;//true lock false unlock
};

#endif // MOUSE_H
