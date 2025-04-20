
#ifndef TT2D_TT2D_H
#define TT2D_TT2D_H

//All TT2D header files to be included:
#include "App.h"
#include "TT2D/components/primitives/Point.h"
#include "TT2D/components/primitives/PointCollection.h"
#include "TT2D/components/Arc.h"
#include "TT2D/components/FillRectangle.h"
#include "TT2D/components/Line.h"
#include "TT2D/components/ColoredPoint.h"
#include "TT2D/components/Rectangle.h"
#include "TT2D/render/Color.h"
#include "TT2D/render/Renderable.h"
#include "TT2D/render/Window.h"
#include "TT2D/util/Log.h"
#include "TT2D_defines.h"

namespace TT2D {

    //Basic testing function - logs "Hello World" using SDL_Log and prints "Hello World" into the standard output
    void hello();
    
}

#endif //TT2D_TT2D_H