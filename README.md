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

Assert( expression, "Assert description");

Failed Asserts that are skipped are written to a file for future reference.


To run your tests simply call:

RUN_TESTS();

This will run all tests currently in the test list.
