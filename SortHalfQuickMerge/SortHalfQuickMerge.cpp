// SortHalfQuickMerge.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

#include "BetterQuickSort.h"
#include "HalfQuickMergeSort.h"

template <class _RandomAccessIterator>
int32_t countTime(_RandomAccessIterator first, _RandomAccessIterator last, void (*sort)(_RandomAccessIterator, _RandomAccessIterator))
{
    auto begin = std::chrono::high_resolution_clock::now();
    sort(first, last);
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
}

int main()
{
    std::mt19937 gen(time(nullptr));
    std::uniform_int_distribution<int> dist_n(10000, 20000);
    std::uniform_int_distribution<int> dist(-100000, 100000);

    size_t t;
    std::cout << "Input number of tests: ";
    std::cin >> t;

    for (size_t _ = 0; _ < t; ++_) {
        size_t n = dist_n(gen);
        std::vector<int> arr(n);
        std::generate_n(arr.begin(), n, [&dist, &gen]() { return dist(gen); });
        std::vector<std::vector<int>> arrs(5, arr);

        std::cout << "\nArray size: " << n;
        std::cout << "\nstd::sort time: " << countTime(arrs[0].begin(), arrs[0].end(), std::sort);
        std::cout << "\nquickSort time: " << countTime(arrs[1].begin(), arrs[1].end(), quickSort);
        std::cout << "\nbetterQuickSort time: " << countTime(arrs[2].begin(), arrs[2].end(), betterQuickSort);
        std::cout << "\nhalfQuickMergeSort time: " << countTime(arrs[3].begin(), arrs[3].end(), halfQuickMergeSort);
        std::cout << "\nbetterHalfQuickMergeSort time: " << countTime(arrs[4].begin(), arrs[4].end(), betterHalfQuickMergeSort);
        std::cout << '\n';
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
