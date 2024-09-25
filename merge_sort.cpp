#include "merge_sort.h"

void merge(std::vector<int>& A, int p, int q, int r) {
    int nL = q - p + 1;
    int nR = r - q;
    std::vector<int> L(nL), R(nR);

    for (int i = 0; i < nL; i++) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < nR; j++) {
        R[j] = A[q + 1 + j];
    }

    int i = 0, j = 0, k = p;
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nL) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < nR) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortHelper(std::vector<int>& A, int p, int r) {
    if (p >= r) return;
    int q = (p + r) / 2;
    mergeSortHelper(A, p, q);
    mergeSortHelper(A, q + 1, r);
    merge(A, p, q, r);
}

void mergesort(std::vector<int>& ar) {
    mergeSortHelper(ar, 0, ar.size() - 1);
}
