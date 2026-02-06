#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

long long comparisons = 0;
long long swaps = 0;

void swap(int *a, int *b) {
    swaps++;
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int n) {
    comparisons = swaps = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            comparisons++;
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    comparisons = swaps = 0;
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(&arr[i], &arr[minIdx]);
        }
    }
}

void insertionSort(int arr[], int n) {
    comparisons = swaps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;

        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j+1] = arr[j];
                swaps++; 
                j--;
            } else {
                break;
            }
        }
        arr[j+1] = key;
        swaps++; 
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    int i=0, j=0, k=l;

    while (i < n1 && j < n2) {
        comparisons++;
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
            swaps++; 
        } else {
            arr[k++] = right[j++];
            swaps++;
        }
    }

    while (i < n1) {
        arr[k++] = left[i++];
        swaps++;
    }

    while (j < n2) {
        arr[k++] = right[j++];
        swaps++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int N;
    printf("Enter the number of random integers (N): ");
    scanf("%d", &N);

    if (N <= 0 || N > MAX) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX);
        return 1;
    }

    int arr[N], original[N];

    // Generate N random integers in range [1,1000]
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        arr[i] = (rand() % 1000) + 1;
        original[i] = arr[i]; 
    }

    //(a) Ask user to choose sorting algorithm
    int choice;
    printf("Choose sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);

    // (c) Print numbers before sorting
    printf("\nNumbers before sorting:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", original[i]);
    }
    printf("\n");

    // (b) Sort using chosen algorithm and (d) count comparisons and swaps
    switch(choice) {
        case 1:
            bubbleSort(arr, N);
            break;
        case 2:
            selectionSort(arr, N);
            break;
        case 3:
            insertionSort(arr, N);
            break;
        case 4:
            comparisons = swaps = 0;
            mergeSort(arr, 0, N-1);
            break;
        default:
            printf("Invalid choice. Exiting.\n");
            return 1;
    }

    // Print numbers after sorting
    printf("\nNumbers after sorting:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // (d) Display comparisons and swaps
    printf("\nTotal comparisons: %lld\n", comparisons);
    printf("Total swaps/assignments: %lld\n", swaps);

    return 0;
}
