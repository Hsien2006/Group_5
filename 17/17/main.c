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