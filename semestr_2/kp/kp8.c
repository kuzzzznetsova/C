/*
Переставить первую и вторую половины списка.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ИТЕРАТОРЫ
typedef struct item
{
    char data;
    struct item* next;
}item;

typedef struct
{
    item* node;
} iterator;

//РЕАЛИЗАЦИЯ СПИСКА
typedef struct {
    item* head;
    int size;
}list;

//СОЗДАНИЕ СПИСКА
void create(list* l) {
    l->head = 0;
    l->size = 0;
}

//ПЕРЕМЕЩЕНИЕ ПО СПИСКУ
//СЛЕДУЮЩИЙ ЭЛЕМЕНТ
iterator next(iterator* i) {
    i->node = i->node->next;
    return *i;
}

//ЧТЕНИЕ ЭЛЕМЕНТА СПИСКА
char fetch(const iterator* i) {
    return i->node->data;
}

//СРАВНЕНИЕ ИТЕРАТОРОВ
int equal(const iterator* lhs, const iterator* rhs) {
    return lhs->node == rhs->node;
}

//ПОЛУЧЕНИЕ ИТЕРАТОРА ПО НОМЕРУ ЭЛЕМЕНТА
iterator search(const list* l, const int* num) {
    int j = 1;
    iterator i;
    i.node = l->head;
    while (j < *num) {
        next(&i);
        j++;
    }
    return i;
}

//ПОЛУЧЕНИЕ ИТЕРАТОРА ПОСЛЕДНЕГО ЭЛЕМЕНТА
iterator get_last(list* l) {
    iterator i;
    i.node = l->head;
    while (i.node->next) {
        i = next(&i);
    }
    return i;
}

//ПЕЧАТЬ СПИСКА
void print_list(const list *l) {
    int k = 0;
    //ПРОВЕРКА НА ПУСТОТУ СПИСКА
    if (l->head == 0) {
        printf("Список пустой\n");
        return;
    }
    //СОЗДАНИЕ ИТЕРАТОРА ДЛЯ ГОЛОВЫ СПИСКА
    iterator i;
    i.node = l->head;
    //ПЕЧАТЬ ЕСЛИ ИТЕРАТОР СЛЕДУЮЩЕГО ЭЛЕМЕНТА НЕ НОЛЬ
    while(i.node->next) {
        k++;
        printf("%d | %c\n", k, fetch(&i));
        //ПОЛУЧЕНИЕ СЛЕДУЮЩЕГО ЭЛЕМЕНТА
        i = next(&i);
    }
    //ПЕЧАТЬ ПОСЛЕДНЕГО ЭЛЕМЕНТА
    k++;
    printf("%d | %c\n", k, fetch(&i));
}


iterator prev(list * l, iterator * it) {

    if (it->node == NULL) {
        return get_last(l);
    }

    if (it->node == l->head) {
        iterator res = {NULL};
        return res;
    }
    iterator first = {l->head};
	iterator res = first;

	while (res.node->next != it->node)
		res = next(&first);

	return res;
}

//ВСТАВКА
void insert(list* l, iterator* i, const char t) {
    //СОЗДАНИЕ ИТЕРАТОРА
    iterator res;
    res.node = (item*) malloc(sizeof(item));
    //ПОЛУЧЕНИЕ ИТЕРАТОРА ГОЛОВЫ СПИСКА
    iterator h;
    h.node = l->head;
    //ЕСЛИ СПИСОК ПУСТ
    if (l->head == 0) {
        printf("Список пуст\nДобавляемый элемент будет первым\n");
        l->head = (item*) malloc(sizeof(item));
        l->head->data= t;
        l->head->next = 0;
        l->size++;
        return;
    }
    //ЕСЛИ НОМЕР ИТЕРАТОРА "1"
    if (equal(i, &h))
    {
        res.node->data = t;
        res.node->next = l->head;
        l->head = res.node;
        l->size++;
        return;
    }
    //В ОСТАЛЬНЫХ СЛУЧАЯХ
    res.node->data = t;
    res.node->next = i->node;
    iterator p = prev(l, i);
    p.node->next = res.node;
    l->size++;
    return;
}

//УДАЛЕНИЕ
iterator delete(list* l, iterator* i) {
    iterator res = get_last(l);
    if (res.node == NULL) {
        return res;
    }

    iterator i_prev = prev(l, i);
    res.node = i->node->next;
    if (i_prev.node == NULL) {
        l->head = i->node->next;
    } else {
        i_prev.node->next = res.node;
    }
    l->size--;

    free(i->node);
    i->node = NULL;
    return res;
}

//ПОДСЧЕТ ДЛИНЫ СПИСКА
int size(const list* l) {
    return l->size;
}

void result_execution(list* l) {
    int list_len = size(l);
    int middle = list_len / 2;
    int first_int = 1;

    while(middle) {
        iterator first = search(l, &first_int);
        iterator last = get_last(l);
        insert(l, &first, last.node->data);
        delete(l, &last);
        middle--;
    }
}


int main()
{
    //СОЗДАНИЕ СПИСКА
    list l;
    create(&l);

    printf("Введите число:\n");
    printf("\"1\" - печать списка\n");
    printf("\"2\" - вставка нового элемента в список\n");
    printf("\"3\" - удаление элемента из списка\n");
    printf("\"4\" - подсчет длины списка\n");
    printf("\"5\" - поменять местами половины списка\n");
    printf("\"6\" - выход\n");
    char menu = 0;
    char t;
    int num;
    iterator i;

    while (menu != 54) {
        do { scanf("%c", &menu);}
        while (menu < 49 || menu > 54);
        
        
        //ПУНКТЫ МЕНЮ
        switch (menu) {
            case '1':
                print_list(&l);
                printf("\nВведите число:\n");
                printf("\"1\" - печать списка\n");
                printf("\"2\" - вставка нового элемента в список\n");
                printf("\"3\" - удаление элемента из списка\n");
                printf("\"4\" - подсчет длины списка\n");
                printf("\"5\" - поменять местами половины списка\n");
                printf("\"6\" - выход\n");
                break;
            case '2':
                t = getchar();
                printf("Введите литеру, которую хотите добавить: ");
                scanf("%c", &t);
                printf("Номер элемента, перед которым хотите добавить данные: ");
                scanf("%d", &num);
                //ПОИСК ИТЕРАТОРА ЭЛЕМЕНТА С ТАКИМ НОМЕРОМ
                i = search(&l, &num);
                insert(&l, &i, t);
                printf("\nВведите число:\n");
                printf("\"1\" - печать списка\n");
                printf("\"2\" - вставка нового элемента в список\n");
                printf("\"3\" - удаление элемента из списка\n");
                printf("\"4\" - подсчет длины списка\n");
                printf("\"5\" - поменять местами половины списка\n");
                printf("\"6\" - выход\n");
                break;
            case '3':

                printf("Введите элемент, который хотите удалить: ");
                scanf("%d", &num);
                i = search(&l, &num);
                delete(&l, &i);
                printf("\nВведите число:\n");
                printf("\"1\" - печать списка\n");
                printf("\"2\" - вставка нового элемента в список\n");
                printf("\"3\" - удаление элемента из списка\n");
                printf("\"4\" - подсчет длины списка\n");
                printf("\"5\" - поменять местами половины списка\n");
                printf("\"6\" - выход\n");
                break;
            case '4':
                printf("Длина списка: %d\n", size(&l));
                printf("\nВведите число:\n");
                printf("\"1\" - печать списка\n");
                printf("\"2\" - вставка нового элемента в список\n");
                printf("\"3\" - удаление элемента из списка\n");
                printf("\"4\" - подсчет длины списка\n");
                printf("\"5\" - поменять местами половины списка\n");
                printf("\"6\" - выход\n");
                break;
            case '5':
                result_execution(&l);
                printf("Задание выполнено, напечатайте список\n");
                printf("\nВведите число:\n");
                printf("\"1\" - печать списка\n");
                printf("\"2\" - вставка нового элемента в список\n");
                printf("\"3\" - удаление элемента из списка\n");
                printf("\"4\" - подсчет длины списка\n");
                printf("\"5\" - поменять местами половины списка\n");
                printf("\"6\" - выход\n");
                break;
            
        }
    }
    return 0;
}
