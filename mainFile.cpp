#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "firstMenu.cpp"
#include "login.cpp"
#include <ctime>


int main () {
    insertHash("Kevin","1");
    insertHash("Carrick","2");
    insertHash("Djoni","3");
    insertHash("nana","papa");
	 int inputMenu = 0;
    while (inputMenu != 3) {
    	printMainMenu();
    	scanf("%d",&inputMenu);
    	login(inputMenu);
        system("cls");
	}
}

