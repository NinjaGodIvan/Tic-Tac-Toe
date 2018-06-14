#include <iostream>
#include <cstdlib>
using namespace std;

void board(char []);
bool validNumber(bool [],char);
bool validNumber_AI(bool [],int);
bool checkNumPlayers(int);
bool checkWhoWon(char[]);
bool checkDraw(bool[],char []);
void placeX(char [],char);
void placeO(char [],char);
void placeO_AI(char [],int);
void rules();
void twoPlayer();
void onePlayer();

int main(){
    
    char enter;
    char play_again = 'N';
    int numPlayers = 0;
    
    //Displays rules
    rules();
    
    cout << endl;
    
    cout <<"Press enter if you agree with the rules\n";
    cin.get(enter);
    
    //As long as user types Y or y, the game will run
    do{
    
    cout <<"Select the number of players: ";
    cin >> numPlayers;
        
    bool valid = checkNumPlayers(numPlayers);
        
    cout << endl;
        
        while(!valid){
            cout <<"Error: Select 1 or 2 players\n";
            cout <<"Select the number of players: ";
            cin >> numPlayers;
            valid = checkNumPlayers(numPlayers);
        }
    
    if(numPlayers == 1)
        onePlayer();
    else
        twoPlayer();
        
        cout <<"Play again? ";
        cin >> play_again;
        
    }while(play_again == 'y' || play_again == 'Y');
    
    cout <<"Thanks you for playing!\n";

    return 0;
}

bool checkNumPlayers(int players){
    
    if(players == 1 || players == 2)
        return true;
    else
        return false;
    
    return false;
}

void onePlayer(){
    
    bool valid_slot[9] = {false,false,false,false,false,false,false,false,false};
    char num[10] = {'1','2','3','4','5','6','7','8','9'};
    char selection;
    int AI = 0;
    
    bool x = false;
    
    while(x == false){
        
        //prints board
        board(num);
        
        //Player 1's turn
        cout <<"Player 1\n";
        cout <<"Choose number: ";
        cin >> selection;
        
        //checks to see if there's a slot taken
        bool valid = validNumber(valid_slot,selection);
        
        //if player 1 chose an invalid slot, reenter number
        while(valid == false){
            cout << endl;
            cout <<"Error: This spot is used!" << endl;
            cout <<"Reenter a valid number: ";
            cin >> selection;
            valid = validNumber(valid_slot,selection);
        }
        
        //places X on any slot
        placeX(num,selection);
        
        x = checkWhoWon(num);
        
        //terminates loop if there a match is made
        if(x == true)
            break;
        
        x = checkDraw(valid_slot,num);
        
        //terminates loop if all slots are taken
        if(x == true)
            break;
        
        srand(time(NULL));
        
        //AI picks numbers 1-10
        AI = rand() % 10 + 1;
        
        valid = validNumber_AI(valid_slot,AI);
        
        while(valid == false){
            srand(time(NULL));
            AI = rand() % 10 + 1;
            valid = validNumber_AI(valid_slot,AI);
        }
        
        //places O on any slot
        placeO_AI(num,AI);
        
        //checks if any player has a match
        x = checkWhoWon(num);
        
        
        //terminates loop if there a match is made
        if(x == true)
            break;
        
        //checks to see if all slots are taken; if all taken, game is a draw
        x = checkDraw(valid_slot,num);
    }
    
}

void twoPlayer(){
    
    bool valid_slot[9] = {false,false,false,false,false,false,false,false,false};
    char num[10] = {'1','2','3','4','5','6','7','8','9'};
    char selection;
    
    bool x = false;
    
    while(x == false){
        
        //prints board
        board(num);
        
        //Player 1's turn
        cout <<"Player 1\n";
        cout <<"Choose number: ";
        cin >> selection;
        
        //checks to see if there's a slot taken
        bool valid = validNumber(valid_slot,selection);
        
        //if player 1 chose an invalid slot, reenter number
        while(valid == false){
            cout << endl;
            cout <<"Error: This spot is used!" << endl;
            cout <<"Reenter a valid number: ";
            cin >> selection;
            valid = validNumber(valid_slot,selection);
        }
        
        //places X on any slot
        placeX(num,selection);
        
        x = checkWhoWon(num);
        
        //terminates loop if there a match is made
        if(x == true)
            break;
        
        x = checkDraw(valid_slot,num);
        
        //terminates loop if all slots are taken
        if(x == true)
            break;
        
        board(num);
        
        //Player 2's turn
        cout <<"Player 2\n";
        cout <<"Choose number: ";
        cin >> selection;
        
        valid = validNumber(valid_slot,selection);
        
        while(valid == false){
            cout << endl;
            cout << "Error: This spot is used!" << endl;
            cout << "Reenter a valid number: ";
            cin >> selection;
            valid = validNumber(valid_slot,selection);
        }
        
        //places O on any slot
        placeO(num,selection);
        
        //checks if any player has a match
        x = checkWhoWon(num);
        
        //terminates loop if there a match is made
        if(x == true)
            break;
        
        //checks to see if all slots are taken; if all taken, game is a draw
        x = checkDraw(valid_slot,num);
    }
}

