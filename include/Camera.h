#ifndef CAMERA_H
#define CAMERA_H


#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Player;
class Vektor3D;
class Vertex3D;

class Camera
{
    public:
		static Camera* Instance();
		void Start();


		static Vertex3D *Position;//kde jsem
		static Vektor3D *Direction;//Kam se divam

    private:
        Camera();
        ~Camera(){};
        Camera(const Camera&){}
		void operator= (const Camera){}
		static Camera* pinstance;
};

#endif // CAMERA_H
