#include<stdio.h>
#include<stdlib.h>

int global1 = 1;
int global2 = 1;
int global3 = 1;

void rec(int stack) {

    int x = stack;;

    printf("stack[%d]  = %p\n",stack + 1, &x);

    // Base case to stop recursion
    if (stack < 2) {
        rec(stack + 1); // Call the function recursively
    }
}

int main(){
    char *heap[3];
    for(int i = 0; i < 3; i++){
        heap[i] = malloc(sizeof(int));
    }

    printf("global \n");
        printf("global[1] = %p\n", &global1);
        printf("global[2] = %p\n", &global2);
        printf("global[3] = %p\n", &global3);
    printf("------------------------------- \n");
    printf("stack \n");
        rec(0);
    printf("------------------------------- \n");
    printf("heap \n");
    for(int i = 0; i < 3; i++) {
        *heap[i] = i;
        printf("heap[%d]   = %p\n", i + 1, heap[i]);
    }

    for(int i = 0; i < 3; i++) {
        free(heap[i]);
    }

    return 0;
}