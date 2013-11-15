//----------------------------------------
//------------ Simple Test ---------------
//----------------------------------------
//........................................
//.. This allows us to create tests for ..
//.. stand alone functions that do not  ..
//.. require a setup and teardown method..
//........................................

#ifndef SIMPLETEST
#define SIMPLETEST

#include <vector>
#include "SimpleAssert.h"

struct testBase {                                                     
  virtual void run() = 0;                                             
  virtual const char* getDesc() = 0;
};

std::vector<testBase*> g_test_collection; 

bool g_insert_test(testBase* in){

	g_test_collection.push_back(in);

	return true;

}

void RUN_TESTS(){

	std::vector<testBase*>::iterator it = g_test_collection.begin();

	for( ; it < g_test_collection.end(); it++){
		(*it)->run();
	}

}

#define TEST(name,desc)                                               \
struct test_##name : public testBase {                                \
  virtual void run();                                                 \
  virtual const char* getDesc() { return desc; }					  \
  static bool start;												  \
};                                                                    \
bool test_##name::start = g_insert_test(new test_##name());			  \
void test_##name::run()

#endif