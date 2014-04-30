#include "Resources.h"
#include "Units/Vektor3D.h"
#include "Shapes/Shape.h"

Resources* Resources::pinstance;
Resources::Resources(){}


Resources* Resources::Instance()
{
  if(pinstance==NULL)
  {
	  pinstance=new Resources();
  }
  return pinstance;
}


