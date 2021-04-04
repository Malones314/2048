/** environment     Code::Blocks 17.12
 *   author             Malones   ( RuiChen Zhai)
 *   date                2021.3.28
 */
#include<bits/stdc++.h>
using namespace std;
void first_print();
void print( int [4][4]);
void ways( string way, int [4][4], int* number, int* maxNumber, int* totalScore);
int main(){
    system("title 2048");
    srand(time(0));
    int n[3] = { 2, 4, 8};
    int newNumber = 0;
    int maxNumber = 0;
    int number = 0;
    string way = "0";
    int matrix[4][4] = {0};
    int*totalScore;
    totalScore = new int(0);
    //WASD控制数字整体上下左右的移动
    do{
        print( matrix);
        int row, column;
        cout << "你的积分为：" << *totalScore << endl;
        cout << "请输入WSAD操控上下左右：";
        cin >> way;
        ways( way, matrix, &number, &maxNumber, totalScore);
        number++;
        if(number > 16)
            break;
        do{
            row = rand()%4;
            column = rand()%4;
        }while( matrix[row][column] != 0);
        newNumber = n[rand()%3];
        matrix[row][column] = newNumber;
    }while( maxNumber < 2048 && number <= 16);
    print(matrix);
    if( maxNumber == 2048)
        cout << "you Win";
    else
        cout << "you Lose";
    cout << endl << *totalScore;
    return 0;
}

void ways( string way, int matrix[4][4], int* number, int* maxNumber, int* totalScore){
    int number_ = 0;
    int maxNumber_ = *maxNumber;
    int i, j, k;
    if( way == "A"){
        for( i = 0; i < 4; i++)
            for( j = 0; j < 3; j++)
                if( matrix[i][j] == matrix[i][j+1]){
                    *totalScore += matrix[i][j];
                    matrix[i][j] *= 2;
                    matrix[i][j+1] = 0;
                }
        for( k = 0; k < 3; k++)
            for( i = 0; i < 4; i++)
                for( j = 0; j < 3; j++)
                    if( matrix[i][j] == 0){
                        matrix[i][j] = matrix[i][j+1];
                        matrix[i][j+1] = 0;
                    }
    }else if( way == "W"){
        for( j = 0; j < 4; j++)
            for( i = 0; i < 3; i++)
                if( matrix[i][j] == matrix[i+1][j]){
                    *totalScore += matrix[i][j];
                    matrix[i][j] *= 2;
                    matrix[i+1][j] = 0;
                }
        for( k = 0; k < 3; k++)
            for( j = 0; j < 4; j++)
                for( i = 0; i < 3; i++)
                    if( matrix[i][j] == 0){
                        matrix[i][j] = matrix[i+1][j];
                        matrix[i+1][j] = 0;
                    }
    }else if( way == "S"){
        for( j = 3; j > -1; j--)
            for( i = 3; i > 0; i--)
                if( matrix[i][j] == matrix[i-1][j]){
                    *totalScore += matrix[i][j];
                    matrix[i][j] *= 2;
                    matrix[i-1][j] = 0;
                }
        for( k = 0; k < 3; k++)
            for( j = 3; j > -1; j--)
                for( i = 3; i > 0; i--)
                    if( matrix[i][j] == 0){
                        matrix[i][j] = matrix[i-1][j];
                        matrix[i-1][j] = 0;
                    }
    }else if( way == "D"){
        for( i = 3; i > -1; i--)
            for( j = 3; j > 0; j--)
                if( matrix[i][j] == matrix[i][j-1]){
                    *totalScore += matrix[i][j];
                    matrix[i][j] *= 2;
                    matrix[i][j-1] = 0;
                }
        for( k = 0; k < 3; k++)
            for( i = 3; i > -1; i--)
                for( j = 3; j > 0; j--)
                    if( matrix[i][j] == 0){
                        matrix[i][j] = matrix[i][j-1];
                        matrix[i][j-1] = 0;
                    }
    }
    for( i = 0; i < 4; i++)
        for( j = 0; j < 4; j++){
            if( matrix[i][j])
                number_++;
            if( matrix[i][j] > maxNumber_)
                maxNumber_ = matrix[i][j];
        }
    *maxNumber = maxNumber_;
    *number = number_;
}

void first_print(){
    cout << "---------------------------------\n";
    cout << "每输入一次随机增加一个数字, \n当两个相邻数字相同时两数合并成一个\n当最大数字到2048则胜利";
    cout << "---------------------------------\n";
}
void print( int matrix[4][4]){
    system( "cls");
    for( int i  = 0; i < 4; i++){
        cout << "_____________________\n";
        cout << "|    |    |    |    |\n";
        cout << "|" << setw(4) << matrix[i][0] << "|" << setw(4) << matrix[i][1]
         << "|" << setw(4) << matrix[i][2] << "|" << setw(4) << matrix[i][3] << "|\n";
        cout << "|    |    |    |    |\n";
    }
}
