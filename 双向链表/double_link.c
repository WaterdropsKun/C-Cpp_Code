#include <stdio.h>
#include <malloc.h>


// ˫������ڵ�
typedef struct tag_node
{
	struct tag_node *prev;
	struct tag_node *next;
	void *p;
}node;

// ��ͷ
// ע�⣺��ͷ���������
static node *phead = NULL;

// �ڵ����
static int count = 0;

// �����ڵ㡣�ɹ������ؽڵ�ָ�룻���򣬷���NULL
static node* create_node(void *pval)
{
	node *pnode = NULL;
	pnode = (node *)malloc(sizeof(node));
	if (!pnode)
	{
		printf("create node error!\n");
		return NULL;
	}

	// Ĭ�ϵ�pnode��ǰһ���ͺ�һ���ڵ㶼ָ��������
	pnode->prev = pnode->next = pnode;
	// �ڵ�ֵΪpval
	pnode->p = pval;

	return pnode;
}

// �½�˫�������ɹ�������0�����򣬷���-1��
int create_dlink()
{
	// ������ͷ
	phead = create_node(NULL);
	if (!phead)
	{
		return -1;
	}

	// ���ýڵ����Ϊ0
	count = 0;

	return 0;
}

// ˫�������Ƿ�Ϊ��
int dlink_is_empty()
{
	return count == 0;
}

// ����˫������Ĵ�С
int dlink_size()
{
	return count;
}

// ��ȡ˫�������е�indexλ�õĽڵ�
// index��Χ��[0,count-1]
static node* get_node(int index)
{
	if (index < 0 || index >= count)
	{
		printf("%s failed! index out of bound!\n", __FUNCTION__);
		return NULL;
	}

	// �������
	if (index <= (count / 2))
	{
		int i = 0;
		node *pnode = phead->next;
		while ((i++) < index)
		{
			pnode = pnode->next;
		}
		return pnode;
	}

	// �������
	int j = 0;
	int rindex = count - 1 - index;
	node *rnode = phead->prev;
	while ((j++) < rindex)
	{
		rnode = rnode->prev;
	}
	return rnode;
}

// ��ȡ��һ���ڵ�
static node* get_first_node()
{
	return get_node(0);
}

// ��ȡ���һ���ڵ�
static node* get_last_node()
{
	return get_node(count - 1);
}

// ��ȡ˫�������е�indexλ�õ�Ԫ�ء��ɹ������ؽڵ�ֵ�����򣬷���-1��
void* dlink_get(int index)
{
	node *pindex = get_node(index);
	if (!pindex)
	{
		printf("%s failed!\n", __FUNCTION__);
		return NULL;
	}

	return pindex->p;
}

// ��ȡ˫�������е�1��Ԫ�ص�ֵ
void* dlink_get_first()
{
	return dlink_get(0);
}

// ��ȡ˫�����������1��Ԫ�ص�ֵ
void* dlink_get_last()
{
	return dlink_get(count - 1);
}

// ��pval���뵽��ͷλ��
int dlink_insert_first(void *pval)
{
	node *pnode = create_node(pval);
	if (!pnode)
	{
		return -1;
	}

	pnode->prev = phead;
	pnode->next = phead->next;
	
	phead->next->prev = pnode;
	phead->next = pnode;

	count++;
	return 0;
}

// ��pval���뵽ĩβλ��
int dlink_insert_last(void *pval)
{
	node *pnode = create_node(pval);
	if (!pnode)
	{
		return -1;
	}

	pnode->prev = phead->prev;
	pnode->next = phead;

	phead->prev->next = pnode;
	phead->prev = pnode;

	count++;
	return 0;
}

// ��pval���뵽indexλ�á��ɹ�������0�����򣬷���-1��
int dlink_insert(int index, void *pval)
{
	// �����ͷ
	if (index == 0)
	{
		return dlink_insert_first(pval);
	}

	// ��ȡҪ����λ�ö�Ӧ�Ľڵ�
	node *pindex = get_node(index);
	if (!pindex)
	{
		return -1;
	}

	// �����ڵ�
	node *pnode = create_node(pval);
	if (!pnode)
	{
		return -1;
	}

	pnode->prev = pindex->prev;
	pnode->next = pindex;

	pindex->prev->next = pnode;
	pindex->prev = pnode;

	count++;
	return 0;
}

// ɾ��˫��������indexλ�õĽڵ㡣�ɹ�������0�������򣬷���-1��
int dlink_delete(int index)
{
	node *pindex = get_node(index);
	if (!pindex)
	{
		printf("%s failed! the index in out of bound!\n", __FUNCTION__);
		return -1;
	}

	pindex->next->prev = pindex->prev;
	pindex->prev->next = pindex->next;

	free(pindex);
	count--;

	return 0;
}

