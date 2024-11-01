#include "pch.h"
#include "CppUnitTest.h"
#include "D:\лаба 4\ConsoleApplication1\ConsoleApplication1\ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Test1)
	{
	public:
		TEST_METHOD(TestMethod1_nValidation)
		{
			int n = 1;

			try
			{
				nValidation(0, n);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(TestMethod2_dataValidation)
		{
			double a = 6.0;
			double b = 4.0;
			double h = 1.0;
			int n = 3;

			try
			{
				dataValidation(a, b, h, n);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(TestMethod3_calculateY_n1a6b2h1)
		{
			double x = -3.0;
			int n = 3;

			double expected_x = -3.0;

			double expected_y = 9999;

			double y = calculateY(x, n);

			Assert::AreEqual(expected_x, x);
			Assert::AreEqual(expected_y, y);
		}
	};
}
