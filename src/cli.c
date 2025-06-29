#include <stdio.h>
#include <string.h>
#include "cli.h"

Contact people[MAX_CONTACTS];
int count = 0;

void clean_buff(void) 
{
        int ch;
        while((ch=getchar())!='\n'&&ch!=EOF);
}

void add_contact(void) 
{
    if(count >= MAX_CONTACTS) {
            printf("Error: over limit of contacts\n");
            printf("Max contacts: 10\n");
            return;
    }

    printf("Enter name: ");
    fgets(people[count].name,30,stdin);
    people[count].name[strcspn(people[count].name,"\n")] = 0;

    if(strlen(people[count].name)==0) {
            printf("Name cannot be empty\n");
            return;
    }

    printf("Enter phone number: ");
    if(scanf("%d",&people[count].phone)!=1) {
            printf("Invalid phone number\n");
            clean_buff();
            return;
    }

    clean_buff();
    count++;
}

void show_contacts(void) 
{
    if(count == 0) {
            printf("No contacts yet\n");
            return;
    }

    for(int i=0; i<count; i++) {
            printf("Contact %d# name: %s phone %d\n",i+1,people[i].name,people[i].phone);
    }
}

void search_contact(void) 
{
    if(count == 0) {
            printf("No contacts yet\n");
            return;
    }

    char search[30];
    printf("Enter contacts name: ");
    fgets(search,30,stdin);
    search[strcspn(search,"\n")] = 0;

    int found = 0;
    for(int i=0; i<count; i++) {
            if(strcmp(search,people[i].name)==0) {
                    printf("Contact found phone number: %d\n",people[i].phone);
                    found = 1;
        }
    }

    if(!found) {
            printf("Contact not found\n");
    }
}
