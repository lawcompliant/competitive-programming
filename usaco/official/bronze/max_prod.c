#include <stdio.h>

int main() {
  int N, Q, i;
  scanf("%d %d", &N, &Q);
  
  int c[N], t[N];
  for(i=0; i<N; i++) {
    scanf("%d", &c[i]);
  }
  for(i=0; i<N; i++) {  
    scanf("%d", &t[i]);
  }

  for(i=0; i<Q; i++) {
    int V, S;
    scanf("%d %d", &V, &S);
    
    int count = 0;
    for(int j=0; j<N; j++) {
      if(t[j] + S < c[j]) {
        count++;
      }
    }
    
    if(count >= V) {
      printf("YES\n");
    } else {
      printf("NO\n"); 
    }
  }
  
  return 0;
}
