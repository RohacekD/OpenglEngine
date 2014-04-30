#ifndef VERTEX3D_H
#define VERTEX3D_H

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Units_define.h"//define enum{X, Y, Z}

class Vertex3D
{
    public:
        Vertex3D(float x, float y, float z);
        Vertex3D(){};
        void SetVertex(GLfloat x, GLfloat y, GLfloat z);
        inline GLfloat GetCoord(int index){return Coords[index];}
        GLfloat operator[](const int index){return Coords[index];}
    private:
        GLfloat Coords[3];

};

#endif // VERTEX3D_H
