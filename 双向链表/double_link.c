#include <stdio.h>
#include <malloc.h>


// 双向链表节点
typedef struct tag_node
{
	struct tag_node *prev;
	struct tag_node *next;
	void *p;
}node;

// 表头
// 注意：表头不存放数据
static node *phead = NULL;

// 节点个数
static int count = 0;

// 新增节点。成功，返回节点指针；否则，返回NULL
static node* create_node(void *pval)
{
	node *pnode = NULL;
	pnode = (node *)malloc(sizeof(node));
	if (!pnode)
	{
		printf("create node error!\n");
		return NULL;
	}

	// 默认的pnode的前一个和后一个节点都指向它自身
	pnode->prev = pnode->next = pnode;
	// 节点值为pval
	pnode->p = pval;

	return pnode;
}

// 新建双向链表。成功，返回0；否则，返回-1。
int create_dlink()
{
	// 创建表头
	phead = create_node(NULL);
	if (!phead)
	{
		return -1;
	}

	// 设置节点个数为0
	count = 0;

	return 0;
}

// 双向链表是否为空
int dlink_is_empty()
{
	return count == 0;
}

// 返回双向链表的大小
int dlink_size()
{
	return count;
}

// 获取双向链表中第index位置的节点
// index范围：[0,count-1]
static node* get_node(int index)
{
	if (index < 0 || index >= count)
	{
		printf("%s failed! index out of bound!\n", __FUNCTION__);
		return NULL;
	}

	// 正向查找
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

	// 反向查找
	int j = 0;
	int rindex = count - 1 - index;
	node *rnode = phead->prev;
	while ((j++) < rindex)
	{
		rnode = rnode->prev;
	}
	return rnode;
}

// 获取第一个节点
static node* get_first_node()
{
	return get_node(0);
}

// 获取最后一个节点
static node* get_last_node()
{
	return get_node(count - 1);
}

// 获取双向链表中第index位置的元素。成功，返回节点值；否则，返回-1。
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

// 获取双向链表中第1个元素的值
void* dlink_get_first()
{
	return dlink_get(0);
}

// 获取双向链表中最后1个元素的值
void* dlink_get_last()
{
	return dlink_get(count - 1);
}

// 将pval插入到表头位置
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

// 将pval插入到末尾位置
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

// 将pval插入到index位置。成功，返回0；否则，返回-1。
int dlink_insert(int index, void *pval)
{
	// 插入表头
	if (index == 0)
	{
		return dlink_insert_first(pval);
	}

	// 获取要插入位置对应的节点
	node *pindex = get_node(index);
	if (!pindex)
	{
		return -1;
	}

	// 创建节点
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

// 删除双向链表中index位置的节点。成功，返回0，；否则，返回-1。
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

// 删除第一个节点
int dlink_delete_first()
{
	return dlink_delete(0);
}

// 删除最后一个节点
int dlink_delete_last()
{
	return dlink_delete(count - 1);
}

// 撤销双向链表。成功，返回0；否则，返回-1。
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
* C 语言实现的双向链表的测试程序。
*
* (01) int_test()
*      演示向双向链表操作“int数据”。
* (02) string_test()
*      演示向双向链表操作“字符串数据”。
* (03) object_test()
*      演示向双向链表操作“对象”。
*
* @author skywang
* @date 2013/11/07
*/

// 双向链表操作int数据
void int_test()
{
	int iarr[4] = { 10, 20, 30, 40 };

	printf("\n----%s----\n", __FUNCTION__);
	create_dlink();        // 创建双向链表

	dlink_insert(0, &iarr[0]);    // 向双向链表的表头插入数据
	dlink_insert(0, &iarr[1]);    // 向双向链表的表头插入数据
	dlink_insert(0, &iarr[2]);    // 向双向链表的表头插入数据

	printf("dlink_is_empty()=%d\n", dlink_is_empty());    // 双向链表是否为空
	printf("dlink_size()=%d\n", dlink_size());            // 双向链表的大小

														  // 打印双向链表中的全部数据
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
	create_dlink();        // 创建双向链表

	dlink_insert(0, sarr[0]);    // 向双向链表的表头插入数据
	dlink_insert(0, sarr[1]);    // 向双向链表的表头插入数据
	dlink_insert(0, sarr[2]);    // 向双向链表的表头插入数据

	printf("dlink_is_empty()=%d\n", dlink_is_empty());    // 双向链表是否为空
	printf("dlink_size()=%d\n", dlink_size());            // 双向链表的大小

														  // 打印双向链表中的全部数据
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
	create_dlink();    // 创建双向链表

	dlink_insert(0, &arr_stu[0]);    // 向双向链表的表头插入数据
	dlink_insert(0, &arr_stu[1]);    // 向双向链表的表头插入数据
	dlink_insert(0, &arr_stu[2]);    // 向双向链表的表头插入数据

	printf("dlink_is_empty()=%d\n", dlink_is_empty());    // 双向链表是否为空
	printf("dlink_size()=%d\n", dlink_size());            // 双向链表的大小

														  // 打印双向链表中的全部数据
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
	int_test();        // 演示向双向链表操作“int数据”。
	string_test();    // 演示向双向链表操作“字符串数据”。
	object_test();    // 演示向双向链表操作“对象”。

	return 0;
}






