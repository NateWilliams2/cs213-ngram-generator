#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

// Main body of the program. Prints all ngrams of size N from user input.
void generate_ngrams(int N){
  // Dynamically allocated buffer to hold N-sized stream of chars
  char* buff = calloc(N+1, sizeof(char));
  char* get_success;
  char newVal[2];

  // Get initial input
  for(int i=0; i<N; i++){
    get_success = fgets(newVal, 2, stdin);
    rotate_and_add(buff, newVal[0], N);
  }
  // If Nth call to fgets returned NULL, then input string < N so we should exit and print nothing.
  if(get_success == NULL){
    free(buff);
    return;
  }

  // If input is received, proceed through next iteration of loop
  while (get_success != NULL) {
    printf("%s\n", buff);
    // Get next character, read it into the buffer stream
    get_success = fgets(newVal, 2, stdin);
    rotate_and_add(buff, newVal[0], N);
  }
  free(buff);
}

/* rotates buff so that the next character can stream in and all characters are shifted one to the left.
  N should be the size of buff. The first character is erased.*/
void rotate_and_add(char* buff, char newVal, int N){
  for(int i=0; i<N; i++){
    buff[i] = buff[i+1];
  }
  buff[N-1] = newVal;
}
