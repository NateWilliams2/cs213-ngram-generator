#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT_STRING 10

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

  get_success = fgets()
  // TODO: read from standard input and print out ngrams until we reach the end of the input

  return 0;
}
