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

int coins[] = { 1000 , 500 , 100 , 50, 10, 5, 1 }; 
int counts[7] = { 0 }; 

int main() {
    int sandwich_prices[] = { 118, 118, 103, 103 }; 
    char* sandwich_names[] = { "卡拉雞腿總匯", "勁辣雞腿總匯", "豬排總匯", "燻雞總匯" }; 

    int drink_prices[] = { 68, 48, 68, 48, 68, 48, 48, 48, 38, 73, 38, 38, 38, 38, 38 }; 
    char* drink_names[] = { "冬瓜鮮奶", "可可亞", "鮮奶茶", "紅茶豆漿", "豆漿鮮奶", "檸檬紅", "可樂", "檸檬冬瓜",
                            "豆漿", "可可鮮奶", "無糖豆漿", "Black Tea", "冬瓜奶茶", "冬瓜茶", "Milk Tea" }; 

    OrderItem orders[MAX_ITEMS]; 
    int order_count = 0; 
    int total = 0; 

    char need_f, need_d, continue_choice; 

    printf("請問需要總匯三明治嗎?(y/n): ");
    scanf(" %c", &need_f);
    if (need_f == 'Y' || need_f == 'y') {
        printf("請選擇一個總匯三明治:\n");
        for (int i = 0; i < SANDWICH_COUNT; i++) {
            printf("%d. %s - $%d\n", i + 1, sandwich_names[i], sandwich_prices[i]);
        }
        do {
            int sandwich_choice, sandwich_quantity; 

            printf("\n請選擇總匯三明治 (1-4): ");
            scanf("%d", &sandwich_choice);
            if (sandwich_choice < 1 || sandwich_choice > 4) {
                printf("輸入錯誤，請重新輸入\n");
                continue;
            } 

            printf("請輸入數量: ");
            scanf("%d", &sandwich_quantity);

            orders[order_count].price = sandwich_prices[sandwich_choice - 1];
            orders[order_count].quantity = sandwich_quantity;
            strcpy(orders[order_count].name, sandwich_names[sandwich_choice - 1]); 
            order_count++; 

            total += sandwich_prices[sandwich_choice - 1] * sandwich_quantity;

            printf("\n是否繼續選擇總匯三明治？(y/n): ");
            scanf(" %c", &continue_choice);
        } while (continue_choice == 'y' || continue_choice == 'Y'); 
    }

    printf("\n請問需要飲品嗎?(y/n): ");
    scanf(" %c", &need_d);
    if (need_d == 'Y' || need_d == 'y') {
        printf("\n請選擇一個飲品:\n");
        for (int i = 0; i < DRINK_COUNT; i++) {
            printf("%d. %s - $%d\n", i + 1, drink_names[i], drink_prices[i]);
        } 
        do {
            int drink_choice, drink_quantity, sweetness, temperature; 

            printf("\n請選擇飲品 (1-15): ");
            scanf("%d", &drink_choice);
            if (drink_choice < 1 || drink_choice > 15) {
                printf("輸入錯誤，請重新輸入\n");
                continue;
            } 

            printf("請輸入數量: ");
            scanf("%d", &drink_quantity);

            printf("請選擇飲品甜度 (1. 無糖, 2. 半糖, 3. 全糖): ");
            scanf("%d", &sweetness);
            if (sweetness < 1 || sweetness > 3) {
                printf("輸入錯誤，請重新輸入\n");
                continue;
            } 

            printf("請選擇飲品溫度 (1. 冷, 2. 熱): ");
            scanf("%d", &temperature);
            if (temperature < 1 || temperature > 2) {
                printf("輸入錯誤，請重新輸入\n");
                continue;
            } 

            orders[order_count].price = drink_prices[drink_choice - 1];
            orders[order_count].quantity = drink_quantity;
            orders[order_count].sweetness = sweetness;
            orders[order_count].temperature = temperature;
            strcpy(orders[order_count].name, drink_names[drink_choice - 1]); 
            order_count++; 

            total += drink_prices[drink_choice - 1] * drink_quantity; 

            printf("\n是否繼續選擇飲品？(y/n): ");
            scanf(" %c", &continue_choice);
        } while (continue_choice == 'y' || continue_choice == 'Y'); 
    }

    printf("總金額: $%d\n", total);

    int money_given, change; 
back: !
    printf("請輸入支付金額: $");
    scanf("%d", &money_given);

    change = money_given - total; 

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

        printf("\n總金額: $%d\n", total);
        printf("找零: $%d\n", change);
        for (int c = 0; c < 7; c++) {
            counts[c] = change / coins[c];
            change = change % coins[c];
        } 

        printf("\n找零方式\n");
        printf("1000元紙鈔: %d 個\n", counts[0]);
        printf("500元紙鈔: %d 個\n", counts[1]);
        printf("100元紙鈔: %d 個\n", counts[2]);
        printf("50元硬幣: %d 個\n", counts[3]);
        printf("10元硬幣: %d 個\n", counts[4]);
        printf("5元硬幣: %d 個\n", counts[5]);
        printf("1元硬幣: %d 個\n\n", counts[6]);
    }
    system("pause");
    return 0;
}