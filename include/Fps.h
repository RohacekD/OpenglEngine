#ifndef FPS_H
#define FPS_H
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <iostream>
using namespace std;

/*! \class Fps
    \brief Class ovlivnujici pocet fps.

    Hlavni metoda je Cycle. Ta je volana po kazdem vykresleni. Vyvola spozdeni, a uloz� dobu posledn�ho cyklu pro class Engine, kter� podle toho pohne o n�sobek vektoru s objekty.
    D�le fce LastCycle vrac� dobu, kterou trval cyklus.
    Je�t� vytvo��m class vypisuj�c� fps s p�esnost� na 2 desetin� m�sta.
    Metoda GetTime si drzi dobu od zacatku cyklu, nebo od sveho posledniho volani. Slouzi k zjisteni, ktera cast kodu je nejpomalejsi.

*/
class Fps
{
    public:
		static Fps* Instance();
		inline void SetFps(int MaxCycleTime){this->MaxCycleTime=1000/MaxCycleTime;this->fps=MaxCycleTime;}
        inline int GetFps(){return fps;}
        inline int GetCycleTime() {return SDL_GetTicks()-LastCycle;}
		void Cycle();
    private:
        Fps();
        ~Fps();
        Fps(const Fps&){}
		Fps& operator= (const Fps){}
		static Fps* pinstance;
		int MaxCycleTime;/**< \var MaxCycleTime obsahuje dobu jednoho snimku */
		int Time;
		int fps;
        int LastCycle;/**< \var LastCycle Obsahuje cas kdy probehl posledni cyklus. */
};

#endif // FPS_H
