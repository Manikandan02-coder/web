#include<stdio.h>
int Algebra(int a){
    // int result1 = (a*5)+(a*5);
    int result2 = 2*(a*5);

    return result2;
}
int main(){
    int a;
    printf("algebric reductiom\n");
    
    printf("Enter the value:");
    scanf("%d",&a);
    int result = Algebra(a);
    printf("result:%d",result);
}