void rules(){
    
    cout <<"Welcome to NinjaGodIvan's Tic-Tac-Toe Game!\n";
    cout << endl;
    cout <<"Rules:\n";
    cout <<"1.Don't be a dick in this game\n";
    cout <<"2.Player is declared winner if they did a match\n";
    cout <<"made a match, the player who made the match first will win\n";
    cout <<"3.If all slots are taken, then this game is considered a draw\n";
}

void board(char num[]){
    
    //prints two lines
    for(int i = 0; i < 2; i++){
        cout <<"         |";
    }
    
    cout << endl;
    
    //prints two lines and numbers 1 to 2
    for(int i = 0; i < 2; i++){
        cout <<"    "<< num[i] <<"    |";
    }
    
    //prints number 3
    cout <<"    " << num[2] << endl;
    
    //prints two lines
    for(int i = 0; i < 2; i++){
        cout <<"         |";
    }
    
    cout << endl;
    
    //prints horizontal lines
    cout <<"-----------------------------" << endl;
    
    //prints two lines
    for(int i = 0; i < 2; i++){
        cout <<"         |";
    }
    
    cout << endl;
    
    //prints two lines and numbers 4 to 5
    for(int i = 3; i < 5; i++){
        cout <<"    "<< num[i] <<"    |";
    }
    
    //prints number 6
    cout <<"    " << num[5] << endl;
    
    //prints two lines
    for(int i = 0; i < 2; i++){
        cout <<"         |";
    }
    
    cout << endl;
    
    //prints horizontal lines
    cout <<"-----------------------------" << endl;
    
    //prints two lines
    for(int i = 0; i < 2; i++){
        cout <<"         |";
    }
    
    cout << endl;
    
    //prints two lines and numbers 7 to 8
    for(int i = 6; i < 8; i++){
        cout <<"    "<< num[i] <<"    |";
    }
    
    //prints number 9
    cout <<"    " << num[8] << endl;
    
    //prints two lines
    for(int i = 6; i < 8; i++){
        cout <<"         |";
    }
    
    cout << endl;

    
};

void placeX(char num[],char selection){
    
    if(selection == '1')
        num[0] = 'X';
    else if(selection == '2')
        num[1] = 'X';
    else if(selection == '3')
        num[2] = 'X';
    else if(selection == '4')
        num[3] = 'X';
    else if(selection == '5')
        num[4] = 'X';
    else if(selection == '6')
        num[5] = 'X';
    else if(selection == '7')
        num[6] = 'X';
    else if(selection == '8')
        num[7] = 'X';
    else
        num[8] = 'X';
    
};

void placeO(char num[],char selection){
    
    if(selection == '1')
        num[0] = 'O';
    else if(selection == '2')
        num[1] = 'O';
    else if(selection == '3')
        num[2] = 'O';
    else if(selection == '4')
        num[3] = 'O';
    else if(selection == '5')
        num[4] = 'O';
    else if(selection == '6')
        num[5] = 'O';
    else if(selection == '7')
        num[6] = 'O';
    else if(selection == '8')
        num[7] = 'O';
    else
        num[8] = 'O';
    
};

void placeO_AI(char num[],int val){
    
    if(val == 1)
        num[0] = 'O';
    else if(val == 2)
        num[1] = 'O';
    else if(val == 3)
        num[2] = 'O';
    else if(val == 4)
        num[3] = 'O';
    else if(val == 5)
        num[4] = 'O';
    else if(val == 6)
        num[5] = 'O';
    else if(val == 7)
        num[6] = 'O';
    else if(val == 8)
        num[7] = 'O';
    else
        num[8] = 'O';
    
};

bool validNumber(bool valid_number[],char selection){
    
    if(selection == '1' && valid_number[0] == false){
        valid_number[0] = true;
        return true;
    }
    else if(selection == '2' && valid_number[1] == false){
        valid_number[1] = true;
        return true;
    }
    else if(selection == '3' && valid_number[2] == false){
        valid_number[2] = true;
        return true;
    }
    else if(selection == '4' && valid_number[3] == false){
        valid_number[3] = true;
        return true;
    }
    else if(selection == '5' && valid_number[4] == false){
        valid_number[4] = true;
        return true;
    }
    else if(selection == '6' && valid_number[5] == false){
        valid_number[5] = true;
        return true;
    }
    else if(selection == '7' && valid_number[6] == false){
        valid_number[6] = true;
        return true;
    }
    else if(selection == '8' && valid_number[7] == false){
        valid_number[7] = true;
        return true;
    }
    else if(selection == '9' && valid_number[8] == false){
        valid_number[8] = true;
        return true;
    }
    else
        return false;
    
    return false;
}

