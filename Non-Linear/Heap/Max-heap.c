#include <stdio.h>
#define MAX 100


void bottomUpHeapify(int *h, int n) {
    int i, j, key;
    for (int k = (n - 1) / 2; k >= 0; k--) {
        j = k;
        key = h[j];
        i = 2 * j + 1; // left child
        while (i < n) {
            if (i + 1 < n && h[i + 1] > h[i]) i++; // choose larger child
            if (key < h[i]) {
                h[j] = h[i];
                j = i;
                i = 2 * j + 1;
            } else break;
        }
        h[j] = key;
    }
}

// Top-Down Heapify (insert)
void topDownHeapify(int *h, int *n, int value) {
    if (*n >= MAX) {
        printf("Heap Overflow\n");
        return;
    }
    int i = (*n)++;
    h[i] = value;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h[parent] < h[i]) {
            int temp = h[parent];
            h[parent] = h[i];
            h[i] = temp;
            i = parent;
        } else break;
    }
}

// Delete max (root) from heap
int deleteMax(int *h, int *n) {
    if (*n <= 0) {
        printf("Heap Underflow\n");
        return -1;
    }
    int max = h[0];
    h[0] = h[--(*n)];
    bottomUpHeapify(h, *n);
    return max;
}

int main() {
    int h[MAX], n = 0, choice, value;

    while (1) {
        printf("\n--- MAX HEAP MENU ---\n");
        printf("1. Insert (Top-Down)\n");
        printf("2. Build Heap (Bottom-Up)\n");
        printf("3. Delete Max\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                topDownHeapify(h, &n, value);
                break;

            case 2:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter elements:\n");
                for (int i = 0; i < n; i++) scanf("%d", &h[i]);
                bottomUpHeapify(h, n);
                break;

            case 3: {
                int max = deleteMax(h, &n);
                if (max != -1) printf("Deleted Max: %d\n", max);
                break;
            }

            case 4:
                printf("Heap elements: ");
                for (int i = 0; i < n; i++) printf("%d ", h[i]);
                printf("\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
