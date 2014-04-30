#include "../include/Window.h"

Window* Window::pinstance;

Window* Window::Instance()
{
  if(pinstance==NULL)
  {
	  pinstance=new Window();
  }
  return pinstance;
}

Window::Window()
{
    this->height = 480;
    this->width = 640;

    this->bpp = 0;

    this->flags = 0;

    SetUpSDL();
    SetUpGL();
}

Window::~Window(){}

void Window::SetUpSDL()
{
  #ifdef DEBUG
    #undef main
  #endif // DEBUG
  const SDL_VideoInfo* info = NULL;
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    cout<<"Selhala inicializace sdl"<<endl;

  info = SDL_GetVideoInfo( );

  #ifdef DEBUG
    ofstream ctt("CON");
    freopen( "CON", "w", stdout );
    freopen( "CON", "w", stderr );
    cout << "Debug mode"<<endl;
  #endif // DEBUG

    if( !info )
        cout<<"Video query failed: %s\n"<< SDL_GetError( ) <<endl;

    bpp = info->vfmt->BitsPerPixel;
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    flags = SDL_OPENGL;
    if( SDL_SetVideoMode( width, height, bpp, flags ) == 0 )
        cout<<"Video mode set failed: %s\n"<<SDL_GetError( )<<endl;

}

void Window::SetUpGL()
{
    float ratio = (float) width / (float) height;

    glShadeModel( GL_SMOOTH );

    glCullFace( GL_BACK );
    glFrontFace( GL_CCW );
    glEnable( GL_CULL_FACE );
    glEnable(GL_DEPTH_TEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glClearColor( 0, 0, 0, 0 );

    glViewport( 0, 0, width, height );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    gluPerspective( 60.0, ratio, 1.0, 1024.0 );
}
