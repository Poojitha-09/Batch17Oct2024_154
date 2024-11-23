/*3 3. WAP to test the eligibility for deployment post training. Need to fulfill all the 4 conditions. Read the score inputs from user at runtime. (Use if else and switch together).
i. Test1 Score >= 75%
ii. Test2 Score >= 75%
iii. Test3 Score >= 70%
iv. Project Score >=75%

*/ 

#include <stdio.h>

int main() {
    float test1, test2, test3, project;
    
    // Read the scores from the user
    printf("Enter the score for Test 1: ");
    scanf("%f", &test1);

    printf("Enter the score for Test 2: ");
    scanf("%f", &test2);

    printf("Enter the score for Test 3: ");
    scanf("%f", &test3);

    printf("Enter the Project score: ");
    scanf("%f", &project);

    // Using if-else and switch to check the conditions
    if (test1 >= 75) {
        switch (1) {
            case 1:
                if (test2 >= 75) {
                    switch (2) {
                        case 2:
                            if (test3 >= 70) {
                                switch (3) {
                                    case 3:
                                        if (project >= 75) {
                                            printf("Eligible for deployment post training.\n");
                                        } else {
                                            printf("Project score should be >= 75%%.\n");
                                        }
                                        break;
                                    default:
                                        break;
                                }
                            } else {
                                printf("Test3 score should be >= 70%%.\n");
                            }
                            break;
                        default:
                            break;
                    }
                } else {
                    printf("Test2 score should be >= 75%%.\n");
                }
                break;
            default:
                break;
        }
    } else {
        printf("Test1 score should be >= 75%%.\n");
    }

    return 0;
}
