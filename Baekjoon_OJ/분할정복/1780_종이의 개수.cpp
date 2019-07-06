#include<iostream>
using namespace std;

int num[3] = {0, 0, 0};
int arr[2187][2187];
int row;
int divide(int a, int b, int chunk){
    if (chunk == 1)
        return arr[a][b];
    
    int sub_arr[9];
    int index = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            sub_arr[index++] = divide(a+(chunk/3)*i, b+(chunk/3)*j, chunk/3);
    int same = 1;
    for(int i = 0 ; i <8; i++){
        if (sub_arr[i] != sub_arr[i+1] || sub_arr[i] == -2){
            same = 0;
            break;
        }
    }
    if (sub_arr[9] == -2)
        same = 0;

    if (same){
        if(chunk == row)
            num[sub_arr[0]+1]++;
        return sub_arr[0];
    }
    else{
        for(int i = 0 ; i <9; i++){
                num[sub_arr[i]+1]++;
        }
        return -2;
    
    }
    
}

int main(){
    cin>>row;
    for(int i = 0; i < row; i++)
        for(int j = 0; j < row; j++)
            cin>>arr[i][j];
    divide(0, 0, row);
    for(int i = 0; i < 3; i++)
        cout<<num[i]<<endl;
}