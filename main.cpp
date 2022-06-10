#include <iostream>
#include "quicksort.h"
#include "mergesort.h"
#include <chrono>

int main() {

    //Get size of array
    std::cout << "Enter dataset size" << "\n";
    int setSize{};
    std::cin >> setSize;

    int dataset[setSize];
    //fill array with rand()
    for (int i = 0; i < setSize; i++)
    {
        int num = rand();
        dataset[i] = num;
    }

    int dataset2[setSize];
    std::copy(dataset, dataset+setSize, dataset2);

    //Mergesort
    std::cout << "Mergesort begin..." << "\n";

    auto mergeStart = std::chrono::high_resolution_clock::now();

    mergeSort(dataset, 0, setSize - 1);

    auto mergeStop = std::chrono::high_resolution_clock::now();
    std::cout << "Mergesort end..." << "\n";

    auto mergeDuration = std::chrono::duration_cast<std::chrono::microseconds>(mergeStop - mergeStart);

    std::cout << "Mergesort runtime: " << mergeDuration.count() << " microseconds\n";

    //Quicksort
    std::cout << "Quicksort begin..." << "\n";

    auto start = std::chrono::high_resolution_clock::now();

    quickSort(dataset2, 0 , setSize - 1);

    auto stop = std::chrono::high_resolution_clock::now();

    std::cout << "Quicksort complete" << "\n";

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Quicksort runtime: " << duration.count() << " microseconds\n";



    return 0;
}
