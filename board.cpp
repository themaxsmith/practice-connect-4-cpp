#include <ncurses.h>
#include "board.h"


int Board::dropAtSpot(int playerID,int value){
  for (int y = 5; y >= 0; y--)
    {
    if (this->map[value][y] == 0){
        this->map[value][y] = playerID;

        if (this->checkWin(value,y) == 1){

                
            return 2;
        }

        return 1;
    }
    }
    return -1;
}

int Board::checkWin(int x,int y){
    int player = this->map[x][y];
    int count = 0;

    count = 0;
    //check row
    for (int xa = 0; xa < 7; xa++)
    {
       if (this->map[xa][y] == player){

           count = count + 1;
                 
           if (count == 4){
              
               return 1;
           }
       }else{
           count = 0;
       }
    }
    

    count = 0;
    //check col
    for (int ya = 0; ya < 7; ya++)
    {
       if (this->map[x][ya] == player){

           count = count + 1;
                 
           if (count == 4){
              
               return 1;
           }
       }else{
           count = 0;
       }
    }

       count = 0;
    //check dig
    for (int xa = -7; xa < 7; xa++)
    {
           attron(COLOR_PAIR(100));
   
       if (x + xa >= 0 && x + xa < 7 &&  y + xa >= 0  &&  y + xa < 6 && this->map[x + xa][y + xa] == player){
       
           count = count + 1;
            
           
           if (count == 4){
              
               return 1;
           }
       }else{
           count = 0;
       }
    }

   //check dig other
    for (int xa = -7; xa < 7; xa++)
    {
       if (x + xa >= 0 && x + xa < 7 &&  y - xa >= 0  &&  y - xa < 6 && this->map[x + xa][y - xa] == player){

           count = count + 1;
        
           if (count == 4){
              
               return 1;
           }
       }else{
           count = 0;
       }
    }
    return -1;
}

void Board::drawScene(){
    
        attron(COLOR_PAIR(1));


    for (size_t x = 0; x < 7; x++)
    {
         for (size_t y = 0; y < 6; y++)
    {

        switch (this->map[x][y])
        {
        case 1:

        attron(COLOR_PAIR(100));
        mvaddch( (y+1) * 2, (x*2) + 1, ' ');
            break;
              case 2:

        attron(COLOR_PAIR(101));
        mvaddch( (y+1) * 2, (x*2) + 1, ' ');
            break;
        default:
        attron(COLOR_PAIR(4));
        mvaddch( (y+1) * 2, (x*2) + 1, ' ');
            break;
        }

 

    } 
    }


//paint board
       for (size_t x = 0; x < 15; x++)
    {
         for (size_t y = 0; y < 13; y++)
    {
      attron(COLOR_PAIR(3));

            if (x % 2 == 0){
       mvaddch( y+1, x, ' ');
            }else{
            if (y % 2 == 0){
            mvaddch( y+1, x, ' ');

            }
            }
    }

    }

    mvaddch( 14, 0, ' ');
    mvaddch( 15, 0, ' ');

    mvaddch( 14, 14, ' ');
    mvaddch( 15, 14, ' ');
    
               

}
