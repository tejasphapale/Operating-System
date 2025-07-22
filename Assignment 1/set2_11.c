#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


void bubblesort(int arr[], int n) {
int temp;
for (int i = 0; i < n-1; i++) {
  for (int j = 0; j < n-1-i; j++) {
 if (arr[j] > arr[j+1]) {
 temp = arr[j];
 arr[j] = arr[j+1];
 arr[j+1] = temp;
 }
 }
 }
}

void insertionsort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    printf("Enter number of integers: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    pid_t pid = fork();

    if (pid == 0) {
        printf("\n[Child Process] PID: %d, Parent PID: %d\n", getpid(), getppid());
        printf("Performing Insertion Sort...\n");

        insertionsort(arr, n);

        printf("Sorted Array (Insertion Sort):\n");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");

    } else if (pid > 0) {
        wait(NULL); 
        printf("\n[Parent Process] PID: %d, Child PID: %d\n", getpid(), pid);
        printf("Performing Bubble Sort...\n");

        bubblesort(arr, n);

        printf("Sorted Array (Bubble Sort):\n");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");

    } else {
        printf("Failed to create child process.\n");
    }

    free(arr);
    return 0;
}

