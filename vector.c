#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "helper.h"

int* createVector(int size, int range) {
  int *vector;
  int index;

  vector = (int * ) malloc (sizeof(int) * (size+1));
  srand((unsigned)time(NULL));

  for (index = 0; index < size; index++) {
    vector[index] = create_random(range);
  }
  
  vector[index] = -1; 
  return vector;
}

void destroyVector(int* vector){
  if (vector != NULL)
    free(vector);
}

void printVector(int *vector, int size) {
  printf("\n\n==================\n");
  for (int index = 0; index < size; index++)
    printf("%d: %d\n", index + 1, vector[index]);
  printf("==================\n\n");
}
