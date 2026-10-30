#include<stdio.h>
int main(){
    char modnum;
    float volt;
    float current;
    float temp;
    float power;
    printf("Enter Model Number:");
    scanf("%s",&modnum); 
    printf("Enter Voltage:");
    scanf("%f",&volt);
    printf("Enter Current:\n");
    scanf("%f",&current);
    printf("Enter Temperature:\n");
    scanf("%f",&temp);
     power=volt*current;
    printf("Power is:%.2f\n",power);
    return 0;
}
