#include "Player.h"
#include "Units/Vektor3D.h"
#include "Units/Vertex3D.h"
#include "Camera.h"
#include <cstddef>
#include <cmath>
#include <tgmath.h>

#include <iostream>
Player* Player::pinstance;

Player* Player::Instance()
{
  if(pinstance==NULL)
  {
      std::cout<<"jeste nebyl inicializovan!"<<std::endl;
	  exit(1);//jeste nebyl inicializovan!
  }
  return pinstance;
}

Player* Player::Instance(GLfloat force, Vektor3D Direction, GLfloat x, GLfloat y, GLfloat z, GLfloat l)
{
  if(pinstance==NULL)
  {
	  pinstance=new Player();
	  pinstance->SetPlayer(force, Direction, x, y, z, l);
  }
  return pinstance;
}

void Player::SetPlayer(GLfloat force, Vektor3D Direction, GLfloat x, GLfloat y, GLfloat z, GLfloat l)
{
    this->Direction=Direction;
    this->Body = new Cube(x, y, z, l, HIDDEN, MOVABLE);
    Position=this->Body->GetPosition();
    this->Body->SetForce(Direction);
    Kamera = Camera::Instance();
    this->Force=force;
}


void Player::Move(Vektor3D v)
{
    GLfloat y=cos((double)this->Direction.Orientation[Y]*3.14159265/180);

    if(this->Direction.Orientation[Y]<180){
        this->Body->force=Vektor3D((-sqrt(1-pow(y, 2)))*v.Orientation[X]*this->Force, 0, y*v.Orientation[X]*this->Force);
    }
    else{
        this->Body->force=Vektor3D(sqrt(1-pow(y, 2))*v.Orientation[X]*this->Force, 0, y*v.Orientation[X]*this->Force);
    }
}
