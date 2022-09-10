#include<stdio.h>
#include <stdlib.h>

int main(){
  int op;
  double a,b;
  while(1){
    printf("Enter the number of the operation \n1. Addition(+)\n2. Subtraction(-)\n3. Multiplication(*)\n4.Division(/)\nIf you want to exit press 0\n");
    scanf("%d", &op);
    if (op == 0)
    {
        exit(0);
    }
    printf("Enter the first and second numbers\n");
    scanf("%lf %lf",&a,&b);
    switch (op)
    {
    case 1:
        printf("%.1lf + %.1lf = %.1lf\n", a, b, a + b);
        break;

    case 2:
        printf("%.1lf - %.1lf = %.1lf\n", a, b, a - b);
        break;
    }
  }
  return 0;
}
