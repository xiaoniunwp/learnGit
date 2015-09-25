/*
 * 第二章课后作业 2-23（P42）
 * 学号： 20128405
 * 姓名： 牛万鹏
*/

#include <stdio.h>
#include <stdlib.h>

// 宏定义
#define OK 1
#define ERROR 0

// 声明别名
typedef int element;
typedef int status;
// 节点类型
typedef struct Node{
	element data;
	struct Node *next;
} node, *link;
// 链表类型
typedef struct {
	link head, tail;
	int size;
} linkList;

// 单循环链表操作函数
linkList initLinkList();
int size(linkList list);
status inserts(linkList *list, int i, element e);
status deletes(linkList *list, int i);
element getElement(linkList *list, int i);
void lists(linkList *list);

// 主函数-用于测试
int main() {
    // 初始化链表
    linkList list = initLinkList();
    // 插入三个元素
    inserts(&list, 0, 3);
    inserts(&list, 1, 222);
    inserts(&list, 2, 2222);

    // 遍历链表
    lists(&list);

    // 求列表中元素个数
    printf("size = %d\n", list.size);

    // 获取列表中的元素
    printf("value = %d\n", getElement(&list, 0));
    printf("value = %d\n", getElement(&list, 1));
    printf("value = %d\n", getElement(&list, 2));

    // 删除列表中的元素
    deletes(&list, 2);

    printf("value = %d\n", getElement(&list, 0));
    printf("value = %d\n", getElement(&list, 1));
    // 查看最终列表中元素个数
    printf("size = %d\n", list.size);
}

// 初始化函数
linkList initLinkList() {
    linkList list;
    list.head = (link) malloc(sizeof(node));
    list.tail = (link) malloc(sizeof(node));
    list.head -> data = list.tail -> data = 0;
    list.head -> next = list.tail;
    list.tail -> next = list.head;
    list.size = 0;

	return list;
}

// 求列表中元素个数
int size(linkList list) {
	return list.size;
}

// 遍历链表
 void lists(linkList *list) {
    link p = list -> head;
    for (int index = 0; index < list -> size; index++) {
        p = p -> next;
        printf("list[%d]=%d\n", index, p -> data);
    }
 }
// 查入元素
status inserts(linkList *list, int i, element e) {
    if (i > list -> size) {
        return ERROR;
    }

    link p = list -> head;
    for (int index = 0; index < i; index++) {
        p = p -> next;
    }

    link l = (link)malloc(sizeof(node));
    (l -> data) = e;
    (l -> next) = (p -> next);
    (p -> next) = l;

    (list -> size)++;
    return OK;
}

// 删除列表中元素
status deletes(linkList *list, int i) {
    if (i >= list -> size) {
        return ERROR;
    }

    link p = list -> head;
    for (int index = 0; index < i; index++) {
        p = p -> next;
    }

    p -> next = p -> next -> next;
    (list -> size)--;
    return OK;
}

// 获取列表中的元素
element getElement(linkList *list, int i) {
    if (i >= list -> size) {
        return ERROR;
    }

    link p = list -> head;
    for (int index = 0; index <= i; index++) {
        p = p -> next;
    }
    return p -> data;
}
