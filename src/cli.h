#ifndef CLI_H
#define CLI_H

#define MAX_CONTACTS 10
typedef struct Contact {
        char name[30];
        int phone;
} Contact;

extern Contact people[MAX_CONTACTS];
extern int count;

void clean_buff(void);
void add_contact(void);
void show_contacts(void);
void search_contact(void);

#endif
