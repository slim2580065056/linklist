#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node_t
{
	int data;
	struct node_t *prev,*next;
}Node,*pNode;

pNode list_init(void)
{
	pNode head = (pNode)malloc(sizeof(Node));
	if(NULL == head)
	{
		printf("apply memory faild...\n");
		return NULL;
	}
	head->next = head;
	head->prev = head;
	return head;
}

//链表头插入
pNode list_add_head(pNode head, int data)
{
	pNode new = (pNode)malloc(sizeof(Node));
	if(NULL == new)
	{
		printf("apply memory faild...\n");
		return NULL;
	}
	new->data = data;
	new->next = head->next;
	new->prev = head;
	head->next->prev = new;
	head->next = new;
	return head;
}

//链表头删除
pNode list_del_head(pNode head)
{
	pNode tmp;
	tmp = head->next;
	if(tmp == head)
	{
		printf("list is empty ...\n");
		return head;
	} 
	head->next= tmp->next;
	tmp->next->prev= head;
	free(tmp);
	return head;
}

//链表尾插入
pNode list_add_tail(pNode head, int data)
{
	pNode new = (pNode)malloc(sizeof(Node));
	if(NULL == new)
	{
		printf("apply memory faild...\n");
		return NULL;
	}
	new->data = data;
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
	return head;
}

//链表尾删除
pNode list_del_tail(pNode head)
{
	pNode tmp;
	tmp = head->prev;
	if(tmp == head)
	{
		printf("list is empty ...\n");
		return head;
	} 
	head->prev = tmp->prev;
	head->prev->next = head;
	free(tmp);
	return head;
}

void list_show(pNode head)
{
	pNode tmp;
	tmp = head->next;
	while(tmp != head)
	{
		printf("%d\t",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
 
 int main(void)
 {
 	int i,j;
 	pNode head;
 	head = list_init();
 	printf("head addr:%p\n",head);
 	while(1)
 	{
		scanf("%d",&i);
		if(0 == i)	return 0;
		else if(i > 0 ) 
		{
			list_add_head(head, i);	//链表头插入
			list_add_tail(head, i); //链表尾插入
			list_show(head); 
		}	
		else if(i < 0)
		{
			list_del_head(head);	//链表头删除
			list_del_tail(head);	//链表尾删除 
			list_show(head); 
		}
 	}
 	free(head);
 	return 0;
 }
