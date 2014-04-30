#include "../include/Mouse.h"
#include "../include/Window.h"

Mouse* Mouse::pinstance;
Mouse::Mouse(){
    this->sx=(int)Window::Instance()->width/2;
    this->sy=(int)Window::Instance()->height/2;
    this->lock=false;
    this->grab=false;
    this->visible=true;
}


Mouse* Mouse::Instance()
{
  if(pinstance==NULL)
  {
	  pinstance=new Mouse();
  }
  return pinstance;
}
