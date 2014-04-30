#include <stdlib.h>
#include "Terrain.h"

Terrain* Terrain::pinstance;

Terrain* Terrain::Instance()
{
  if(pinstance==NULL)
  {
	  pinstance=new Terrain();
  }
  return pinstance;
}
