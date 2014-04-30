#include "Controler.h"
#include "Camera.h"
#include "Units\Vektor3D.h"
#include "Units\Vertex3D.h"
#include "Mouse.h"
#include "Player.h"

Controler* Controler::pinstance;
Controler::Controler(){}


Controler* Controler::Instance()
{
  if(pinstance==NULL)
  {
	  pinstance=new Controler();
  }
  return pinstance;
}

void Controler::Run(){

    KeyPressed();
    SDL_Event event;

    while( SDL_PollEvent( &event ) ) {

        switch( event.type ) {
        case SDL_KEYDOWN:
            this->KeyDown( &event.key.keysym );
            break;
        case SDL_MOUSEMOTION:
            this->MouseMotion(&event.motion);
            break;
        case SDL_QUIT:
            SDL_Quit( );
            exit( 0 );
            break;
        }
    }

}

void Controler::MouseMotion(SDL_MouseMotionEvent* motion)
{
      Vektor3D *Direction=Player::Instance()->GetDirection();
      if((Direction->Orientation[Y]+=motion->xrel)>359)Direction->Orientation[Y]-=360;
      else if((Direction->Orientation[Y]+=motion->xrel)<0)Direction->Orientation[Y]+=360;

      if((Direction->Orientation[X]+=motion->yrel)<-90)Direction->Orientation[X]=-90;
      else if(Direction->Orientation[X]>90)Direction->Orientation[X]=90;
}

void Controler::KeyDown(SDL_keysym* keysym){

    Camera* Kamera = Camera::Instance();
    switch( keysym->sym ) {
    case SDLK_ESCAPE:
            SDL_Quit( );
            exit( 0 );
        break;
    case SDLK_1:
        Mouse::Instance()->Lock();
        break;
    case SDLK_2:
        Mouse::Instance()->Grab();
        break;
    case SDLK_3:
        Mouse::Instance()->Hide();
        break;
    default:
        break;
    }
}

void Controler::KeyPressed()
{
    Uint8 *key_map = SDL_GetKeyState(NULL);
    GLboolean tl=false;
    if(key_map[SDLK_w]){Player::Instance()->Move();tl=true;}//W
    if(key_map[SDLK_s]){Player::Instance()->Move(Vektor3D(-1,-1,-1));tl=true;}//S
    if(tl)
      return;
    Player::Instance()->Move(Vektor3D(0,0,0));
}
