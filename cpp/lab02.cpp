//หลอดไอซี
/*
#include <iostream>
#include <string>
#include <list>
using namespace std;
int main(){
    list<int> l;
    string type;
    int n , num;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>> type;
        if(type == "li"){
            cin>>num;
            l.push_front(num);
        }else if(type == "ri"){
            cin>>num;
            l.push_back(num);
        }else if(type == "lr"){
            l.push_back(l.front());
            l.pop_front();
        }else if(type == "rr"){
            l.push_front(l.back());
            l.pop_back();
        }
    }
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << endl;
    }
}*/

//ใส่เเละลบ 1
/*
#include<iostream>
#include<list>
#include <iterator>
using namespace std;
int main(){
    int n,num;
    string type;
    list<int> l;
    cin>>n;
    for(int i = 0 ;i<n;i++){
        cin>>type;
        if(type == "I"){
            cin>> num;
            l.push_front(num);
        }
        else if(type == "D"){
            cin >>num;
            if(num>0 && num<=l.size()){ 
                auto itr = l.begin();
                advance(itr,num-1);
                l.erase(itr);
                }
        }
        
    }
    for (auto v : l)
        std::cout << v << "\n";
    return 0 ;
}*/


//ข้อสอง
/*
#include<iostream>
#include<list>
#include <iterator>
using namespace std;
int main(){
    int n,num;
    string type;
    list<int> l;
    cin>>n;
    for(int i = 0 ;i<n;i++){
        cin>>type;
        if(type == "I"){
            cin>> num;
            l.push_front(num);
        }
        else if(type == "A"){
            cin >>num;
            l.push_back(num);
        }
        else if(type == "D"){
            cin >>num;
            if(num>0 && num<=l.size()){ 
                auto itr = l.begin();
                advance(itr,num-1);
                l.erase(itr);
                }
        }
        
    }
    for (auto v : l)
        std::cout << v << "\n";
    return 0 ;
}*/


#include <iostream>
#include <list>
using namespace std;

int main() {
    const int NOstation = 200000;
    int n, data1, data2;
    char command;

    // Create an array of linked lists
    list<int> station[NOstation];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command >> data1 >> data2;
        if (command == 'N' && data2 >= 1 && data2 < NOstation) {
            station[data2].push_back(data1);
        } else if (command == 'M' && data1 < NOstation && data2 < NOstation) {
            station[data2].splice(station[data2].end(), station[data1]);
        }
    }

    // Display elements in all linked lists
    for (int i = 1; i < NOstation; i++) {
        for (const auto &element : station[i]) {
            cout << element << endl;
        }
    }

    return 0;
}