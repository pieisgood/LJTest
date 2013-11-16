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

#ifdef _WIN32
#include <Windows.h>
void print_green_text( const char* text ){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf(text);

    /* Restore original attributes */
    SetConsoleTextAttribute(hConsole, saved_attributes);
}

void print_red_text( const char* text ){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole, BACKGROUND_RED);
    printf(text);

    /* Restore original attributes */
    SetConsoleTextAttribute(hConsole, saved_attributes);
}
#else
void print_red_text( const char* text ){}
void print_green_text( const char* text ){}
#endif


#include <vector>
#include <iostream>
#include "SimpleAssert.h"

struct failure{
	int line;
	const char* file;
	const char* description;
};

class TestParent {
public:
	bool check;
	std::vector<failure> fails;
	const char* test_name;
	TestParent(){check = true;}
	virtual void run() = 0;
	virtual const char* GetDesc() = 0;
	virtual void setup() = 0;
	virtual void tearDown() = 0;

	void CHECK_TRUE( bool exp, const char* desc, int line, const char* file){
		if( !exp ){
			check = false;
			failure in;
			in.line = line;
			in.file = file;
			in.description = desc;

			fails.push_back(in);
		}
	}

	void PRINT_TEST(){
		if( check ){

			std::cout << test_name << ":";
			print_green_text(" PASS \n");
		}
		else{

			std::cout << test_name << ": ";
			print_red_text("FAIL\n");

			std::vector<failure>::iterator it = fails.begin();
			for( ; it < fails.end(); it++){
				print_red_text("FAIL");
				std::cout << ": " << (*it).description << "\n";
			}
		}
	}

	bool getTestCheck(){return check;}
	const char* getTestName(){ return test_name;}
};

#define SOFT_ASSERT(exp, desc) \
	CHECK_TRUE(exp, desc, __LINE__, __FILE__);

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

	for( it = g_class_test_collection.begin(); \
		it < g_class_test_collection.end(); it++){
			(*it)->PRINT_TEST();
	}


}


#define TEST_CLASS( classname, desc )					\
class test_##desc : public classname {                  \
	static bool start;									\
	test_##desc(){ test_name = #desc; }					\
	virtual const char* GetDesc() { return #desc; }		\
	virtual void run();									\
	virtual void setup() { classname::setup(); }		\
	virtual void tearDown() { classname::tearDown(); }	\
};														\
bool test_##desc::start = g_insert_class_test(new test_##desc());\
void test_##desc::run()									\




#endif