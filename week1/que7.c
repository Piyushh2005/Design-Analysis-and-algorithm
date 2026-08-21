Write a C program to rotate an array to the right by K positions without using another array.
  Array: 1 2 3 4 5 6 K = 2 Output: 5 6 1 2 3 4
  #include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main() {
    int n, k, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter K: ");
    scanf("%d", &k);

    k = k % n;

    // Reverse complete array
    reverse(arr, 0, n - 1);

    // Reverse first K elements
    reverse(arr, 0, k - 1);

    // Reverse remaining elements
    reverse(arr, k, n - 1);

    printf("Rotated array:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
