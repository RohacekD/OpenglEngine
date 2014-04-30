#include "../include/Camera.h"
#include "../include/Player.h"
#include "../include/Units/Vertex3D.h"
#include "../include/Units/Vektor3D.h"
#include <cstddef>

#include <iostream>

Camera* Camera::pinstance;
Vektor3D* Camera::Direction;
Vertex3D* Camera::Position;

Camera* Camera::Instance()
{
  if(pinstance==NULL)
	  pinstance=new Camera();
  return pinstance;
}

Camera::Camera()
{
  Direction=Player::Instance()->GetDirection();
  Position=Player::Instance()->GetPosition();
}

void Camera::Start()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(Direction->Orientation[X], 1, 0, 0);
    glRotatef(Direction->Orientation[Y]+180, 0, 1, 0);
    glTranslatef(-(*Position)[X], -(*Position)[Y], -(*Position)[Z]);
}
