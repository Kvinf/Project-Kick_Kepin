#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.cpp"

struct post {
  char para[255]; // Content of Post
  char title[100]; // Title of Post
};

struct publicDashboard { 
  int id; // User's ID
  post publicPost; // User's Post
  publicDashboard *next, *prev; // point to the left and right
} *headpub, *tailpub; // point to the leftmost and rightmost node

struct privateDashboard {
  int id; // User's ID
  int access[4]; // Limited to 3 selected users
  post privatePost; // Private Post
  privateDashboard *next, *prev; // point to the left and right
} *headpriv, *tailpriv; // point to the leftmost and rightmost node

post *createPost() { // Still needs to be implemented in creating heads (private or public)
    post *newPost = (post*)malloc(sizeof(post));
    printf("Please enter the title of your post...\n>>");
    scanf("%[\n]", newPost->title);

    printf("Enter your thoughts here...\n>>");
    scanf("%[\t]s", newPost->para);
    return newPost;
}

publicDashboard *createPubNode(int value) { // UNFINISHED POST
  publicDashboard *newNode = (publicDashboard*)malloc(sizeof(publicDashboard));
  newNode->publicPost = *createPost();
  newNode->id = value;
  newNode->next = newNode->prev = NULL;
  return newNode;
}

privateDashboard *createPrivNode(int value,int *akses) { // UNFINISHED POST
  privateDashboard *newNode = (privateDashboard*)malloc(sizeof(privateDashboard));
  newNode->privatePost = *createPost();
  newNode->id = value;
  newNode->next = newNode->prev = NULL;
  for (int i;akses[i]!='\0';i++){
      newNode->access[i] = akses[i];
  }
  return newNode;
}

void pushPubHead(int value) {
  publicDashboard *temp = createPubNode(value);

  if(!headpub) { // No public post
    headpub = tailpub = temp; // temp (head and tail)
  } else { // A (head), insert B
    headpub->prev = temp; // B (temp) <- A (head)
    temp->next = headpub; // B (temp) -><- A (head)
    headpub = temp; // B (temp, head) -><- A
  }
}

void pushPrivHead(int value,int *akses) {
  privateDashboard *temp = createPrivNode(value,akses);

  if(!headpriv) { // No public post
    headpriv = tailpriv = temp; // temp (head and tail)
  } else { // A (head), insert B
    headpriv->prev = temp; // B (temp) <- A (head)
    temp->next = headpriv; // B (temp) -><- A (head)
    headpriv = temp; // B (temp, head) -><- A
  }
}

// void pushTail(int value) {
//   publicDashboard *temp = createPubNode(value);

//   if(!head) { // empty list
//     head = tail = temp; // temp (head dan tail)
//   } else { // A (tail), insert B
//     tail->next = temp; // A (tail) -> B (temp)
//     temp->prev = tail; // A (tail) -><- B (temp)
//     tail = temp;  // A -><- B (temp, tail)
//   }
// }

// void pushMid(int value) {
//   if(!head) { // empty list
//     Node *temp = createNode(value);
//     head = tail = temp;
//   } else if(value < head->value) { // add to the leftmost
//     pushHead(value);
//   } else if(value > tail->value) { // add to the rightmost
//     pushTail(value);
//   } else { // value is between head and tail
//     Node *temp = createNode(value); // 9 (temp)
//     Node *curr = head; // 1 (head, curr) -><- 8 -><- 12 -><- 15, insert 9

//     while(curr->value < value) {
//       curr = curr->next; // traverse until curr->value > value
//     }

//     // 1 -><- 8 -><- 12 (curr) -><- 15 || 9 (temp)
//     temp->prev = curr->prev; // 9->prev = 8
//     temp->next = curr; // 9->next = 12
    
//     // 1 -><- 8 ->      <- 12 (curr) -><- 15
//     //        \(prev)   /(next)
//     //               9 (temp)

//     curr->prev->next = temp; // 8->next = 9
//     curr->prev = temp; // 12->prev = 9
//     // 1 -><- 8                           12 (curr) -><- 15
//     //       \(prev)\(next)     /(next)/(prev)
//     //                   9 (temp)
//   }
// }

// void popHead() {
//   if(!head) { // empty list
//     return;
//   } else if(head == tail) { // 1 node
//     free(head);
//     head = tail = NULL;
//   } else { // >= 1 node
//     Node *newHead = head->next; // A (head) -><- B (newHead) -><- C
//     head->next = newHead->prev = NULL; // A (head) || B (newHead) -><- C
//     free(head); // B (newHead) -><- C
//     head = newHead; // B (head, newHead) -><- C
//   }
// }

