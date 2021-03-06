//Question 3 (15 pts): C Functions using Pointers
//The following questions ask you to debug or write a function.
//Submit your source code but you do not have to compile and execute the program.

//a. [5] Write the following function:
//void split_date(int day_of_year, int year, int *month, int *day);
//day_of_year is an integer between 1 and 366, specifying a particular day within the year
//designated by the parameter year. month and day point to variables in which the function will store
//the equivalent month (1 � 12) and day within the month (1 � 31)
#include <stdio.h>
#include <stdlib.h>

int doy, yr, mon, dom;
int i;
int currentmonth;

int calendars[2][12] = { //Didn't know how to create structs before. Found calendar struct on http://www.learntosolveit.com/cprogramming/Ex_5.8_day_date.html
    {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31},
};

void split_date(int day_of_year, int year, int *month, int *day){
//Determine Leap Year Days in February -> Routed to array of two types of years rather than hardcode all months in loops
    if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0)){ //Algorithm referenced from https://bit.ly/33LCK0O
        printf("%d leap year\n", year);
        i = 1;
    }
        else{
        printf("%d not leap year\n", year);
        i = 0;
    }
    currentmonth=1;
    while(day_of_year > calendars[i][currentmonth]){
        day_of_year = day_of_year - calendars[i][currentmonth];
        currentmonth++;
    }
    printf("The month is %d. The day is %d\n",currentmonth,day_of_year);

    //Reference values to the pointed locations
    *month = currentmonth;
    *day = day_of_year;
    //Pointer Proof Check
    printf("%d\n",*month);
    printf("%d\n",*day);
}





//b. [5] Write the following function:
int *find_largest(int a[], int n){
    int largest;
    int i;

    largest = 0;

    for (i=0;i<n;i++){//Print array for precheck transfer
        printf("Array %d is %d. Address is:%d\n",n,a[i], &a[i]);
    }


    for (i=0;i<n;i++){
        printf("loop %d\n",i);
        printf("largest is %d\n",largest);
        printf("a[%d] is %d\n", i,a[i]);
        if (largest < a[i]){// If current value is larger than next, keep first value, else replace with next
            largest = a[i];// Slightly off in using address for comparison but allows less to initialize so I'm okay with it
        }
    }
    printf("Largest value is: %d\n",largest);

    for (i=0;i<n;i++){
        if (largest == a[i]){
            largest = (int)&a[i];//Correct return value
            printf("a[i] here1 is a[%d]\n", &(a[i]));
        }
    }
    printf("Pointer location of array is: %d\n",largest);
    printf("Largest value is: %d\n",largest);
    return (int *)largest;
}
//When passed an array a of length n, the function returns a pointer to array�s largest element.




//c. [5] Having to check the return value of malloc() (or any other memory allocation function) each
//time we call it can become annoying and monotonous.
//Write a function called my_malloc(int n_bytes) that servers as a �wrapper� for malloc().
//When we call my_malloc() and ask it to allocate n_bytes, my_alloc() calls malloc(), ...
//tests to make sure that malloc() doesn�t return a null pointer and then returns the pointer from malloc().
//Have my_malloc() print an error message and terminate the program if malloc() returns a null pointer.
int my_malloc(int n_bytes){
int *basepoint;

basepoint = (int*)malloc(n_bytes*sizeof (int));
//Check if bad and exit
if(basepoint == NULL){
    printf("Failed to allocate to not a null pointer\n");
    exit(0);
}
else{
    printf("Good job allocating to %d\n",basepoint);
}
return *basepoint;
}




//###############################################################
int main(){

//Problem 3 - a
printf("Start of Problem 1-a\n");
doy = 365;
yr = 2018;
split_date(doy,yr,&mon,&dom);
printf("End of problem 1-a\n\n\n");

//Problem 3 - b
printf("Start of problem 3-b\n");
int arraycheck[4] = {5,13,6,12};

int *retur;
retur = find_largest(arraycheck, 4);
printf("Value: %d, Addr:%d , point: %d\n", *retur, &retur, retur);
printf("End of problem 3-b\n\n");

//Problem 3 - c
printf("Start of problem 3-c\n");
my_malloc(4);
printf("End of problem 3-c\n");
}
//###############################################################
