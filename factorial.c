#include <stdio.h>

int fact(int num){
    if(num==0 || num==1){
        return 1;
    }
    
    return (num*fact(num-1));
}

int main() {
    int num;
    
    printf("Enter the number of which you want factorial\n");
    scanf("%d", &num);
    int ans = fact(num);
    printf("%d\n", ans);
    return 0;
}