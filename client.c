#include <stdio.h>
#include <stdlib.h>

#include "factor.h"
// hi
int main(int argc, char* argv[]) {
  CLIENT* clnt;
  char* server;
  int num;
  char** result;

  if (argc != 3) {
    printf("Usage: %s <server_host> <number>\n", argv[0]);
    exit(1);
  }

  server = argv[1];
  num = atoi(argv[2]);

  clnt = clnt_create(server, FACTOR_PROG, FACTOR_VERS, "udp");
  if (clnt == NULL) {
    clnt_pcreateerror(server);
    exit(1);
  }

  result = factor_1(&num, clnt);
  if (result == NULL) {
    clnt_perror(clnt, "Call failed");
    exit(1);
  }

  printf("Prime factors: %s\n", *result);

  clnt_destroy(clnt);
  return 0;
}
