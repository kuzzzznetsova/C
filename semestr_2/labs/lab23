/*
Определить степень дерева.
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Tnode
{
    int key;               //данные, которые вы собираетесь хранить
    struct Tnode *son;     //указатель на старшего сына
    struct Tnode *brother; //указатель на брата
};
typedef struct Tnode Node; //называем struct Tnode просто Node

Node *create_tree(int v)
{                                              //создадим функцию, которая осуществляет добавление вершины
    Node *Tree = (Node *)malloc(sizeof(Node)); //выделяет память под вершину и передает указатель на эту вершину

    //обнуляем указатели к братьям и сыновьям, независимая вершина, которая хранит value
    Tree->son = NULL;
    Tree->brother = NULL;
    Tree->key = v;
    return Tree;
}

Node *to_brother(Node *t)
{
    if (t->brother != NULL)
    {
        t = t->brother;
    }
    return t;
}

Node *to_son(Node *t)
{
    if (t->son != NULL)
    {
        t = t->son;
    }
    return t;
}
Node *last_son(Node *t)
{
    while (t->brother != NULL)
    {
        t = t->brother;
    }
    return t;
}

Node *to_daddy(Node *t, Node *t2, int daddy, int *i)
{
    if (*i != 1)
        t2 = t;
    if (t->key != daddy)
    {
        if (t2->son != NULL)
        {
            t = to_daddy(t2->son, t2, daddy, i);
        }
        if (t2->brother != NULL && *i != 1)
        {
            t = to_daddy(t2->brother, t2, daddy, i);
        }
    }
    else
    {
        *i = 1;
    }
    return t;
}
Node *add_node(Node **tree, int daddy, int son)
{
    if (*tree == NULL)
    {
        *tree = create_tree(son);
        return *tree;
    }
    int j = 0;
    int *i = &j;
    Node *t2 = *tree;
    Node *t = to_daddy(*tree, t2, daddy, i);
    //printf("%d-", t->key);
    if (t->son != NULL)
    {
        t = last_son(t->son); // мы перешли к вершине, к которой хотели
        //и теперь идем к последнему ее сыну,
        //чтобы добавить в конец списка
        t->brother = create_tree(son);
        return *tree; // было t->brother возвращалось только последнее значение
    }
    else
    { //если сына нет, то создадим его
        t->son = create_tree(son);
        return *tree; // было t->son возвращалось только последнее значение
    }
}
void print_tree(Node *t, int s)
{
    for (int i = 0; i < s; i++)
    {
        printf("\t");
    }
    printf("%d\n", t->key);
    if (t->son != NULL)
    {
        print_tree(t->son, s + 1);
    }
    if (t->brother != NULL)
    {
        print_tree(t->brother, s);
    }
}
void deleteTree(Node **t, int val, int id)
{ // id: 1 - удалить, 0 - пропустить

    Node *tmp = *t;
    Node *tmp1;
    Node *tmp2;

    if (tmp->key == val)
        id = 1;
    if (tmp->son)
    {
        if (tmp->son->key == val && tmp->son->brother)
        { // swap указателей

            tmp1 = tmp->son->brother;
            tmp2 = tmp->son;
            tmp2->brother = NULL;
            tmp->son = tmp1;

            deleteTree(&tmp2, tmp2->key, 1);
        }
        else
            deleteTree(&tmp->son, val, id);
    }
    if (tmp->brother)
    {
        if (tmp->brother->key == val && tmp->brother->brother)
        { // swap указателей

            tmp1 = tmp->brother->brother;
            tmp2 = tmp->brother;
            tmp2->brother = NULL;
            tmp->brother = tmp1;

            deleteTree(&tmp2, tmp2->key, 1);
        }
        else
            deleteTree(&tmp->brother, val, id);
    }

    if (id == 1)
    {
        free(*t);
        *t = NULL;
    }

    return;
}

int poisk_stepeny(Node *t)
{
    int st = 1;
    if (t->brother != NULL)
    {
        // st = st + 1;
        t = t->brother;
        st = poisk_stepeny(t) + st;
    }
    return st;
}

int stepen_tree(Node *t)
{
    int st, stm;
    stm = 0;
    if (t->son != NULL)
    {
        // t = t->son;
        st = poisk_stepeny(t->son);

        if (st > stm)
        {
            stm = st;
        }

        st = stepen_tree(t->son);
        if (st > stm)
        {
            stm = st;
        }
        
    }

     if (t->brother != NULL) {
        st = poisk_stepeny(t->brother);
        if (st > stm) {
            stm = st;
        }

        st = stepen_tree(t->brother);
        if (st > stm)
        {
            stm = st;
        }
    }

    

    return stm;
}

int main()
{
    int k; //степень дерева;
    int b, a, s;
    char m;
    Node *tree = NULL; //oбъявим указатель на вершину;
    printf("Options: \n");
    printf("a - add node\n");
    printf("d - delete node\n");
    printf("p - print tree\n");
    printf("s - find stepen\n");

    while (1)
    {

        //s = scanf("%c", &m);
        scanf("%c", &m);
        if (m == 'a')
        {
            //s = scanf("%d%d", &a, &b);
            s = scanf("%d %d", &a, &b);
            tree = add_node(&tree, a, b);
            printf("Options: \n");
            printf("a - add node\n");
            printf("d - delete node\n");
            printf("p - print tree\n");
            printf("s - find stepen\n");
        }
        else if (m == 'd')
        {
            s = scanf("%d", &a);
            deleteTree(&tree, a, 0);
            printf("Options:\n");
            printf("a - add node\n");
            printf("d - delete node\n");
            printf("p - print tree\n");
            printf("s - find stepen\n");
        }
        else if (m == 'p')
        {
            print_tree(tree, 0);
            printf("Options: \n");
            printf("a - add node\n");
            printf("d - delete node\n");
            printf("p - print tree\n");
            printf("s - find stepen\n");
        }
        else if (m == 's')
        {
            k = stepen_tree(tree);
            printf("%d\n", k);
            printf("Options: \n");
            printf("a - add node\n");
            printf("d - delete node\n");
            printf("p - print tree\n");
            printf("s - find stepen\n");
        }
    }
    return 0;
}
