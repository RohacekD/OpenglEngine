#ifndef TEST_H
#define TEST_H

#include <SDL/SDL.h>

class Cube;

class Test
{
    public:
        Test();
        virtual ~Test();
        static void Cycle();
        static void NewTest();
        static int counter;
        static Cube* kostka;
        static int* val;
        static unsigned int Time;
        static unsigned int Times;
        static SDL_Event event;
};

#endif // TEST_H
