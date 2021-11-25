#include <bits/stdc++.h>
#include<thread>
#include<mutex> 
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

mutex mu;
mutex mu2;

void f_1(){
    mu.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));// for explicit context switch// 
    mu2.lock();
    rep(i,-1000,0){
        cout<<"i: "<<i<<" ";
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    cout<<"\n";
    mu.unlock();
    mu2.unlock();
}
void f_2(){
    mu2.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    mu.lock();
    rep(j,1,1001){
    cout<<"j: "<<j<<" ";
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    cout<<"\n";
    mu.unlock();
    mu2.unlock();
}
void solve(){
    thread t1(f_1);
    
    f_2();
    
    t1.join();
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

/*
//OUTPUT//
// DeadLock Case//
// The program will stop in between because or give SIGKILL //
// What happens is f_1 locks mutex mu and after context switching(as we have sleep statement after mu)  
// f_2 locks mu2 and now because f_1 cannot use mu2 and f_2 cannot use mu(already locked) both funtcions will wait
// for the other mutex to unlock //
*/