#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctime>


int reg(const char *name, const char *password) {
    int index = 0;
    headHash[index];
    int flag=1;
    while(headHash[index]) {

        if(strcmp(headHash[index]->name, name)==0) { //kalau username telah diambil, return 0 
            return 0;
        }
        index++;
    }

    insertHash(name, password); //kalau username belum ada, register user tersebut
    return 1;
}

//output tergantung function return 1 atau 0
int login(const char *logname, const char *logpass) {
    int index = 0;
    int flag=0;
    while(headHash[index]) {
        
        if(strcmp(headHash[index]->name, logname)==0) { //kalau username dan password ada di database dan benar
            if (strcmp(headHash[index]->pass,logpass) != 0) {
                return 2;
            }
            else{ 
                id = index;
                return 1;
        }
        }
        index++;
    }

    return 0; //kalau tidak ada, return 0;
}



int login(int n) {
    //CURRENTUSER == USER SEKARANG. DITENTUKAN MELALUI FUNGSI LOGIN DIBAWAH
        
    if(n==1)
    {
        	char name[255];
            char pass[255];
            
            printf("-----------------------------------------\n");
			printf("Please type in your username [lowercase || 1..24]: name\b\b\b\b");
			scanf("%s" , &name);
			printf("Please type in your password [lowercase || 1..24]: pass\b\b\b\b");
			scanf("%s" , &pass);
			getchar();
			puts("");

            //fungi register user. Menerima hanya jika username unik -> liat line 40
            if(reg(name, pass)==1) {
                printf("--- Registration Successfull ---\n\n");
			    printf("Press enter to continue!");
			    getchar();
                return 0;
            }
            
            else if(reg(name, pass)==0) {
                printf("Username already taken.\n");
                return 0;
            }
			
    }
    if(n==2)
    {
            char logname[255];
            char logpass[255];
            
            printf("-----------------------------------------\n");
			printf("Username: ");
			scanf("%s", &logname);
			printf("Password: ");
			scanf("%s" , &logpass);
			getchar();
			
            //kalau logpass dan logname ada di database -> login berhasil
            //CURRENT USER DITENTUKAN. PAKAI CURRENT USER UNTUK OPERASI LAINNYA
            if(login(logname, logpass)==1) {
                puts("");
				puts("---Login Successfull---");
				printf("Press enter to continue!");
				getchar();
				system("cls");
				printLoginMenu();
				getchar();
            }

            //kalau logname atau logpass salah
            else if(login(logname, logpass)==2) {
                printf("Your password is wrong!\n");
				printf("Press enter to go back!");
				getchar();
				system("cls");
            }
            else if(login(logname, logpass)==0) {
                printf("You are not in the database!\n");
				printf("Press enter to go back!");
				getchar();
				system("cls");
            }
    } else if (n ==3) {
        system("exit");
    }
    
    return 0;
}
