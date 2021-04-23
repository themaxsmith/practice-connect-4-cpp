#include "board.h"
#include <ncurses.h>
#include <stdlib.h> 

int main(){
    int playerTurn = 1;
    int status = 1;

      initscr(); 
          start_color();
 
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_BLUE);
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
 init_pair(4, COLOR_WHITE, COLOR_WHITE);
init_pair(100, COLOR_BLACK, COLOR_RED);
init_pair(101, COLOR_BLACK, COLOR_YELLOW);
init_pair(200, COLOR_BLACK,  COLOR_WHITE);
   Board board =  Board();

   while (status){
    clear();
     if (playerTurn == 1){
     attron(COLOR_PAIR(100));
         printw("Player 1 select a spot to place your circle thing (1-8): ");
     }else{
  attron(COLOR_PAIR(101));
         printw("Player 2 select a spot to place your circle thing (1-8): ");
     }

    board.drawScene();

    refresh();  
  char input =  getch();   
  int inputDrop = atoi(&input);
  if (inputDrop != 0){
    status = board.dropAtSpot(playerTurn,inputDrop-1);
               
        if (status == 2){
  attron(COLOR_PAIR(200));
                    clear();
              printw("Player %d won!", playerTurn);
               refresh();
              getch();   
              status = 0;
                  endwin();    

              return 0;
        }
                playerTurn == 1 ? playerTurn = 2 : playerTurn = 1;
    
   }
   }


  
    endwin();    


return 0;
}