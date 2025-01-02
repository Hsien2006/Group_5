int sandwich_prices[] = { 118, 118, 103, 103 };
char* sandwich_names[] = { "�d�����L�`��", "�l�����L�`��", "�ޱ��`��", "�t���`��" }; 

int drink_prices[] = { 68, 48, 68, 48, 68, 48, 48, 48, 38, 73, 38, 38, 38, 38, 38 }; 
char* drink_names[] = { "�V���A��", "�i�i��", "�A����", "��������", "�����A��", "�f�c��", "�i��", "�f�c�V��",
                        "����", "�i�i�A��", "�L�}����", "Black Tea", "�V�ʥ���", "�V�ʯ�", "Milk Tea" }; 

OrderItem orders[MAX_ITEMS];
int order_count = 0; 
int total = 0; 

char need_f, need_d, continue_choice;

printf("�аݻݭn�`�פT���v��?(y/n): ");
scanf(" %c", &need_f);
if (need_f == 'Y' || need_f == 'y') {
    printf("�п�ܤ@���`�פT���v:\n");
    for (int i = 0; i < SANDWICH_COUNT; i++) {
        printf("%d. %s - $%d\n", i + 1, sandwich_names[i], sandwich_prices[i]);
    }
    do {
        int sandwich_choice, sandwich_quantity;

        printf("\n�п���`�פT���v (1-4): ");
        scanf("%d", &sandwich_choice);
        if (sandwich_choice < 1 || sandwich_choice > 4) {
            printf("��J���~�A�Э��s��J\n");
            continue;
        } 

        printf("�п�J�ƶq: ");
        scanf("%d", &sandwich_quantity);

        orders[order_count].price = sandwich_prices[sandwich_choice - 1];
        orders[order_count].quantity = sandwich_quantity;
        strcpy(orders[order_count].name, sandwich_names[sandwich_choice - 1]);
        order_count++;

        total += sandwich_prices[sandwich_choice - 1] * sandwich_quantity; 

        printf("\n�O�_�~�����`�פT���v�H(y/n): ");
        scanf(" %c", &continue_choice);
    } while (continue_choice == 'y' || continue_choice == 'Y'); 
}

printf("\n�аݻݭn���~��?(y/n): ");
scanf(" %c", &need_d);
if (need_d == 'Y' || need_d == 'y') {
    printf("\n�п�ܤ@�Ӷ��~:\n");
    for (int i = 0; i < DRINK_COUNT; i++) {
        printf("%d. %s - $%d\n", i + 1, drink_names[i], drink_prices[i]);
    }
    do {
        int drink_choice, drink_quantity, sweetness, temperature; 

        printf("\n�п�ܶ��~ (1-15): ");
        scanf("%d", &drink_choice);
        if (drink_choice < 1 || drink_choice > 15) {
            printf("��J���~�A�Э��s��J\n");
            continue;
        }

        printf("�п�J�ƶq: ");
        scanf("%d", &drink_quantity);

        printf("�п�ܶ��~���� (1. �L�}, 2. �b�}, 3. ���}): ");
        scanf("%d", &sweetness);
        if (sweetness < 1 || sweetness > 3) {
            printf("��J���~�A�Э��s��J\n");
            continue;
        }

        printf("�п�ܶ��~�ū� (1. �N, 2. ��): ");
        scanf("%d", &temperature);
        if (temperature < 1 || temperature > 2) {
            printf("��J���~�A�Э��s��J\n");
            continue;
        }

        orders[order_count].price = drink_prices[drink_choice - 1];
        orders[order_count].quantity = drink_quantity;
        orders[order_count].sweetness = sweetness;
        orders[order_count].temperature = temperature;
        strcpy(orders[order_count].name, drink_names[drink_choice - 1]); 
        order_count++;

        total += drink_prices[drink_choice - 1] * drink_quantity; 

        printf("\n�O�_�~���ܶ��~�H(y/n): ");
        scanf(" %c", &continue_choice);
    } while (continue_choice == 'y' || continue_choice == 'Y'); 
}

printf("�`���B: $%d\n", total);