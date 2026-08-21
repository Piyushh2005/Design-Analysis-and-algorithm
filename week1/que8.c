//Student Result Analysis • Store the roll number, name, and marks in five subjects for N students using structures. • Calculate the total, percentage, and grade of each student. • Display the class topper, students who failed in one or more subjects, and the class average.
#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    float marks[5];
    float total;
    float percentage;
    char grade;
    int failed;
};

int main() {
    int n, i, j;
    float classTotal = 0;
    int topper = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    // Input and calculation
    for (i = 0; i < n; i++) {
        s[i].total = 0;
        s[i].failed = 0;

        printf("\nEnter details of Student %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &s[i].roll);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter marks in 5 subjects:\n");

        for (j = 0; j < 5; j++) {
            scanf("%f", &s[i].marks[j]);

            s[i].total = s[i].total + s[i].marks[j];

            if (s[i].marks[j] < 40) {
                s[i].failed = 1;
            }
        }

        // Calculate percentage
        s[i].percentage = s[i].total / 5;

        // Assign grade
        if (s[i].failed == 1) {
            s[i].grade = 'F';
        }
        else if (s[i].percentage >= 90) {
            s[i].grade = 'A';
        }
        else if (s[i].percentage >= 80) {
            s[i].grade = 'B';
        }
        else if (s[i].percentage >= 70) {
            s[i].grade = 'C';
        }
        else if (s[i].percentage >= 60) {
            s[i].grade = 'D';
        }
        else {
            s[i].grade = 'E';
        }

        classTotal = classTotal + s[i].percentage;

        // Find topper
        if (s[i].percentage > s[topper].percentage) {
            topper = i;
        }
    }

    // Display all student results
    printf("\n\n----- STUDENT RESULTS -----\n");

    for (i = 0; i < n; i++) {
        printf("\nRoll Number: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal Marks: %.2f / 500", s[i].total);
        printf("\nPercentage: %.2f%%", s[i].percentage);
        printf("\nGrade: %c\n", s[i].grade);
    }

    // Display topper
    printf("\n----- CLASS TOPPER -----\n");
    printf("Name: %s\n", s[topper].name);
    printf("Roll Number: %d\n", s[topper].roll);
    printf("Percentage: %.2f%%\n", s[topper].percentage);

    // Display failed students
    printf("\n----- FAILED STUDENTS -----\n");

    int found = 0;

    for (i = 0; i < n; i++) {
        if (s[i].failed == 1) {
            printf("Roll Number: %d, Name: %s\n",
                   s[i].roll, s[i].name);
            found = 1;
        }
    }

    if (found == 0) {
        printf("No student has failed.\n");
    }

    // Calculate class average
    float classAverage = classTotal / n;

    printf("\n----- CLASS AVERAGE -----\n");
    printf("Class Average Percentage = %.2f%%\n", classAverage);

    return 0;
}
