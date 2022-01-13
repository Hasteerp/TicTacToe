#include "globals.h"
#include "GameState.h"

void playMove(GameState& game_state) 
{
    int elementO=0;
    int elementX=0;
    // Checking if move is valid or not 
    if((game_state.get_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn())==Empty))
    {
        game_state.set_moveValid(true); 
    }
    else 
    {
        game_state.set_moveValid(false); 
        return;
    }
// putting X or O according to turn 
    if(game_state.get_moveValid() == true)
    {
        if(game_state.get_turn())
        {
            game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), X); 
        } 
        else 
        {
            game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), O);
        }
    }
    
    
// Changing the turn of the player from X to O and vice versa 
    if( game_state.get_turn())
    {
        game_state.set_turn(false);
    }
    else 
    {
        game_state.set_turn(true);
    }
// Checking for all the win statements begins here... 
// Diagonal from top left to bottom right 
    for(int i=0;i<3; i++)
    {
        if(game_state.get_gameBoard(i,i) == X)
        {
            elementX=elementX+1;
            
        }
        else if (game_state.get_gameBoard(i,i) == O)
        {
            elementO=elementO+1;
        }
        if(elementX == 3||elementO == 3)
        {
            game_state.set_winCode(7);
            game_state.set_gameOver(true);
            return; 
        }
        
    }
    elementX=0;
    elementO=0;
// Row 1 
    for(int i=0;i<3; i++)
    {
        if(game_state.get_gameBoard(0,i)==X)
        {
            elementX=elementX+1;
            
        }
        else if (game_state.get_gameBoard(0,i)==O)
        {
            elementO=elementO+1;
        }
        if(elementX == 3||elementO == 3)
        {
            game_state.set_winCode(1);
            game_state.set_gameOver(true);
            return; 
        }
        
    }
    elementX=0;
    elementO=0;
//Row 2
    for(int i=0;i<3; i++)
    {
        if(game_state.get_gameBoard(1,i)==X)
        {
            elementX=elementX+1;
            
        }
        else if (game_state.get_gameBoard(1,i)==O)
        {
            elementO=elementO+1;
        }
        if(elementX == 3||elementO == 3)
        {
            game_state.set_winCode(2);
            game_state.set_gameOver(true);
            return; 
        }
        
    }
    elementX=0;
    elementO=0;
// Row 3
    for(int i=0;i<3; i++)
    {
        if(game_state.get_gameBoard(2,i) == X)
        {
            elementX=elementX+1;
            
        }
        else if (game_state.get_gameBoard(2,i) == O)
        {
            elementO=elementO+1;
        }
        if(elementX == 3||elementO == 3)
        {
            game_state.set_winCode(3);
            game_state.set_gameOver(true);
            return; 
        }
        
    }
    elementX=0;
    elementO=0;
// Column 1
    for(int i=0;i<3; i++)
    {
        if(game_state.get_gameBoard(i,0) == X)
        {
            elementX=elementX+1;
            
        }
        else if (game_state.get_gameBoard(i,0) == O)
        {
            elementO=elementO+1;
        }
        if(elementX == 3||elementO == 3)
        {
            game_state.set_winCode(4);
            game_state.set_gameOver(true);
            return;
        }
        
    }
    elementX=0;
    elementO=0;
// Column 2
    for(int i=0;i<3; i++)
    {
        if(game_state.get_gameBoard(i,1) == X)
        {
            elementX=elementX+1;
            
        }
        else if (game_state.get_gameBoard(i,1) == O)
        {
            elementO=elementO+1;
        }
        if(elementX == 3||elementO == 3)
        {
            game_state.set_winCode(5);
            game_state.set_gameOver(true);
            return;
        }
        
    }
    elementX=0;
    elementO=0;
// Column 3
    for(int i=0;i<3; i++)
    {
        if(game_state.get_gameBoard(i,2) == X)
        {
            elementX=elementX+1;
            
        }
        else if (game_state.get_gameBoard(i,2) == O)
        {
            elementO=elementO+1;
        }
        if(elementX == 3||elementO == 3)
        {
            game_state.set_winCode(6);
            game_state.set_gameOver(true);
            return; 
        }
        
    }
    elementX=0;
    elementO=0;
//Other Diagonal 

    
    if(game_state.get_gameBoard(2,0) == X && game_state.get_gameBoard(1,1) == X && game_state.get_gameBoard(0,2) == X)
    {
        elementX=3;
            
    }
    else if(game_state.get_gameBoard(2,0) == O && game_state.get_gameBoard(1,1) == O && game_state.get_gameBoard(0,2) == O)
    {
        elementO=elementO+1;
    }
    if(elementX == 3||elementO == 3)
    {
        game_state.set_winCode(8);
        game_state.set_gameOver(true);
        return; 
    }
    elementX=0;
    elementO=0;

// Incase of draw 
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(game_state.get_gameBoard(i,j) != Empty)
            {
                elementX=elementX+1;
            }
            if(elementX == 9)
            {
                game_state.set_winCode(0);
                game_state.set_gameOver(true);
                return;
            } 
        }
    }
    game_state.set_winCode(0);
    game_state.set_gameOver(false);
    return; 
        
        
        
    
    



}

