//If you have "SimpleAssert.h", "SimpleAssert.cpp", and "SimpleTest.h"
//you only need to include "SimpleTest.h" and write tests like the one
//below. 

//TEST should be for testing functions and simple things
//TEST_CLASS should be used for testing classes and other
//items that require a setup and teardown method.

#include "SimpleTest.h"
#include "ClassTest.h"


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


//to create a test that has a setup and tear down method
//create a class and inherit publicly from TestParent
//create any methods you need and then create a test
//as shown below.
class ExampleClassTest : public TestParent {
public:

	virtual void setup() {
		thing = 1;
		other_thing = 2;
	}

	virtual void tearDown() {
		thing = 0;
		other_thing = 0;
	}

	virtual const char* GetDesc() {return "Description";}

protected:
	int thing;
	int other_thing;
	
};

TEST_CLASS(ExampleClassTest, testFail){

	Assert(thing == other_thing, "Failure description for test");

}

TEST_CLASS(ExampleClassTest, testPass){

	Assert( thing == (other_thing - 1), "We should pass this");

}


int main(){
	RUN_CLASS_TESTS();
	RUN_TESTS();
	return 0;
}