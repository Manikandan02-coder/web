#include<stdio.h>

int Strength(int a)
{
// int result1 = a* 8;
int result2 = a << 3;


return result2 ;
}
int main(){
int a;
 printf("Strength Reduction ");
printf("Enter A:");
scanf("%d" , &a);

int result1 = Strength(a);
printf("result: %d" , result1);
}
