#include <iostream>
using namespace std;

int inorder[100000];
int postorder[100000];
int position[100001];

/*
2263 트리의 순회
프리오더 : root left right
in: 좌우 cnt 구하기 // post: root 찾기

 1) root출력 어떻게? postorder의 마지막은 root이다. => root를 찾는다.
2) root를 기준으로 좌,우로 나누자. inorder에서 root의 위치를 찾고, 좌 우로 분할.
3) 좌에서 root를 찾고, 우에서 root를 찾는다.
 
반복
 */

void solve(int in_start, int in_end, int post_start, int post_end){
    if(in_start > in_end || post_start > post_end) return;
    int root = postorder[post_end];
    int r_idx = position[root]; // inorder에서 root의 위치(cnt 계산 목적)
    int left_cnt = r_idx - in_start; // 좌측 개수 inorder에서 root의 위치 - inorder 시작 위치
 
    printf("%d ", root); // pre root 출력
    //좌측 호출
    solve(in_start, r_idx-1, post_start, post_start + left_cnt - 1);
    //우측 호출
    solve(r_idx+1, in_end, post_start+left_cnt, post_end-1);
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++) scanf("%d", &inorder[i]);
    for(int i=0;i<n;i++) scanf("%d", &postorder[i]);
    for(int i=0;i<n;i++){
        position[inorder[i]] = i;
    }
    solve(0, n-1, 0, n-1);
    return 0;
}
