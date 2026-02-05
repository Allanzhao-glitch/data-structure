#include <stdio.h>


#if 0
int main() {
    int a = -1,b =1;
    if(0<a<2 || b++ !=1)
    {
        printf("%d,%d\n",a,b);
    }
    else
    {
        printf("%d,%d\n",b,a);
    }
    return 0;
}


#-1,1





int main() {
    int arr[] = {12,13,14,15,16};
    printf("%d,%d,%d",sizeof(arr),sizeof(*arr),sizeof(arr[0]));
    return 0;
}


#20,4,4





#include <stdio.h>
#include <stdarg.h>
void varfun(int n,...);
int main()
{
    varfun(3,7,-11.2,0.66);
    return 0;
}

void varfun(int n,...)
{
    va_list *ptr;
    int num;
    va_start(ptr,n);
    num = va_arg(ptr,int);
    printf("%d\n",num);
}

#ptr必须是va_list类型




int main()
{
    FILE *fp;
    int k,a[6] = {4,5,6,3,2,1},b[6];
    // 写入阶段
    fp = fopen("d.dat","wb");
    for(k=0;k<6;k++)
        fwrite(&a[5-k],sizeof(int),1,fp);
    fclose(fp);  // 关闭文件，确保数据写入磁盘
    
    // 读取阶段
    fp = fopen("d.dat","rb");  // 以二进制读模式重新打开
    fseek(fp,sizeof(int)*2,SEEK_SET);  // 从文件开头偏移
    fread(b,sizeof(int),4,fp);
    fclose(fp);
    
    // 输出结果
    for (k=0;k<4;k++)
        printf("%d ",b[k]);
    return 0;
}

# 3 6 5 4





#define MAX 128 
int main()
{
    const int max = 128;
    char array[max];
    char string[MAX];
    array[0] = string[0] = 'A';
    printf("%c %c\n",array[0],string[0]);
    return 0;
}


#没有错误：打印"A A"




int main()
{
    int a = 654321,b;
    while (a)
    {
        /* code */
        b = a % 10;
        a /= 10;
        switch (b)
        {
            default: printf("%d",b++);
            case 1: printf("%d",b++); break;
            case 2: printf("%d",b++);
            case 3: printf("%d",b++);
            case 4: printf("%d",b++); break;
            case 5: printf("%d",b++);
        }
    }
    return 0;
}

// 1 1 2 
// 2 2 3 3 4 4 5 
// 3 3 4 4 5 
// 4 4 5 
// 5 5 6 7


//输出结果：1234344567



typedef struct s {
    int a;
    float b;
} s;

int main()
{
    printf("%zu\n",sizeof(s));
    return 0;
}

#正确




int main()
{
    int i=3,*j,k;
    j = &i;
    printf("%d\n",i**j*i+*j);
    return 0;
}

// 3 * 3 * 3 + 3 = 30

// 表达式：i**j*i+*j

// 运算符优先级与计算顺序：

// 首先计算 *j（解引用）：*j = i = 3
// 然后计算乘法（优先级相同，从左到右）：
// i**j → 3*3 = 9
// 9*i → 9*3 = 27
// 最后计算加法：
// 27+*j → 27+3 = 30
// 最终结果：30





int fun(int(*)());

int main()
{
    fun(main);
    printf("Hi \n");
    return 0;
}

int fun(int(*p)())
{
    printf("Hello");
    return 0;
}

//HelloHi






int main()
{
    union a
    {
        int i;
        char ch[2];
    };
    union a u;
    u.ch[0] = 3;
    u.ch[1] = 2;
    printf("%d,%d,%d\n",u.ch[0],u.ch[1],u.i);
    return 0;
}


