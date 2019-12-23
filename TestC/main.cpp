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
    bubbleSort(arr, 0, (int)arr.size());
    
    int i,n;
        printf("输入数字个数：\n");
        scanf("%d",&n);      //输入数字个数
        printf("输入%d个数:\n",n);
        for(int j=0;j<n;j++)    //用一个for循环来输入所有数字
            scanf("%d",&globalNum[j]) ;
        bubble_sort_reverse(globalNum,n);   //引用函数bubble_sort
        for (i=0;i<n-1;i++)   //输出传来的排序好的数组
            printf("%d ",globalNum[i]);   //这里这么写是因为有些题有格式要求(最后一个数后面不能有空格)
        printf("%d\n",globalNum[i]);

    
    return 0;
}

