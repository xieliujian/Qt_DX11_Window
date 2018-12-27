
#ifndef __VECTOR4_H_
#define __VECTOR4_H_

#include "Prerequest.h"

NAMESPACEBEGIN(GameEngine)

class Vector4
{
public:
	Vector4();
	Vector4(float x, float y, float z, float w);

public:
	float x;
	float y;
	float z;
	float w;
};

NAMESPACEEND

#endif
