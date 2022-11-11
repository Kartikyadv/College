#include <stdio.h>

int main() {
    int temp, num, sum=0, digit;
    printf("Enter no.\n");
    scanf("%d", &num);
    temp = num;
    while(num>0){
        digit = num%10;
        sum = (sum*10)+digit;
        num = num/10;
    }
    if(temp == sum)
    printf("%d is palindrome\n", temp);
    
    else
    printf("%d is not palindrome\n", temp);    

    return 0;
}