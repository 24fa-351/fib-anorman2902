#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibonacci_iterative(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    int fib_num1 = 0;
    int fib_num2 = 1;
    int next;
    for (int i = 2; i < n; i++) {
        next = fib_num1 + fib_num2;
        fib_num1 = fib_num2;
        fib_num2 = next;
    }
    return fib_num2;
}

int fibonacci_recursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 0;
    if (n == 2) return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <integer> <r|i> <file_name>\n", argv[0]);
        return 1;
    }

    int num;
    if (sscanf(argv[1], "%d", &num) != 1) {
        fprintf(stderr, "Error: First argument must be an integer.\n");
        return 1;
    }

    char method = argv[2][0];
    char *filename = argv[3];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int file_num;
    if (fscanf(file, "%d", &file_num) != 1) {
        fprintf(stderr, "Error reading integer from file\n");
        fclose(file);
        return 1;
    }
    fclose(file);

    int n = num + file_num; // calculation off by one!
    int result;

    if (method == 'i') {
        result = fibonacci_iterative(n);
    } else if (method == 'r') {
        result = fibonacci_recursive(n);
    } else {
        fprintf(stderr, "Invalid method. Use 'r' for recursive or 'i' for iterative.\n");
        return 1;
    }

    printf("%d\n", result);
    return 0;
}
