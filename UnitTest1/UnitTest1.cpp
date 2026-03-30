#include "pch.h"
#include "CppUnitTest.h"
#include "../ООП_РІ-13_Резниченко_ЛР-3.4/ООП_РІ-13_Резниченко_ЛР-3.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			SymString s1("test_id1", "Hello World");
			SymString s2("test_id2", "lo "); 
			SymString resultSym = s1 - s2;

			Assert::AreEqual(std::string("HelWorld"), resultSym.GetValue());
		}
	};
}
