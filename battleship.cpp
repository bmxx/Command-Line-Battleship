/******************
Brian Macdonald
Assignment: Battleship, Final Project
Course:
******************/

#include <iostream>

using namespace std;


void error(char message)
{
     //Board::draw_board();
     cout << message << endl;
}

class Board
{
private:
    int x_size;
    int y_size;
public:
    Board(int x, int y)
    {
        x_size = x;
        y_size = y;
    }
    
    void draw_board()
    {
        draw_column_legend(); 
        for (int y = 0; y <= y_size; y++)
        {
            for (int x = 0; x <= x_size ; x++)
            {
                draw_cell(x, y);
            }
        }       
    }
    
    void draw_column_legend()
    {
        for (int x = 0; x <= x_size; x++)
        {
	    if(x == 0){
                cout << "   ||";
	    }
            cout << x << "||";
            if(x == x_size){ 
                cout << endl;
            }
        }
    }
    
    void draw_row_legend(int x)
    {
	string row_label;
	row_label = (string)x;
	if(x < 10){
	    row_label = " " + row_label;
	}
        cout << " " << x << " ";     
    }
    
    void draw_cell(int x, int y)
    {
         string CELL_BORDER = "||";
         // Left side border
         if(x == 0){
             draw_row_legend(y);
             cout << CELL_BORDER;
         }
         cout << x << CELL_BORDER;
         // End of row
         if(x == x_size){
             cout << endl;
         }
         
    }
    
    /*void place_ship(Ship &ship)
    {
        ship_x = ship.get_x_coord();                
    } */        
};

class Ship
{
private:
    int length;
    int height;
    int x_coord;
    int y_coord;
public:       
    Ship(int l, int h, int x)
    {
          set_length(l);
          set_height(h);
    }
    
    void set_length(int l)
    {
        length = l;               
    }
    
    int get_length()
    {
        return length;    
    }
    
    void set_height(int h)
    {
        height = h;               
    }
    
    int get_height()
    {
        return height;    
    }
        
    void set_new_coord(int x, int y)
    {
        x_coord = x;
        y_coord = y;                      
    }
    
    int get_x_coord()
    {
        return x_coord;    
    }
    
    int get_y_coord()
    {
        return y_coord;    
    }
    
};


int main()
{
    Board board(10, 10);
    board.draw_board();
    return 0;
}

