#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_ngrams(int N);
void rotate_and_add(char* buff, char newVal, int N);

int main(int argc, char** argv) {
  // Make sure the program is run with an N parameter
  if(argc != 2) {
    fprintf(stderr, "Usage: %s N (N must be >= 1)\n", argv[0]);
    exit(1);
  }

  // Convert the N parameter to an integer
  int N = atoi(argv[1]);

  // Make sure N is >= 1
  if(N < 1) {
    fprintf(stderr, "Invalid N value %d\n", N);
    exit(1);
  }

  // Main body of the program
  generate_ngrams(N);

  return 0;
}

void generate_ngrams(int n){
  // Dynamically allocated buffer to hold N-sized stream of chars
  char* buff = malloc(sizeof(char) * N+1);
  char* newVal[2];
  // Get initial input
  char* get_success = fgets(newVal, 1, stdin);
  // If input is received, proceed through next iteration of loop
  while (get_success != NULL) {
    rotate_and_add(buff, newVal[0], N);
    printf("\s", buff);
    get_success = fgets(newVal, 1, stdin);
  }
}

void rotate_and_add(char* buff, char newval, int N){
  for(int i=0; i<N-1; i++){
    buff[i] = buff[i+1];
  }
  buff[N-1] = newVal;
}
