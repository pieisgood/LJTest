LJTest
======

A simple test framework.

Put the files into your source directory and #include "SimpleTest.h"

Each test is written as:

TEST( test_name, "Test description"){


}

There is also an overloaded assert function.

Asserts are written as:

Assert( expression, "Assert description");

Failed Asserts that are skipped are written to a file for future reference.
