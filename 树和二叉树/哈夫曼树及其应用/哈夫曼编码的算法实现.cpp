#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char **HuffmanCode; //哈夫曼编码表的存储表示

//哈夫曼编码左孩子为0，右孩子为1
void CreateHuffmanCode(HuffmanTree HT,HuffmanCode *HC,int n){ //n个叶子结点
  //从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
  if (n <= 1) return;
  int c; //用于记录从叶子结点向上回溯至根结点所经过的结点下标
  int f; //用于指向父结点
  int start;  //start用于记录编码在cd中存放的位置
  *HC = (char**)malloc(sizeof(char*) * (n+1)); //分配存储n个字符编码的编码表空间（从1号下标开始用，所以分配了n+1个）
  char *cd = (char*)malloc(sizeof(char) * n); //分配临时存放每个字符编码的动态数组空间(用一串编码来表示一个字符，编码的长度不会超过字符的个数n)
  cd[n - 1] = '\0';
  for(int i = 1; i <= n; i++){  //遍历所有叶子结点
    start = n - 1;  ///start开始指向最后，即编码结束符的位置
    c = i; //保存当前回溯结点i下标
    f = HT[c].parent; //指向当前回溯结点i的父结点下标
    
    while(f != 0){ //从叶子结点向上回溯，直到根结点（我们在构造哈夫曼树时初始化下标都为0，构造完后如果下标还是为0说明它是根结点）
      start--;  //回溯一次start向前指向一个位置
      if(HT[f].lchild == c){
        cd[start] = '0'; //为父结点的左孩子，赋0
      }
      else {
        cd[start] = '1'; //为父结点的右孩子，赋1
      }
      c = f;
      f = HT[c].parent; //继续向上回溯
    }
    (*HC)[i] = (char*)malloc(n - start); //为第i个字符编码分配空间
    strcpy((*HC)[i],*cd[start]); 
  }
  free(cd);  //释放空间
}
/*
 **测试示例**
假设哈夫曼树结构：
下标 weight parent lchild rchild
1    5      4       0       0
2    3      4       0       0
3    2      5       0       0
4    8      5       1       2
5   10      0       4       3

调用 `CreateHuffmanCode(HT, &HC, 3)` 后：
- HC[1] = "0"
- HC[2] = "11"
- HC[3] = "10"

**注意事项**
- 调用前需确保哈夫曼树已正确构建
- 使用后需要遍历释放每个编码字符串：
for(int i=1; i<=n; i++) free(HC[i]);
free(HC);
*/
