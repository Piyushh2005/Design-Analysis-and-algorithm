 Write a C program to find all pairs of elements in an array whose sum is equal to a given target value. Each pair should be displayed only once.
   Array: 2 7 4 5 1 3 Target: 6 Output: (2, 4), (5, 1)
   #include <stdio.h>

int main() {
    int n, target;
    int i, j;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &target);

    printf("Pairs are:\n");

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {

            if (arr[i] + arr[j] == target) {

                int duplicate = 0;

                for (int x = 0; x < i; x++) {
                    for (int y = x + 1; y < n; y++) {
                        if (arr[x] + arr[y] == target &&
                            arr[x] == arr[i] &&
                            arr[y] == arr[j]) {
                            duplicate = 1;
                        }
                    }
                }

                if (!duplicate) {
                    printf("(%d, %d)\n", arr[i], arr[j]);
                }
            }
        }
    }

    return 0;
}
