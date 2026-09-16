#define _POSIX_C_SOURCE_200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;
  char *token;
  char *saveptr;

  printf("Please enter some text: ");

  nread = getline(&line, &len, stdin);
  if (nread == -1) {
    perror("getline failed");
    exit(1);
  }

  token = strtok_r(line, " ", &saveptr);
  printf("\nTokens:\n");
  while (token != NULL) {
    printf("  %s\n", token);
    token = strtok_r(NULL, " ", &saveptr);
  }

  free(line);

  return 0;
}
