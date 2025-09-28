#include <iostream>
#include <string>
using namespace std;

// 단일 상속 코드에 introduce를 private, protected로 수정 ⇒ 상속할 때도 public, private, protected로 해서 6가지
// ⇒ introduce를 private 넣고 접근하는 법  (friend 쓰지 말고)
// 
// 부모 클래스 (기반 클래스)
class Person {
    void introduce() {
        cout << "이름: " << name << ", 나이: " << age << endl;
    }

public:
    Person(string n, int a) : name(n), age(a) {}
    void introduce2() {
        cout << "이름: " << name << ", 나이: " << age << endl;
    }
protected:
    string name;
    int age;
    void introduce3() {
        cout << "이름: " << name << ", 나이: " << age << endl;
    }
};

// 자식 클래스 (파생 클래스)
class Student : private Person {
private:
    string major;

public:
    Student(string n, int a, string m) : Person(n, a), major(m) {}

    void study() {
        cout << name << " 학생이 " << major << " 전공 공부 중입니다." << endl;
    }
};

class Student2 : public Person {
private:
    string major;

public:
    Student2(string n, int a, string m) : Person(n, a), major(m) {}

    void study() {
        cout << name << " 학생이 " << major << " 전공 공부 중입니다." << endl;
    }
};

class Student3 : protected Person {
private:
    string major;

public:
    Student3(string n, int a, string m) : Person(n, a), major(m) {}

    void study() {
        cout << name << " 학생이 " << major << " 전공 공부 중입니다." << endl;
    }
};

int main() {
    Student s("최길동", 21, "컴퓨터공학");
    Student2 s2("김길동", 22, "컴퓨터공학");
    Student3 s3("박길동", 23, "컴퓨터공학");
    // s.introduce();   // 부모 클래스 함수 사용
    // s2.introduce();
    // s3.introduce();
    // 부모 클래스 내에서 함수가 private에 있을 때 ==> 상속을 어떻게 받든 접근할 수 없음 (오류로 주석 처리)

    // 이전 실습(표) 확인용
    // s.introduce2();
    s2.introduce2(); // public - public만 가능
    // s3.introduce2();
    

    // s.introduce3();
    // s2.introduce3(); 
    // s3.introduce3();
    // 부모 클래스 내에서 함수가 protected에 있을 때 ==> protected 성질에 따라 클래스 외부에서는 private 성질로 바뀌기 때문에 접근이 막혀 상속을 어떻게 받든 접근할 수 없음 (오류로 주석 처리)

    s.study();       // 자식 클래스 함수 사용
    return 0;
}
