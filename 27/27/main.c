#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define SANDWICH_COUNT 4
#define DRINK_COUNT 14


typedef struct {
    char name[100];
    int quantity;
    int price;
    int sweetness;
    int temperature;
} OrderItem;

int main() {
   
    int money_given, change;
back:
    printf("�п�J��I���B: $");
    scanf("%d", &money_given); change = money_given - total;

    if (change < 0) {
        printf("��I���B�����A�мW�[��I���B�C\n");
        goto back;
    }
    else {
      
        printf("\n�q�����:\n");
        for (int i = 0; i < order_count; i++) {
            if (orders[i].sweetness > 0) {
                printf("���~: %s x %d, ����: %s, �ū�: %s\n",
                    orders[i].name,
                    orders[i].quantity,
                    orders[i].sweetness == 1 ? "�L�}" : orders[i].sweetness == 2 ? "�b�}" : "���}",
                    orders[i].temperature == 1 ? "�N" : "��");
            }
            else {
                printf("�T���v: %s x %d\n", orders[i].name, orders[i].quantity);
            }
        }

       
    }