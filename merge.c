#include <stdio.h>

int main() {
    int a[20], temp[20];
    int n, size, left, mid, right, i, j, k, l;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (size = 1; size < n; size = 2 * size) {
        for (left = 0; left < n - 1; left += 2 * size) {
            mid = left + size - 1;
            right = left + 2 * size - 1;
            if (right >= n)
                right = n - 1;

            i = left;
            j = mid + 1;
            k = left;

            while (i <= mid && j <= right) {
                if (a[i] <= a[j])
                    temp[k++] = a[i++];
                else
                    temp[k++] = a[j++];
            }
            while (i <= mid)
                temp[k++] = a[i++];
            while (j <= right)
                temp[k++] = a[j++];

            for (l = left; l <= right; l++)
                a[l] = temp[l];
        }
    }
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
