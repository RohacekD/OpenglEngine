#include "Shapes/Cube.h"
#include "Units/Vertex3D.h"
#include "Shapes/Shape.h"
#include "Fps.h"

#include <iostream>

Cube::Cube(GLfloat x, GLfloat y, GLfloat z, GLfloat l, visible v, movable mov):Shape(v, mov)
{
    this->Position.SetVertex(x,y,z);
    this->l=l;
}

Cube::~Cube(){}

void Cube::Draw()
{
    if(!Visibility)
        return;

    static GLfloat v0[] = { -l, -l,  l };
    static GLfloat v1[] = {  l, -l,  l };
    static GLfloat v2[] = {  l,  l,  l };
    static GLfloat v3[] = { -l,  l,  l };
    static GLfloat v4[] = { -l, -l, -l };
    static GLfloat v5[] = {  l, -l, -l };
    static GLfloat v6[] = {  l,  l, -l };
    static GLfloat v7[] = { -l,  l, -l };
    static GLubyte red  []    = { 255,   0,   0, 255 };
    static GLubyte green[]  = {   0, 255,   0, 255 };
    static GLubyte blue[]   = {   0,   0, 255, 255 };
    static GLubyte white[]  = { 255, 255, 255, 255 };
    static GLubyte yellow[] = {   0, 255, 255, 255 };
    static GLubyte black[]  = {   0,   0,   0, 255 };
    static GLubyte orange[] = { 255, 255,   0, 255 };
    static GLubyte purple[] = { 255,   0, 255,   0 };

    glTranslatef( Position[X], Position[Y], Position[Z] );

    /* Send our triangle data to the pipeline. */
    glBegin( GL_TRIANGLES );

    glColor4ubv( red );
    glVertex3fv( v0 );
    glColor4ubv( green );
    glVertex3fv( v1 );
    glColor4ubv( blue );
    glVertex3fv( v2 );

    glColor4ubv( red );
    glVertex3fv( v0 );
    glColor4ubv( blue );
    glVertex3fv( v2 );
    glColor4ubv( white );
    glVertex3fv( v3 );

    glColor4ubv( green );
    glVertex3fv( v1 );
    glColor4ubv( black );
    glVertex3fv( v5 );
    glColor4ubv( orange );
    glVertex3fv( v6 );

    glColor4ubv( green );
    glVertex3fv( v1 );
    glColor4ubv( orange );
    glVertex3fv( v6 );
    glColor4ubv( blue );
    glVertex3fv( v2 );

    glColor4ubv( black );
    glVertex3fv( v5 );
    glColor4ubv( yellow );
    glVertex3fv( v4 );
    glColor4ubv( purple );
    glVertex3fv( v7 );

    glColor4ubv( black );
    glVertex3fv( v5 );
    glColor4ubv( purple );
    glVertex3fv( v7 );
    glColor4ubv( orange );
    glVertex3fv( v6 );

    glColor4ubv( yellow );
    glVertex3fv( v4 );
    glColor4ubv( red );
    glVertex3fv( v0 );
    glColor4ubv( white );
    glVertex3fv( v3 );

    glColor4ubv( yellow );
    glVertex3fv( v4 );
    glColor4ubv( white );
    glVertex3fv( v3 );
    glColor4ubv( purple );
    glVertex3fv( v7 );

    glColor4ubv( white );
    glVertex3fv( v3 );
    glColor4ubv( blue );
    glVertex3fv( v2 );
    glColor4ubv( orange );
    glVertex3fv( v6 );

    glColor4ubv( white );
    glVertex3fv( v3 );
    glColor4ubv( orange );
    glVertex3fv( v6 );
    glColor4ubv( purple );
    glVertex3fv( v7 );

    glColor4ubv( green );
    glVertex3fv( v1 );
    glColor4ubv( red );
    glVertex3fv( v0 );
    glColor4ubv( yellow );
    glVertex3fv( v4 );

    glColor4ubv( green );
    glVertex3fv( v1 );
    glColor4ubv( yellow );
    glVertex3fv( v4 );
    glColor4ubv( black );
    glVertex3fv( v5 );

    glEnd( );

}

void Cube::Move()
{
    if(Movable){
        Vektor3D vect = this->force.GetVector()/Fps::Instance()->GetFps();
        Position.SetVertex(Position[X]+vect.Orientation[X], Position[Y]+vect.Orientation[Y], Position[Z]+vect.Orientation[Z]);
    }
}

