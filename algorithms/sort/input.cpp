#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

template <typename T>
void print(T *d, int len){
    for(int i=0; i<len; i++)
        cout<<d[i]<<' ';
    cout<<endl;
    for(int i=0; i<len; i++)
        cout<<int(d[i])<<' ';
    cout<<endl;
}
template <typename T>
void loopRead(T *in, int len){
    int i = 0;
    while (i<len){
        std::cin>>in[i++];
    }
}
int main(int argc, char ** argv){
    /*
    int a, b;
    cin >> a >> b;
    cout << a<<' ' <<b<<endl;
    cout <<"========================="<<endl;
    */
    /*
    char a[20];
    cin>>a;
    cout<<a<<endl;
    */
   /*
    int a;
    char b[10];
    b[0] = cin.get();
    //cout<<b[0]<<':'<<int(b[0])<<endl;
    cout<<int(b[0])<<endl;
    b[0] = cin.get();
    cout<<int(b[0])<<endl;
    */
   
   int a;
   char b[10];
   cin.getline(b, 3);
   print(b,3);
   //cout<<"====\n"<<cin.fail()<<endl<<cin.bad()<<endl<<cin.good()<<endl;
   cout<<"====\n"<<cin.rdstate()<<endl;
   cin.clear(ios::eofbit|ios::badbit);
   //cout<<"====\n"<<cin.fail()<<endl<<cin.bad()<<endl<<cin.good()<<endl;
   cout<<"====\n"<<cin.rdstate()<<endl;
   a = cin.get();
   cout<<int(a)<<endl;
   //char c[10];
   //cin.getline(c, 3);
   //print(c,3);
  
   /*
    char d[4];
    cin.getline(d, 4);
    print(d,4);
    cout<<cin.get()<<endl;
    /*out
    string str;
    getline(cin, str, 'a');
    cout<<str<<endl;*/
}
