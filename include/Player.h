#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>

#include <math.h>

#include "Units/Vertex3D.h"

class Camera;
class Vektor3D;
class Vertex3D;

#include "Shapes/Shapes.h"

class Player
{
    public:
        static Player* Instance();
        static Player* Instance(GLfloat force, Vektor3D Direction, GLfloat x, GLfloat y, GLfloat z, GLfloat l);
        inline Vektor3D* GetDirection(){return &Direction;}
        inline Vertex3D* GetPosition(){return this->Body->GetPosition();}
        void Move(Vektor3D v = Vektor3D(1,1,1));//vektorem se vynasobi cely vysledny vektor -> otoci se smerem kam jdu... implicitne to je rovne
        inline void SetSpeed(GLfloat Val){this->Force=Val;this->Body->GetForce()*Val;}
    private:
        Player(){};
        ~Player(){};
        Player(const Player&){}
		Player& operator= (const Player X){}
		static Player* pinstance;
        void SetPlayer(GLfloat force, Vektor3D Direction, GLfloat x, GLfloat y, GLfloat z, GLfloat l);

        Camera* Kamera;
        Cube* Body;
        Vektor3D Direction;//smer kam se divam
        Vertex3D *Position;//kde jsem
        GLfloat Force;//jakou rychlosti mohu jit
};

#endif // PLAYER_H
