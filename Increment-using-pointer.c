#include<stdio.h>
int incre(int*a){
    *a+=10;
    return 0;
}
int main(){
    int a=5;
    int c;
    printf("Before Increment:%d",a);
    c=incre(&a);
    printf("After Increment:%d",a);
    return 0;
}