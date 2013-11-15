//----------------------------------------
//------------ Class Test ----------------
//----------------------------------------
//........................................
//.. This allows us to create tests for ..
//.. classes and functions that require ..
//.. setup and teardown methods for     ..
//.. testing.                           ..
//........................................

#ifndef CLASS_TEST
#define CLASS_TEST

#include <vector>
#include "SimpleAssert.h"

class TestParent {
public:
	TestParent(){}
	virtual void run() = 0;
	virtual const char* GetDesc() = 0;
	virtual void setup() = 0;
	virtual void tearDown() = 0;
};

std::vector<TestParent*> g_class_test_collection;

bool g_insert_class_test( TestParent* in ){

	g_class_test_collection.push_back(in);

	return true;

}

void RUN_CLASS_TESTS(){

	std::vector<TestParent*>::iterator it = g_class_test_collection.begin();

	for( ; it < g_class_test_collection.end(); it++){
		(*it)->setup();
		(*it)->run();
		(*it)->tearDown();
	}

}


#define TEST_CLASS( classname, desc )					\
class test_##desc : public classname {                  \
	static bool start;									\
	test_##desc(){}										\
	virtual const char* GetDesc() { return #desc; }		\
	virtual void run();									\
	virtual void setup() { classname::setup(); }		\
	virtual void tearDown() { classname::tearDown(); }	\
};														\
bool test_##desc::start = g_insert_class_test(new test_##desc());\
void test_##desc::run()									\




#endif