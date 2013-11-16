//----------------------------------------
//------------ Simple Assert -------------
//----------------------------------------
//........................................
//.. This will use a simple assert func ..
//.. in place of the standard assert.   ..
//.. You can comment out the debug break..
//.. line and all assert failures will  ..
//.. be printed to a file insead of     ..
//.. interupting your program.          ..
//........................................

#ifndef SIMPLEASSERT
#define SIMPLEASSERT

#include <assert.h>

#if defined( _DEBUG)
extern bool QDGE_ASSERT( bool, char*, int, char*);

#define Assert( exp, description) \
	if( QDGE_ASSERT((int)(exp), description, __LINE__, __FILE__) )\
	{ _asm{ int 3 } } //debugger will break here

#else
//we make asserts easier to read by allowing a description
#define Assert( exp, description) assert(exp && description)

#endif


bool QDGE_ASSERT( bool exp, char* desc, int line, char* file_name);

#endif