#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "factor.h"

char** factor_1_svc(int* n, struct svc_req* req) {
  static char* result;
  static char buffer[1024];

  int num = *n;
  int i = 2;
  char temp[32];
  double limit = sqrt(num);

  buffer[0] = '\0';

  while (num % i == 0) {
    sprintf(temp, "%d ", i);
    strcat(buffer, temp);
    num /= i;
  }

  for (i = 3; i <= limit; i += 2) {
    while (num % i == 0) {
      sprintf(temp, "%d ", i);
      strcat(buffer, temp);
      num /= i;
    }
  }

  if (num > 2) {
    sprintf(temp, "%d", i);
    strcat(buffer, temp);
  }

  result = buffer;
  return &result;
}