#ifndef TERRAIN_H
#define TERRAIN_H


class Terrain
{
    public:
        static Terrain* Instance();
    private:
        Terrain(){};
        ~Terrain(){};
        Terrain(const Terrain&){}
    Terrain& operator= (const Terrain X){}
    static Terrain* pinstance;
};
#endif // TERRAIN_H
