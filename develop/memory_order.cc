#include<iostream>
#include<atomic>
#include<thread>
#include<unistd.h>
#include <vector>
#include <atomic>
#include <iostream>
#include<chrono>

#include<assert.h>

std::atomic<bool> x, y;
std::atomic<int> z;
void write_x(){
    x.store(true, std::memory_order_seq_cst);
}

void write_y(){
    y.store(true, std::memory_order_seq_cst);
}

void read_x_then_y(){
    while(!x.load(std::memory_order_seq_cst));
    if(y.load(std::memory_order_seq_cst))
        z++;
}

void read_y_then_x(){
    while(!y.load(std::memory_order_seq_cst));
    if(x.load(std::memory_order_seq_cst))
        z++;
}




std::vector<int> data;
std::atomic<bool> data_ready(false);

void reader_thread()
{
  while(!data_ready.load())  // 1
  {
    //std::cout<<"sleep"<<"\n";
    //std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
  std::cout<<"The answer="<<data[0]<<"\n";  // 2
}
void writer_thread()
{
  data.push_back(42);  // 3
  //data_ready=true;  // 4
}

int main(int agrc, char** argv){
    // x = false;
    // y = false;
    // z = 0;
    // std::thread a(write_x);
    // std::thread b(write_y);
    // std::thread c(read_x_then_y);
    // std::thread d(read_y_then_x);
    // a.join();
    // b.join();
    // c.join();
    // c.join();
    // assert(z.load() != 0);
    std::thread a(reader_thread);
    std::thread b(writer_thread);
    a.join();
    b.join();
}