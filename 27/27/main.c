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
    change = money_given - total;

    if (change < 0) {
        printf("��I���B�����A�мW�[��I���B�C\n");
        goto back;
    }
    else {
        // ��ܭq�����
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

        printf("\n�`���B: $%d\n", total);
        printf("��s: $%d\n", change);
        // �p���s�覡
        for (int c = 0; c < 7; c++) {
            counts[c] = change / coins[c];  // �p��ϥΪ��w���ƶq
            change = change % coins[c];   // �ѤU�����B
        }
        return 0;
    }