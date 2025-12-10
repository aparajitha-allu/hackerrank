#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
     char s[10000];
    int freq[10] = {0}; // frequency of digits 0 to 9
    
    scanf("%s", s);
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            freq[s[i] - '0']++; // convert char digit to index
        }
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", freq[i]);
    }

    return 0;
   
}
