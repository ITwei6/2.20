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
//1.ɾ����������ĳ�����
void ListDele(Node* L, int i,Data e)
{
	Node* p;
	Node* q;
	p = L;
	int j = 1;
	while (p && j < i - 1)//�ҵ�i-1�Ľ��
	{
		p = p->next;
	}
	if (p == NULL || j > i - 1)
		return 0;
	q = p->next;//q��i�Ľ���ַ
	p = q->next;
	free(q);
	
}
//����������---ͷ�巨   
void CreatList(Node* L, int n)
{
	L->next = NULL;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		Node* p = (Node*)malloc(sizeof(Node));//���ٿռ�,����һ�����
		scanf(&p->data);
		p->next = L->next;
		L->next = p;
	}
}
//β�巨
void CreatList(Node* L, int n)
{
	L->next = NULL;
	Node* r;//βָ��
	r = L;
	for (int j = 0; j < n; j++)
	{
		Node* p = (Node*)malloc(sizeof(Node));//���ٿռ�,����һ�����
		scanf(&p->data);
		//p->next = NULL;
		p->next = r->next;
		r->next = p;
		r = p;
	}
}
//ѭ������
//��βָ��ѭ������ĺϲ�
void Connect(Node* Ta, Node* Tb)
{
	//����Ta,Tb�Ƿǿյĵ�ѭ������ta��tb�ֱ���ָ��βָ��
	Node* p;
	p = Ta->next;//��ָ��ͷָ��ĵ�ַ��������
	Ta->next = (Tb->next)->next;//Tb�ı�ͷ��ta�ı�β����
	free(Tb->next);//ɾ��Tb��ͷָ��
	Tb->next = p;//Tb��next��������Ta��ͷָ�룻
	//��������������ӳɹ�
}
//˫������
//��������ǰ���Ƚ����ѡ� ǰ��ָ�룬����ָ��

typedef struct DuNode
{
	Data data;
	struct Node* prior, * next;
}DuNode;//˫����
//˫ѭ������---β���������ͷָ���ǰ����---�Գ���
//1.˫������Ĳ��� 

void DuListInsert(DuNode* L, int i, Data e)//�ڴ�ͷ����˫��ѭ������L�е�i��λ�ò���Ԫ��e
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
	s->prior = p->prior;//s��ǰ������i-1�ĵ�ַ
	p->prior->next = s;//��s�ĵ�ַ����i-1�ĺ��
	s->next = p;//��p�ĵ�ַ����s�ĺ��
	p->prior = s;//��s�ĵ�ַ����p��ǰ��


}
//2.˫�������ɾ��
void ListDelete_Du(DuNode* L, int i, Data e)
{
	//ɾ����ͷ����˫��ѭ������L�ĵ�iԪ��,����e����
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
//�����ĺϲ�--����
void MergeList(DuNode* La, DuNode* Lb, DuNode* Lc)
{//La,Lb���������ͷ���
	//La->next �൱����Ԫ��㣬pa,pb������Ԫ���ĵ�ַ
	DuNode* pa = (DuNode*)malloc(sizeof(DuNode));
	pa = La->next;//����ָ�������ҵ����������е�ֵ
	DuNode* pb = (DuNode*)malloc(sizeof(DuNode));
	DuNode* pc = (DuNode*)malloc(sizeof(DuNode));
	pc = Lc = La;//��La��ͷ�����ΪLc��ͷ���
	pb = Lb->next;
	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;//��С�Ľ��ĵ�ַ����pc�ĺ�̣���������
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		pc->next = pa ? pa : pb;//����ʣ���
		free(Lb);//�ͷ�Lb��ͷ���
	}
}
int main()
{
	int i = 0;
	int n = 5;
	Data e;
	Node* L = (Node*)malloc(sizeof(Node));//���ٿռ�
	ListDele(L,i,e); //ɾ����������ĳ�����
	CreatList(L, n);//����һ����ͷ���ĵ�����--ͷ�巨
	CreatList(L, n); //����һ����ͷ���ĵ�����--β�巨

}