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
    printf("請輸入支付金額: $");
    scanf("%d", &money_given); change = money_given - total;

    if (change < 0) {
        printf("支付金額不足，請增加支付金額。\n");
        goto back;
    }
    else {
      
        printf("\n訂單明細:\n");
        for (int i = 0; i < order_count; i++) {
            if (orders[i].sweetness > 0) {
                printf("飲品: %s x %d, 甜度: %s, 溫度: %s\n",
                    orders[i].name,
                    orders[i].quantity,
                    orders[i].sweetness == 1 ? "無糖" : orders[i].sweetness == 2 ? "半糖" : "全糖",
                    orders[i].temperature == 1 ? "冷" : "熱");
            }
            else {
                printf("三明治: %s x %d\n", orders[i].name, orders[i].quantity);
            }
        }

       
    }