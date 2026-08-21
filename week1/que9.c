// Library Book Management • Store the book ID, title, author, total copies, and available copies using structures. • Create a menu-driven program to add and search for books, issue and return books, and display all books currently unavailable.
   #include <stdio.h>
#include <string.h>

struct Book {
    int bookID;
    char title[100];
    char author[100];
    int totalCopies;
    int availableCopies;
};

int main() {
    struct Book books[100];

    int count = 0;
    int choice;
    int i;
    int id;
    int found;

    while (1) {

        printf("\n\n----- LIBRARY BOOK MANAGEMENT -----\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Display Unavailable Books\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        // ADD BOOK
        case 1:

            printf("\nEnter Book ID: ");
            scanf("%d", &books[count].bookID);

            printf("Enter Book Title: ");
            scanf(" %[^\n]", books[count].title);

            printf("Enter Author Name: ");
            scanf(" %[^\n]", books[count].author);

            printf("Enter Total Copies: ");
            scanf("%d", &books[count].totalCopies);

            books[count].availableCopies =
                books[count].totalCopies;

            count++;

            printf("Book added successfully!\n");
            break;


        // SEARCH BOOK
        case 2:

            printf("\nEnter Book ID to search: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < count; i++) {

                if (books[i].bookID == id) {

                    printf("\nBook Found!\n");
                    printf("Book ID: %d\n",
                           books[i].bookID);

                    printf("Title: %s\n",
                           books[i].title);

                    printf("Author: %s\n",
                           books[i].author);

                    printf("Total Copies: %d\n",
                           books[i].totalCopies);

                    printf("Available Copies: %d\n",
                           books[i].availableCopies);

                    found = 1;
                    break;
                }
            }

            if (found == 0) {
                printf("Book not found!\n");
            }

            break;


        // ISSUE BOOK
        case 3:

            printf("\nEnter Book ID to issue: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < count; i++) {

                if (books[i].bookID == id) {

                    found = 1;

                    if (books[i].availableCopies > 0) {

                        books[i].availableCopies--;

                        printf("Book issued successfully!\n");

                    } else {

                        printf("Book is currently unavailable!\n");
                    }

                    break;
                }
            }

            if (found == 0) {
                printf("Book not found!\n");
            }

            break;


        // RETURN BOOK
        case 4:

            printf("\nEnter Book ID to return: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < count; i++) {

                if (books[i].bookID == id) {

                    found = 1;

                    if (books[i].availableCopies <
                        books[i].totalCopies) {

                        books[i].availableCopies++;

                        printf("Book returned successfully!\n");

                    } else {

                        printf("All copies are already available!\n");
                    }

                    break;
                }
            }

            if (found == 0) {
                printf("Book not found!\n");
            }

            break;


        // DISPLAY UNAVAILABLE BOOKS
        case 5:

            found = 0;

            printf("\n----- UNAVAILABLE BOOKS -----\n");

            for (i = 0; i < count; i++) {

                if (books[i].availableCopies == 0) {

                    printf("\nBook ID: %d\n",
                           books[i].bookID);

                    printf("Title: %s\n",
                           books[i].title);

                    printf("Author: %s\n",
                           books[i].author);

                    found = 1;
                }
            }

            if (found == 0) {
                printf("No books are currently unavailable.\n");
            }

            break;


        // EXIT
        case 6:

            printf("Exiting program...\n");
            return 0;


        default:

            printf("Invalid choice! Please try again.");
        }
    }

    return 0;
}
