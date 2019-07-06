#include<iostream>
using namespace std;

int main(){
    int n1, n2, m1, m2;
    cin>>n1>>m1;
    int a[100][100], b[100][100], result[100][100];
    for(int i = 0; i < n1; i++)
        for(int j=0; j < m1; j++)
            cin>>a[i][j];
    cin>>n2>>m2;
    for(int i = 0; i < n2; i++)
        for(int j=0; j < m2; j++)
            cin>>b[i][j];

    int new_n = n1;
    int new_m = m2;

    for(int i = 0; i < new_n; i++){
        for(int j = 0; j <new_m; j++){
            int sum = 0;
            for(int k = 0; k < m1; k++){
                sum += a[i][k]*b[k][j];
            }
            result[i][j] = sum;
            cout<<result[i][j]<<" ";   
        }
        cout<<endl;
    }
    return 0;
}