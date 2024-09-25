#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "selection_sort.h"
#include "merge_sort.h"
#include "quicksort.h"

using namespace std;

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

vector<int> generateVector(int size, int min = 0, int max = 100) {
    vector<int> vec(size);
    for (int i = 0; i < size; i++) {
        vec[i] = min + rand() % (max - min + 1);
    }
    return vec;
}

void RegenerateVector(const vector<int>& vec, vector<int>&vec2){
    vec2 = vec;
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    vector<int> vec = generateVector(100);
    vector<int> vec2 = vec;
    
    cout << "Original vector (Selection Sort A):" << endl;
    printVector(vec2);
    selectionSortA(vec2);
    cout << "\nSorted vector (Selection Sort A):" << endl;
    printVector(vec2);
    
    RegenerateVector(vec, vec2);
    
    cout << "\nOriginal vector (Selection Sort B):" << endl;
    printVector(vec2);
    selectionSortB(vec2);
    cout << "\nSorted vector (Selection Sort B):" << endl;
    printVector(vec2);
    
    RegenerateVector(vec, vec2);
    
    cout << "\nOriginal vector (Merge Sort):" << endl;
    printVector(vec2);
    mergesort(vec2);
    cout << "\nSorted vector (Merge Sort):" << endl;
    printVector(vec2);
    
    RegenerateVector(vec, vec2);
    
    cout << "\nOriginal vector (QuickSort):" << endl;
    printVector(vec2);
    quicksort(vec2);
    cout << "\nSorted vector (QuickSort):" << endl;
    printVector(vec2);
    
    return 0;
}