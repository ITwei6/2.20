#include <stdio.h>
typedef struct Data
{
	char name[10];
	char sex[10];
	int score;
}Data;
typedef struct Node
{
	Data data;
	struct Node *next
}Node;
//1.删除单链表中某个结点
void ListDele(Node* L, int i,Data e)
{
	Node* p;
	Node* q;
	p = L;
	int j = 1;
	while (p && j < i - 1)//找到i-1的结点
	{
		p = p->next;
	}
	if (p == NULL || j > i - 1)
		return 0;
	q = p->next;//q是i的结点地址
	p = q->next;
	free(q);
	
}
//建立单链表---头插法   
void CreatList(Node* L, int n)
{
	L->next = NULL;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		Node* p = (Node*)malloc(sizeof(Node));//开辟空间,生成一个结点
		scanf(&p->data);
		p->next = L->next;
		L->next = p;
	}
}
//尾插法
void CreatList(Node* L, int n)
{
	L->next = NULL;
	Node* r;//尾指针
	r = L;
	for (int j = 0; j < n; j++)
	{
		Node* p = (Node*)malloc(sizeof(Node));//开辟空间,生成一个结点
		scanf(&p->data);
		//p->next = NULL;
		p->next = r->next;
		r->next = p;
		r = p;
	}
}
//循环链表
//带尾指针循环链表的合并
void Connect(Node* Ta, Node* Tb)
{
	//假设Ta,Tb是非空的单循环链表，ta，tb分别是指向尾指针
	Node* p;
	p = Ta->next;//将指向头指针的地址保存下来
	Ta->next = (Tb->next)->next;//Tb的表头与ta的表尾链接
	free(Tb->next);//删除Tb的头指针
	Tb->next = p;//Tb的next里面存放这Ta的头指针；
	//最后两个链表链接成功
}
//双向链表
//单链表找前驱比较困难。 前驱指针，后驱指针

typedef struct DuNode
{
	Data data;
	struct Node* prior, * next;
}DuNode;//双链表
//双循环链表---尾结点后继链接头指针的前驱。---对称性
//1.双向链表的插入 

void DuListInsert(DuNode* L, int i, Data e)//在带头结点的双向循环链表L中第i个位置插入元素e
{
	DuNode* p;
	p = L;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
	}
	if (p == NULL || j > i)
		return 0;
	DuNode* s = (DuNode*)malloc(sizeof(DuNode));
	s->data = e;
	s->prior = p->prior;//s的前驱放入i-1的地址
	p->prior->next = s;//将s的地址放入i-1的后继
	s->next = p;//将p的地址放入s的后继
	p->prior = s;//将s的地址放入p的前驱


}
//2.双向链表的删除
void ListDelete_Du(DuNode* L, int i, Data e)
{
	//删除带头结点的双向循环链表L的第i元素,并用e返回
	DuNode* p;
	p = L;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
	}
	if (p == NULL || j > i)
		return 0;
	e = p->data;
	p->prior->next = p->next;
	/*p->next->prior= p->prior;*/
}
//有序表的合并--链表
void MergeList(DuNode* La, DuNode* Lb, DuNode* Lc)
{//La,Lb两个链表的头结点
	//La->next 相当于首元结点，pa,pb就是首元结点的地址
	DuNode* pa = (DuNode*)malloc(sizeof(DuNode));
	pa = La->next;//两个指针用来找到两个链表中的值
	DuNode* pb = (DuNode*)malloc(sizeof(DuNode));
	DuNode* pc = (DuNode*)malloc(sizeof(DuNode));
	pc = Lc = La;//用La的头结点作为Lc的头结点
	pb = Lb->next;
	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;//将小的结点的地址放入pc的后继，构成链表
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		pc->next = pa ? pa : pb;//插入剩余段
		free(Lb);//释放Lb的头结点
	}
}
int main()
{
	int i = 0;
	int n = 5;
	Data e;
	Node* L = (Node*)malloc(sizeof(Node));//开辟空间
	ListDele(L,i,e); //删除单链表中某个结点
	CreatList(L, n);//创建一个带头结点的单链表--头插法
	CreatList(L, n); //创建一个带头结点的单链表--尾插法

}