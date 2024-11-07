#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_8.1_it/8.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            char str[201] = "abc++def--==ghi"; // Збільшено розмір буфера
            const char* expected = "abc****def********ghi";

            // Виклик функції Change
            Change(str);

            // Перевірка результату
            Assert::AreEqual(std::string(expected), std::string(str));
        }
    };
}