#include <gtest/gtest.h>//注意斜杠方向，左斜杠有可能找不到头文件
int Foo(int a,int b)
{
   if(0 == a||0 == b)
   throw "don't do that";
   int c = a%b;
   if (0 == c)
  {
     return b;
  }
  return Foo(b,c);
}
 
TEST(FooTest,HandleNoneZeroInput)//名称随便
{
   EXPECT_EQ(2,Foo(4,10));
   EXPECT_EQ(6,Foo(30,18));
}
int main(int argc,char*argv[])
{
   testing::InitGoogleTest(&argc,argv);
   return RUN_ALL_TESTS();
}

// g++ gtesttest.cc -lgtest -lpthread