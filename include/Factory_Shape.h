#ifndef FACTORY_SHAPE_H
#define FACTORY_SHAPE_H

#include "Shapes/Shapes.h"


class Factory_Shape
{
    public:
        /** Default constructor */
        Factory_Shape();
        /** Default destructor */
        virtual ~Factory_Shape();
        static Shape* Shape_cache;
};

#endif // FACTORY_SHAPE_H
