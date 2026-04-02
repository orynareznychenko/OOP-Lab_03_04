#include "pch.h"
#include "CppUnitTest.h"
#include "../ООП_РІ-13_Резниченко_ЛР-3.4/DecString.h"
#include "../ООП_РІ-13_Резниченко_ЛР-3.4/Factory.h"
#include "../ООП_РІ-13_Резниченко_ЛР-3.4/SymString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            SymString s1("test_id1", "HelloWorldStringWorld");
            SymString s2("test_id2", "World");

            SymString result = s1 - s2;

            Assert::AreEqual(std::string("HelloString"), result.getValue(), L"Substring was not removed correctly!");

            Assert::AreEqual(std::string("test_id1_res"), result.getId(), L"ID was not generated correctly!");
        }
	};
}
