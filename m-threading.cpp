#include <bits/stdc++.h>
#include<thread>
using namespace std;
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(int i=a ; i<(b) ; ++i )
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
void method1(int n){
    int res=0;
    rep(i,1,n+1)
    res+=i;
    
    cout<<"Sum of First "<<n<<" Numbers: "<<res<<"\n";
}
void method2(int n){
    int res=1;
    rep(i,1,n+1)
    res*=i;
    
    cout<<"Factorial of "<<n<<": "<<res<<"\n";
}
void solve(){
    
    thread t1(method1, 5);// sigma = 15
    
    thread t2(method2, 5);// 5! = 120
    
    
    //Now we want the MainThread to wait for the thread t1//
    t1.join(); // join this to the MainThread
    
    
    //Now we want the MainThread to wait for the thread t1//
    t2.join(); // join this to the MainThread
    
    cout<<"The Text at the last of the Program\n";
}
int main() {
	fast_io;
	int t=1;
// 	cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}
/**
//OUTPUT ON EXECUTION//
Factorial of 5: 120
Sum of First 5 Numbers: 15
The Text at the last of the Program
*/
