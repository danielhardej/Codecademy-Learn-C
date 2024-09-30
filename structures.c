#include <stdio.h>

// Write your code below
struct Table {
    int length;
    int width;
    int height;
    char* color[20];
    // char* colorPtr;
};

int main(void) {
    int table1Length = 24;
    int table1Width = 24;
    int table1Height = 20;
    char table1Color[20] = "Dark Brown";
    // char* table1ColorPtr = table1Color;

    int table2Length = 42;
    int table2Width = 18;
    int table2Height = 32;
    char table2Color[20] = "Matte Black";
    // char* table2ColorPtr = table2Color;

    // Write your code below
    struct Table table1 = {table1Length, table1Width, table1Height, table1Color};
    struct Table table2 = {table2Length, table2Width, table2Height, table2Color};

    // print table 1 properties
    printf("Table 1 len: %i\n", table1.length);
    printf("Table 1 width: %i\n", table1.width);
    printf("Table 1 height: %i\n", table1.height);
    printf("Table 1 color: %s\n", *table1.color);
    // printf("Table 1 colorPtr: %p\n", table1.colorPtr);

    // print table 2 properties
    printf("Table 2 len: %i\n", table2.length);
    printf("Table 2 width: %i\n", table2.width);
    printf("Table 2 height: %i\n", table2.height);
    printf("Table 2 color: %s\n", *table2.color);
    // printf("Table 2 colorPtr: %p\n", table2.colorPtr);

    return 0;
  
}