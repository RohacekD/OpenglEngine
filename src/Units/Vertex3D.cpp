#include "../../include/Units/Vertex3D.h"

Vertex3D::Vertex3D(float x, float y, float z)
{
    this->Coords[X]=x;
    this->Coords[Y]=y;
    this->Coords[Z]=z;
}

void Vertex3D::SetVertex(GLfloat x, GLfloat y, GLfloat z)
{
    this->Coords[X]=x;
    this->Coords[Y]=y;
    this->Coords[Z]=z;
}
