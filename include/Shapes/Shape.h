#ifndef SHAPE_H
#define SHAPE_H
#include "Units/Vektor3D.h"
#include "Units/Vertex3D.h"
#include <GL/GL.h>
#include <iostream>
using namespace std;

class Resources;
enum visible{HIDDEN=0,VISIBLE};
enum movable{STATIC=0,MOVABLE};

class Shape
{
    public:
        Shape(visible vis = VISIBLE, movable mov = MOVABLE);
        virtual ~Shape(){}
        virtual void Draw() = 0;
        virtual void Move() = 0;
        void SetForce(GLfloat x, GLfloat y, GLfloat z);
        void SetForce(Vektor3D Force);
        inline Vektor3D& GetForce(){return force;}
        Vertex3D* GetPosition(){return &Position;}
        static Shape* Cache;
        inline static void End(){Cache=NULL;}

        Vertex3D Position;//stred objektu
        Vektor3D force;
        visible Visibility;
        movable Movable;
};

#endif // SHAPE_H
