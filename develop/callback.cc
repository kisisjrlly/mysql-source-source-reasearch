#include<stdio.h>

void printNum(int n);

typedef void (*func)(int n);
void showNum(int n, void (* ptr)(int n));

void printMessage1();

void printMessage2();

void printMessage3();

void showMessage(void (* ptr)());

int main(){
    func = printNum;
    func(10);
    showNum(111, printNum);
    showMessage(printMessage1);
    showMessage(printMessage2);
    showMessage(printMessage3);
}


void printNum(int n){
   printf("Test1 is called,the number is %d\n",n);
}

void showNum(int n, void (*ptr)(int n)){
    (* ptr)(n);
}

void printMessage1(){
   printf("This is the message 1!\n");
}
 
void printMessage2(){
   printf("This is the message 2!\n");
}
 
void printMessage3(){
   printf("This is the message 3!\n");
}

void showMessage(void (* ptr)()){
    (* ptr)();
}