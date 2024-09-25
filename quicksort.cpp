#include "quicksort.h"
#include <algorithm>

int partition(std::vector<int>& A, int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[r]);
    return i + 1;
}

void quickSortHelper(std::vector<int>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSortHelper(A, p, q - 1);
        quickSortHelper(A, q + 1, r);
    }
}

void quicksort(std::vector<int>& ar) {
    quickSortHelper(ar, 0, ar.size() - 1);
}
