#include "PhysicEngine.h"
#include "Resources.h"
PhysicEngine* PhysicEngine::pinstance;

bool Move(Shape* X){
    X->Move();
}

bool MoveByGravity(Shape* X){
    (X->force)+=PhysicEngine::Instance()->gravity;
}

PhysicEngine* PhysicEngine::Instance()
{
  if(pinstance==NULL)
  {
	  pinstance=new PhysicEngine();
  }
  return pinstance;
}

void PhysicEngine::Run()
{
    Resources::Instance()->For_Each(MoveByGravity, Resources::Instance()->Shapes.begin());
    Resources::Instance()->For_Each(Move, Resources::Instance()->Shapes.begin());
}
