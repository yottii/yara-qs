#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#define ASIZE 255
void preQsBc(char *x, int m, int qsBc[]) {
  int i;
  for (i = 0; i < ASIZE; ++i)
    qsBc[i] = m + 1;
  for (i = 0; i < m; ++i)
    qsBc[x[i]] = m - i;
}
void QS(char *x, int m, char *y, int n) {
  int j, qsBc[ASIZE];
  preQsBc(x, m, qsBc);
  j = 0;
  while (j <= n - m) {
    if (memcmp(x, y + j, m) == 0)
    j += qsBc[y[j + m]];             
    OUTPUT(j);
  }
}

int main(void){
  char *a;
  int y;
  char *b;
  int yy;
  a="hogehogehoge1";
  b="hoge1";
  QS(a,13,b,5);
  return 0;
}

