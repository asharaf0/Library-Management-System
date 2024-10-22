#include <stdio.h>
#include <string.h>

// Structure to represent a book
struct Book {
    char title[50];
    char author[50];
    int isIssued;
};

// Array of books to simulate the library's book collection
struct Book library[100];
int bookCount = 0;

// Function to add a book to the library
void addBook() {
    printf("Enter the title of the book: ");
    scanf(" %[^\n]", library[bookCount].title);  // Read input with spaces
    printf("Enter the author of the book: ");
    scanf(" %[^\n]", library[bookCount].author);
    library[bookCount].isIssued = 0;
    bookCount++;
    printf("Book added successfully!\n\n");
}

// Function to list all books in the library
void booksList() {
    if (bookCount == 0) {
        printf("No books available in the library.\n\n");
    } else {
        printf("Books available in the library:\n");
        for (int i = 0; i < bookCount; i++) {
            printf("%d. %s by %s - %s\n", i + 1, library[i].title, library[i].author, 
                   library[i].isIssued ? "Issued" : "Available");
        }
        printf("\n");
    }
}

// Function to remove a book from the library
void removeBook() {
    int index;
    booksList();
    if (bookCount == 0) return;
    printf("Enter the book number to remove: ");
    scanf("%d", &index);
    if (index > 0 && index <= bookCount) {
        for (int i = index - 1; i < bookCount - 1; i++) {
            library[i] = library[i + 1];
        }
        bookCount--;
        printf("Book removed successfully!\n\n");
    } else {
        printf("Invalid book number.\n\n");
    }
}

// Function to issue a book from the library
void issueBook() {
    int index;
    booksList();
    if (bookCount == 0) return;
    printf("Enter the book number to issue: ");
    scanf("%d", &index);
    if (index > 0 && index <= bookCount) {
        if (!library[index - 1].isIssued) {
            library[index - 1].isIssued = 1;
            printf("Book issued successfully!\n\n");
        } else {
            printf("Book is already issued.\n\n");
        }
    } else {
        printf("Invalid book number.\n\n");
    }
}

// Function to list all issued books
void issuedBooksList() {
    int issuedCount = 0;
    printf("Issued books:\n");
    for (int i = 0; i < bookCount; i++) {
        if (library[i].isIssued) {
            printf("%d. %s by %s\n", i + 1, library[i].title, library[i].author);
            issuedCount++;
        }
    }
    if (issuedCount == 0) {
        printf("No books have been issued.\n\n");
    }
    printf("\n");
}

// Main function to display the menu and handle user choices
int main() {
    int choice;
    
    do {
        printf("<== Library Management System ==>\n");
        printf("1. Add Book\n");
        printf("2. Books List\n");
        printf("3. Remove Book\n");
        printf("4. Issue Book\n");
        printf("5. Issued Book List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                booksList();
                break;
            case 3:
                removeBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                issuedBooksList();
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    } while (choice != 0);
    
    return 0;
}
