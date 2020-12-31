#include<bits/stdc++.h>
#include <iostream>             // std::cout
#include <future>               // std::async, std::future
#include <chrono>   
using namespace std;

#define TASK_POOL_ELEMS 1000
 
struct task_ptr {
  int state;
  void *ptr;
};

typedef struct task_ptr TaskAlign;


struct task_env {
  
  TaskAlign *where;     /* High water mark in heap */
  TaskAlign *stack_top; /* The stack top */
  TaskAlign *sp;        /* The current stack pointer */
  TaskAlign buf[TASK_POOL_ELEMS]; /* Heap and stack */
};

typedef struct task_env task_env;

typedef unsigned char uchar;


uint64_t uint8korr(const char *A) {
  uint64_t ret;
  memcpy(&ret, A, sizeof(ret));
  return ret;
}

void uint8korrTest(){
  uint64_t n = uint8korr("aaaaaaaa-aaaa-aaaa-aaaa-aaaaaaaaaaaa:1-118");
  cout<<n<<endl;
}


// void gtidTest(){
//   auto packet = new Data_packet(data, len);
//   uchar *payload = packet->payload;
//   Sid_map sid_map(nullptr);
//   Gtid_set executed_set(&sid_map, nullptr);
//   if (member_set.add_gtid_encoding(payload, packet->len) !=
//         RETURN_STATUS_OK) {
//       LogPluginErr(ERROR_LEVEL,
//                    ER_GRP_RPL_CANT_READ_GTID); /* purecov: inspected */
//       error = 1;                               /* purecov: inspected */
//     }
// }

