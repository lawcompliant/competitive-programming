#include <stdio.h>
#include <stdbool.h>

bool is_palindrome(int n) {
    int reverse = 0;
    int original = n;
    
    while (n != 0) {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }
    
    return original == reverse;
}

char who_wins(int S) {
    if (is_palindrome(S)) {
        return 'B';
    } else if (S % 10 != 0) {
        return 'B';
    } else {
        return 'E';
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int S;
        scanf("%d", &S);
        printf("%c\n", who_wins(S));
    }

    return 0;
}
