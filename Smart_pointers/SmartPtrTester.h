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

	void RunTests()
	{
		this->EmptyConstructor();
		this->PtrConstructor();
		this->NullPtrConstructor();
		this->CopyConstructor();
		this->EmptyCopyConstructor();
		this->PolymorfClassConstructor();
		this->EmptyPolymorfClassConstructor();
		this->IncorrectPolymorfClassConstructor();

		this->EmptyPtrMake();
		this->NonEmptyPtrMake();

		this->NonEmptyPtrAssignmentOperator();
		this->EmptyPtrAssignmentOperator();
	}

	size_t GetPassedTests()
	{
		return passed_tests;
	}
private:
	const size_t number_of_tests = 22;
	size_t passed_tests;

	//7 constructor tests 
	void EmptyConstructor() 
	{
		SmrtPtr<int> ptr;
		try
		{
			ptr.Get();
		}
		catch (const std::exception& e)
		{
			std::string eName = e.what();
			assert(eName == "Empty pointer");
		}

		passed_tests++;
	}

	void PtrConstructor()
	{
		int* number = new int(5);
		SmrtPtr<int> ptr(number);
		assert(ptr.Get() == *number);

		passed_tests++;
	}
	void NullPtrConstructor()
	{
		int* num = NULL;
		SmrtPtr<int> ptr(num);

		try
		{
			ptr.Get();
		}
		catch (const std::exception& e)
		{
			std::string eName = e.what();
			assert(eName == "Empty pointer");
		}

		passed_tests++;
	}

	void CopyConstructor()
	{
		int* number = new int(5);
		SmrtPtr<int> ptr1(number);
		SmrtPtr<int> ptr2 = ptr1;
		assert(ptr2.Get() == ptr1.Get());

		passed_tests++;
	}
	void EmptyCopyConstructor()
	{
		SmrtPtr<int> ptr1;
		SmrtPtr<int> ptr2 = ptr1;

		try
		{
			ptr2.Get();
		}
		catch (const std::exception& e)
		{
			std::string eName = e.what();
			assert(eName == "Empty pointer");
		}

		passed_tests++;
	}

	void PolymorfClassConstructor()
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

		assert(parentPtr.Get().func());

		passed_tests++;
	}
	void EmptyPolymorfClassConstructor()
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
			parentPtr.Get();
		}
		catch (const std::exception& e)
		{
			std::string eName = e.what();
			assert(eName == "Empty pointer");
		}

		passed_tests++;
	}
	void IncorrectPolymorfClassConstructor()
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

	//make tests
	void EmptyPtrMake()
	{
		SmrtPtr<int> intPtr;
		intPtr.Make(5);

		assert(intPtr.Get() == 5);

		passed_tests++;
	}
	void NonEmptyPtrMake()
	{
		int* num = new int(5);
		SmrtPtr<int> ptr1(num);
		ptr1.Make(10);

		assert(ptr1.Get() == 10);

		passed_tests++;
	}

	//operators tests
	void EmptyPtrAssignmentOperator()
	{
		SmrtPtr<int>numPtr1;
		numPtr1.Make(10);
		SmrtPtr<int>numPtr2;
		numPtr2 = numPtr1;

		assert(numPtr1.Get() == numPtr2.Get());

		passed_tests++;
	}
	void NonEmptyPtrAssignmentOperator()
	{
		SmrtPtr<int> ptr1;
		SmrtPtr<int> ptr2;

		ptr2 = ptr1;

		try
		{
			ptr2.Get();
		}
		catch (const std::exception& e)
		{
			std::string eName = e.what();
			assert(eName == "Empty pointer");
		}

		passed_tests++;
	}
};

#endif