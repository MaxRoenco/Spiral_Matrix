
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print( int n, int m, int arr[][m]){
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d \t", arr[i][j]);
        }
    printf("\n ");
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void valley(int n, int m, int arr[][m]){
int sum_valley = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((j == 0 || arr[i][j] < arr[i][j - 1]) && (j == m -1 || arr[i][j] < arr[i][j + 1]) && (i == 0 || arr[i][j] < arr[i - 1][j]) && (i == n -1 || arr[i][j] < arr[i + 1][j])){
                printf("\t%d %d", i, j);
                sum_valley++;
            }
        }
    }
printf("\nAmount of valleys: %d\n", sum_valley);
}


void mountain(int n, int m, int arr[][m]){
int sum_mountain = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((j == 0 || arr[i][j] > arr[i][j - 1]) && (j == m -1 || arr[i][j] > arr[i][j + 1]) && (i == 0 || arr[i][j] > arr[i - 1][j]) && (i == n -1 || arr[i][j] > arr[i + 1][j])){
                printf("\t%d %d", i, j);
                sum_mountain++;
            }
        }
    }
printf("\nAmount of mountains: %d\n", sum_mountain);
}

int main(){
int n;
int m;
printf("Input number of rows in 2D array: ");
scanf("%d", &n);
printf("Input number of columns in array: ");
scanf("%d", &m);
int arr[n][m];
srand(time(NULL));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = rand()%2000 - 1000;
        }
    }
print(n, m, arr);
valley(n, m, arr);
mountain(n, m, arr);
}
