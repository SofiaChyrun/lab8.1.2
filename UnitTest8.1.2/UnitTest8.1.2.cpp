#include "pch.h"
#include "CppUnitTest.h"
#include "../ChyrunSofia8.1.2/ChyrunSofia8.1.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest812
{
	TEST_CLASS(UnitTest812)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			char str[10] = ".abd.hkv.";
			t = Count(str,0);
			Assert::AreEqual(t, 3);
		}
	};
}
