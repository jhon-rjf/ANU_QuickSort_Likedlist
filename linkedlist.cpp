#include <iostream> 

// 노드 구조체 정의: 단일 연결 리스트의 각 요소
struct Node {
    int data; // 노드의 데이터
    Node* next; // 다음 노드를 가리키는 포인터

    
    Node(int d) : data(d), next(nullptr) {}// 생성자: 새로운 노드를 만들고, 다음 노드는 nullptr로 설정
};

// 연결 리스트 클래스 정의
class LinkedList {
    Node* head; // 리스트의 첫 번째 노드를 가리키는 포인터

public:
    // 생성자: 리스트가 비어있음을 나타내기 위해 head를 nullptr로 초기화
    LinkedList() : head(nullptr) {}

    // 새로운 데이터를 리스트에 추가하는 함수
    void add(int d) {
        Node* n = new Node(d); // 새로운 노드를 동적으로 생성
        if (!head) { // 리스트가 비어있다면, 새로운 노드를 head로 설정
            head = n;
        } else {
            Node* t = head; // 임시 포인터 t를 사용하여 리스트의 끝까지 이동
            while (t->next) t = t->next; // t가 마지막 노드를 가리킬 때까지 반복
            t->next = n; // 마지막 노드의 next를 새로운 노드로 설정
        }
    }

    // 리스트의 모든 데이터를 출력하는 함수
    void print() {
        Node* t = head; // 임시 포인터 t를 head로 초기화
        while (t) { // t가 nullptr이 아닐 때까지 반복
            std::cout << t->data << " "; // 현재 노드의 데이터를 출력
            t = t->next; // t를 다음 노드로 이동
        }
        std::cout << std::endl; // 출력 형식을 맞추기 위해 줄바꿈
    }

    // 소멸자: 리스트의 모든 노드를 삭제하여 메모리 누수를 방지
    ~LinkedList() {
        while (head) { // head가 nullptr이 될 때까지 반복
            Node* t = head; // 임시 포인터 t에 현재 head를 저장
            head = head->next; // head를 다음 노드로 이동
            delete t; // t가 가리키는 노드를 삭제
        }
    }
};

int main() {
    LinkedList list; // LinkedList 객체 생성
    list.add(1); // 리스트에 1 추가
    list.add(2); // 리스트에 2 추가
    list.add(3); // 리스트에 3 추가
    list.print(); // 리스트 출력: 1 2 3
    return 0; // 프로그램 종료
}

