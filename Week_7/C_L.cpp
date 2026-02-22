#include <stdio.h>

#define SIZE 5


int LQ[SIZE];
int lfront = -1, lrear = -1;

int L_isEmpty() {
    return (lfront == -1);
}

int L_isFull() {
    return (lrear == SIZE - 1);
}


void L_display() {
    if (L_isEmpty()) {
        printf("Linear Queue is EMPTY\n");
        return;
    }
    printf("Linear Queue: ");
    for (int i = lfront; i <= lrear; i++) {
        printf("%d ", LQ[i]);
    }
    printf("\n");
}


void L_enqueue(int x) {
    if (L_isFull()) {
        printf("Linear Queue is FULL\n");
        return;
    }
    if (L_isEmpty()) lfront = 0;
    lrear++;
    LQ[lrear] = x;
    printf("%d enqueued (Linear)\n", x);
    L_display();
}


void L_dequeue() {
    if (L_isEmpty()) {
        printf("Linear Queue is EMPTY\n");
        return;
    }
    printf("Deleted (Linear): %d\n", LQ[lfront]);

    if (lfront == lrear) { 
        lfront = lrear = -1;
    } else {
        lfront++;
    }
    L_display();
}


void L_peek() {
    if (L_isEmpty()) {
        printf("Linear Queue is EMPTY\n");
        return;
    }
    printf("Front (Linear): %d\n", LQ[lfront]);
}


int CQ[SIZE];
int cfront = -1, crear = -1;

int C_isEmpty() {
    return (cfront == -1);
}

int C_isFull() {
    return ((crear + 1) % SIZE == cfront);
}


void C_display() {
    if (C_isEmpty()) {
        printf("Circular Queue is EMPTY\n");
        return;
    }
    printf("Circular Queue: ");
    int i = cfront;
    while (1) {
        printf("%d ", CQ[i]);
        if (i == crear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}


void C_enqueue(int x) {
    if (C_isFull()) {
        printf("Circular Queue is FULL\n");
        return;
    }

    if (C_isEmpty()) {
        cfront = crear = 0;
    } else {
        crear = (crear + 1) % SIZE;
    }

    CQ[crear] = x;
    printf("%d enqueued (Circular)\n", x);
    C_display();
}


void C_dequeue() {
    if (C_isEmpty()) {
        printf("Circular Queue is EMPTY\n");
        return;
    }

    printf("Deleted (Circular): %d\n", CQ[cfront]);

    if (cfront == crear) { 
        cfront = crear = -1;
    } else {
        cfront = (cfront + 1) % SIZE;
    }
    C_display();
}


void C_peek() {
    if (C_isEmpty()) {
        printf("Circular Queue is EMPTY\n");
        return;
    }
    printf("Front (Circular): %d\n", CQ[cfront]);
}

int main() {
    int choice, x;

    while (1) {
        printf("\n===== QUEUE ASSIGNMENT MENU =====\n");
        printf("---- Linear Queue ----\n");
        printf("1. Enqueue (Linear)\n");
        printf("2. Dequeue (Linear)\n");
        printf("3. Peek (Linear)\n");
        printf("4. Display (Linear)\n");
        printf("5. IsEmpty (Linear)\n");
        printf("6. IsFull (Linear)\n");

        printf("\n---- Circular Queue ----\n");
        printf("7. Enqueue (Circular)\n");
        printf("8. Dequeue (Circular)\n");
        printf("9. Peek (Circular)\n");
        printf("10. Display (Circular)\n");
        printf("11. IsEmpty (Circular)\n");
        printf("12. IsFull (Circular)\n");

        printf("\n13. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            /* Linear Queue */
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                L_enqueue(x);
                break;
            case 2:
                L_dequeue();
                break;
            case 3:
                L_peek();
                break;
            case 4:
                L_display();
                break;
            case 5:
                printf(L_isEmpty() ? "Linear Queue is EMPTY\n" : "Linear Queue is NOT empty\n");
                break;
            case 6:
                printf(L_isFull() ? "Linear Queue is FULL\n" : "Linear Queue is NOT full\n");
                break;

            /* Circular Queue */
            case 7:
                printf("Enter element: ");
                scanf("%d", &x);
                C_enqueue(x);
                break;
            case 8:
                C_dequeue();
                break;
            case 9:
                C_peek();
                break;
            case 10:
                C_display();
                break;
            case 11:
                printf(C_isEmpty() ? "Circular Queue is EMPTY\n" : "Circular Queue is NOT empty\n");
                break;
            case 12:
                printf(C_isFull() ? "Circular Queue is FULL\n" : "Circular Queue is NOT full\n");
                break;

            case 13:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}