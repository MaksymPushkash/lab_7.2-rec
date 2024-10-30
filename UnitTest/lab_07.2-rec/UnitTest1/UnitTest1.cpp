#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_07.2-rec/lab_07.2-rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixTest
{
    TEST_CLASS(MatrixTest)
    {
    public:

        // Тест для функції CreateRows (перевірка коректного заповнення матриці)
        TEST_METHOD(TestCreateMatrix)
        {
            int N = 3;
            int Low = -9, High = 9;

            int** a = new int* [N];
            for (int i = 0; i < N; i++)
                a[i] = new int[N];

            CreateRows(a, N, Low, High, 0);

            // Перевірка, що всі елементи знаходяться у вказаному діапазоні
            bool inRange = true;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (a[i][j] < Low || a[i][j] > High) {
                        inRange = false;
                        break;
                    }
                }
            }
            Assert::IsTrue(inRange);

            for (int i = 0; i < N; i++)
                delete[] a[i];
            delete[] a;
        }

        // Тест для функції SearchFirstEven (пошук першого парного елемента побічної діагоналі)
        TEST_METHOD(TestSearchFirstEven)
        {
            int N = 3;
            int** a = new int* [N];
            for (int i = 0; i < N; i++)
                a[i] = new int[N];

            // Встановлення матриці з відомими значеннями
            a[0][2] = 5;  // побічна діагональ
            a[1][1] = 8;  // побічна діагональ (перший парний елемент)
            a[2][0] = 4;  // побічна діагональ

            int k = -1;
            int minEven;

            SearchFirstEven(a, N, 0, minEven, k);

            // Перевірка: перший парний елемент повинен бути 8, і він знаходиться в рядку 1
            Assert::AreEqual(8, minEven);
            Assert::AreEqual(1, k);

            for (int i = 0; i < N; i++)
                delete[] a[i];
            delete[] a;
        }

        // Тест для функції SearchMinEven (пошук найменшого парного елемента на побічній діагоналі)
        TEST_METHOD(TestSearchMinEven)
        {
            int N = 3;
            int** a = new int* [N];
            for (int i = 0; i < N; i++)
                a[i] = new int[N];

            // Встановлення матриці з відомими значеннями
            a[0][2] = 5;  // побічна діагональ
            a[1][1] = 8;  // побічна діагональ
            a[2][0] = 4;  // побічна діагональ (мінімальний парний елемент)

            int minEven = 8; // Початкове значення мінімального парного (вже відомо з попередньої функції)
            SearchMinEven(a, N, 2, minEven); // Починаємо з наступного елемента після першого знайденого парного

            // Перевірка: найменший парний елемент на побічній діагоналі має бути 4
            Assert::AreEqual(4, minEven);

            for (int i = 0; i < N; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}
