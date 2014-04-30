#ifndef RESOURCES_H
#define RESOURCES_H

#include <vector>
#include <iostream>

using namespace std;
class Shape;
class Vektor3D;
class Vertex3D;

class Resources
{
    public:
        static Resources* Instance();
        //------------------------Shapes-----------------------
        inline void GetShape(Shape* handle){Shapes.push_back(handle);}//urcite je volana
        template<class InputIterator>
        void For_Each(bool (*fce)(Shape*), InputIterator zacatek=Resources::Instance()->Shapes.begin(), InputIterator konec=Resources::Instance()->Shapes.end())
        {
            for(InputIterator i=zacatek;i!=konec;i++){
                fce(*i);
            }
        }
        //------------------------textures---------------------
        //------------------------terrain----------------------

    private:
        Resources();
        ~Resources(){std::cout<<"Res vola konec"<<std::endl;};
        Resources(const Resources&){}
        static Resources* pinstance;
        //------------------------Shapes-----------------------
    public:
        vector<Shape*> Shapes;
};

#endif
