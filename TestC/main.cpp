//
//  main.cpp
//  TestC
//
//  Created by eport2 on 2019/12/13.
//  Copyright © 2019 eport2. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <stdio.h>
#include <vector>

int globalNum[10000000];

void bubble_sort(int a[], int b){
    int i, j, tmp;
    for (int j = 0; j < b - 1; j++) {
        for (int i = 0; i < b - 1 - j; i++) {
            if (a[i] > a[i + 1]) {
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
            }
        }
    }
}

void bubble_sort_reverse(int a[], int b){
    int i, j, tmp;
    for (int j = 0; j < b - 1; j++) {
        for (int i = 0; i < b - 1 - j; i++) {
            if (a[i] < a[i + 1]) {
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
            }
        }
    }
}

void fast_sort(int left, int right){
        if(left>=right)  //如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了
            return ;
        int i=left;     //将区间记录下来
        int j=right;
        int key=globalNum[i];    //记录参考值
        while(i<j)   //控制在当组内寻找一遍
        {
            while(i<j&&key<=globalNum[j])   //而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升序还是降序）2，没有符合条件1的，并且i与j的大小没有反转
                j--;    //向前寻找
            globalNum[i]=globalNum[j];     //找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是a[left]，那么就是给key）
            while(i<j&&key>=globalNum[i])   //这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反
                i++;
            globalNum[j]=globalNum[i];
        }
        globalNum[i]=key;                  //当在当组内找完一遍以后就把中间数key回归
        fast_sort(left,i-1);     //最后用同样的方式对分出来的左边的小组进行同上的做法
        fast_sort(i+1,right);    //用同样的方式对分出来的右边的小组进行同上的做法
                                   //当然最后可能会出现很多分左右，直到每一组的i = j 为止
}

void fast_sort_reverse(int left,int right)
{
    if(left>=right)
        return ;
    int i=left;
    int j=right;
    int key=globalNum[i];
    while(i<j)
    {
        while(i<j&&key>=globalNum[j])   //顺序这里改
            j--;
        globalNum[i]=globalNum[j];
        while(i<j&&key<=globalNum[i])   //还有这里（不清楚怎么改可以对照上面升序的函数）
        i++;
        globalNum[j]=globalNum[i];
    }
    globalNum[i]=key;
    fast_sort_reverse(left,i-1);
    fast_sort_reverse(i+1,right);
}


void insert_sort(int a[], int b){
    int i, j, temp;
    for (int i = 1; i < b; i++) {
        temp = globalNum[i];
        j = i - 1;
        while (j >= 0 && temp < globalNum[j]) {
            globalNum[j + 1] = globalNum[j];
            j--;
        }
        globalNum[j+1] = temp;
    }
}

void select_sort(int a[], int b){
    int i, j, k, index;
    for (int i = 0; i < b - 1; i++) {
        k = i;
        for (int j = i + 1; j < b; j++) {
            if (a[j] < a[k]) {
                k = j;
            }
        }
        if (k != j) {
            index = a[i];
            a[i] = a[k];
            a[k] = index;
        }
    }
}

void println(std::string argc){
    std::cout << argc + "\n";
}

int getMax(const std::vector<int> &arr){
    int max = INT_MIN;
    for (auto tmp : arr) {
        if (tmp > max) {
            max = tmp;
        }
    }
    return max;
}

int println1(const char *format __restrict, ...){
     char buffer[1024] = {0};

    va_list args;

    va_start(args, format);

    vsnprintf(buffer,1024, format,args);

    va_end(args);

    return printf("%s\n", buffer);

//    return printf("%s", format);
}

int CheckWireLessConnectState(char *pSsid)
{
    FILE* fp;
    char buf[512] = {0};
    char command[300] = "iwconfig wlan0";
    int ret = -1;
    char str[100];
    memset(str, '\0', sizeof(str));
 
 
        if((fp = popen(command, "r")) != NULL)
        {
                if(fgets(buf, 128, fp) != NULL)
                {
                        char * q = strstr(buf, "ESSID:");
                        if (q == NULL)
                        {
                            pclose(fp);
                            return -1;
                        }
 
                        ret = 0;
                        sscanf(q, "ESSID:\"%[^\"]\"", str);
                }
                pclose(fp);
        }
 
    memcpy(pSsid, str, strlen(str));
 
    return ret;
}

