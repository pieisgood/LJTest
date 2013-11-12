//If you have "SimpleAssert.h", "SimpleAssert.cpp", and "SimpleTest.h"
//you only need to include "SimpleTest.h" and write tests like the one
//below. 
#include "SimpleTest.h"


TEST(example, "Test description goes here"){
	int testing_int = 0;
	int testing_other_int = 1;

	Assert(testing_int == testing_other_int, "Assert failure description goes here");
}

TEST(otherExample, "Another description"){
	bool test_bool = false;
	bool test_other_bool = true;

	Assert(test_bool == test_other_bool, "Another failure description");

}


int main(){
	RUN_TESTS();
	return 0;
}