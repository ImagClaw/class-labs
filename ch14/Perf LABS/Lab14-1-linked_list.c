/*
*
*  name: Whelpley
*  date: 27 Feb 2019
*  project: Linked Lists Lab
*  
*  Requirments
*  
*      Utilize headers for all declarations
*      Utilize proper naming schemas
*      Document code
*      Push code to Github
*          Use branching! Create a development branch and push to there. Merge when all requirments are met
*      Break your code out into functions
*      Utilize multiple C files if needed
*  
*  Instructions
*  
*      /Create a linked list, the struct members should contain the following:
*          /Each students initals
*          /Each students favoriate musical artist
*          /Each students dream car
*          /Required data for linked list completion
*          /May be worth each student just posting their data into a slack channel so everyone can grab off of it
*      Create a menu allowing for the following:
*          /Print out of all students and all of their data
*          Print out of all students and only one of their data members on request of user (ex. print out all students and their fav car)
*          /Print out of only a specific student (This one can be challanging)
*      BONUS
*          Add additonal students to the end
*          Remove students at the end
*          Remove a specific student (This one is challanging)
*      Push code to Github and post the link in code (This is so that we can get more practice with git)
*          Ensure you are commiting often
*          Advice: Commit anything a moderate feature is added or changed
*              ex: You added the ability to print out a specific student
*              ex: You removed a section of code that was giving you issues
*          Advice: You can commit often without the need to push your code. It's recommended to push code after larger work is done
*              ex: You finished an entire requirment
*              ex: You changed a large amount of code
*              ex: You have a ton of commits
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Create a linked list, the struct members should contain the following:
*          Each students initals
*          Each students favoriate musical artist
*          Each students dream car
*          Required data for linked list completion
*/

struct members {
    int member_index;
    char * member_initials;
    char * member_favMusician;
    char * member_dreamCar;
    struct members *next;
};

void displayMember(struct members *membID, int id);
void display(struct members *myMembers);
void displaySpecificData(struct members *memb, int n);
void getch();
//void remove(struct members *memb);

