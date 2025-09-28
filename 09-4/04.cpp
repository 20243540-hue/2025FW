#include <iostream>
#include <string>
using namespace std;

// 부모 클래스 (기반 클래스)
class Mob {
private:
    string type; // 몬스터 종류

protected:
    int HP;   // 체력
    int ATK;  // 공격력
    string Size; // 크기

public:
    // (부모)생성자
    Mob(string t, int hp, int atk, string size)
        : type(t), HP(hp), ATK(atk), Size(size) {
        cout << type << " 몹 생성" << endl;
    }

    // Mob의 상태를 출력하는 함수
    void get_stats() {
        cout << "체력(HP): " << HP << endl;
        cout << "공격력(ATK): " << ATK << endl;
        cout << "크기(Size): " << Size << endl;
    }
};

// 자식 클래스 (파생 클래스) _ 오크
class Ork : public Mob {
public:
  // 자식 생성자
      Ork()
          : Mob("오크", 100, 30, "L") {}    // 부모 생성자 호출 및 초기화
};

// 자식 클래스2 _ 요정
class Fairy : public Mob {
public:
    // 자식 생성자
    Fairy()
        // 부모 Mob 생성자 호출 및 초기화
        : Mob("요정", 30, 15, "S") {}

    void heal() {
        HP += 10;
        cout << "요정이 회복합니다. 요정의 체력이 " << HP << "가 되었습니다." << endl;
    }
};

int main() {
    cout << "\n--- 몬스터 1: 오크 ---" << endl;
    Ork Ork1;
    Ork1.get_stats();

    // protected 멤버 변수 직접 접근 ==> 불가
    // Ork1.HP = 10; 

    Fairy Fairy1;
    Fairy1.get_stats();
    Fairy1.heal();
    Fairy1.get_stats();

    return 0;
}
