#include<bits/stdc++.h>

using namespace std;

// s = "ab#c", t = "ad#c"
// s = "ab##", t = "c#d#"

/*

"bxj##tw"
"bxo#j##tw"
*/

bool areEqual(string s, string t){
    int i = s.length()-1;
    int j = t.length()-1;
    while(i>=0 and j>=0){
        int count=0;
        while(i>=0 and s[i]=='#'){
            while(i>=0 and s[i]=='#'){
                count++;
                i--;
            }
            while(count>0){
                if(i>=0 and s[i]=='#'){
                    count++;
                }else{
                    count--;
                    i--;
                }
            }
            count=0;
        }
        count=0;
        while(j>=0 and t[j]=='#'){
            while(j>=0 and t[j]=='#'){
                count++;
                j--;
            }
            while(count>0){
                if(j>=0 and t[j]=='#'){
                    count++;
                }else{
                    count--;
                    j--;
                }
            }
            count=0;
        }
        i = max(i,-1);
        j = max(j,-1);
        if(i<0 and j<0){
            return true;
        }
        if(i<0 or j<0){
            return false;
        }
        if(s[i]!=t[j]){
            return false;
        }else{
            i--;j--;
        }
    }
    return true;
}

int main(){

    return 0;
}


