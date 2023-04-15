#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct node
{
    int item;
    struct node *next;
};

struct node *head=NULL,*id = NULL;

int main()
{
    setlocale(LC_ALL, "Rus"); /*включаем русский язык, потому что мы русские программисты*/

    int flag = 0, num;

    while (flag == 0){
        printf("\n\nСписок возможных команд:");
        printf("\n1 -> Добавить первый элемент односвязного списка");
        printf("\n2 -> Добавить элемент в конец односвязного списка");
        printf("\n3 -> Удалить элемент с конца односвязного списка");
        printf("\n4 -> Поcмотреть односвязный список");
        printf("\n5 -> Удалить всесь односвязный список");
        printf("\n6 -> Выполнить последовательный поиск заданного элемента в односвязном списке");
        printf("\n7 -> Выйти из программы");
        printf("\nВведите команду: ");

        int result;

        result = scanf("%d",&num);
        getchar();

        if (result != 1){
            printf("Неверное введенное значение!");
            result = 0;
            while(getchar() != '\n');
            continue;
        }

        if (num == 1){
            begin();
            continue;
        }

        if (num == 2){
            add();
            continue;
        }

        if (num == 3){
            delete_el();
            continue;
        }

        if (num == 4){
            display_list();
            continue;
        }

        if (num == 5){
            clear();
            continue;
        }

        if (num == 6){
            find();
            continue;
        }

        if (num==7){
            break;
        }

        else{
            printf("Неверное введенное значение!");
            continue;
        }
    }
    return 0;
}

/* Добавить первый элемент односвязного списка */
void begin(){
    struct node *a;
    int value;
    a = (struct node *) malloc(sizeof(struct node *));
    if(a == NULL){
        printf("\nПереполнение!");
        return;
    }
    else{
        printf("\nВведите нужный элемент: ");

        int result;
        result = scanf("%d",&value);
        getchar();

        if (result != 1){
            printf("Неверное введенное значение!");
            result = 0;
            while(getchar() != '\n');
            return;
        }
        else{
            a->item = value;
            a->next = head;
            head = a;
            printf("Элемент добавлен!");
        }
    }
}


/* Поcмотреть односвязный список*/
void display_list(){
    struct node *a;
    a = head;
    if(a == NULL){
        printf("\nПустой список");
        return;
    }
    else{
        printf("\nВсе элементы списка:");
        printf("\nstart -> ");
        while (a!=NULL){
            printf("%d -> ",a->item);
            a = a -> next;
        }
        puts("end");
    }
}

/* Удалить элемент с конца односвязного списка*/
void delete_el(){
    struct node *a,*b;
    if(head == NULL){
        printf("\nПустой список");
    }
    else if(head -> next == NULL){
        head = NULL;
        printf("\nУдален: %d\n", head->item);
        free(head);
    }
    else{
        a = head;
        while(a->next != NULL){
            b = a;
            a = a -> next;
        }
        b -> next = NULL;
        printf("\nУдален: %d\n",a -> item);
        free(a);
    }
}

/* Добавить элемент в конец односвязного списка*/
void add(){
    struct node *a,*b;
    int value;
    a = (struct node*)malloc(sizeof(struct node));
    if(a == NULL){
        printf("\nПереполнение!");
        return;
    }
    else{
        printf("\nВведите нужный элемент: ");

        int result;
        result = scanf("%d",&value);
        getchar();

        if (result != 1){
            printf("Неверное введенное значение!");
            result = 0;
            while(getchar() != '\n');
            return;
        }
        else{
            a->item = value;
            if(head == NULL){
                a -> next = NULL;
                head = a;
                printf("Элемент добавлен!");
            }
            else{
                b = head;
                while (b -> next != NULL){
                    b = b -> next;
                }
                b->next = a;
                a->next = NULL;
                printf("Элемент добавлен!");
            }
        }
    }
}

/* Удалить всесь односвязный список */
void clear(){
    struct node *a,*b;
    a = head->next;
    while(a){
        b = a -> next;
        free(a);
        a = b;
    }
    free(b);
    free(head);

    printf("\nГотово!");
}

/* Выполнить последовательный поиск заданного элемента в односвязном списке*/
void find(){
    struct node *a;
    int value,i=0,flag;
    a = head;
    if(a == NULL){
        printf("\nПустой список");
        return;
    }
    else{
        printf("\nВведите элемент для поиска: ");

        int result;
        result = scanf("%d",&value);
        getchar();

        if (result != 1){
            printf("Неверное введенное значение!");
            result = 0;
            while(getchar() != '\n');
            return;
        }
        else{
            while (a!=NULL){
                if(a->item == value){
                    printf("Элемент на позиции %d\n",i+1);
                    flag=0;
                }
                else{
                    flag=1;
                }
                i++;
                a = a -> next;
            }
        }
        if(flag==1){
            printf("\nЭлемент не найден!");
        }
    }
}
