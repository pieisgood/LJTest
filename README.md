LJTest
======

A simple test framework.

Put the files into your source directory and #include "SimpleTest.h"

Each test is written as:

```C++
TEST( test_name, "Test description"){


}
```

There is also an overloaded assert function.

Asserts are written as:
```C++
Assert( expression, "Assert description");
```
Failed Asserts that are skipped are written to a file for future reference.


To run your tests simply call:
```C++
RUN_TESTS();
```
This will run all tests currently in the test list.

To create larger tests of classes and other things that require a Setup and TearDown method, you can use the TEST_CLASS function.

In order to use it, we start with a simple class and derive from TestParent.

```C++
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

	SOFT_ASSERT(thing == other_thing, "Our integers did not match up!");

}

TEST_CLASS(ExampleClassTest, testPass){

	SOFT_ASSERT( thing == (other_thing - 1), "We should pass this");

}


```

We create our setup and teardown methods and call TEST_CLASS( ourClass, OurTestName) and write our test.

Then we use 
```C++
RUN_CLASS_TEST();
```
to run our class tests.

In the end we get an output that looks like this:
![alt text](https://raw.github.com/pieisgood/LJTest/master/LJTest/TestFailPass.gif "Command Line Tests")
