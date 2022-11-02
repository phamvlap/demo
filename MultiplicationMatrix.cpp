#include<iostream>
#include<vector>
#include<strings.h>
#include<string.h>

using namespace std;

vector<vector<int> > inputMaxtrix(){
    vector<vector<int> > A;
    cout << "Enter the Matrix:";
    int m,n;
    cout << "\nRows: ";
    cin >> m ;
    cout << "Colums: ";
    cin >> n;
    A.resize(m);
    for(int i=0;i<m;i++){
        A[i].resize(n);
    }
    for(int i=0;i<m;i++){
        for( int j=0;j<n;j++){
            cin >> A[i][j];
        }
    }
    return A;
}
void outputMatrix(vector<vector<int> > arr, string s){
    for(int i=0;i<arr.size();i++){
        if(i==0){
            cout << s << "| ";
            for( int j=0;j<arr[i].size();j++){
                cout << arr[i][j] << "  ";
            }
        }
        else{
            for(int i=0;i<s.length(); i++){
                cout << " ";
            }
            cout << "| ";
            for( int j=0;j<arr[i].size();j++){
                cout << arr[i][j] << "  ";
            }
        }
        cout << "|\n";
    }
    cout << "\n";
}
vector<vector<int> > multiplication(vector<vector<int> > arr1, vector<vector<int> > arr2){
    vector<vector<int> > arr;
    arr.resize(arr1.size());
    for( int i=0;i<arr1.size(); i++){
        arr[i].resize(arr2[0].size());
    }
    int k=0;
    for(int i=0;i<arr1.size();i++){
        for(int k=0;k<arr2[0].size();k++){
            int c=0;
            for(int j=0;j<arr1[0].size();j++){
                c+=arr1[i][j]*arr2[j][k];
            }
            arr[i][k]=c;
        }
    }
    return arr;
}
vector<vector<int> > Mab(vector<vector<int> > arr, int a, int b){
    vector<vector<int> > arr1;
    int n=arr.size()-1;
    arr1.resize(n);
    for( int i=0;i<arr1.size(); i++){
        arr1[i].resize(n);
    }
    vector<int> a_temp;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            if(i!=a && j!=b)
                a_temp.push_back(arr[i][j]);
        }
    }
    int k=0;
    for(int i=0;i<arr1.size(); i++){
        for(int j=0;j<arr1[i].size();j++){
            arr1[i][j]=a_temp[k++];
        }
    }
    return arr1;
}
int det(vector<vector<int> > arr){
    if(arr.size()==2)
        return arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
    else{
        int result=0;
        for(int i=0;i<arr.size(); i++){
            if(i%2==0)
                result+=arr[i][0]*det(Mab(arr, i, 0));
            else
                result-=arr[i][0]*det(Mab(arr, i, 0));
        }
        return result;
    }
}
void menu(){
    cout << "\n1.Multiplication Matrix (*)";
    cout << "\n2.Det() (.)";
    cout << "\n3.Exit";
}
int main(){
    int sel;
    system("cls");
    do{
        menu();
        cout << "\nEnter the your selection: ";
        cin >> sel;
        if(sel==1){
            vector<vector<int> > arr1, arr2, arr;
            arr1=inputMaxtrix();
            arr2=inputMaxtrix();
            if(arr1[0].size()==arr2.size()){
                system("cls");
                outputMatrix(arr1, "A = ");
                outputMatrix(arr2, "B = ");
                arr=multiplication(arr1, arr2);
                cout << "**Result\n";
                outputMatrix(arr, "A.B = ");
            }
            else{
                system("cls");
                outputMatrix(arr1, "A = ");
                outputMatrix(arr2, "B = ");
                cout << "Colums of matrix A is different rows of matrix B, so do not multiplication matrix!\n";
            }
        }
        else if(sel==2){
                vector<vector<int> > arr;
                arr=inputMaxtrix();
                if(arr.size()==arr[0].size()){
                    system("cls");
                    outputMatrix(arr, "A = ");
                    cout << "**Result\ndet(A) = " << det(arr) << "\n";
                }
                else{
                    system("cls");
                    outputMatrix(arr, "A = ");
                    cout << "This matrix is not square matrix\n";
                }
            }
            else{
                if(sel==3)
                    cout << "Good Bye!";
                else{
                    system("cls");
                    cout << "Please enter the valid number!\n";
                }
            }
    }while(sel!=3);
    return 0;
}