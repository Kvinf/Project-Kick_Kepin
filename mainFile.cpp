#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "firstMenu.cpp"
#include "login.cpp"
#include <ctime>


int main () {
int inputMenu = 0;
    while (inputMenu != 3) {
    	printMainMenu();
    	scanf("%d",&inputMenu);
    	login(inputMenu);
        system("cls");
	}
}

