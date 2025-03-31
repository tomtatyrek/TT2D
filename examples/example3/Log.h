//
// Created by Tomáš Tatyrek on 29.03.2025.
//

#ifndef LOG_H
#define LOG_H

#include "SDL3/SDL.h"
#include <iostream>


//This code makes sure that debug printing does not get to release version
#define LOG_DEBUG_MODE false

#if(LOG_DEBUG_MODE)
#define LOG_D(x) std::cout << x << "\n";
#else
#define LOG_D(x)
#endif //LOG_DEBUG_MODE

#define IGNORE(x)

#endif //LOG_H
