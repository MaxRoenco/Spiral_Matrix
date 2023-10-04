#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void print(int n, int m, int mat[][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void flatten(int n, int m, int arr[], int mat[][m]){
int index = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[index] = mat[i][j];
            index++;
        }
    }
}

int qk_partition(int arr[], int low, int high){
    int pivot = high;
    int i = low;
    for(int j = low; j < high; j++){
        if(arr[j] <= arr[pivot]){
            swap(&arr[j], &arr[i]);
            i++;
        }
    }
    swap(&arr[i], &arr[pivot]);
return i;
}

void recursive (int arr[], int low, int high){
if(low >= high){
    return;
}
int pivot = qk_partition(arr, low, high);
recursive(arr, low, pivot - 1);
recursive(arr, pivot + 1, high);
}

void quicksort(int arr[], int n){
recursive(arr, 0, n - 1);
}

void rows_wise(int n, int m, int arr[], int mat[][m]){
int index = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] = arr[index];
            index++;
        }
    }
}

void column_wise(int n, int m, int arr[], int mat[][m]){
int index = 0;
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            mat[i][j] = arr[index];
            index++;
        }
    }
}

int main(){
int n;
int m;
int k;
start:
printf("Input number of rows in matrix: ");
scanf("%d", &n);
printf("Input number of columns in matrix: ");
scanf("%d", &m);
int mat[n][m];
int arr[n*m];
srand(time(NULL));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            mat[i][j] = rand()%2000 - 1000;
        }
    }
print(n, m, mat);
printf("1 - rows_wise\n");
printf("2 - columns_wise\n");
printf("3 - stop\n");
scanf("%d", &k);
    switch(k){
    case 1:
        flatten(n, m, arr, mat);
        quicksort(arr, n*m);
        rows_wise(n, m, arr, mat);
        printf("\n");
        print(n, m, mat);
        break;
    case 2:
        flatten(n, m, arr, mat);
        quicksort(arr, n*m);
        column_wise(n, m, arr, mat);
        printf("\n");
        print(n, m, mat);
        break;
    case 3:
        return;
    }
goto start;
}