// ɾ����һ���ڵ�
int dlink_delete_first()
{
	return dlink_delete(0);
}

// ɾ�����һ���ڵ�
int dlink_delete_last()
{
	return dlink_delete(count - 1);
}

// ����˫�������ɹ�������0�����򣬷���-1��
int destroy_dlink()
{
	if (!phead)
	{
		printf("%s failed! the index in out of bound!\n", __FUNCTION__);
		return -1;
	}

	node *pnode = phead->next;
	node *ptmp = NULL;
	while (pnode != phead)
	{
		ptmp = pnode;
		pnode = pnode->next;
		free(ptmp);
	}

	free(phead);
	phead = NULL;
	count = 0;

	return 0;
}



/**
* C ����ʵ�ֵ�˫������Ĳ��Գ���
*
* (01) int_test()
*      ��ʾ��˫�����������int���ݡ���
* (02) string_test()
*      ��ʾ��˫������������ַ������ݡ���
* (03) object_test()
*      ��ʾ��˫��������������󡱡�
*
* @author skywang
* @date 2013/11/07
*/

// ˫���������int����
void int_test()
{
	int iarr[4] = { 10, 20, 30, 40 };

	printf("\n----%s----\n", __FUNCTION__);
	create_dlink();        // ����˫������

	dlink_insert(0, &iarr[0]);    // ��˫������ı�ͷ��������
	dlink_insert(0, &iarr[1]);    // ��˫������ı�ͷ��������
	dlink_insert(0, &iarr[2]);    // ��˫������ı�ͷ��������

	printf("dlink_is_empty()=%d\n", dlink_is_empty());    // ˫�������Ƿ�Ϊ��
	printf("dlink_size()=%d\n", dlink_size());            // ˫������Ĵ�С

														  // ��ӡ˫�������е�ȫ������
	int i;
	int *p;
	int sz = dlink_size();
	for (i = 0; i<sz; i++)
	{
		p = (int *)dlink_get(i);
		printf("dlink_get(%d)=%d\n", i, *p);
	}

	destroy_dlink();
}

void string_test()
{
	char* sarr[4] = { "ten", "twenty", "thirty", "forty" };

	printf("\n----%s----\n", __FUNCTION__);
	create_dlink();        // ����˫������

	dlink_insert(0, sarr[0]);    // ��˫������ı�ͷ��������
	dlink_insert(0, sarr[1]);    // ��˫������ı�ͷ��������
	dlink_insert(0, sarr[2]);    // ��˫������ı�ͷ��������

	printf("dlink_is_empty()=%d\n", dlink_is_empty());    // ˫�������Ƿ�Ϊ��
	printf("dlink_size()=%d\n", dlink_size());            // ˫������Ĵ�С

														  // ��ӡ˫�������е�ȫ������
	int i;
	char *p;
	int sz = dlink_size();
	for (i = 0; i<sz; i++)
	{
		p = (char *)dlink_get(i);
		printf("dlink_get(%d)=%s\n", i, p);
	}

	destroy_dlink();
}

typedef struct tag_stu
{
	int id;
	char name[20];
}stu;

static stu arr_stu[] =
{
	{ 10, "sky" },
	{ 20, "jody" },
	{ 30, "vic" },
	{ 40, "dan" },
};
#define ARR_STU_SIZE ( (sizeof(arr_stu)) / (sizeof(arr_stu[0])) )

void object_test()
{
	printf("\n----%s----\n", __FUNCTION__);
	create_dlink();    // ����˫������

	dlink_insert(0, &arr_stu[0]);    // ��˫������ı�ͷ��������
	dlink_insert(0, &arr_stu[1]);    // ��˫������ı�ͷ��������
	dlink_insert(0, &arr_stu[2]);    // ��˫������ı�ͷ��������

	printf("dlink_is_empty()=%d\n", dlink_is_empty());    // ˫�������Ƿ�Ϊ��
	printf("dlink_size()=%d\n", dlink_size());            // ˫������Ĵ�С

														  // ��ӡ˫�������е�ȫ������
	int i;
	int sz = dlink_size();
	stu *p;
	for (i = 0; i<sz; i++)
	{
		p = (stu *)dlink_get(i);
		printf("dlink_get(%d)=[%d, %s]\n", i, p->id, p->name);
	}

	destroy_dlink();
}

int main_double_link()
{
	int_test();        // ��ʾ��˫�����������int���ݡ���
	string_test();    // ��ʾ��˫������������ַ������ݡ���
	object_test();    // ��ʾ��˫��������������󡱡�

	return 0;
}