// void popTail() {
//   if(!head) { // empty list
//     return; 
//   } else if(head == tail) { // 1 node
//     free(head);
//     head = tail = NULL;
//   } else { // >= 1 node
//     Node *newTail = tail->prev; // A -><- B (newTail) -><- C (tail)
//     tail->prev = newTail->next = NULL; // A -><- B (newTail) || C (tail)
//     free(tail); // A -><- B (newTail)
//     tail = newTail; // A -><- B (tail, newTail)
//   }
// }

// void popMid(int value) {
//   if(!head) { // empty list
//     return;
//   } else if(head->value == value) {
//     popHead(); 
//   } else if(tail->value == value) {
//     popTail(); 
//   } else { // value is between head and tail
//     Node *curr = head; // 10 (curr) 20 30 40 50, remove 30

//     while(curr && curr->value != value) {
//       curr = curr->next; // traverse until we find the value
//     }

//     // 10 -><- 20 -><- 30 (curr) -><- 40 -><- 50, remove 30
//     curr->prev->next = curr->next; // 20->next = 40
//     curr->next->prev = curr->prev; // 40->prev = 20

//     // 10 -><- 20      -><-     40 -><- 50, mau hapus 30
//     //          \<- 30 (curr) ->/ 

//     curr->prev = curr->next = NULL; // set pointers to NULL
//     free(curr); // free assigned memory
//     curr = NULL; // remove value
//   }
// }

void printPub() { // UNFINISHED
  publicDashboard *curr = headpub;
  printf("PUBLIC DASHBOARD: ");

  while(curr) {
    //printf("%d's content: %s -> ", curr->id, curr->post);
    curr = curr->next;
  }
  puts("NULL");
}

void printPriv() { // UNFINISHED
  privateDashboard *curr = headpriv;
  printf("Linked List: ");

  while(curr) {
    //printf("%d's content: %s -> ", curr->id, curr->post);
    curr = curr->next;
  }
  puts("NULL");
}

// void visualizeList(int N, int values[]) {
//   for(int i = 0; i < N; i++) {
//     pushMid(values[i]);
//     printf("Inserted %d to the list.\n", values[i]);
//     printLinkedList();
//     getchar();
//   }

//   for(int i = 0; i < N; i++) {
//     popMid(values[i]);
//     printf("Removed %d from the list.\n", values[i]);
//     printLinkedList();
//     getchar();
//   }
// }
int billboardmenu(){
    int choosemenu;
    system("cls");
    puts("-----------------------------------------");
    puts("[1] Add Notes");
    puts("[2] Edit Notes");
    puts("[3] Announce Notes");
    puts("[4] Delete Note");
    puts("[5] Quit");
    puts("-----------------------------------------");
    printf(">> ");
    scanf("%d",&choosemenu);
    return choosemenu;
}
void printprivatedashboard(int id){
    privateDashboard *curr = headpriv;
    while(curr){
        printf("%d : %s\n",id,curr->privatePost.title);//ini idnya waktu kepin buat
        curr = curr->next;
    }
    
}
void printpublicdashboard(){
    publicDashboard *curr = headpub;
    while(curr){
        printf("%d : %s\n",id,curr->publicPost.title);//ini juga sama
        curr = curr->next;
    }
    
}
void billboard(int *choosemenu){
    if (*choosemenu == 1){
        int posttype;
        printf("\n Private Notes[0]/ Public Notes?[1]?\n >> ");
        scanf("%d",&posttype);
        if (posttype == 0){
           printpublicdashboard();
        }else if(posttype == 1){
            //pushPrivateHead(IDKEPIN);
        }else{
            printf("Invalid Choise");
        }
    }else if (*choosemenu == 2){
        int choose;// choose ini nanti dicocokkan sama id
        printf("Choose post u want to edit : \n");
        printf("Private : \n");
        printprivatedashboard();
        printf("Public : \n");
        printpublicdashboard();
        printf(">> ");
        scanf("%d",&choose);
        publicDashboard *curr = headpub;
        while(curr){
            if(curr->id == choose){
                printf("Please enter the title of your post...\n>>");
                scanf("%[\n]", curr->publicPost.title);

                printf("Enter your thoughts here...\n>>");
                scanf("%[\t]s", curr->publicPost.para);
                break;
            }
            curr = curr->next;
        }
    }else if (*choosemenu == 3){
        // ANNOUNCE KEPIN SEMANGAT BUATNYA GW KEKNYA UD MAU OFF
    }else if(*choosemenu == 4){
        // POP NOTENYA
    }else if(*choosemenu == 5){
        printf("Bye");
    }else{
        printf("NOTE NOT EXIST");
    }
}

int main() {
  // UNFINISHED

  return 0;
}