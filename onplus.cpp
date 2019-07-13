#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printv(std::vector<int> v){
    for(int i = 0; i<v.size(); i++)
            cout<< v[i];
    cout<<endl;
}

/*vector<int> plusOne(vector<int> &A) {
    int n = A.size()-1;
    int carry = 0;
    if(A[n]!=9)
        A[n] = A[n]+1;
    else{
        for (int i = n; i>=0; i--){
            //int carry = 0;
            cout<<"checkpoint 1: "<<A[i]<<endl;
            if(A[i]==9){
                A[i] = 0;
                carry+=1;
            }
            else{
                A[i] = A[i]+carry;
                carry = 0;
                cout<<"checkpoint 2: "<<A[i]<<endl;
            }
        }
    }
    printv(A);
    cout<< endl;
    if(A[0]==0){
        cout<<"hello, inside last if "<<endl;
        A.push_back(1);
        int temp = A[0];
        cout<<"temp: "<<temp<<endl;
        A[0] = A[A.size()-1];
        cout<<A[0]<<endl;
        A[A.size()-1] = temp;
        cout<<A[A.size()-1]<<endl;
    }
    return A;
}
*/

vector < int > plusOne(vector < int > & A) {
    //printv(A);
    int n = A.size() - 1;
    int sum = A[n] + 1;
    A[n] = sum % 10;
    int carry = sum / 10;
    for (int i = n - 1; i >= 0; i--) {
        int sum = A[i] + carry;
        A[i] = sum % 10;
        carry = sum / 10;
    }
    vector < int > B;
    if (carry == 1) {
        B.push_back(1);
        for (int i = 0; i < A.size(); i++)
            B.push_back(A[i]);
        //printv(B);
        return B;
    } 
    else {
        bool done = false;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != 0)
                done = true;
            if (done)
                B.push_back(A[i]);
        }

    }
}

int main(){
    vector <int> A;

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        A.push_back(a);
    }
    vector<int> v = plusOne(A);
    for(int i = 0; i<v.size(); i++)
            cout<< v[i];
    cout<<endl;
    return 0;

}
