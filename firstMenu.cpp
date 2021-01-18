#include <stdio.h>
#include <ctime>
#include "linked.cpp"
#include "DashBoardFinal.cpp"
void printMainMenu(){
    puts(" Oo=====================================oO");
    puts("               STUDY NETWORK              ");
    puts(" Oo=====================================oO");
    //for blablabla buat print semua user
    printf(" No.     Username\n");
    int i = 0;
    while (headHash[i]) {
        printf(" %2d      %s\n",i+1,headHash[i]->name);
        i++;
    }
    puts(" -----------------------------------------");
    puts(" [1] Register");
    puts(" [2] Login");
    puts(" [3] Exit");
    puts(" -----------------------------------------");
    puts(" Press 0 and enter to abort an operation");
    puts(" -----------------------------------------");
    printf(">> ");
}
void printLoginMenu(){
	time_t now = time(0);
	char *waktu = ctime(&now);
	while (1){
        system("cls");
	printf("Oo=====================================oO\n");
	printf("	Welcome %s \n",headHash[id]->name );
	printf("Oo=====================================oO\n");
	printf(" Logged in: %s" ,waktu);
	printf("-----------------------------------------\n\n");
	printf(" Friends of %s\n",headHash[id]->name);
	printf(" No.     Username\n");
    friendList *curr = headHash[id]->head;
    while (curr) {
        printf(" %2d      %s\n",curr->id,headHash[curr->id]->name);
        curr = curr->next;
    }
	printf("-----------------------------------------\n");
 	printf("		>>Menu<<\n");
	printf("-----------------------------------------\n");
	printf("[1] Add Friend\n");
	printf("[2] Remove Friend\n");
	printf("[3] View Inbox\n");
	printf("[4] View Sent Request\n");
	printf("[5] Add, Edit, Announce, Delete Note\n");
	printf("[6] Log out\n");
	
	printf("-----------------------------------------\n");
	printf(">> ");    
    int indexInputLogin = 0;
    
    while (indexInputLogin != 6)
    {
    scanf("%d",&indexInputLogin);
    if (indexInputLogin == 1) {
        printf("-----------------------------------------\n");
		printf("[All User]\n");
		printf(" ID.      Username\n");
		
        int i = 0;
        while (headHash[i]) {
            int n = 0;
            if (id == i ) {
                i++;
                continue;
            } else {
                 friendList *curr = headHash[id]->head;
                while (curr) {
                   if (curr->id == i) {
                       n = 1;
                       break;
                   }
                   curr = curr->next;
                }
                    if (n == 1) {
                        i++;
                        continue;
                    }
                }
            
            printf(" %d.      %s\n",i,headHash[i]->name);
            i++;
        }
		puts("Which use do you want to add?");
		printf(">> ");
        int indexInput = 0 ;
        scanf ("%d",&indexInput);
        pushInvitation(id,indexInput);
        printf("Back To The Main Menu");
        getchar();
        break;
		puts("");
    } else if (indexInputLogin == 2) {
        system("cls");
        printf("-----------------------------------------\n");
		printf(" Friends of %s\n",headHash[id]->name );//namanya
		printf(" No.      Username\n");
         friendList *curr = headHash[id]->head;
        while (curr) {
        printf(" %2d      %s\n",curr->id,headHash[curr->id]->name);
        curr = curr->next;
        }
		printf("\n\n");
		puts("Which user do you want to remove?");
		printf(">> ");
        int input;
        scanf("%d",&input);
        getchar();
        popFriend(input,id);
        popFriend(id,input);
        printf("Friends has been remove");
        getchar();
        break;
		puts("");
    } else if (indexInputLogin == 3) {
        int input ;
        invitation *temp = headInvitation;
        int  l = 1;
        int idStore[10002] = {};
        while(temp){
            if (temp->dest == id) {
            printf("%d. %s Add friend request from %s\n",l,headHash[temp->dest]->name,headHash[temp->from]->name);
            idStore[l] = temp->from;
            l++;
            }
            temp = temp->next;
        }

        // BRB KAWAN KONTOL AKU
        if (l == 1) {
            printf("1");
            printf("Good Carrick Kontol Djoni Juga");
            getchar();
            break;
        }
        getchar();
        scanf(">> %d",&input);
        insertFriend(id,idStore[input]);
        insertFriend(idStore[input],id);
        popInvitation(id,idStore[input]);
        printf("YAY YOU HAVE A NEW FAKE FRIEND");
        getchar();
        getchar();
        break;
    } else if (indexInputLogin == 4) {
         invitation *temp = headInvitation;
        int l = 1;
        while(temp){
            if (temp->from == id) {
            printf("%d. Sent Request to %s status Pending\n",l,headHash[temp->dest]);
            l++;
            }
            temp = temp->next;
        }
        getchar();
        getchar();
        break;
    }else if (indexInputLogin == 5){
        int inputUser = 0;
        
        while (inputUser != 3)
        {
        system("cls");
        printf("DashBoard\n");
        printf("------------------------------------\n");
        publicDashBoard *temp = headPublic;
        const char category[7][255] = {"Backlog","Progress","Peer Review","In Test","Done","Blocked"};
        int indexing = 1;
        while (temp) {
            printf(" %d.  Submit By: %s\n",indexing,headHash[temp->idPerson]);
            printf("     Category : %s\n",category[temp->category]);;
            printf("     Quote    : %s\n",temp->quote);
            indexing++;
            temp = temp->next;
        }
        privateDashBoard *cur = headPrivate;
        while (cur) {
            bool flag = false;
            for (int i = 0 ;cur->access[i] != '\0' ; i++) {
                if (cur->access[i] == id || cur->idPerson == id) {
                    flag = true;
                    break;
                }
            }
            if (flag == true) {
            printf(" %d.  Submit By: %s\n",indexing,headHash[cur->idPerson]);
            printf("     Category : %s\n",category[cur->category]);;
            printf("     Quote    : %s\n",cur->quote);
            indexing++;
            }
            cur = cur->next;
        }
        
        
        printf("------------------------------------\n");
        printf("What to do\n");
        printf("1. Add\n");
        printf("2. Edit \\ Delete\n");
        printf("3. Back\n");
        printf(">> ");
        scanf("%d",&inputUser);
            if (inputUser == 1) {
            int option = 0;
            printf("1. Public\n");
            printf("2. Private\n");
            printf(">> ");
            scanf("%d",&option);
            if (option == 1) {
                 printf("1. %s\n2. %s\n3. %s\n4. %s\n5. %s\n6. %s\n",category[0],category[1],category[2],category[3],category[4],category[5]);
            int cateOption = 0;
            scanf("%d",&cateOption);
            getchar();
            printf("Quotes : ");
            char quotesInput [256];
            scanf("%[^\n]",quotesInput);
            if (!headPublic){
                insertPublic(1,cateOption,quotesInput,id);
            } else {
                insertPublic((headPublic->id)+1,cateOption,quotesInput,id);
            }
            
            printf("Inputed");
            } else {
                   printf("1. %s\n2. %s\n3. %s\n4. %s\n5. %s\n6. %s\n",category[0],category[1],category[2],category[3],category[4],category[5]);
            int cateOption = 0;
            scanf("%d",&cateOption);
            getchar();
            printf("Quotes : ");
            char quotesInput [256];
            scanf("%[^\n]",quotesInput);
            int person;
            printf("Many Access [MAX 3] >> ");
            scanf("%d",&person);
            int access[4];
            for (int i = 0 ;i<person;i++) {
                printf("Person %d : ",i+1);
                scanf("%d",&access[i]);
            }
            if (!headPrivate) {
                insertPrivate(1,cateOption,quotesInput,access,id);
            }
            else insertPrivate((headPrivate->id)+1,cateOption,quotesInput,access,id);
            printf("Inputed");
            }
        }
            if (inputUser == 2) {
                publicDashBoard *array[1000];
                privateDashBoard *array2[1000];
                publicDashBoard *temp = headPublic;
                int indexing = 1;
                while (temp) {
                bool flag = false;
                if (temp->idPerson == id) {
                 printf(" %d.  Category : %s\n",indexing,category[temp->category]);;
                 printf("     Quote    : %s\n",temp->quote);
                 array[indexing-1] = temp;
                 indexing++;
                }
                 temp = temp->next;
                 privateDashBoard *cur = headPrivate;
                 int indexMid = indexing;
        while (cur) {
            bool flag = false;
            if (cur->idPerson == id) {
            printf(" %d. Category : %s\n",indexing,category[cur->category]);;
            printf("     Quote    : %s\n",cur->quote);
            array2[indexing-indexMid-1] = cur;
            indexing++;
            }
            cur = cur->next;
        }
        int option = 0;
        int indexOption = 0;
        printf("1. Edit\n");
        printf("2. Delete\n");
        printf("[1/2] [Edit/Delete Note] >> ");
        scanf("%d %d",&option,&indexOption);
        if (option == 1) {
            printf("1. %s\n2. %s\n3. %s\n4. %s\n5. %s\n6. %s\n",category[0],category[1],category[2],category[3],category[4],category[5]);
            int cateOption = 0;
            scanf("%d",&cateOption);
            printf("Quotes : ");
            getchar();
            char quotesInput [256];
            scanf("%[^\n]",quotesInput);
            if (indexOption <= indexMid) {
                publicDashBoard *node = array[indexOption-1];
                node->category = cateOption;
                strcpy(node->quote,quotesInput);
            } else {
                privateDashBoard *node = array2[indexOption-indexMid-1];
                node->category = cateOption;
                strcpy(node->quote,quotesInput);
            }
        } else if (option == 2) {
            printf("%d %s",array[indexOption-1]->id,array[indexOption-1]->quote);
            getchar();
            if (indexOption <= indexMid) {
                popPublic(array[indexOption-1]->idPerson,array[indexOption-1]->id);
                printf("Has deleted\n");
                getchar();
            } else {
                popPrivate(array2[indexOption-indexMid-1]->idPerson,array2[indexOption-indexMid-1]->id);
                printf("Deleted");
                getchar();
            }
        }
        }
            } else if (inputUser == 3) {
                system("cls");
                printMainMenu();
                break;
            }
        }
    }
    else if (indexInputLogin == 6) {
        break;
    }
    }
    if (indexInputLogin == 6) {
        break;
    }
    }
}
