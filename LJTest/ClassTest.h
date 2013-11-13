#ifndef CLASS_TEST
#define CLASS_TEST

#include <vector>
#include "SimpleAssert.h"

typedef void (*pfunc)();

class TestParent {
public:
	TestParent() {start = true;}
	virtual void run() = 0;
	virtual const char* GetDesc() = 0;
	virtual void setup() = 0;
	virtual void tearDown() = 0;
	bool start;
};

std::vector<TestParent*> g_class_test_collection;

bool g_insert_class_test( TestParent* in ) {
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


#define TEST_CLASS( classname, desc ) \
 bool start =  g_insert_class_test(new classname());\
 void classname::run() \


#endif