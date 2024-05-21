#include <iostream> 
#include <vector> 
#include <algorithm> //swap

void qsort(std::vector<int>& a, int l, int r) {
    // l >= r, 정렬할 구간이 없으면 함수 종료
    if (l >= r) return;
    
    // 마지막 숫자를 피벗(pivot)으로 선택
    int p = a[r];
    // i는 피벗보다 작은 요소들이 들어갈 위치를 나타냄
    int i = l - 1;
    
    // l부터 r-1까지 반복하면서 피벗보다 작은 요소를 찾음
    for (int j = l; j < r; ++j) {
        if (a[j] < p) {
            // 피벗보다 작은 요소를 찾으면 i를 하나 증가시키고
            // 그 위치에 a[j]를 swap으로 교환함
            std::swap(a[++i], a[j]);
        }
    }
    // 피벗을 중간 위치로 이동
    std::swap(a[++i], a[r]);
    
    // 피벗의 왼쪽과 오른쪽 부분 배열에 대해 재귀적으로 퀵 정렬을 수행
    qsort(a, l, i - 1);
    qsort(a, i + 1, r);
}

int main() {
    // 정렬할 배열 시작점
    std::vector<int> a = {3, 2, 5, 1, 4};
    
    // qsort 함수를 호출하여 배열을 정렬
    qsort(a, 0, a.size() - 1);
    
    // 정렬된 배열을 출력
    for (int x : a) std::cout << x << " ";
    
    return 0;
}

