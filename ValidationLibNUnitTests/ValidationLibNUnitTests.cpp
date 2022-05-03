#include "pch.h"
#include "CppUnitTest.h"
#include "../HomeAutomationControllor/src/ValidationLibrary.h"
 
using namespace ValidationLibrary;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ValidationLibNUnitTests
{
	TEST_CLASS(ValidationLibNUnitTests)
	{
	public:
		
		TEST_METHOD(isMACValid_Test)
		{
			Assert::AreEqual(true, Network::isMACValid("AA:BB:CC:DD:EE:FF:"));
		}
	};
}
