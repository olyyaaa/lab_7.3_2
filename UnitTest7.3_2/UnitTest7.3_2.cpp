#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.3_2/lab_7.3_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest731
{
	TEST_CLASS(UnitTest731)
	{
		TEST_METHOD(TestMethod1)
		{
			int r;
			r = main();
			Assert::AreEqual(r, 0);
		}
	};
}

