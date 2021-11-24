#include <iostream>
#include<thread>
#include <chrono>
using namespace std;
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(int i=a ; i<(b) ; ++i )
typedef long long ll;
void method1(){
    rep(i,0,50){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        cout<<"$";
    }
}
void method2(){
    rep(i,0,50){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        cout<<"#";
    }
}
void solve(){
    
    thread t1(method1);// sigma = 15

    thread t2(method2);// 5! = 120
    
    cout<<"Thread id t1: "<<t1.get_id()<<"\n";
    //Now we want the MainThread to wait for the thread t1//
    t1.join(); // join this to the MainThread
    cout<<"Thread id t1: "<<t1.get_id()<<"\n";
    
    cout<<"Thread id t2: "<<t2.get_id()<<"\n";
    //Now we want the MainThread to wait for the thread t1//
    t2.join(); // join this to the MainThread
    cout<<"Thread id t2: "<<t2.get_id()<<"\n";
    
    
    cout<<"The Text at the last of the Program\n";
    system("pause>nul");
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
Thread id t1: 23249053124352
##################################################$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$Thread id t1: thread::id of a non-executing thread
Thread id t2: 23249051023104
Thread id t2: thread::id of a non-executing thread
The Text at the last of the Program


//AFTER ADDING SLEEP STATEMENT BEFORE PRINTING IN BOTH THE FUNCTIONS//
// WE CAN WITNESS CONTEXT SWITCHING // t=1ms
Thread id t1: 22514290558720
#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$$#$##$$##$$##$$##$$##$$##$$##$$#$##$$##$$##$Thread id t1: thread::id of a non-executing thread
Thread id t2: 22514288457472
Thread id t2: thread::id of a non-executing thread
The Text at the last of the Program

//t=100ms
Thread id t1: 23252564117248
#$#$#$#$#$#$#$#$#$#$$##$$##$$#$##$$##$$##$#$$##$$##$$##$$##$$##$#$$##$$#$##$$##$$##$$##$$##$$##$$#$Thread id t1: thread::id of a non-executing thread
Thread id t2: 23252562016000
#Thread id t2: thread::id of a non-executing thread
The Text at the last of the Program

*/
