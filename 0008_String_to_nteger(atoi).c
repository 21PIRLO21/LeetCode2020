#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648


int myAtoi(char * str){
    int res = 0;
    while(*str == ' ')
        str++;

    int flag = 1;
    if(*str == '-'){
        flag = -1;
        str++;
    }    
    else if(*str == '+')
        str++;

    int dig, div = INT_MAX / 10;
    
    while(*str >= '0' && *str <= '9'){
        dig = *str - '0';
        
        if(res < div || (res == div && dig<8)){
            res = res * 10 + dig;
            str++;
        }
        else
            return (flag == 1 ? INT_MAX : INT_MIN);
    }
    return res * flag;
}