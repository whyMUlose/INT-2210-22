#include <bits/stdc++.h>
#include <map>
#include <string>

using namespace std;

struct Student {
public:
        string name;
    string class_name;

    Student(string name, string class_name) {
        this->name = name;
        this->class_name = class_name;
    }
};

struct University {
public:
   map<int , Student> students;

public:
    void insert(int ID, string name, string class_name) {
        Student x =  Student(name, class_name);
       students.insert({ID, x});

    }

    void deletestudent(int ID) {
        for(auto &x : students) {
                if(x.first == ID) {
                     students.erase(x.first);
                     break;
                }
        }
    }
 void infor(int ID) {
     bool check = false;
     for(auto&x : students) {
        if(x.first == ID)
        {
            check = true;
            cout << (x.second).name<< " "<< (x.second).class_name;
        break;
        }
     }
     if(!check) cout << "NA,NA";
 }
};


int main() {
University uni = University();
  uni.insert(1,"Tuan", "K61CS");
  uni.insert(2, "Vinh", "K43C");



  uni.deletestudent(3);
  cout << endl;
  uni.infor(3);
  cout << endl;
 uni.infor(3);
 cout << endl;
 uni.infor(2);
 cout << endl;
 uni.deletestudent(2);
 cout << endl;
 uni.infor(2);



    return 0;
}
