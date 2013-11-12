#include "SimplTest.h"

bool g_insert_test(testBase* in){
	global_test_collection.push_back(in);
	return true;
}

void RUN_TESTS(){
	std::vector<testBase*>::iterator it = global_test_collection.begin();
	for( ; it < global_test_collection.end(); it++){
		(*it)->run();
	}
}