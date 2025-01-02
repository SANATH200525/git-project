// binarysearch.c
#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search
int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Element found
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Element not found
}

// Function to read input from a file
void read_input(const char *filename, int *arr, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    *size = 0;
    while (fscanf(file, "%d", &arr[*size]) == 1) {
        (*size)++;
    }
    fclose(file);
}

// Function to read the search element from a file
int read_search_element(const char *filename) {
    int target;
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open search element file");
        exit(EXIT_FAILURE);
    }
    fscanf(file, "%d", &target);
    fclose(file);
    return target;
}

// Function to check if the array is sorted
int is_sorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return 0; // Not sorted
        }
    }
    return 1; // Sorted
}

int main() {
    int arr[100]; // Adjust size as needed
    int size;

    // Read input from input.txt
    read_input("input.txt", arr, &size);

    // Check if the array is sorted
    if (!is_sorted(arr, size)) {
        printf("Input array is not sorted. Please fix the input.txt file.\n");
        return 1;
    }

    // Read the search element from srchele.txt
    int target = read_search_element("srchele.txt");

    // Perform binary search
    int result = binary_search(arr, size, target);
    if (result != -1) {
        printf("Element found at index %d.\n", result);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}