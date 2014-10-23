#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Node{
  int left;
  int right;
  int parent;
  int index;
  int weight;
  char value;
  Node(){
  left = right = parent = weight =  index = -1;
   }
  bool operator > (const Node &A) const{
   return weight > A.weight;
  }
};
priority_queue<Node, vector<Node> , greater<Node> >  Q ;
Node * allNode;
int buildHuffman();
void printHuffmanCode(int n);
void decodeHuffman(string code,int root);

int main(){



  //  8 a 1 b 1 c 2 d 3 e 5 f 8 g 13 h 21
  int n  = buildHuffman();
  printHuffmanCode(n);
  cout<<"Please input Huffman code:"<<endl;
  string code;

  while(true){
    cin>>code;
    decodeHuffman(code,2*n-1);cout<<endl;
  }

  // free space
  if (allNode != 0) delete []allNode;

}
int buildHuffman(){
  cout<<"Please input N and correspoing characters and theri frequency:"<<endl;
  int n,space;
  cin>>n;
  space = n+1;
  allNode = new Node[2*n];
  int we;
  char c;
  while(Q.empty()== 0) Q.pop();
  for(int i =0; i< n;i++){
     cin>>c>>we;
     allNode[i].value = c;
     allNode[i].weight = we;
     allNode[i].index = i;
     Q.push(allNode[i]);
  }
  Node tL,tR;
  while(Q.size()>=2){
    tL = Q.top(); Q.pop();
    tR = Q.top(); Q.pop();
    allNode[space].left = tL.index;
    allNode[space].right = tR.index;
    allNode[space].index = space;
    allNode[space].value = 0;
     allNode[tL.index].parent = allNode[tR.index].parent = space;
    //cout<<tL.parent<<endl;
    tL.parent = tR.parent = space;
    allNode[space].weight = tR.weight + tL.weight;
    Q.push(allNode[space]);
    space++;
  }
  return n;
}
// Êä³öHuffman ±àÂë
void printHuffmanCode(int n){
  char code[2*n+5];
  int j,m;
  Node temp;
  Node tParent;
  char a;
  for(int i =0;i< n;i++){
    j = 0;
    temp = allNode[i];
    a = temp.value;
    while(temp.parent != -1){
      tParent = allNode[temp.parent];
      if(tParent.left == temp.index)code[j]='0';
      else code[j]='1';
      j++;
      temp = tParent ;
    }
    cout<< a <<"\t";
    for( int k = j-1;k >=0; k--) cout<<code[k];
    cout<<endl;
  }
}
void decodeHuffman(string code, int root){
  string::size_type  s = code.size();
  int left,right;
  int tRoot = root;
  for( int i = 0; i<s;i++){
    if(code[i] == '0'){
       left  = allNode[tRoot].left;
       if(left == -1) {
         cout<<allNode[tRoot].value<<" ";
         tRoot = root;
       }else{
         if(allNode[left].left == -1) {
           cout<<allNode[left].value<<" ";
           tRoot = root;
         }else tRoot = left;

       }

    }else{ // 1
      if( code[i]!='1'){
        cout<<"Huffman code must contain only 0 or 1"<<endl; return;
      }
      right = tRoot = allNode[tRoot].right;
      if(right == -1 ){
        cout<<allNode[tRoot].value<<" ";
        tRoot = root ;
      }
      else{
        if(allNode[right].left == -1){
           cout<<allNode[right].value<<" ";
          tRoot = root;
        } else tRoot = right;
      }
    }
  }

}

