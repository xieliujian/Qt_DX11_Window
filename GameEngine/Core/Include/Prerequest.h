

#ifndef __Prerequest_h__
#define __Prerequest_h__

#define NAMESPACEBEGIN(x) namespace x {
#define NAMESPACEEND };

typedef char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;
typedef long int32;
typedef unsigned long uint32;
typedef __int64 int64;
typedef unsigned __int64 uint64;

#define SAFE_DELETE_ARRAY(p) {if(p){delete []p; p = NULL;}}
#define SAFE_DELETE(p) {if(p){delete p; p = NULL;}}
#define SAFE_RELEASE(p) {if(p){p->Release(); p = NULL;}}

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#include <vector>
#include <map>
#include <list>
#include <stack>

#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#endif