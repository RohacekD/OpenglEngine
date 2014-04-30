#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <vector>

#include "Window.h"
#include "Fps.h"
#include "Shapes/Shapes.h"
#include "Camera.h"
#include "RenderEngine.h"
#include "PhysicEngine.h"
#include "Controler.h"
#include "Mouse.h"
#include "Units/Vertex3D.h"
#include "Units/Vektor3D.h"
#include "Player.h"
#include "Resources.h"

#include "test/Test.h"

int main( int argc, char* argv[] )
{
    Player* player = NULL;
    Fps* fps = NULL;
    Window* Okno = NULL;
    RenderEngine* Render = NULL;
    PhysicEngine* Engine = NULL;
    Controler* Control = NULL;
    Camera* Kamera = NULL;
    Resources* resources = NULL;

    Okno = Window::Instance();
    Mouse::Instance()->MovePos();
    player = Player::Instance(5, Vektor3D(1,0,0), 0, 1, 0, 50);
    fps = Fps::Instance();
    Kamera = Camera::Instance();
    Render = RenderEngine::Instance();
    Engine = PhysicEngine::Instance();
    Control = Controler::Instance();
    resources = Resources::Instance();



    fps->SetFps(30);
    Test* test = new Test();

    glLineWidth(1.0f);

    while( 1 ) {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        Control->Run();

        Kamera->Start();

//=========Docasne=============
        Render->DrawGrid();

        Render->AxisCross(0,0,0);
        Render->AxisCross(0,0,-2);
//=========Docasne=============

        Engine->Run();

        Render->Render();

        SDL_GL_SwapBuffers();

        fps->Cycle();
    }

    return 0;
}
