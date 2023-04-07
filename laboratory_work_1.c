#include  <stdio.h >
#include <string.h>
#include <locale.h>
#include <time.h>


int main(){
    setlocale(LC_ALL, "Rus"); /*включаем русский язык, потому что мы русские программисты*/

    int flag = 0, num, show, len;

    /*Генерируем массив случайных чисел размером len*/
    printf("Введите кол-во элементов в списке 100-200-500-1000: ");
    scanf("%d",&len);

    int n = len;
    int a[n];
    int i;

    for(i=0;i<n;i++){
        a[i]=rand()%100;
    }

    /*Выводим массив на экран*/
    printf("1 -> показать массив");
    printf("\n2 -> не показывать массив");
    printf("\nВыберите: ");
    scanf("%d",&show);

    if (show == 1){
        printf("Сгенерированный массив: ");
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
    }

    while (flag == 0){
        printf("\n\nСписок возможных комманд:");
        printf("\n1 -> Сортировка массива выбором");
        printf("\n2 -> Сортировка массива вставками");
        printf("\n3 -> Найти число в массиве при помощи бинарного поиска (предварительно проведена сортировка)");
        printf("\n4 -> Выйти из программы");
        printf("\nВведите команду: ");
        scanf("%d",&num);


        if (num == 1){
            double time = 0.0;

            /*Время начала*/
            clock_t begin = clock();

            sorting_by_selection(a,n);

            /*Время окончания*/
            clock_t end = clock();
            time += (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nВремя затраченное на метод сортировки выбором для %d элементов составляет %f секунд", n, time);

            /*Выводим отсортированный массив на экран*/
            printf("\n1 -> показать массив");
            printf("\n2 -> не показывать массив");
            printf("\nВыберите: ");
            scanf("%d",&show);

            if (show == 1){
                printf("Массив, отсортированный выбором: ");
                for(i=0; i<n; i++){
                    printf("%d ",a[i]);
                }
            }

            continue;
        }


        if (num == 2){
            double time = 0.0;

            /*Время начала*/
            clock_t begin = clock();

            sorting_by_inserts(a,n);

            /*Время окончания*/
            clock_t end = clock();
            time += (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nВремя затраченное на метод сортировки вставками для %d элементов составляет %f секунд", n, time);

            /*Выводим отсортированный массив на экран*/
            printf("\n1 -> показать массив");
            printf("\n2 -> не показывать массив");
            printf("\nВыберите: ");
            scanf("%d",&show);

            if (show == 1){
                printf("Массив, отсортированный вставками: ");
                for(i=0; i<n; i++){
                    printf("%d ",a[i]);
                }
            }

            continue;
        }


        if (num == 3){
            int search_element;
            printf("Введите элемент для поиска (от 1 до 100):");
            scanf("%d",&search_element);

            int index;
            index = binary_search(search_element, a, n);

            if (index != -1){
                printf("Элемент %d найден, индекс элемента - %d", search_element, index);
            }
            else{
                printf("Элемент %d не найден!", search_element);
            }

            continue;
        }

        if (num == 4){
            break;
        }

    }
     return 0;
}

/*бинарный поиск*/
int binary_search(int search_element, int a[], int n){
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high){
        middle = (low + high) / 2;
        if (search_element < a[middle])
            high = middle - 1;
        else if (search_element > a[middle])
            low = middle + 1;
        else
            return middle;
    }
    return -1;
}

/*Сортировка вставками*/
void sorting_by_inserts(int a[],int n){
    int el;
    int i;

    for (i = 1; i < n; i++){
        el = a[i];
        while ( (i - 1) >= 0 && a[i - 1] > el){
            a[i] = a[i - 1];
            i = i - 1;
        }
        a[i] = el;
    }
}

/*Сортировка выбором*/
void sorting_by_selection(int a[],int n){
    int x,y;
    int min;
    int save;

    for (x = 0; x < n - 1; x++){
        min = x;
        for (y = x + 1; y < n; y++){
            if(a[y] < a[min]){
                min = y;
            }
        }
        save = a[x];
        a[x] = a[min];
        a[min] = save;
    }
}
