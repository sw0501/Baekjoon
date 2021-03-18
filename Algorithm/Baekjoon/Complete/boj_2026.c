#include <stdio.h>

int stu[900][900]={0}; //친구관계
int fr[900]={0}; //소풍 갈 학생들 나열
int K; //소풍 갈 학생 수
int N; //전체 학생 수
int F; //친구 관계 수
int next=0; //시작할 친구 번호 -> 필요없음
int flag=1; //출력여부 확인

void friend(); //관계 입력
int search(int count); //예시를 찾음

int main()
{
    scanf("%d %d %d",&K,&N,&F); //K,N,F 입력
    friend(); //관계 정리
    //K==1인 경우 1출력
    if(K==1){
      flag=0;
      printf("%d",1);
    }
    else search(1);
    if(flag)printf("-1");
    return 0;
}

void friend(){
    int f1,f2; //친구 관계 임시 저장
    for(int i=0;i<F;i++){
        scanf("%d %d",&f1,&f2); //친구 관계 입력
        //if(next>(f1>f2?f2:f1)-1)next=(f1>f2?f2:f1)-1; next 구하기
        //양쪽에 모두 입력 -> 1,8 or 8,1 모두 동일하게 적용
        stu[f1-1][f2-1]=1;
        stu[f2-1][f1-1]=1;
    }
}

int search(int count){
    int temp; //친구 번호 임시 저장

    //0부터 시작하여 이미 등록된 학생은 제외
    for(int i=next;i<N;i++){

      //친구관계가 성립하고 소풍갈 학생으로 등록되지 않았다면
        if(stu[next][i]==1&&fr[i]==0){
              int flag2=1; //앞서 등록된 친구들과도 친구관계인지 확인
              //앞서 등록된 친구들과 비교
              for(int j=0;j<N;j++){
                //등록된 친구라면
                if(fr[j]!=0){
                  //등록된 친구와 현재 친구가 친구관계가 아니라면
                  if(stu[j][i]!=1){
                    flag2=0; //조건X
                    break; //탈출
                  }
                  
                }
              }
              if(flag2){
                count++; //카운트 증가
                fr[next]=next+1; //소풍 갈 학생으로 등록
                temp = next; //현재 번호 임시저장
                next=i; //next에 친구관계인 다음 학생 저장
                fr[next]=next+1;

                //목표 학생 수에 도달했다면
                if(count==K){

                  flag=0; //출력여부 저장
                  fr[next]=next+1; //현재 학생 등록
                    
                  //등록된 학생 출력
                  for(int j=0;j<N;j++){
                      if(fr[j]!=0)printf("%d\n",fr[j]);
                  }

                  //종료
                  return count;
                }
                  
                //다음 친구관계 찾기 실행
                int s_count = search(count);
                //카운트가 증가하지 않았다면 조건에 부합하지않으므로
                if(s_count==count){
                    count--; //카운트 감소
                    fr[next]=0;
                    fr[temp]=0; //소풍 갈 학생 취소
                    next=temp; //기존의 친구 번호로 다시 진행
                }
                else if(s_count==count+1)return count; //카운트가 증가했다면 조건에 부합하므로 리턴
              }
        }
    }
    //시작한 번호에서 조건에 부합하는 친구 관계가 없을 때 다음 친구 번호로 넘어감
    if(count==1&&next!=N-1&&flag){
      next++;
      search(1);
    }
    //진행중인 친구관계에서 다음 친구 관계가 없을 때 현재 카운트 리턴 -> 생략 가능
    else return count;
}


