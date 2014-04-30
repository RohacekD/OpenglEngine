#ifndef CUBE_H
#define CUBE_H

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Units/Vertex3D.h"
#include "Shapes/Shape.h"



class Cube : public Shape
{
    public:
        Cube(GLfloat x, GLfloat y, GLfloat z, GLfloat l, visible v=VISIBLE, movable mov = MOVABLE);
        virtual ~Cube();
        void Draw();
        void Move();
        Vertex3D* GetPosition(){return &Position;}

    private:
        GLfloat l;//vzdálenost od støedu k ploše
};

#endif // CUBE_H
