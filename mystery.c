#include "mystery.h"

int num[200];

int add (int a, int b){
  return a + b;
}
int dothething(int n){
  if (n == 1 || n == 2){
    return 1;
}else{
    return add(dothething(n-1), dothething(n-2));
}
}
int main(int argc,char** argv){
int tmp = atoi(argv[1]);
int result;
if(tmp==0){
result=0;
}else if(tmp<0){
printf("Invalid input\n");
return 0;
}else{
result = dothething(tmp);
}
printf("value = %d\n",result);
return 0;
}
