#include<iostream>
using namespace std;

int getMax(int x,int y){
    return x>y?x:y;
}


void print_matrix(int **mat,int Rows,int Columns){
      for(int i=0;i<Rows;i++){
        for(int j=0;j<Columns;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int Coin_Collector(int **matrix,int Rows,int Columns){
    int** Dummy_matrix=new int*[Rows+1];
        for(int i=0;i<=Rows;i++)
            Dummy_matrix[i]=new int[Columns+1];
    //Fill dummy matrix with 0s for first column and row
    for(int i=0;i<=Rows;i++){
        for(int j=0;j<=Columns;j++){
            if(i==0 || j==0)
                Dummy_matrix[i][j]=0;
            else
                Dummy_matrix[i][j]=matrix[i-1][j-1];
        }
    }

    for(int i=1;i<=Rows;i++){
        for(int j=1;j<=Columns;j++){
            //f(i,j)=max{f(i-1,j),f(i,j-1)}+c[i][j]
           Dummy_matrix[i][j]+=getMax(Dummy_matrix[i-1][j],Dummy_matrix[i][j-1]);
        }
    }

    print_matrix(Dummy_matrix,Rows+1,Columns+1);
    return Dummy_matrix[Rows][Columns];
}



int main(){
    //1 represent a coin.
    int Row,Column;
    cout<<"enter # of rows:";
    cin>>Row;cout<<endl;
    cout<<"enter # of columns";
    cin>>Column;cout<<endl;
    int** matrix=new int*[Row];
    for(int i=0;i<Row;i++)
        matrix[i]=new int[Column];
    
    cout<<"Fill the matrix, 1 means there's a coin otherwise put 0"<<endl;
    for(int i=0;i<Row;i++)
        for(int j=0;j<Column;j++)
            cin>>matrix[i][j];
    
    cout<<"you can collect "<<Coin_Collector(matrix,Row,Column)<<" coin(s)\n";
}

/*
Test case:
matrix:
Rows = 5
Columns = 6

0 0 0 0 1 0
0 1 0 1 0 0
0 0 0 1 0 1
0 0 1 0 0 1
1 0 0 0 1 0

output: 5
*/