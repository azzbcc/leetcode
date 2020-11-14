/**
 * print.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/11/12 上午11:53
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <print.h>

/**
 * @param tree             指向 N 叉树的指针
 * @param offsets          孩子指针在结构体中的偏移量 offsetof(struct type, point)
 * @param size             N 叉树孩子个数
 * @param depth            当前递归节点树的深度
 * @param flags            标记当前节点是左孩子还是右孩子
 * @param print_tree_node  打印回调函数（函数中不可换行）
 */
static void print_static_tree_real(void *tree, int *offsets, int size, int depth, bool flags[],
                                   void (*print_tree_node)(void *)) {
    for (int i = 0; i < depth - 1; i++) {
        printf(" %s  ", flags[i] ? "│" : " ");
    }
    if (depth) printf(" %s─> ", flags[depth - 1] ? "├" : "└");
    if (*( void ** )tree == NULL) {
        printf("INF\n");
        return;
    }

    print_tree_node(*( void ** )tree);
    printf("\n");

#if 1
    bool has_child = false;
    for (int i = 0; !has_child && i < size; ++i) {
        void *next = (*( void ** )tree) + offsets[i];
        has_child  = *( void ** )next;
    }
    if (!has_child) return;
#endif

    for (int i = 0; i < size; ++i) {
        void *next   = (*( void ** )tree) + offsets[i];
        flags[depth] = i + 1 < size;
        print_static_tree_real(next, offsets, size, depth + 1, flags, print_tree_node);
    }
}

/**
 * 打印 N 叉树
 * @param tree             指向N叉树的指针
 * @param offsets          孩子指针在结构体中的偏移量 offsetof(struct type, point)
 * @param size             N 叉树孩子个数
 * @param depth            预测树的最大深度
 * @param print_tree_node  打印回调函数（函数中不可换行）
 */
void print_static_tree(void *tree, int offsets[], int size, int depth, void (*print_tree_node)(void *)) {
    bool flags[depth];
    print_static_tree_real(&tree, offsets, size, 0, flags, print_tree_node);
}

/**
 * @param tree             指向 N 叉树的指针
 * @param count_offset     孩子个数属性在结构体中的偏移量   offsetof(struct type, count)
 * @param point_offset     第一个孩子指针在结构体中的偏移量 offsetof(struct type, point[])
 * @param depth            当前递归节点树的深度
 * @param flags            标记当前节点是左孩子还是右孩子
 * @param print_tree_node  打印回调函数（函数中不可换行）
 */
static void print_dynamic_tree_real(void *tree, int count_offset, int point_offset, int depth, bool flags[],
                                    void (*print_tree_node)(void *)) {
    for (int i = 0; i < depth - 1; i++) {
        printf(" %s  ", flags[i] ? "│" : " ");
    }
    if (depth) printf(" %s─> ", flags[depth - 1] ? "├" : "└");
    if (*( void ** )tree == NULL) {
        printf("INF\n");
        return;
    }

    print_tree_node(*( void ** )tree);
    printf("\n");

    int size = *((*( int ** )tree) + count_offset);

#if 1
    bool has_child = false;
    for (int i = 0; !has_child && i < size; ++i) {
        void *next = (*( void ** )tree) + point_offset + i * sizeof(void *);
        has_child  = *( void ** )next;
    }
    if (!has_child) return;
#endif

    for (int i = 0; i < size; ++i) {
        void *next   = (*( void ** )tree) + point_offset + i * sizeof(void *);
        flags[depth] = i + 1 < size;
        print_dynamic_tree_real(next, count_offset, point_offset, depth + 1, flags, print_tree_node);
    }
}

/**
 * 打印 N 叉树
 * @param tree             指向N叉树的指针
 * @param count_offset     孩子个数属性在结构体中的偏移量   offsetof(struct type, count)
 * @param point_offset     第一个孩子指针在结构体中的偏移量 offsetof(struct type, children[])
 * @param size             N 叉树孩子个数
 * @param depth            预测树的最大深度
 * @param print_tree_node  打印回调函数（函数中不可换行）
 */
void print_dynamic_tree(void *tree, int count_offset, int point_offset, int depth, void (*print_tree_node)(void *)) {
    bool flags[depth];
    print_dynamic_tree_real(&tree, count_offset, point_offset, 0, flags, print_tree_node);
}