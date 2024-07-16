#include <stdio.h> 
int main(void){

  printf("N\t10*N\t100*N\t1000*N\n\n");  
  for (int i=1;i<=10;i++)
    printf("%d %d %d %d\n",i,10*i,100*i,1000*i);

  return(0);
}