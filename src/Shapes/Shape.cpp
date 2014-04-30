#include "Shapes/Shape.h"
#include "Resources.h"

Shape* Shape::Cache;

Shape::Shape(visible vis, movable mov){
    this->Cache=this;
    Resources::Instance()->GetShape(this);
    this->force=Vektor3D(0,0,0);
    this->Visibility=vis;
    this->Movable=mov;
}

void Shape::SetForce(GLfloat x, GLfloat y, GLfloat z){
    if(Movable)
      this->force=Vektor3D(x,y,z);
}

void Shape::SetForce(Vektor3D Force){
    if(Movable)
      this->force=Force;
}