bool validNumber_AI(bool valid_number[],int val){
    
    if(val == 1 && valid_number[0] == false){
        valid_number[0] = true;
        return true;
    }
    else if(val == 2 && valid_number[1] == false){
        valid_number[1] = true;
        return true;
    }
    else if(val == 3 && valid_number[2] == false){
        valid_number[2] = true;
        return true;
    }
    else if(val == 4 && valid_number[3] == false){
        valid_number[3] = true;
        return true;
    }
    else if(val == 5 && valid_number[4] == false){
        valid_number[4] = true;
        return true;
    }
    else if(val == 6 && valid_number[5] == false){
        valid_number[5] = true;
        return true;
    }
    else if(val == 7 && valid_number[6] == false){
        valid_number[6] = true;
        return true;
    }
    else if(val == 8 && valid_number[7] == false){
        valid_number[7] = true;
        return true;
    }
    else if(val == 9 && valid_number[8] == false){
        valid_number[8] = true;
        return true;
    }
    else
        return false;
    
    return false;
}

bool checkWhoWon(char winner[]){
    
        if(winner[0] == 'X' && winner[1] == 'X' && winner[2] == 'X'){
            board(winner);
            cout <<"Player 1 wins!\n";
            return true;
        }
        else if(winner[0] == 'O' && winner[1] == 'O' && winner[2] == 'O'){
            board(winner);
            cout <<"Player 2 wins!\n";
            return true;
        }
        else if(winner[3] == 'X' && winner[4] == 'X' && winner[5] == 'X'){
            board(winner);
            cout <<"Player 1 wins!\n";
            return true;
        }
        else if(winner[3] == 'O' && winner[4] == 'O' && winner[5] == 'O'){
            board(winner);
            cout <<"Player 2 wins!\n";
            return true;
        }
        else if(winner[6] == 'X' && winner[7] == 'X' && winner[8] == 'X'){
            board(winner);
            cout <<"Player 1 wins!\n";
            return true;
        }
        else if(winner[6] == 'O' && winner[7] == 'O' && winner[8] == 'O'){
            board(winner);
            cout <<"Player 2 wins!\n";
            return true;
        }
        else if(winner[0] == 'X' && winner[3] == 'X' && winner[6] == 'X'){
            board(winner);
            cout <<"Player 1 wins!\n";
            return true;
        }
        else if(winner[0] == 'O' && winner[3] == 'O' && winner[6] == 'O'){
            board(winner);
            cout <<"Player 2 wins!\n";
            return true;
        }
        else if(winner[1] == 'X' && winner[4] == 'X' && winner[7] == 'X'){
            board(winner);
            cout <<"Player 1 wins!\n";
            return true;
        }
        else if(winner[1] == 'O' && winner[4] == 'O' && winner[7] == 'O'){
            board(winner);
            cout <<"Player 2 wins!\n";
            return true;
        }
        else if(winner[2] == 'X' && winner[5] == 'X' && winner[8] == 'X'){
            board(winner);
            cout <<"Player 1 wins!\n";
            return true;
        }
        else if(winner[2] == 'O' && winner[5] == 'O' && winner[8] == 'O'){
            board(winner);
            cout <<"Player 2 wins!\n";
            return true;
        }
        else if(winner[0] == 'X' && winner[4] == 'X' && winner[8] == 'X'){
            board(winner);
            cout <<"Player 1 wins!\n";
            return true;
        }
        else if(winner[0] == 'O' && winner[4] == 'O' && winner[8] == 'O'){
            board(winner);
            cout <<"Player 2 wins!\n";
            return true;
        }
        else if(winner[2] == 'X' && winner[4] == 'X' && winner[6] == 'X'){
            board(winner);
            cout <<"Player 1 wins!\n";
            return true;
        }
        else if(winner[2] == 'O' && winner[4] == 'O' && winner[6] == 'O'){
            board(winner);
            cout <<"Player 2 wins!\n";
            return true;
        }
        else
            return false;
   
    return false;
}

bool checkDraw(bool slot[],char num[]){
    
    if(slot[0] == true && slot[1] == true && slot[2] == true && slot[3] == true && slot[4] == true && slot[5] == true && slot[6] == true && slot[7] == true && slot[8] == true)
    {
        
        if(num[0] != '1' && num[1] != '2' && num[2] != '3' && num[3] != '4' && num[4] != '5' && num[5] != '6' && num[6] != '7' && num[7] != '8' && num[8] != '9')
        {
            board(num);
            cout <<"Draw\n";
            return true;
        }
        else
            return false;
        
    }
    else
        return false;
    
    return false;
}
