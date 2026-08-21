//10. ATM Transaction System • Create a menu-driven program to check balance, deposit money, withdraw money, and exit. • Prevent a withdrawal when the balance is insufficient. • Maintain and display the last five transactions.
#include <stdio.h>
#include <string.h>

int main() {
    int choice;
    float balance = 5000;
    float amount;

    char transactions[5][100];
    int transactionCount = 0;

    while (1) {

        printf("\n\n----- ATM TRANSACTION SYSTEM -----\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Last Five Transactions\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        // CHECK BALANCE
        case 1:
            printf("\nCurrent Balance = Rs. %.2f\n", balance);
            break;


        // DEPOSIT MONEY
        case 2:

            printf("\nEnter amount to deposit: ");
            scanf("%f", &amount);

            if (amount > 0) {

                balance = balance + amount;

                // Store transaction
                if (transactionCount < 5) {

                    sprintf(
                        transactions[transactionCount],
                        "Deposited Rs. %.2f",
                        amount
                    );

                    transactionCount++;
                }
                else {

                    // Shift transactions
                    for (int i = 0; i < 4; i++) {
                        strcpy(
                            transactions[i],
                            transactions[i + 1]
                        );
                    }

                    sprintf(
                        transactions[4],
                        "Deposited Rs. %.2f",
                        amount
                    );
                }

                printf("Money deposited successfully!\n");

            } else {
                printf("Invalid amount!\n");
            }

            break;


        // WITHDRAW MONEY
        case 3:

            printf("\nEnter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= 0) {

                printf("Invalid amount!\n");

            }
            else if (amount > balance) {

                printf("Insufficient balance! Withdrawal not possible.\n");

            }
            else {

                balance = balance - amount;

                // Store transaction
                if (transactionCount < 5) {

                    sprintf(
                        transactions[transactionCount],
                        "Withdrawn Rs. %.2f",
                        amount
                    );

                    transactionCount++;
                }
                else {

                    // Shift old transactions
                    for (int i = 0; i < 4; i++) {
                        strcpy(
                            transactions[i],
                            transactions[i + 1]
                        );
                    }

                    sprintf(
                        transactions[4],
                        "Withdrawn Rs. %.2f",
                        amount
                    );
                }

                printf("Money withdrawn successfully!\n");
            }

            break;


        // DISPLAY LAST FIVE TRANSACTIONS
        case 4:

            printf("\n----- LAST FIVE TRANSACTIONS -----\n");

            if (transactionCount == 0) {

                printf("No transactions available.\n");

            }
            else {

                for (int i = 0;
                     i < transactionCount;
                     i++) {

                    printf(
                        "%d. %s\n",
                        i + 1,
                        transactions[i]
                    );
                }
            }

            break;


        // EXIT
        case 5:

            printf("Thank you for using the ATM!\n");
            return 0;


        default:

            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
