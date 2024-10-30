#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_07.2-rec/lab_07.2-rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixTest
{
    TEST_CLASS(MatrixTest)
    {
    public:

        // ���� ��� ������� CreateRows (�������� ���������� ���������� �������)
        TEST_METHOD(TestCreateMatrix)
        {
            int N = 3;
            int Low = -9, High = 9;

            int** a = new int* [N];
            for (int i = 0; i < N; i++)
                a[i] = new int[N];

            CreateRows(a, N, Low, High, 0);

            // ��������, �� �� �������� ����������� � ��������� �������
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

        // ���� ��� ������� SearchFirstEven (����� ������� ������� �������� ������ �������)
        TEST_METHOD(TestSearchFirstEven)
        {
            int N = 3;
            int** a = new int* [N];
            for (int i = 0; i < N; i++)
                a[i] = new int[N];

            // ������������ ������� � ������� ����������
            a[0][2] = 5;  // ������ ��������
            a[1][1] = 8;  // ������ �������� (������ ������ �������)
            a[2][0] = 4;  // ������ ��������

            int k = -1;
            int minEven;

            SearchFirstEven(a, N, 0, minEven, k);

            // ��������: ������ ������ ������� ������� ���� 8, � �� ����������� � ����� 1
            Assert::AreEqual(8, minEven);
            Assert::AreEqual(1, k);

            for (int i = 0; i < N; i++)
                delete[] a[i];
            delete[] a;
        }

        // ���� ��� ������� SearchMinEven (����� ���������� ������� �������� �� ������ �������)
        TEST_METHOD(TestSearchMinEven)
        {
            int N = 3;
            int** a = new int* [N];
            for (int i = 0; i < N; i++)
                a[i] = new int[N];

            // ������������ ������� � ������� ����������
            a[0][2] = 5;  // ������ ��������
            a[1][1] = 8;  // ������ ��������
            a[2][0] = 4;  // ������ �������� (��������� ������ �������)

            int minEven = 8; // ��������� �������� ���������� ������� (��� ����� � ���������� �������)
            SearchMinEven(a, N, 2, minEven); // �������� � ���������� �������� ���� ������� ���������� �������

            // ��������: ��������� ������ ������� �� ������ ������� �� ���� 4
            Assert::AreEqual(4, minEven);

            for (int i = 0; i < N; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}