void gtidTest(){
  //pppp:1-2,3-4
  //pppp:1
  //pppp:1-45;
  //pppp:
  vector<string> str1{"pppp:1-3:4:5-10,pppa:2:4"};
  vector<string> str2{"pppp:"};
  //cout<<"str1:"<<str1<<endl;
  //string str2
  //size_t pos_of_colon = str1.find_first_of(':');
  //cout<<str1.find_first_of(':')<<endl;
  //int res = 0;
  //string temp;

  cout<<"str[0]: "<<str1[0]<<endl;
  string group_name("pppa");
  cout<<"pos: "<<str1[0].find(group_name.c_str())<<endl;
  
  auto Split = [](const std::string &str, std::string sep) -> std::map<std::string, std::string>{
    std::map<std::string, std::string> ret;
    if (str.empty()) {
        return ret;
    }
    
    std::string temp;
    std::string::size_type begin = str.find_first_not_of(sep);
    std::string::size_type pos = 0;

    while (begin != std::string::npos) {
        pos = str.find(sep, begin);
        if (pos != std::string::npos) {
            temp = str.substr(begin, pos - begin);
            begin = pos + sep.length();
        } else {
            temp = str.substr(begin);
            begin = pos;
        }

        if (!temp.empty()) {
            ret[temp.substr(0,temp.find(":"))] = temp.substr(temp.rfind(":")+1);
            temp.clear();
        }
    }
    return ret;
  };

  //map<std::string, std::string> res;

  map<std::string, std::string> res = Split(str1[0],",");
  for(auto re: res){
    cout<<"after split:"<<re.first<<":"<<re.second<<endl;
  }

  cout<<"ooooo:"<<res["fsfs"]<<endl;


  for(int i = 0 ;i < str1.size(); i++){
    int re;
    auto f = [&re](string str1, string str2){
      int i1 = str1.size() - 1;
      int i2 = str2.size() - 1;
      for(; isdigit(str1[i1]); i1--);
      for(; isdigit(str2[i2]); i2--);
      int n1 = i1 == str1.size() - 1 ? 0 : stoll(str1.substr(i1+1));
      int n2 = i2 == str2.size() - 1 ? 0 : stoll(str2.substr(i2+1));
      re =  n1 < n2;
      cout<<re<<endl;
    };
    f(str1[i],str2[i]);
    cout<<re<<endl;
  }
    //cout<<temp<<endl;

//   std::string a = "hello";
// for(int i = 0; i < 100; ++i)
// {
// 	a.insert(0, to_string(i));
// }
// cout<<a<<endl;

}

  

  void finanlGtidtest(){

    //string This = "pppa:1-2:3:10-16,pppb:1-4:5";
    string This = "";
    string Other = "pppa:1-2:3:10-15,pppb:1-4:5";
    string group_name("pppa");
    
    auto Split = [](const std::string &str, std::string sep) -> std::map<std::string, std::string>{
    std::map<std::string, std::string> ret;
    if (str.empty()) {
        return ret;
    }

    std::string temp;
    std::string::size_type begin = str.find_first_not_of(sep);
    std::string::size_type pos = 0;

    while (begin != std::string::npos) {
        pos = str.find(sep, begin);
        if (pos != std::string::npos) {
            temp = str.substr(begin, pos - begin);
            begin = pos + sep.length();
        } else {
            temp = str.substr(begin);
            begin = pos;
        }

        if (!temp.empty()) {
            ret[temp.substr(0,temp.find(":"))] = temp.substr(temp.rfind(":")+1);
            temp.clear();
        }
    }
    return ret;
  };

  std::string str = This;
  str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());  // erase '\n' in string executed_gtid_set
  map<std::string, std::string> gtidset_map_this = Split(str, ","); // split gitd_set with ","
  std::string gitdset_this = gtidset_map_this[group_name];          // gtidset in current group

  str = Other;
  str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
  map<std::string, std::string> gtidset_map_other = Split(str, ",");
  std::string gitdset_other = gtidset_map_other[group_name];


  long long int n1 = 0;
  long long int n2 = 0;

  // find the maximum gtid of this
  if(!gitdset_this.empty()){
    size_t this_max_gtid_i = gitdset_this.size() - 1;
    for(;isdigit(gitdset_this[this_max_gtid_i]);--this_max_gtid_i);
    n1 = (this_max_gtid_i == gitdset_this.size() - 1) ? 0 : stoll(gitdset_this.substr(this_max_gtid_i + 1));
  }

  // find the maximum gtid of other
  if(!gitdset_other.empty()){
    size_t other_max_gtid_i = gitdset_other.size() - 1;
    for(;isdigit(gitdset_other[other_max_gtid_i]);--other_max_gtid_i);
    n2 = (other_max_gtid_i == gitdset_other.size() - 1) ? 0 : stoll(gitdset_other.substr(other_max_gtid_i + 1));
  }

  // fisrt compare the maximum gitd, then member_weight, then uuid

  //if (n1 > n2) return true;

  cout<<"n1:"<<n1<<endl;
  cout<<"n2:"<<n2<<endl;
}

std::atomic<int> foo(0);

void set_foo(int x)
{
  foo = x;
}

void print_foo()
{
  while (foo == 0)
  {
    std::this_thread::yield(); // 只有在别的线程也需要cpu的时候当前线程才让出cpu
  }
  std::cout << "x: " << foo << std::endl;
}

bool is_primer(int x){
  for(int i = 2; i < x; i++){
    if(x % i == 0)
      return false;
  }
  return true;
}

void temp(){

  std::future<bool> fut = std::async(is_primer, 444444443);
  std::chrono::milliseconds span(100);
  while(fut.wait_for(span) == std::future_status::timeout){
    std::cout<<".";
  }
  bool x = fut.get();

  std::cout<<"\n44444443" << (x ? " is " : " is not ") <<" primer\n";

}

void refTest(){
  int a = 1;
  int& b = a;
  cout<<b<<endl;
}

int main(){

    // task_env *t = (task_env *)malloc(sizeof(task_env));
    // memset(t->buf, 0, 1000 * sizeof(TaskAlign));
    // t->where = t->buf;
    // t->stack_top = &t->buf[TASK_POOL_ELEMS - 1];
    // t->sp = t->stack_top;

    // printf("%d\n", t->buf);
    // printf("%d\n", *(t->stack_top));
    //uint8korrTest();
    //finanlGtidtest();
    //temp();
    refTest();

}