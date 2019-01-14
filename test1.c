#include <ncurses.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void openFile( char *name );
void editFile(char *name);
void menu();

int main(){

    initscr();
    keypad (stdscr, TRUE);
    noecho();
    
    int ch=0;
    char namefile[100]; 
    char *name;  
    
    while(ch != KEY_F(7)){
        
        clear();
        //gets_s(namefile);  
                
        menu();
        ch = getch();
        echo();
        
        
        switch(ch){
            
          case KEY_F(2):
	   printw("write name file\n");
	   scanw("%99s",namefile);
	   name=namefile;
	   
	   openFile(name);
	   break;
          
          case KEY_F(4):
	   printw("write name file\n");
	   scanw("%99s",namefile);
	   name=namefile;
	   
	   editFile(name);
	   break;
          default:
	   printw("not \n");
         }              
    }
    
    getch();
    endwin();   

return 0;

}

void openFile( char *name ){
	
	FILE *file;
	char c=0;
	
	file = fopen(name,"r");
	if(file == NULL){
	
	    printw("Error opening file\n");
	    return;
	}
	printw("file open\n");
	while(!feof(file)){
	
	    c=fgetc(file);
	    printw("%c",c);
	
	}
	printw("\n");
	getch();
	fclose(file);

}

void editFile(char *name){
	
	FILE *file;
	char c=0;
	
	file = fopen(name,"a+");
	if(file == NULL){
	
	    printw("Error opening file\n");
	    return;
	}
	printw("write q for exit\n");
	
	while(c != 'q'){    
	    
	    fputc(c,file);
	    c = getch();
	    }
	
	fclose(file);
}

void menu(){
	
	printw("F7 - exit\n");
	printw("F2 - reading file\n");
	printw("F4 - editing file \n");
	printw("\n");
	printw("write comand\n");
	
}