void sweapNum(int *o, int *n){
    int t = *o;
    *o = *n;
    *n = t;
}

void bubbleSort(std::vector<int> &arr, int begin, int end){
    bool isLoop = true;
    for (int i = end; isLoop == true && i > begin; --i) {
        isLoop = false;
        int pint = arr[i];
        for (int j = begin + 1; j < i; ++j) {
            if (arr[j] < arr[j - 1]) {
                sweapNum(&arr[j], &arr[j - 1]);
                isLoop = true;
//                std::cout << arr[j] << " ";
                pint = arr[j];
            }
            
        }
        std::cout << pint << " ";
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
//    printf("Please Input .... :");
    println("Please Input .... :");
    std::string strinput;
    std::cin >> strinput;
    println(strinput);
    int intinput;
    std::cin >> intinput;
    switch (intinput) {
        case 4:
            println1("has inputed %d", intinput);
            break;
            
        default:
            println1("has inputed %d", intinput);
            break;
    }
    
      char ssid[100];
      memset(ssid, '\0', sizeof(ssid));
    
      CheckWireLessConnectState(ssid);
    
      printf("ssid=%s\n", ssid);
    std::vector<int> arr = std::vector<int>();
    arr.push_back(434343);
    arr.push_back(12);
    arr.push_back(123);
    arr.push_back(1555);
    arr.push_back(121);
    arr.push_back(87);
    arr.push_back(5);
    int max = getMax(arr);
    println1("max = %d", max);
    bubbleSort(arr, 0, (int)arr.size() - 1);
    
//    int i,n;
//        printf("输入数字个数：\n");
//        scanf("%d",&n);      //输入数字个数
//        printf("输入%d个数:\n",n);
//        for(int j=0;j<n;j++)    //用一个for循环来输入所有数字
//            scanf("%d",&globalNum[j]) ;
//        insert_sort(globalNum,n);   //引用函数bubble_sort
//        for (i=0;i<n-1;i++)   //输出传来的排序好的数组
//            printf("%d ",globalNum[i]);   //这里这么写是因为有些题有格式要求(最后一个数后面不能有空格)
//        printf("%d\n",globalNum[i]);
    
    
    int n,m,i,choice;
        printf("快速排序小程序(By STY)\n\n");
        printf("升序还是降序\n");
        printf("升序选“1 ”\n");
        printf("降序选“2 ”\n");
        printf("请输入:(1~2)\n");
        printf("退出请按“Ctrl+Z ”(在键盘上)，并按回车，谢谢使用！\n");
        while(scanf("%d",&choice)!=EOF)
        {
            memset(globalNum,0,sizeof(globalNum));    //清空数组
            printf("请输入要排序的数字个数:\n");
            scanf("%d",&n);
            printf("请输入%d个数字:\n",n);
            if(choice==1)
            {
                for(int ii=0;ii<n;ii++)
                    scanf("%d",&globalNum[ii]);
                fast_sort(0,n);    //引用函数
                printf("结果：\n");
                for(i=1;i<n;i++)      //循环输出
                    printf("%d ",globalNum[i]);
                printf("%d(升序)\n\n\n\n",globalNum[i]);
            }
            else if(choice==2)
            {
                for(int ii=0;ii<n;ii++)
                    scanf("%d",&globalNum[ii]);
                fast_sort_reverse(0,n);
                printf("结果：\n");
                for(i=0;i<n-1;i++)
                    printf("%d ",globalNum[i]);
                printf("%d(降序)\n\n\n\n",globalNum[i]);
            }
            else
                printf("开玩笑吧!\n");

            printf("快速排序小程序(By STY)\n\n");
            printf("升序还是降序\n");
            printf("升序选“1”\n");
            printf("降序选“2”\n");
            printf("请输入:(1~2)\n");
            printf("退出请按“Ctrl+Z”(在键盘上)，并按回车，谢谢使用！\n");
        }

    
    return 0;
}