int main() {
    
    // Initialize the variables
    int choice;
    int index = 0;
    int id;
    char initials[4];
    char favMusician[32];
    char dreamCar[32];

    struct members* members = NULL;
    struct members* currentMember = members;
    struct members* newMember = members;

    // allocating all member nodes in the heap
    //members = (struct members*)malloc(sizeof(struct members));
    //currentMember = (struct currentmembers*)malloc(sizeof(struct members));

    do {
        printf(",-.-.          |                       ,-.-.\n");                
        printf("| | |,---.,-.-.|---.,---.,---.,---.    | | |,---.,---..   .\n");
        printf("| | ||---'| | ||   ||---'|    `---.    | | ||---'|   ||   |\n"); 
        printf("` ' '`---'` ' '`---'`---'`    `---'    ` ' '`---'`   '`---'\n");
        printf("===========================================================\n");   
        printf("1. Add Member.\n");
        printf("2. Print all Member's data.\n");
        printf("3. Print specific Member's data.\n");
        printf("4. Print a section of Member data\n");
        printf("5. TODO: Remove a member (by ID).\n");
        printf("6. Exit\n\n");
        printf("Enter your choice here: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // allocating newMember node in the heap
                newMember = (struct members *)malloc(sizeof(struct members));
                // increases index for each user added to the list
                newMember->member_index = ++index;
                // Add Member Menu header and prompts user to input 
                printf("\n /\\  _| _|  |\\/| _  _ _ |_  _  _.\n");
                printf("/~~\\(_|(_|  |  |(/_| | ||_)(/_| .\n");
                printf("==================================\n");
                printf("Answer a few questions, there are only 3.\n");
                printf("1. Member's initials: ");
                scanf(" %[^\t\n]s", initials);
                // if input is larger than 3, error out.
                if (strlen(initials) > 3) {
                    printf("\n\n\nERROR: 3 initials only. Try again.\n\n\n");
                    break;
                }
                newMember->member_initials = (char *)malloc(sizeof(char)*4);
                strcpy(newMember->member_initials, initials);
                //newMember->next = favMusician;
                printf("2. Member's favorite musician: ");
                scanf(" %[^\t\n]s", favMusician);
                //fgets(favMusician, 31, stdin);
                newMember->member_favMusician = (char *)malloc(sizeof(char)*32);
                strcpy(newMember->member_favMusician, favMusician);
                //newMember->next = dreamCar;
                printf("3. Member's dream car: ");
                scanf(" %[^\t\n]s", dreamCar);
                //fgets(dreamCar, 31, stdin);
                newMember->member_dreamCar = (char *)malloc(sizeof(char)*32);
                strcpy(newMember->member_dreamCar, dreamCar);
                newMember->next = NULL;
                printf("\nThanks! Info has been added to the Database.\nReturning you to the Main Menu.\n\n");
                printf("Press any key to continue...\n\n\n");
                getch();
                if (members == NULL) {
                    members = newMember;
                    currentMember = newMember;
                } else {
                    currentMember->next = newMember;
                    currentMember = newMember;
                }
                //
                break;
            case 2: // Print all members data //
                printf(" /\\ ||  |\\/| _  _ _ |_  _  _ _  |~\\ _ _|_ _ .\n");
                printf("/~~\\||  |  |(/_| | ||_)(/_| _\\  |_/(_| | (_|.\n");
                printf("===============================================\n");
                if (members == NULL) {
                    printf("\nThere are no members loaded.\n\n");
                } else {
                    display(members);
                }
                printf("Press any key to continue...\n\n\n");
                getch();
                break;
            case 3: // Print specific members data //
                printf("Enter the ID of the Member's data: ");
                scanf(" %d", &id);
                displayMember(members, id);
                printf("Press any key to continue...\n\n\n");
                getch();
                break;
            case 4: // Print all of a single members data //
                printf("(~ _  _  _. |`. _  |\\/| _  _ _ |_  _  _  |~\\ _ _|_ _ .\n");
                printf("_)|_)(/_(_|~|~|(_  |  |(/_| | ||_)(/_|   |_/(_| | (_|.\n");
                printf("  |\n");                                             
                printf("======================================================\n");
                printf("\t1. Initials\n");
                printf("\t2. Favorite Musician\n");
                printf("\t3. Dream Car\n\n");
                printf("\tEnter the number associated with the data you want: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1: // Member Intials // 
                        displaySpecificData(members, 1);
                        printf("Press any key to continue...\n\n\n");
                        getch();
                        break;
                    case 2: // Mmeber Favorite Musician //
                        displaySpecificData(members, 2);
                        printf("Press any key to continue...\n\n\n");
                        getch();
                        break;
                    case 3: // Mmeber Dream Car //
                        displaySpecificData(members, 3);
                        printf("Press any key to continue...\n\n\n");
                        getch();
                        break;
                }
                break;
            case 5: // Remove Member //
                printf("Still in the works.  Pls come back later... O_O\n\n");
                break;
            case 6: // Exit program //
                free(newMember);
                free(members);
                printf("OK, thanks. Latez!\n");
                break;
            default:
                printf("Wrong choice.  Try again.\n");
                break;        
        } 
    } while (choice !=6);   
}


// Displays all members added into node `members`.
void display(struct members *memb) {
    while (memb != NULL)
    {
        printf("%d.) Initials - %s\tFavorite Musician - %s\t\tDream Car - %s\n", 
            memb->member_index, 
            memb->member_initials, 
            memb->member_favMusician, 
            memb->member_dreamCar
        );
        memb = memb->next;
    }
    printf("\n\n");
}

void displayMember(struct members *membID, int id) {
    while (membID != NULL && membID->member_index != id) {
        membID = membID->next;
    }
    if (membID != NULL) {
        printf("%d.) Initials - %s\tFavorite Musician - %s\t\tDream Car - %s\n", 
            membID->member_index, 
            membID->member_initials, 
            membID->member_favMusician, 
            membID->member_dreamCar
        );
        } else {
            printf("ID not found.");
    }
    printf("\n\n");
}

void displaySpecificData(struct members *memb, int n) {
    while (n != 0 && memb != NULL) {
        switch (n) {  
            case 1:
                printf("\t%d.) Initials - %s\n", 
                    memb->member_index, 
                    memb->member_initials
                );
                memb = memb->next;
                break;
            case 2:
                printf("\t%d.) Favorite Musician - %s\n", 
                    memb->member_index, 
                    memb->member_favMusician
                );
                memb = memb->next;
                break;
            case 3:
                printf("\t%d.) Dream Car - %s\n", 
                    memb->member_index, 
                    memb->member_dreamCar
                );
                memb = memb->next;
                break;
            default: 
                printf("\tData not found.\n");
                break;
        }
    }
    printf("\n\n");
}
//
//void remove(struct members *memb) {
//    return 0;
//}