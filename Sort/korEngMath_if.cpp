/*
10825 국영수
*/
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

struct Person{
    string name;
    int korean, english, math;
};

bool cmp(const Person &p1, const Person &p2){
    if(p1.korean == p2.korean){ // 국어 같고
        if(p1.english == p2.english){ // 영어 같고
            if(p1.math == p2.math){ // 수학도 같으면
                return p1.name < p2.name; // 증가 정렬 완료 true
            }else { // 국 영 같고 수학이 다르면
                return p1.math > p2.math;
            }
        } else { //영어가 다르면
            return p1.english < p2.english; // 영어 점수가 같지 않으면 증가하는 순서(true)
        }
    } else { // 국어가 다르면
        return p1.korean > p2.korean; // 국어 감소 true
    }
}

int main(){
    int n;
    scanf("%d",&n);
    
    vector<Person> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].name >> a[i].korean >> a[i].english >> a[i].math;
    }
    
    sort(a.begin(), a.end(), cmp);
    
    for(auto &p: a)
        cout << p.name << "\n";

    return 0;
}
