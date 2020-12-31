#include<bits/stdc++.h>

using namespace std;

#define BIT(n) (1L << n)

enum xcom_dbg_type {
  D_NONE = 0,
  D_TASK = BIT(0),
  D_BASE = BIT(1),
  D_FSM = BIT(2),
  D_TRANSPORT = BIT(3),
  D_PROPOSE = BIT(4),
  D_DISPATCH = BIT(5),
  D_SEMA = BIT(6),
  D_XDR = BIT(7),
  D_STORE = BIT(8),
  D_EXEC = BIT(9),
  D_DETECT = BIT(10),
  D_ALLOC = BIT(11),
  D_FILEOP = BIT(12),
  D_CACHE = BIT(13),
  D_CONS = BIT(14),
  D_BUG = ~0L
};
typedef enum xcom_dbg_type xcom_dbg_type;

long xcom_debug_mask =
     D_DETECT |  D_FSM  | D_FILEOP | D_CONS | D_BASE  | D_TRANSPORT;

int do_dbg(xcom_dbg_type x) { return (x & xcom_debug_mask) != 0; }

int main(){

    lable:
        printf("1111\n");

    cout<<do_dbg(D_FSM)<<endl;
    //goto lable;
}