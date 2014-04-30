#ifndef PHYSICENGINE_H
#define PHYSICENGINE_H

#include <stdlib.h>

#include <vector>
#include <iostream>

#include "Shapes/Shape.h"

using namespace std;

class PhysicEngine
{
    public:
        static PhysicEngine* Instance();

        void Run();
		Vektor3D gravity;
    private:
        PhysicEngine(){gravity=Vektor3D(0,0,0);};
        ~PhysicEngine(){};
        PhysicEngine(const PhysicEngine&){}
		PhysicEngine& operator= (const PhysicEngine){}
		static PhysicEngine* pinstance;

		void Gravity();


};

#endif // ENGINE_H
