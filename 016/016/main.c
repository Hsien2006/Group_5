printf("\n�`���B: $%d\n", total);
printf("��s: $%d\n", change);
// �p���s�覡
for (int c = 0; c < 7; c++) {
    counts[c] = change / coins[c];  // �p��ϥΪ��w���ƶq
    change = change % coins[c];   // �ѤU�����B
}

// ��X���G
printf("\n��s�覡\n");
printf("1000���ȶr: %d ��\n", counts[0]);
printf("500���ȶr: %d ��\n", counts[1]);
printf("100���ȶr: %d ��\n", counts[2]);
printf("50���w��: %d ��\n", counts[3]);
printf("10���w��: %d ��\n", counts[4]);
printf("5���w��: %d ��\n", counts[5]);
printf("1���w��: %d ��\n", counts[6]);
    }