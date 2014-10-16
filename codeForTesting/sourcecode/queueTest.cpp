#include <iostream>
#include <queue>
using namespace std;

int main(){
  queue<int> q;
  q.push(3);
  cout<<q.size();   // ++ size 返回队列的大小
  cout<<q.front();  // ++ front 查看第一个元素
  q.pop();      // ++pop 弹出第一个元素，没有返回值
  cout<<q.size();


  return 0;
}
