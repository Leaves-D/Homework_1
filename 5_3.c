#include <stdio.h>
#include <stdlib.h>

// 基准日期：2025年11月12日（周三）
int jizhun[4] = {2025, 11, 12, 3};  // 年,月,日,星期(周三)
int daipan[3];                      // 待判断的日期：年,月,日
int yue[12] = {31,28,31,30,31,30,31,31,30,31,30,31};  // 每月>天数(平年)

// 判断年份是否为闰年（返回366/365）
int panyear(int a) {
    if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) {
        return 366;  // 闰年
    }
    return 365;      // 平年
}

// 计算两个年份的11月12日之间的天数差（year2 - year1）
int gaponeyear(int year1, int year2) {
    int gap;
    // 若包含闰年，则两个11月12日之间有366天
    if (panyear(year1) == 366 || panyear(year2) == 366) {
        gap = 366;
    } else {
        gap = 365;
    }
    // 年份小的到年份大的为正差，反之为负差
    return (year1 < year2) ? gap : -gap;
}
// 计算待判断年份与基准年份的总天数差（基于11月12日）
int panricha_nian(int year) {
    int sum = 0;
    if (year > jizhun[0]) {  // 待判断年份在基准年份之后
        for (int i = jizhun[0]; i < year; i++) {
            sum += gaponeyear(i, i + 1);
        }
    } else if (year < jizhun[0]) {  // 待判断年份在基准年份之>前
        for (int i = jizhun[0]; i > year; i--) {
            sum += gaponeyear(i, i - 1);
        }
    }
    // 若年份相同，差为0
    return sum;
}

// 计算待判断月份和日期与当年11月12日的天数差
int panricha_yue(int year, int month, int day) {
    int days = 0;
    int is_leap = (panyear(year) == 366) ? 1 : 0;  // 是否为闰
年

    if (month == 11) {  // 11月内的差
        days = day - 12;
    } else if (month > 11) {  // 11月之后的月份（同一年）
        // 累加从12月到目标月份前一个月的天数
        for (int i = 11; i < month; i++) {
            // 2月特殊处理
            if (i == 1) days += 28 + is_leap;
            else days += yue[i];
        }
        days += day;  // 加目标日期的天数
    } else {  // 11月之前的月份（同一年）
        // 累加从目标月份到10月的天数
        for (int i = month; i < 11; i++) {
            if (i == 1) days += 28 + is_leap;
            else days += yue[i];
        }
        days = (day - 12) - days;  // 计算与11月12日的差
    }
    return days;
}

// 根据总天数差计算星期几（1-7对应周一到周日）
int panweek(int richa) {
    int base_week = jizhun[3];  // 基准星期（周三）
    int res = (base_week + richa) % 7;
    // 处理负数和0的情况（确保结果在1-7之间）
    if (res <= 0) res += 7;
    return res;
}

// 输出指定年月的日历
void print_month(int year, int month) {
    int is_leap = (panyear(year) == 366) ? 1 : 0;
    int days_in_month;  // 当月天数
   // 确定当月天数
    if (month == 1) {  // 2月
        days_in_month = 28 + is_leap;
    } else {
        days_in_month = yue[month];
    }

    // 计算当月1日是星期几
    daipan[0] = year;
    daipan[1] = month + 1;  // 注意：数组是0索引，实际月份需+1
    daipan[2] = 1;
    int nian_diff = panricha_nian(year);
    int yue_diff = panricha_yue(year, month + 1, 1);
    int total_diff = nian_diff + yue_diff;
    int first_week = panweek(total_diff);

    // 打印月份标题
    printf("\n======= %d年%d月 =======\n", year, month + 1);
    printf("一 二 三 四 五 六 日\n");

    // 打印月初空白（1日之前的位置）
    for (int i = 1; i < first_week; i++) {
        printf("   ");
    }

    // 打印日期
    for (int day = 1; day <= days_in_month; day++) {
        printf("%2d ", day);
        // 每周日换行
        if ((first_week + day - 1) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// 输出指定年份的完整日历
void print_year(int year) {
    printf("\n==================== %d年 万年历 ====================\n", year);
    for (int month = 0; month < 12; month++) {  // 0-11对应1-12月
        print_month(year, month);
    }
}

int main() {
    int choice;
    printf("======= 日历查询系统 =======\n");
    printf("1. 查询指定日期是星期几\n");
    printf("2. 查询指定年月的日历\n");
    printf("3. 查询指定年份的完整日历\n");
    printf("请输入功能编号: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // 功能1：查询指定日期的星期
        printf("请输入年 月 日(空格分隔): ");
        scanf("%d %d %d", &daipan[0], &daipan[1], &daipan[2]);
        // 计算总天数差
        int nian_diff = panricha_nian(daipan[0]);
        int yue_diff = panricha_yue(daipan[0], daipan[1], daipan[2]);
        int total_diff = nian_diff + yue_diff;

        // 计算并输出星期
        int week = panweek(total_diff);
        printf("%d年%d月%d日是星期", daipan[0], daipan[1], daipan[2]);
        switch(week) {
            case 1: printf("一"); break;
            case 2: printf("二"); break;
            case 3: printf("三"); break;
            case 4: printf("四"); break;
            case 5: printf("五"); break;
            case 6: printf("六"); break;
            case 7: printf("日"); break;
        }
        printf("\n");
    }
    else if (choice == 2) {
        // 功能2：查询指定年月的日历
        int year, month;
        printf("请输入年 月(空格分隔): ");
        scanf("%d %d", &year, &month);
        print_month(year, month - 1);  // 转为0索引
    }
    else if (choice == 3) {
        // 功能3：查询指定年份的完整日历
        int year;
        printf("请输入年份: ");
        scanf("%d", &year);
        print_year(year);
    }
    else {
        printf("无效的功能编号!\n");
    }

    return 0;
}
