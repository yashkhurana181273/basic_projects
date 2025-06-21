#include<iostream>
using namespace std;
class player{
    private:
     string name;
     char symbol;
    public:
    player(){};
    player(char sym,string n):symbol(sym),name(n){};
    string returnname()const{return name;}
    char returnsymbol()const{return symbol;}
};
class board{
private:
int filledcells;
char grid[3][3];
public:
board():filledcells(0){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            grid[i][j]=' ';
        }
    }
}
void drawBOARD()const{
    cout<<"-------" << endl;
    for(int i=0;i<3;i++){
        cout<<"|";
        for(int j=0;j<3;j++){
            cout<<grid[i][j]<<"|";
        }
        cout<<endl;
    }
    cout<<"-------" << endl;
}
bool valid_entry(int row,int col)const{
    return(row>=0 && row<=3 && col>=0 && col<=3 && grid[row][col]==' ');
    
}
void makemove(int row,int col,char symbol){
    if(valid_entry(row,col)){
      grid[row][col]=symbol; 
      filledcells++; 
    }
}
bool check_win(char symbol)const{
    for(int i =0;i<3;i++){
        if(grid[i][0]==symbol&&grid[i][1]==symbol && grid[i][2]==symbol){
            return true;
        }
    }
    for(int i =0;i<3;i++){
        if(grid[0][i]==symbol&&grid[1][i]==symbol && grid[2][i]==symbol){
            return true;
        }
    }
    if(grid[0][0]==symbol && grid[1][1]==symbol && grid[2][2]==symbol){
        return true;
    }
    if(grid[0][2]==symbol && grid[1][1]==symbol && grid[2][0]==symbol){
        return true;
    }
return false;
}
bool is_full()const{
    return filledcells==9;
}
int getcells()const{
    return filledcells;
}

};
class tic_tac_toe{
    private:
    board b1;
    player p[2];
    int currentplayerindex;
    public:
    tic_tac_toe():currentplayerindex(0){
    p[0]=player('X',"player x");
    p[1]=player('O',"player y");
    }
    void switchturn(){
        currentplayerindex=(currentplayerindex+1)%2;
    }
    player &current_player(){
        return p[currentplayerindex];
    }
    void play(){
        int row,col;
        cout<<"welcome to tic tac toe"<<endl;
        while(!b1.is_full()){
            b1.drawBOARD();
            player & current=current_player();
            while(true){
                cout << current.returnname() << " (" << current.returnsymbol() 
                     << "), enter row (1-3) and column (1-3): ";
                cin>>row>>col;
                row--,col--;
                if(!b1.valid_entry(row,col)){
                    cout<<"try again"<<endl;
                }
                else{
                    break;
                }
            }
            b1.makemove(row,col,current.returnsymbol());
            if(b1.check_win(current.returnsymbol())){
                b1.drawBOARD();
                cout<<current.returnname()<<" wins the game !!!"<<endl;
                return;
            }
            switchturn();
        }
        b1.drawBOARD();
        cout<<"game drawn :("<<endl;
        }

};
int main(){
    tic_tac_toe t;
    t.play();
    
    return 0;
}