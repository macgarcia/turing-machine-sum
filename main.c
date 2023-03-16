#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START_TAPE 50
#define SIZE_WORD 100

void get_input(char* input) {
    int char_count = 0;
    char tmp[SIZE_WORD];
    printf("Input the binary number: ");
    gets(tmp);

    //Count of characters
    for (int c = 0; c < SIZE_WORD; c++) {
        if (tmp[c] != '\0') {
            char_count++;
        } else {
            break;
        }
    }

    //Put all information on middle of tape
    for (int i = 0; i < char_count; i++) {
        input[START_TAPE + i] = tmp[i];
    }
}

//Find the end of information(number)
//Returning this point
int search_null(char* input) {
    int i = START_TAPE;
    int controller = 1;
    while(controller) {
        if (input[i] != '\0') {
            i++;
        } else {
            controller = 0;
        }
    }
    return i;
}

void print_input(char* input, int index_start) {
    int i = index_start < START_TAPE ? index_start : START_TAPE;
    int controller = 1;
    while(controller) {
        if (input[i] != '\0') {
            printf("%c", input[i]);
        } else {
            controller = 0;
        }
        i++;
    }
}

//Sum: add one more to the number
int sum(char* input, int point_null) {
    int i = 0;
    for (i = point_null - 1; ;i--) {
        if (input[i] == '1') {
            input[i] = '0';
        } else if (input[i] == '0' || input[i] == '\0') {
            input[i] = '1';
            break;
        }
    }
    return i;
}

int main() {
    char input[SIZE_WORD];
    get_input(input);
    int point_null = search_null(input);
    int index_start = sum(input, point_null);
    print_input(input, index_start);
    return 0;
}
