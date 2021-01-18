#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct privateDashBoard {
    int access[4];
    int category;
    char quote[256];
    int id;
    int idPerson;
    privateDashBoard *next,*prev;
} *headPrivate,*tailPrivate;

struct publicDashBoard{
    int category;
    char quote[256];
    int id;
    int idPerson;
    publicDashBoard *next,*prev;
}*headPublic , *tailPublic;

privateDashBoard *createNode(int id,int category,const char *quote , int access[],int idPerson) {
    privateDashBoard *newNode = (privateDashBoard*)malloc(sizeof(privateDashBoard));
    newNode->id = id;
    newNode->category = category;
    newNode->next = newNode->prev = NULL;
    newNode->idPerson = idPerson;
    strcpy(newNode->quote,quote);
    int index = 0;
    while (access[index] == '\0') {
        newNode->access[index] = access[index];
        index++;
    } 
    return newNode;
}

publicDashBoard *createNode(int id,int category,const char *quote,int idPerson) {
    publicDashBoard *newNode = (publicDashBoard*)malloc(sizeof(publicDashBoard));
    newNode->id = id;
    newNode->category = category;
    newNode->idPerson = idPerson;
    newNode->next = newNode->prev = NULL;
    strcpy(newNode->quote,quote);
    return newNode;
}

void insertPublic(int id , int category , const char *quote,int idPerson) {
    publicDashBoard *temp = createNode(id,category,quote,idPerson);
    if (!headPublic) {
        headPublic = tailPublic = temp;
    } else {
        headPublic->prev = temp;
        temp->next = headPublic;
        headPublic = temp;
    }
    
}
void insertPrivate (int id,int category , const char *quote , int *access,int idPerson) {
    privateDashBoard *temp = createNode(id,category,quote,access,idPerson);
    if (!headPrivate) {
        headPrivate = tailPrivate = temp;
    } else {
        headPrivate->prev = temp;
        temp->next = headPrivate;
        headPrivate = temp;
    }
}

void popPrivate(int idPerson,int id) {
    if (!headPrivate) {
        return;
    } else if (headPrivate->idPerson == idPerson && headPrivate->id == id) {
        privateDashBoard *temp = headPrivate->next;
        temp->prev = headPrivate->next = NULL;
        free(headPrivate);
        headPrivate = temp;
    } else if (tailPrivate->idPerson == idPerson && tailPrivate->id == id) {
        privateDashBoard *temp = tailPrivate->next;
        temp->prev = tailPrivate->next = NULL;
        free(tailPrivate);
        tailPrivate = temp;
    } else {
        privateDashBoard *curr = headPrivate;
         while(curr && curr->idPerson != idPerson) {
      curr = curr->next; 
        }
        curr->prev->next = curr->next; 
        curr->next->prev = curr->prev; 
        curr->prev = curr->next = NULL; // set pointers to NULL
        free(curr); // free assigned memory
        curr = NULL; // remove value
    }
}
void popPublic(int idPerson,int id) {
    if (!headPublic) {
        return;
    } else if (headPublic == tailPublic && headPublic->idPerson == idPerson && headPublic->id == id && tailPublic->idPerson == idPerson && tailPublic->id == id) {
        free(headPublic);
        headPublic = tailPublic = NULL;
    } 
    else if (headPublic->idPerson == idPerson && headPublic->id == id) {
        publicDashBoard *temp = headPublic->next;
        temp->prev = headPublic->next = NULL;
        free(headPublic);
        headPublic = temp;
    } else if (tailPublic->idPerson == idPerson && tailPublic->id == id) {
        publicDashBoard *temp = tailPublic->prev;
        temp->next = tailPublic->prev = NULL;
        free(tailPublic);
        tailPublic = temp;
    } else {
        publicDashBoard *curr = headPublic;
         while(curr && curr->idPerson != idPerson) {
             
      curr = curr->next; 
        }
        curr->prev->next = curr->next; 
        curr->next->prev = curr->prev; 
        curr->prev = curr->next = NULL; // set pointers to NULL
        free(curr); // free assigned memory
        curr = NULL; // remove value
    }
}

