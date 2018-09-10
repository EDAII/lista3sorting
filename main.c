#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"
#include "helper.h"
#include "sort.h"


int main(void) {
  int size;
  int *vector;
  clock_t begin, end;
  double time_spent;

  printf("Digite o tamanho do vetor: ");
  do{
    scanf("%d", &size);
    if (size <= 0)
      printf("Digite um valor válido.\n");
  }while(size <= 0);
  
  vector = createVector(size, 100);

  printf("Vetor original: ");
  printVector(vector, size);

  selectionSort(vector, size);
  insertionSort(vector, size);
  bubbleSort(vector, size);
  shellSort(vector, size);  
  begin = clock();
  quickSort(vector, 0, size -1);
  end = clock();
  time_spent = (double)(end - begin);
  printf("Tempo de ordenação do quick sort: %fs\n", time_spent / CLOCKS_PER_SEC);

  bucketSort(vector, size);
  destroyVector(vector);
  return 0;
}
