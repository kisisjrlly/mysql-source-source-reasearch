#include <stdio.h>

#define TASK_BEGIN static int state = 0; switch (state) { case 0:
#define TASK_YIELD(x) do { state = __LINE__; return x; case __LINE__:; } while (0)
#define TASK_END }


void f1(){
    static int state = 0;
    switch (state)
    { case 0:
        puts("1");
        puts("2");
        do{ 
            state = __LINE__;
            return;
    case __LINE__:;
            } while (0);
        puts("3");
    };
}

void f1() {
    TASK_BEGIN;
    puts("1");
    puts("2");
    TASK_YIELD();
    puts("3");
    TASK_END;
}

void f2() {
    TASK_BEGIN;
    puts("x");
    TASK_YIELD();
    puts("y");
    puts("z");
    TASK_END;
}

int main (void) {
    f1();
    f2();
    f1();
    f2();
    return 0;
} 