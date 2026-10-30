#include<stdio.h>
int main(){
  int senval;
  printf("Enter Sensor Value:");
  scanf("%d",&senval);
  if((0<=senval)&(senval<=19)){
    printf("LOW:%d",senval);
  }
 else if((20<=senval)&(senval<=69)){
    printf("NORMAL:%d",senval);
  }
  else if((70<=senval)&(senval<=89)){
    printf("HIGH:%d",senval);
  }
  else if((90<=senval)&(senval<=100)){
    printf("CRITICAL:%d",senval);
  }
  else{
    printf("ERROR");
  }
  return 0;
}
