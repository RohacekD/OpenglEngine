#include "..\include\Fps.h"
#include <cstddef>/**< Because NULL error :/ */

Fps* Fps::pinstance;

Fps* Fps::Instance()
{
  if(pinstance==NULL)
  {
	  pinstance=new Fps();
  }
  return pinstance;
}

Fps::Fps()
{
    this->LastCycle=SDL_GetTicks();
    this->MaxCycleTime=33;
}

Fps::~Fps(){}

void Fps::Cycle()
{
  if(GetCycleTime()<MaxCycleTime)
    SDL_Delay(MaxCycleTime-GetCycleTime());

  this->LastCycle=SDL_GetTicks();
}
