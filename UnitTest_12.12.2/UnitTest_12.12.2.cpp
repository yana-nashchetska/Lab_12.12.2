#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.12.2/Lab_12.12.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest12122
{
	TEST_CLASS(UnitTest12122)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Zodiac* root = nullptr;
            Zodiac* testNode = createNode();

			testNode->surname = "winchester";
			testNode->name = "mary";
			testNode->birthday[0] = 12;
			testNode->birthday[1] = 12;
			testNode->birthday[2] = 1912;

			insertNode(testNode);
			string expecdetName = "mary";


			Assert::AreEqual(expecdetName, testNode->name);

         

            // Очистити пам'ять
            delete root;
            delete testNode;

		}
	};
}
