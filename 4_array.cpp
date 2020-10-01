#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n],odd=0,four=0,non_four=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if((arr[i]%2)!=0){
            odd=odd+1;
        }
        else if((arr[i]%4)==0){
            four=four+1;
        }
        else if(((arr[i]%2)==0) && ((arr[i]%4)!=0)){
            non_four=non_four+1;
        }
    }
    int oddarr[odd], fourarr[four], non_fourarr[non_four];
    for(int i=0;i<n;i++){
        if((arr[i]%2)!=0){
            for(int j=0;j<odd;j++){
                oddarr[j]=arr[i];
            }
        }
        else if((arr[i]%4)==0){
            for(int k=0;k<four;k++){
                fourarr[k]=arr[i];
            } 
        }
        else if(((arr[i]%2)==0) && ((arr[i]%4)!=0)){
            for(int l=0;l<non_four;l++){
                non_fourarr[l]=arr[i];
            }
        }
    }
    if(non_four==0 && four>=odd-1){
        int i=0;
        for(i=0;i<odd;i++){
            cout<<oddarr[i]<<" ";
            if(i<four){
                cout<<fourarr[i]<<" ";
            }
            i++;
        }
        while(i<four){
            cout<<fourarr[i]<<" ";
            i++;
        }
        cout<<endl;
    }
    else if(non_four>0 && four>=odd){
        int i=0,j=0;
        for(i=0;i<odd;i++){
            cout<<oddarr[i]<<" ";
            if(i<four){
                cout<<fourarr[i]<<" ";
            }
            i++;
        }
        while(i<four){
            cout<<fourarr[i]<<" ";
            i++;
        }
        while(j<non_four){
            cout<<non_fourarr[j]<<" ";
            j++;
        }
        cout<<endl;
    }
    else{
        cout<<"NOT POSSIBLE"<<endl;
    }
     return 0;
 }