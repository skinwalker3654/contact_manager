#include <stdio.h>
#include "cli.h"

int main(void)
{
    int choice;
    while(1) {
        printf("1. Add contact\n");
        printf("2. Show contacts\n");
        printf("3. search contact\n");
        printf("4. Exit\n");

        printf("\nPick one > ");
        if(scanf("%d",&choice)!=1) {
                printf("Invalid input\n");
                clean_buff();
                continue;
        }
        clean_buff();

        switch(choice) {
        case 1: 
                add_contact(); 
                break;
        case 2: 
                show_contacts(); 
                break;
        case 3: 
                search_contact(); 
                break;
        case 4: 
                printf("Exitting...\n"); 
                return 0;
        default:
                printf("Invalid choise\n");
                continue;
        }
        printf("\n");
    }
    return 0;
}
