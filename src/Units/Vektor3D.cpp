#include "../../include/Units/Vektor3D.h"

Vektor3D::Vektor3D(float x, float y, float z)
{
    this->Orientation[X]=x;
    this->Orientation[Y]=y;
    this->Orientation[Z]=z;
}

Vektor3D::Vektor3D()
{
    this->Orientation[X]=0;
    this->Orientation[Y]=0;
    this->Orientation[Z]=0;
}

void Vektor3D::SetVector(GLfloat x, GLfloat y, GLfloat z)
{
    this->Orientation[X]=x;
    this->Orientation[Y]=y;
    this->Orientation[Z]=z;
}
