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

void min_diagonal(int n, int m, int arr[][m]){
int min = arr[0][m];
int min_n, min_m = 0;
    for(int i = 0, j = m - 1; i < n; i++, j--){
            if(arr[i][j] < min){
             swap(&arr[i][j], &min);
             min_n = i;
             min_m = j;
            }
    }
printf("Position: [%d %d] number: %d \n", min_n, min_m, min);
}

void sum(int n, int m, int arr[][m]){
int sum = 0;
int amount_of_numbers = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j += 2){
            if(arr[i][j] > 0){
                sum += arr[i][j];
                amount_of_numbers++;
            }
        }
    }
printf("\nAmount:%d ", amount_of_numbers);
printf("\nSum:%d \n", sum);
}

int main(){
int n;
int m;
int k;
start:
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
printf("\n1 - min_diagonal\n");
printf("2 - sum_positive_numbers\n");
scanf("%d", &k);
switch(k){
case 1:
    min_diagonal(n, m, arr);
    break;
case 2:
    sum(n, m, arr);
    break;
}
goto start;
}
