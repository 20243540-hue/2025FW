#include <iostream>
using namespace std;

class Animal {
public:
    void speak() {  // 가상 함수
        cout << "동물이 소리를 냅니다." << endl;
    }
};

class Dog : public Animal {
public:
    void speak() { // 뒤에 실습 코드 그대로 override를 적을 경우 기본 클래스 멤버를 재정의하지 않는다는 오류가 출력됨 ==> override 삭제
        cout << "멍멍!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak(string t) { // Dog의 speak와 마찬가지로 override 삭제, a1 = a3을 통한다면 a3의 speak가 되는지, 오버로드가 되는지 테스트를 위해 string t를 파라미터로 받게 수정
        cout << t << endl;
    }
};

int main() {

    Animal a1;
    Dog a2;
    Cat a3;
    Animal a4;

    cout << "a1 = a2 하기 전에 a1 : ";
    a1.speak();

    
    cout << "a1 = a2 한 후에 a1 : ";
    a1 = a2;
    a1.speak();

    cout << "a2 : ";
    a2.speak();

    cout << "a3 : ";
    a3.speak("야~옹");

    cout << "a1 = a3 한 후에 그냥 speak : ";
    a1 = a3;
    a1.speak();

    // cout << "a1 = a3 한 후에 파라미터가 있는 speak : ";
    // a1.speak("냥"); 
    // 위의 경우 a3의 speak(파라미터가 있는 speak)가 호출되지 않음

    
    // a3 = a4;
    // 만약 부모 클래스 = 자식 클래스(Ex a1 = a2)와 반대로 [자식 클래스 = 부모 클래스]와 같이 작성할 경우 부모 클래스에서 자식 클래스로 변환되지 않음

    return 0;



