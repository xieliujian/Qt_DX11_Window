
#ifndef __COLOR_h__
#define __COLOR_h__

#include "Prerequest.h"

NAMESPACEBEGIN(GameEngine)

class Color
{
public:
	Color();
	Color(float r, float g, float b, float a);

public:
	float r;
	float g;
	float b;
	float a;
};

NAMESPACEEND

#endif