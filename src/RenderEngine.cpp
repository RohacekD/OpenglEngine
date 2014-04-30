#include "RenderEngine.h"
#include "Resources.h"

RenderEngine* RenderEngine::pinstance;

RenderEngine::RenderEngine(){}

bool Draw(Shape* X){
        Camera::Instance()->Start();
        X->Draw();
}

void RenderEngine::Render()
{
    Resources::Instance()->For_Each(Draw, Resources::Instance()->Shapes.begin());
}

RenderEngine* RenderEngine::Instance()
{
  if(pinstance==NULL)
  {
	  pinstance=new RenderEngine();
  }
  return pinstance;
}


//Docasna reseni

void RenderEngine::DrawGrid()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
        for (GLfloat i = -50; i <= 50; i += 0.5) {
            glVertex3f(i, 0, 50); glVertex3f(i, 0, -50);
            glVertex3f(50, 0, i); glVertex3f(-50, 0, i);
        }
    glEnd();
}

void RenderEngine::AxisCross(GLfloat x,GLfloat y, GLfloat z)
{
    glBegin(GL_LINES);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(x, y, z);
        glVertex3f(x, y+1, z);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(x, y, z);
        glVertex3f(x, y, z+1);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(x, y, z);
        glVertex3f(x+1, y, z);
    glEnd();
}
