#include <iostream>
using namespace std;

// (1) Base라는 이름의 클래스에 접근 지정자마다 각 하나의 멤버 변수를 만들기 (확인을 위해 초기화 존재)
class Base {
    int a = 1; // private
public:
    int b = 2; // public

protected:
    int c = 3; // protected
};

// (2) Derived 1~3라는 이름의 자식 클래스 정의 및 Base 상속
class Derived1 : private Base {
public:
    void getNum() {
        // cout << Base::a << endl;
        cout << "D1 : " << Base::b << " / " << Base::c << endl;
    }
};

class Derived2 : public Base {
public:
    void getNum() {
        // cout << Base::a << endl;
        cout << "D2 : " << Base::b << " / " << Base::c << endl;
    }
};

class Derived3 : protected Base {
public:
    void getNum() {
        // cout << Base::a << endl;
        cout << "D3 : " << Base::b << " / " << Base::c << endl;
    }
};

// (3) main 함수에서 Derived1~3 객체 생성
int main()
{
    Derived1 D1;
    Derived2 D2;
    Derived3 D3;
    // private 부모 멤버 변수 출력 부분을 주석 처리 후 실행
    D1.getNum();
    D2.getNum();
    D3.getNum();
    // 객체를 통해 a~c에 접근 (= 외부에서 접근)
    cout << "외부 D1 : " << D1.b << endl; 
    cout << "외부 D2 : " << D2.b  << endl;
    cout << "외부 D3 : " << D3.b << endl;
    // D2 - b 제외 접근 불가  (D2의 a,c 포함)
}

