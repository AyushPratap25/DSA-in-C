/* Library Management (using Structures) */
#include <stdio.h>
#define SIZE 2

// struct for the libray_management
struct lib_book
{
    int id;
    char title[50];
    char author[30];
    float price;
};


// function prototype 
void bookInput(struct lib_book b[SIZE]);
void bookDisplay(struct lib_book b[SIZE]);

int main()
{
    struct lib_book book[SIZE];
    // function call
    bookInput(book);
    bookDisplay(book);
    return 0;
}

// Book details input
// void
void bookInput(struct lib_book b[SIZE])
{
    printf("\n\n\t***Enter the book details***\n\n");
    // loop for SIZE book entry
    for (int i = 0; i < SIZE; i++)
    {
        // book details entry
        printf("\n\tEnter book_%d detail", i + 1);
        
        printf("\nId: ");
        scanf("%d", &b[i].id);    // id
        // Skip any whitespace characters (spaces, tabs, newlines) before reading the actual input.
        printf("\nTitle: ");
        scanf(" %[^\n]", b[i].title);  // title

        printf("\nAuthor: ");
        scanf(" %[^\n]", b[i].author); // author

        printf("\nPrice: ");
        scanf("%f", &b[i].price); // price
        // NOTE : Use "%[^\n]" (not "%[^\n]s") to read a full line with spaces.
    }
}

// Book details display
// void
void bookDisplay(struct lib_book b[SIZE])
{
    // printing book deatil in tabular format
    printf("\n\n\t***Book details***\n\n");
    printf("\n|%-5s|%-20s|%-20s|%-10s|\n", "ID", "Title", "Author", "Price");

    for (int i = 0; i < SIZE; i++)
    {
        printf("\n|%-5d|%-20s|%-20s|%-10.2f|\n", b[i].id, b[i].title, b[i].author, b[i].price);
    }
}

// Use "%[^\n]" (not "%[^\n]s") to read a full line with spaces.
// "%s" reads only one word (stops at space), but "%[^\n]" reads until newline.
