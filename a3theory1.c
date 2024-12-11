#include<stdio.h>
#include<string.h>
typedef struct employee{
   int employCode;
   char employName[30];
   int dateOfJoining;
   int monthOfJoining;
   int yearOfJoining;
}employees;
int main(){
    employees arr[4];
    int i=0;
    for(i=0;i<4;i++){
        printf("---------Enter the details of employee %d---------\n",i+1);
        printf("Enter the code of employee %d\n",i+1);
        scanf("%d",&arr[i].employCode);
        printf("Enter the name of employee %d\n",i+1);
        scanf("%s",&arr[i].employName);
        printf("Enter the joining date of employee %d\n",i+1);
        scanf("%d",&arr[i].dateOfJoining);
        printf("Enter the joining month of employee %d\n",i+1);
        scanf("%d",&arr[i].monthOfJoining);
        printf("Enter the joining year of employee %d\n",i+1);
        scanf("%d",&arr[i].yearOfJoining);
    }
    int currdate,currmonth,curryear;
    printf("Enter the current date, month, and year!\n");
    scanf("%d %d %d",&currdate,&currmonth,&curryear);
    int year=0,month=0,count=0;
    for (i=0;i<4;i++){
    year=curryear-arr[i].yearOfJoining;
     if(currmonth<arr[i].monthOfJoining){
        year--;
    }
    if(currmonth==arr[i].monthOfJoining && currdate<arr[i].dateOfJoining){
    year--;
    }
    if (year>=3){
    printf("-----Detail of person %d whose tenure is greater or equal to 3 years-----\n",i+1);
    printf("The code of employee is %d\n",arr[i].employCode);
    printf("Name of employee is %s\n",arr[i].employName);
    printf("The tenure of given employ is %d years \n",year);
    count++;
    }
    }
 printf("%d person(s) having tenure greater or equal to three years! \n",count);
 return 0;
}
