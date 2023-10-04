#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void print(int n, int m, int mat[][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", mat[i][j]);
        }
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

void spiral_recursive(int n, int m, int m_1, int arr[], int mat[][m_1], int x, int y, int dir, int index){
    if(m <= 0 || n <= 0){
        return;
    }
    int steps = dir%2 ? n:m;
    for(int i = 0; i < steps; i++){
        if(dir == 0){
            x++;
        }
        else if(dir == 1){
            y++;
        }
        else if(dir == 2){
            x--;
        }
        else if(dir == 3){
            y--;
        }
        mat[y][x] = arr[index];
        index++;
    }
    dir = (dir + 1)%4;
    dir%2 ? n-- : m--;
    spiral_recursive(n, m, m_1, arr, mat, x, y, dir, index);
}

void spiral(int n_1, int m_1, int arr[], int mat[][m_1]){
int m = m_1;
int n = n_1;
int x = -1;
int y = 0;
int index = 0;
int dir = 0;

spiral_recursive(n, m, m_1, arr, mat, x, y, dir, index);
}

int main(){
int n;
int m;
printf("Input number of rows in 2D array: ");
scanf("%d", &n);
printf("Input number of columns in 2D array: ");
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
flatten(n, m, arr, mat);
quicksort(arr, n*m);
spiral(n, m, arr, mat);
printf("\n---------------------\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}
