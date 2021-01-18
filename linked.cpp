#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>

const int MAX_ELEMENT = 10000;
const int MAX_LENGTH = 255;
int idGlobal = 0;
int id = NULL;



struct invitation{
    int from;
    int dest;
    char status [10];
    invitation *next,*prev;
}*headInvitation, *tailInvitation;

struct friendList{
    int id;
    friendList *next,*prev;
};

struct nodeUser {
    char name[255];
    char pass[16];
    friendList *head = NULL;
    friendList *tail = NULL;
}*headHash[MAX_ELEMENT];

nodeUser *createNodeHash(const char *name,const char *pass) {//utk create node
  nodeUser *newNode = (nodeUser*)malloc(sizeof(nodeUser));
  strcpy(newNode->name, name);
  strcpy(newNode->pass,pass);
  newNode->head = NULL;
  newNode->tail = NULL;
  return newNode;
}

friendList *createFriend(int id) {
    friendList *newNode = (friendList*)malloc(sizeof(friendList));
    newNode->id = id;
    newNode->next = NULL;
    newNode ->prev = NULL;
    return newNode;
}
invitation *createInvitation(int from, int dest) {
    invitation *newNode = (invitation*)malloc(sizeof(invitation));
    newNode->dest = dest;
    newNode->from = from;
    strcpy(newNode->status,"Pending");
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void insertHash(const char *str,const char *pass) {
    int index = idGlobal;
    idGlobal++;
    nodeUser *temp = createNodeHash(str,pass);
    headHash[index] = temp;
}

void pushHead(int index,nodeUser *user) {
    friendList *temp = createFriend(index);
        temp->next = user->head;
        user->head->prev = temp;    
        user->head = temp;
    
}

void pushInvitation(int from , int dest){
    invitation *temp = createInvitation(from,dest);
    if (!headInvitation) {
        headInvitation = tailInvitation = temp;
    } else {
        temp ->next = headInvitation;
        headInvitation ->prev = temp;
        headInvitation = temp;
    }
}
int popInvitation(int dest , int from) {
    if(!headInvitation && !tailInvitation) { // empty list
    return 0;
  } else if (headInvitation == tailInvitation) {
      free(headInvitation);
      headInvitation = tailInvitation = NULL;
  } 
  else if(headInvitation->dest == dest && headInvitation->from == from) {
    invitation *temp = headInvitation->next;
    temp->prev = headInvitation->next = NULL;
    free(headInvitation);
    headInvitation = temp;
  } else if(tailInvitation->dest == dest && tailInvitation->from == from) {
    invitation *temp = tailInvitation->prev;
    temp->next = tailInvitation->prev = NULL;
    free(tailInvitation);
    tailInvitation = temp;
  } else { // value is between head and tail
    invitation *curr = headInvitation;
    while(curr && curr->dest != dest && curr->from != from) {
      curr = curr->next; 
    }
    curr->prev->next = curr->next; 
    curr->next->prev = curr->prev; 
    curr->prev = curr->next = NULL; // set pointers to NULL
    free(curr); // free assigned memory
    curr = NULL; // remove value
  }
}
void insertFriend(int indexInput , int indexUser) {
    if (!headHash[indexUser]->head){
        friendList  *dummy = createFriend(indexInput);
        headHash[indexUser]->head = headHash[indexUser]->tail = dummy;
    }
    else {
        nodeUser *temp = headHash[indexUser];
        pushHead(indexInput,temp);
    }
    return;
}

void popFriend (int index,int userIndex) {
     if(!headHash[userIndex]->head && !headHash[userIndex]->tail) { // empty list
    return ;
  } else if (headHash[userIndex]->head  == headHash[userIndex]->tail) {
      free(headHash[userIndex]->head);
        headHash[userIndex]->head  = headHash[userIndex]->tail = NULL;
  } 
  else if(headHash[userIndex]->head->id == index) {
    friendList *temp = headHash[userIndex]->head->next;
    temp->prev = headHash[userIndex]->head->next = NULL;
    free(headHash[userIndex]->head);
    headHash[userIndex]->head = temp;
  } else if(headHash[userIndex]->tail->id == index) {
    friendList *temp = headHash[userIndex]->tail->prev;
    temp->next = headHash[userIndex]->tail->prev = NULL;
    free(headHash[userIndex]->tail);
    headHash[userIndex]->tail = temp;
  } else { // value is between head and tail
    friendList *curr = headHash[userIndex]->head;
    while(curr->id != id && curr) {
      curr = curr->next; 
    }
    curr->prev->next = curr->next; 
    curr->next->prev = curr->prev; 
    curr->prev = curr->next = NULL; // set pointers to NULL
    free(curr); // free assigned memory
    curr = NULL; // remove value
  }
}

void view() {
    int index = 0;
    nodeUser *temp = headHash[index];
    while (headHash[index] != NULL) {
        printf("Index %d : %s Pass : %s\nFriend -> ",index,headHash[index]->name,headHash[index]->pass);
        friendList *curr = headHash[index]->head;
        while(curr) {
            printf("%d -> ",curr->id);
            curr = curr->next;
        }
        index++;
        puts("NULL");
    }
}
// int main () {
//     view();
//     popFriend(1,0);
//     view();
//     return 0;
// }