// 联合体（Union）的内存共享在 union 中，所有成员共享同一块内存地址。
// 这个联合体 u 的大小取决于最大的成员。因为 int 通常占 4 字节，char ch[2] 占 2 字节，所以 u 至少占 4 字节。
// 内存布局（以小端模式为例）小端模式是指数据的低位字节存储在内存的低地址端。赋值操作：
// u.ch[0] = 3;：在内存的第一个字节（低地址）写入 0x03。
// u.ch[1] = 2;：在内存的第二个字节写入 0x02。
// 读取 u.i：当我们读取 int i 时，计算机会从该地址开始读取 4 个字节。内存状态（十六进制）：03 02 00 00。
// 由于是小端序，还原为十六进制数值是：0x00000203。计算数值：$0x203$ 转换为十进制：$2 \times 16^2 + 0 \times 16^1 + 3 \times 16^0 = 512 + 0 + 3 = 515$。
//3,2,515




int main()
{
    int i=4,j=-1,k=0,w,x,y,z;
    w = i|| j||k;      // 0100 || 0001 || 0000 = 
    x = i&& j&&k;
    y = i||j&&k;
    z = i&&j||k;
    printf("%d,%d,%d,%d\n",w,x,y,z);
    return 0;
}


// 这道题考察逻辑运算符 ||（或）和 &&（与）的真假判定及短路特性。
// 逻辑背景：在 C 语言中，非 0 即为“真”，0 为“假”。逻辑运算的结果真为 1，假为 0。
// 解题思路：w = i || j || k; $\rightarrow$ 4 || -1 || 0。因为 i(4) 为真，触发短路，后面不再计算。结果为 1。
// x = i && j && k; $\rightarrow$ 4 && -1 && 0。4 和 -1 均为真，但遇到 k(0) 为假。结果为 0。
// y = i || j && k; $\rightarrow$ 4 || (-1 && 0)。由于 || 左侧的 i(4) 已经为真，触发短路，右侧不执行。结果为 1。
// z = i && j || k; $\rightarrow$ (4 && -1) || 0 $\rightarrow$ 1 || 0。结果为 1。
// 输出结果：1, 0, 1, 1



char * my_strcpy(char * strDest,const char * strSrc)
{
    if(strDest == NULL || strSrc == NULL ) return NULL;
    char *address = strDest;
    while((*strDest++ = *strSrc++) != '\0');
    return address;
}
char* my_strcpy(char* dest, const char* src) {
    char* d = dest;
    
    if (dest && src) {
        while ((*d++ = *src++) != '\0');
    }
    
    return dest;
}



int main()
{
    char arr1[] = "abcdef";
    char arr2[] = "bit";
    printf("%s\n",my_strcpy(arr1,arr2));
    printf("%s\n",arr1);
    printf("%s\n",arr2); 
    return 0;
}

#endif
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node, *LinkedList;  // LinkedList 是指向 Node 的指针类型


//1.初始化单项链表（创建头结点）
void InitLinkedList(LinkedList *L) {
    *L = (LinkedList)malloc(sizeof(Node));  // 分配头结点内存
    (*L)->next = NULL;  // 头结点的 next 指针初始化为 NULL
}

//尾插 在第i个节点后插入新节点
void InsertLinkedList(LinkedList L,int i,int x)
{
    Node *p = L;
    int j = 0;
    while (p && j < i)
    {
        /* code */
        p = p->next;
        j++;
    }
    if(!p) return;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
}

//删除第i个节点
void DeleteLinkedList(LinkedList L,int i)
{
    if(i <= 0) return;
    Node *p = L;
    int k = 0;
    while (p != NULL && k < i - 1)
    {
        /* code */
        p = p->next;
        k++;
    }
    if( p == NULL || p->next == NULL) return;
    Node *temp = p->next;
    p->next = temp->next;
    free(temp);
}

//获取第i个节点的data值

int GetElement(LinkedList L,int i)
{
    if(i <= 0) return -1; //无效位置
    Node *p = L;
    int k = 0;
    while (p != NULL && k < i)
    {
        /* code */
        p = p->next;
        k++;
    }
    if(p == NULL) return -1; //无效位置
    return p->data;
}


//获取当前链表的长度，不包含表头
int GetLength(LinkedList L)
{
    int length = 0;
    Node *p = L->next; //跳过头结点
    while (p != NULL)
    {
        /* code */
        length++;
        p = p->next;
    }
    return length;
}
