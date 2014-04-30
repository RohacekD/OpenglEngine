#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include <vector>
#include "Shapes/Shapes.h"
#include "Camera.h"
#include <iostream>

using namespace std;
class Resources;


class RenderEngine
{
    public:
        static RenderEngine* Instance();

        void Render();


        //Docasna reseni
        void DrawGrid();
        void AxisCross(GLfloat x, GLfloat y, GLfloat z);
    private:
        RenderEngine();
        ~RenderEngine(){};
        RenderEngine(const RenderEngine&){}
		RenderEngine& operator= (const RenderEngine X){}
		static RenderEngine* pinstance;
};

#endif // ENGINE_H
