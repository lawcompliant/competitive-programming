// tc O(n*m)
#include <stdio.h>

int remaining_milk(int N, int M, char *direction, int capacities[]) {
    int milk[N];
    for (int i = 0; i < N; i++) {
        milk[i] = capacities[i];
    }

    for (int m = 0; m < M; m++) {
        int temp_milk[N];
        for (int i = 0; i < N; i++) {
            temp_milk[i] = 0;
        }

        for (int i = 0; i < N; i++) {
            if (milk[i] > 0) {
                if (direction[i] == 'L') {
                    temp_milk[i] -= 1;
                    temp_milk[(i - 1 + N) % N] += 1;
                } else {
                    temp_milk[i] -= 1;
                    temp_milk[(i + 1) % N] += 1;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            milk[i] += temp_milk[i];
            if (milk[i] > capacities[i]) {
                milk[i] = capacities[i];
            }
        }
    }

    int total_remaining = 0;
    for (int i = 0; i < N; i++) {
        total_remaining += milk[i];
    }
    return total_remaining;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    char direction[N + 1];
    scanf("%s", direction);
    int capacities[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &capacities[i]);
    }

    int result = remaining_milk(N, M, direction, capacities);
    printf("%d\n", result);

    return 0;
}
