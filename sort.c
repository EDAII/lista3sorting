#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"

void swap(int* firstValue, int* secondValue) {
  int aux = *firstValue;
  *firstValue = *secondValue;
  *secondValue = aux;
}


/* Bubble sort */
void bubbleSort(int* vector, int size) {
  int temp[size];
  int i, j;
  clock_t begin, end;
  double time_spent;


  for(i = 0; i < size; i++){
    temp[i] = vector[i];
  }

  begin = clock();
  for(i = 0; i < size; i++){
    for(j = 0; j < size-i; j++){
      if(temp[j] > temp[j+1])
        swap(&temp[j], &temp[j+1]);
    }
  }
  end = clock();
  time_spent = (double)(end - begin); 
  printf("Tempo de ordenação do bubble sort: %fs\n", time_spent / CLOCKS_PER_SEC);
}


/* Insertion Sort */
void insertionSort(int* vector, int size) {
  int temp[size];
  int i, j, aux;
  clock_t begin, end;
  double time_spent;

  for(i = 0; i < size; i++){
    temp[i] = vector[i];
  }

  begin = clock();
  for (i = 1; i < size; i++) {
    aux = temp[i];
    j = i - 1; /* antecessor */
 
    /* Swaping values with sucessor */
    while (j >= 0 && temp[j] > aux) {
      temp[j + 1] = temp[j];
      j = j - 1;
    }

    temp[j + 1] = aux;
  }
  end = clock();
  time_spent = (double)(end - begin); 
  printf("Tempo de ordenação do insertion sort: %fs\n", time_spent / CLOCKS_PER_SEC);
}

/* Selection Sort */
void selectionSort(int* vector, int size) {
  int temp[size];
  int i, j;
  clock_t begin, end;
  double time_spent;


  for(i = 0; i < size; i++){
    temp[i] = vector[i];
  }

  begin = clock();
  for (i = 0; i < size - 1; i++) {
    int minIndex = i;
    for (j = i + 1; j < size; j++)
      if (temp[j] < temp[minIndex])
        minIndex = j;
 
    swap(&temp[minIndex], &temp[i]);
  }
  end = clock();
  time_spent = (double)(end - begin); 
  printf("Tempo de ordenação do selection sort: %fs\n", time_spent / CLOCKS_PER_SEC);
}


/* Shell sort */
void shellSort(int *vector, int size){
  int temp[size];
  int i, j, h;
  int aux;
  clock_t begin, end;
  double time_spent;

  for(i = 0; i < size; i++){
    temp[i] = vector[i];
  }

  begin = clock();

  for(h = 1; h < size; h = 3*h + 1);

  while(h > 0){
    h = (h-1)/3;
    for(i = h; i < size; i++){
      aux = temp[i];
      j = i;
      while(temp[j - h] > aux){
        temp[j] = temp[j - h];
        j-= h;
        if(j < h){
          break;
        }
      }
      temp[j] = aux;
    }
  }
  end = clock();
  time_spent = (double)(end - begin); 
  printf("Tempo de ordenação do shell sort: %fs\n", time_spent / CLOCKS_PER_SEC);
}

/* Quick Sort */
void quickSort(int *vector, int begin, int last) {
   int i, j, middle, aux;
   i = begin;
   j = last;
   middle = vector[(begin + last) / 2];

   do {
      while(vector[i] < middle)
         i++;
      while(vector[j] > middle)
         j--;
      
      if(i <= j) {
         aux = vector[i];
         vector[i] = vector[j];
         vector[j] = aux;
         i++;
         j--;
      }
   } while(i <= j);

   if(begin < j)
      quickSort(vector, begin, j);
   if(i < last)
      quickSort(vector, i, last);
}


void bucketSort(int* vector, int size) {  
    int i, j;
    int count[size];
    int temp[size];
    clock_t begin, end;
    double time_spent;

    for(i = 0; i < size; i++){
      temp[i] = vector[i];
    }

    begin = clock();
    
    for (i = 0; i < size; i++)
        count[i] = 0;
 
    for (i = 0; i < size; i++)
        (count[temp[i]])++;
 
    for (i = 0, j = 0; i < size; i++)
        for(; count[i] > 0; (count[i])--)
            temp[j++] = i;

    end = clock();

    time_spent = (double)(end - begin); 
    printf("Tempo de ordenação do bucket sort: %fs\n", time_spent / CLOCKS_PER_SEC);
}
