#ifndef SMART_POINTER_TESTER
#define SMART_POINTER_TESTER
#include "SmartPointer.h"
#include <assert.h>
#include <string>

//not less than 20 tests because there are 20 functions
class SmrtPtrTester
{
public:
	SmrtPtrTester() 
	{
		passed_tests = 0;
	};

	void RunTests();

	size_t GetPassedTests()
	{
		return passed_tests;
	}
private:
	const size_t number_of_tests = 22;
	size_t passed_tests;

	//7 constructor tests 
	void EmptyConstructorTest();

	void PtrConstructorTest();
	void NullPtrConstructorTest();

	void CopyConstructorTest();
	void EmptyCopyConstructorTest();

	void PolymorfClassConstructorTest();
	void EmptyPolymorfClassConstructor();
	void IncorrectPolymorfClassConstructor();

	//make tests
	void EmptyPtrMakeTest();
	void NonEmptyPtrMake();

	//operators tests
	void EmptyPtrAssignmentOperatorTest();
	void NonEmptyPtrAssignmentOperatorTest();
};

void SmrtPtrTester::RunTests()
{
	this->EmptyConstructorTest();
	this->PtrConstructorTest();
	this->NullPtrConstructorTest();
	this->CopyConstructorTest();
	this->EmptyCopyConstructorTest();
	this->PolymorfClassConstructorTest();
	this->EmptyPolymorfClassConstructor();
	this->IncorrectPolymorfClassConstructor();

	this->EmptyPtrMakeTest();
	this->NonEmptyPtrMake();

	this->NonEmptyPtrAssignmentOperatorTest();
	this->EmptyPtrAssignmentOperatorTest();
}

void SmrtPtrTester::EmptyConstructorTest()
{
	SmrtPtr<int> ptr;
	try
	{
		ptr.get();
	}
	catch (const std::exception& e)
	{
		std::string eName = e.what();
		assert(eName == "Empty pointer");
	}

	passed_tests++;
}

void SmrtPtrTester::PtrConstructorTest()
{
	int* number = new int(5);
	SmrtPtr<int> ptr(number);
	assert(ptr.get() == *number);

	passed_tests++;
}

void SmrtPtrTester::NullPtrConstructorTest()
{
	int* num = NULL;
	SmrtPtr<int> ptr(num);

	try
	{
		ptr.get();
	}
	catch (const std::exception& e)
	{
		std::string eName = e.what();
		assert(eName == "Empty pointer");
	}

	passed_tests++;
}

void SmrtPtrTester::CopyConstructorTest()
{
	int* number = new int(5);
	SmrtPtr<int> ptr1(number);
	SmrtPtr<int> ptr2 = ptr1;
	assert(ptr2.get() == ptr1.get());

	passed_tests++;
}

void SmrtPtrTester::EmptyCopyConstructorTest()
{
	SmrtPtr<int> ptr1;
	SmrtPtr<int> ptr2 = ptr1;

	try
	{
		ptr2.get();
	}
	catch (const std::exception& e)
	{
		std::string eName = e.what();
		assert(eName == "Empty pointer");
	}

	passed_tests++;
}

void SmrtPtrTester::PolymorfClassConstructorTest()
{
	class TestingClass
	{
	public:
		virtual bool func() { return false; };
		TestingClass() {};
	};

	class SubTestingClass : public TestingClass
	{
	public:
		bool func() { return true; };
		SubTestingClass() {};
	};

	SubTestingClass* child = new SubTestingClass;
	SmrtPtr<SubTestingClass> childPtr(child);
	SmrtPtr<TestingClass> parentPtr = childPtr;
	
	assert(parentPtr.get().func());

	passed_tests++;
}

