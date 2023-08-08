/*Write a program take text file as an input and print word, character count and ascii value of
each characters as output.*/

#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    printf("Enter the file name: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file");
    }
    char ch;
    int count = 0;
    int word = 0;
    int ascii = 0;
    while (fscanf(file, "%c", &ch) != EOF) {
        if (ch == ' ' || ch == '\n') {
            word++;
        }
        count++;
        ascii = ch;
        printf("%c %d\n", ch, ascii);
    }
    printf("\nNumber of characters in file: %d\n", count);
    printf("\nNumber of words in file: %d\n", word);
    fclose(file);
    return 0;
}
