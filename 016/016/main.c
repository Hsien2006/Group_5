printf("\n總金額: $%d\n", total);
printf("找零: $%d\n", change);
// 計算找零方式
for (int c = 0; c < 7; c++) {
    counts[c] = change / coins[c];  // 計算使用的硬幣數量
    change = change % coins[c];   // 剩下的金額
}

// 輸出結果
printf("\n找零方式\n");
printf("1000元紙鈔: %d 個\n", counts[0]);
printf("500元紙鈔: %d 個\n", counts[1]);
printf("100元紙鈔: %d 個\n", counts[2]);
printf("50元硬幣: %d 個\n", counts[3]);
printf("10元硬幣: %d 個\n", counts[4]);
printf("5元硬幣: %d 個\n", counts[5]);
printf("1元硬幣: %d 個\n", counts[6]);
    }