#ifndef VEKTOR3D_H
#define VEKTOR3D_H

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Units_define.h"

class Vektor3D
{
    public:
        Vektor3D(float x, float y, float z);
        Vektor3D();
        inline GLfloat* GetVectorv(){return Orientation;}
        void SetVector(GLfloat x, GLfloat y, GLfloat z);
        Vektor3D GetVector(){return Vektor3D(this->Orientation[X], this->Orientation[Y], this->Orientation[Z]);}
        GLfloat Orientation[3];

        inline Vektor3D operator+(const Vektor3D& Get){return Vektor3D(this->Orientation[X]+Get.Orientation[X], this->Orientation[Y]+Get.Orientation[Y], this->Orientation[Z]+Get.Orientation[Z]);}
        inline Vektor3D operator*(const GLfloat Get){return Vektor3D(this->Orientation[X]*Get, this->Orientation[Y]*Get, this->Orientation[Z]*Get);}
        inline Vektor3D& operator+=(const Vektor3D& Get){
                   Orientation[X]+=Get.Orientation[X];
                   Orientation[Y]+=Get.Orientation[Y];
                   Orientation[Z]+=Get.Orientation[Z];
            return (*this);
        }
        inline Vektor3D operator/(const GLfloat Get){return Vektor3D(this->Orientation[X]/Get, this->Orientation[Y]/Get, this->Orientation[Z]/Get);}
};

#endif // VEKTOR3D_H
