#include<iostream>
#include<cstdio>
using namespace std;

int a[64][64];
int n;
void divide(int r, int c, int chunk){
    if (chunk == 1){
        cout<<a[r][c];
        return;
    }
    int current = a[r][c];
    bool ok = true;

    for(int i = r; i < r + chunk; i++){
        for(int j=c; j < c + chunk; j++){
            if (current != a[i][j]){
                ok = false;
                break;
            }
        }
        if (!ok)
            break;
    }

    if (ok){
        cout<<current;
        return;
    }

    int new_chunk = chunk/2;
    cout<<"(";
    divide(r, c, new_chunk);
    divide(r, c + new_chunk, new_chunk);
    divide(r + new_chunk, c, new_chunk);
    divide(r + new_chunk, c + new_chunk, new_chunk);        
    cout<<")";
    
}

int main(){
    cin>>n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    divide(0, 0, n);
    return 0;
}