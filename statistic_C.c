#include <stdio.h>
#include <stdlib.h>

// Function to calculate mean
double calculate_mean(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    return (double)sum / size;
}

// Function to sort array (bubble sort)
void sort_array(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to calculate median
double calculate_median(int arr[], int size) {
    int *temp = (int*)malloc(size * sizeof(int));
    
    // Copy array
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    
    // Sort the copy
    sort_array(temp, size);
    
    double median;
    if (size % 2 == 0) {
        median = (temp[size/2 - 1] + temp[size/2]) / 2.0;
    } else {
        median = temp[size/2];
    }
    
    free(temp);
    return median;
}

// Function to calculate mode
void calculate_mode(int arr[], int size) {
    int max_value = arr[0];
    
    // Find maximum value
    for (int i = 1; i < size; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    
    // Create frequency array
    int *freq = (int*)malloc((max_value + 1) * sizeof(int));
    for (int i = 0; i <= max_value; i++) {
        freq[i] = 0;
    }
    
    // Count frequencies
    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }
    
    // Find max frequency
    int max_freq = 0;
    for (int i = 0; i <= max_value; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
        }
    }
    
    // Print modes
    printf("Mode(s): ");
    int first = 1;
    for (int i = 0; i <= max_value; i++) {
        if (freq[i] == max_freq) {
            if (!first) printf(", ");
            printf("%d", i);
            first = 0;
        }
    }
    printf(" (appears %d time(s))\n", max_freq);
    
    free(freq);
}

// Function to print array
void print_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    
    // Test case 1
    int data[] = {15, 23, 15, 42, 18, 23, 15, 30, 25, 18};
    int size = sizeof(data) / sizeof(data[0]);
    
    printf("Input Data: ");
    print_array(data, size);
    printf("\n");
    
    printf("Mean: %.2f\n", calculate_mean(data, size));
    printf("Median: %.2f\n", calculate_median(data, size));
    calculate_mode(data, size);
    
    
    return 0;
}
