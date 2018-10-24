//Found some mistake...in the process.

#include <bits/stdc++.h>
using namespace std;
#define mp         make_pair
#define pb         push_back
#define mod        1000000007
typedef long long ll;

vector<int>  num;
map<int,int> nap;
void recur(int pos , int cnt , int f){
 if(cnt==0 && nap[0])
      return ;
 if(pos >num.size())
    return ;
 
 nap[cnt]+=1;
  nap[cnt]%= mod;

 int limit = 9;
 ll res = 0;

 if(!f){
  limit = num[pos];
 }
 
 for(int digit=0;digit<limit+1 ;digit++){
  int nf = f;
  int ncnt = cnt;
  if(f==0 && digit < limit) nf = 1;
  ncnt = cnt+ digit;
  recur(pos+1,ncnt,nf);
 }
  return ;

}

void solve(string n){

  num.clear();
   
   for(auto u : n)
    num.pb(u-'0');
   
   recur(0, 0, 0);
    
} 


bool is_prime(int n) {

    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    if (n < 25) return true;
    for (int i = 5; i*i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
  }

int main() 
{


  ios_base::sync_with_stdio(0); cin.tie(0);

  string n;
  cin>>n;
 
  solve(n);


  ll ans =0;
  for(int i=2;i<=449;i++){
   
    if(is_prime(i))
    {

       for(int k=0;k<= i/2 ;k++){
          
            if(k!=i-k){
            ans+= nap[k]*nap[i-k];
            ans%= mod;
           }
       }
    }
  }

  cout<<ans<<"\n";
 
}


  








