#include<iostream>
using namespace std;

char grid[3][3] = {'1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9'};
int row , col; 
char turn = 'X';
bool draw = false;  
string player1 = " ";
string player2 = " ";

void details(){


    cout<<"\n\n"<<"       |       |      \n";
    cout<<"   "<<grid[0][0]<<"   |   "<<grid[0][1]<<"   |  "<<grid[0][2]<<" \n ";
    cout<<"______|_______|______\n";
    cout<<"       |       |      \n";
    cout<<"   "<<grid[1][0]<<"   |   "<<grid[1][1]<<"   |  "<<grid[1][2]<<" \n ";
    cout<<"______|_______|______\n";
    cout<<"       |       |      \n";
    cout<<"   "<<grid[2][0]<<"   |   "<<grid[2][1]<<"   |  "<<grid[2][2]<<" \n ";
    cout<<"      |       |     \n";
    

}

void userinput(){
  
    int value=0;

    // Allowing players to enter their turn  
    if(turn=='X'){
          cout<<"\n"<<player1<<" Enter your turn : ";
          cin>>value;
          
    }
    
    if(turn=='0'){
          cout<<"\n"<<player2<<" Now it's your turn : ";
          cin>>value;
        
    }
    

    //Number entered by players does to this condition 
    if(value==1){
        row = 0;
        col = 0;
    }
    
    if(value==2){
        row = 0;
        col = 1;
    }
    
    if(value==3){
        row = 0;
        col = 2;
    }
    
    if(value==4){
        row = 1;
        col = 0;
    }
    
    if(value==5){
        row = 1;
        col = 1;
    }
    
    if(value==6){
        row = 1;
        col = 2;
    }
    
    if(value==7){
        row = 2;
        col = 0;
    }
    
    if(value==8){
        row = 2;
        col = 1;
    }
    
    if(value==9){
        row = 2;
        col = 2;
    }
    
    else if(value < 1 || value > 9){
        cout<<"Inavlid !!! \n";
    }

    // Checking that if the player1 has enterd their chance ans same for the player2
    if(turn=='X' && grid[row][col] !='X' && grid[row][col] !='0' ){
           grid[row][col] = 'X';
           turn = '0';
    }
    
    else if(turn=='0' && grid[row][col] !='0' && grid[row][col] !='X' ){
           grid[row][col] = '0';
           turn = 'X';
    }
    else{
          cout<<" There is no empty space \n\n";
          userinput();
    }
   details();
}


bool game(){
    
    //Checks whether the game is draw or wins
    for(int i=0 ; i<3 ; i++){
         
          //Condition for Player wins horizontally or vertically 
          if(grid[i][0]==grid[i][1] && grid[i][0]==grid[i][2] || grid[0][i]==grid[1][0] && grid[0][i]==grid[2][i]){
              return true;
         
          }
          
          //Condition for Player wins diagonally 
          if(grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2] || grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0]){
              return true;
         
          }

          //Checks whether the game is finished or not
          for(int i=0 ; i<3 ; i++){
              for(int j=0 ; j<3 ; j++){
 
                  //Checks if the row and cols are not filled by 'X' and '0'
                    if(grid[i][j] != 'X' && grid[i][j] != '0'){
                         return false;
                    }

              }
          }
          
          draw = true;
          return true;
    }


}


int main(){
 
    cout<<" WELCOME TO TIC-TAC-TOE GAME \n\n";
    
    cout<<" Enter name of Player 1 : ";
    getline(cin,player1);
    
    cout<<" Enter name of Player 2 : ";
    getline(cin,player2);

    cout<<player1<<" is Player 1 \n";
    cout<<player2<<" is Player 2 \n";

    //Keeps iterating until game is not over i.e. false
    while(!game()){
        details();
        userinput();
        game();
    }

    //Checks Condition for which player wins the game or its a draw
    if(turn == 'X' && draw == false){
        cout<<player2<<" wins the game :) :)  \n\n";
    }

    else if(turn == '0' && draw == false){
        cout<<player1<<" wins the game :) :)  \n\n";
    }

    else{
        cout<<" Oops!! The game is drawn....Better luck next time :( :( \n\n";
    }
    return 0;
}