void SmrtPtrTester::EmptyPolymorfClassConstructor()
{
	class TestingClass
	{
	public:
		virtual bool func() { return false; };
		TestingClass() {};
	};

	class SubTestingClass : public TestingClass
	{
	public:
		bool func() { return true; };
		SubTestingClass() {};
	};

	SubTestingClass* child = NULL;
	SmrtPtr<SubTestingClass> childPtr(child);
	SmrtPtr<TestingClass> parentPtr = childPtr;

	try
	{
		parentPtr.get();
	}
	catch (const std::exception& e)
	{
		std::string eName = e.what();
		assert(eName == "Empty pointer");
	}

	passed_tests++;
}

void SmrtPtrTester::IncorrectPolymorfClassConstructor()
{
	class TestingClass1
	{
	public:
		virtual bool func() { return false; };
		TestingClass1() {};
	};

	class TestingClass2
	{
	public:
		bool func() { return true; };
		TestingClass2() {};
	};

	TestingClass1* object1 = new TestingClass1;
	SmrtPtr<TestingClass1> obj1Ptr(object1);
	try
	{
		SmrtPtr<TestingClass2> obj2Ptr = obj1Ptr;
	}
	catch (std::exception& e)
	{
		std::string eName = e.what();
		assert(eName == "Class P is not subclass of class T");
	}

	passed_tests++;
}

void SmrtPtrTester::EmptyPtrMakeTest()
{
	SmrtPtr<int> intPtr;
	intPtr.make(5);

	assert(intPtr.get() == 5);

	passed_tests++;
}

void SmrtPtrTester::NonEmptyPtrMake()
{
	int* num = new int(5);
	SmrtPtr<int> ptr1(num);
	ptr1.make(10);

	assert(ptr1.get() == 10);

	passed_tests++;
}

void SmrtPtrTester::NonEmptyPtrAssignmentOperatorTest()
{
	SmrtPtr<int>numPtr1;
	numPtr1.make(10);
	SmrtPtr<int>numPtr2;
	numPtr2 = numPtr1;

	assert(numPtr1.get() == numPtr2.get());

	passed_tests++;
}

void SmrtPtrTester::EmptyPtrAssignmentOperatorTest()
{
	SmrtPtr<int> ptr1;
	SmrtPtr<int> ptr2;

	ptr2 = ptr1;

	try
	{
		ptr2.get();
	}
	catch (const std::exception& e)
	{
		std::string eName = e.what();
		assert(eName == "Empty pointer");
	}

	passed_tests++;
}


class SmrtPtrArrayTester
{

public:
	SmrtPtrArrayTester()
	{
		passed_tests = 0;
	};

	void RunVisibleTests();
	void RunTests();

	size_t GetPassedTests()
	{
		return passed_tests;
	}
private:
	const size_t number_of_tests = 20;
	size_t passed_tests;

	//7 constructor tests 
	void EmptyConstructorTest();

	void SizeConstructorTest();
	void NullPtrConstructorTest();

	void CopyConstructorTest();
	void EmptyCopyConstructorTest();

	void PolymorfClassConstructorTest();
	void EmptyPolymorfClassConstructor();
	void IncorrectPolymorfClassConstructor();

	//make tests
	void EmptyPtrMakeTest();
	void NonEmptyPtrMake();

	//operators tests
	void EmptyPtrAssignmentOperatorTest();
	void NonEmptyPtrAssignmentOperatorTest();
};

void SmrtPtrArrayTester::RunTests()
{
	this->EmptyConstructorTest();
	this->SizeConstructorTest();
}

void SmrtPtrArrayTester::EmptyConstructorTest()
{
	SmrtPtr<int[]> sArray;
	try
	{
		sArray.get(0);
	}
	catch (const std::exception& e)
	{
		std::string eName = e.what();
		assert(eName == "Empty pointer");
	}

	passed_tests++;

}

void SmrtPtrArrayTester::SizeConstructorTest()
{
	SmrtPtr<int[]> sArray(5);
	sArray[2] = 10;

	assert(sArray.get(2) == 10);

	passed_tests++;
}
#endif