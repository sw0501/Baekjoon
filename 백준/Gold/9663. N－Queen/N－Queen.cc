#include<iostream>

using namespace std;

int N; //퀸 개수, 체스보드 넓이
int board[15][15]; //체스보드
int count=0; //놓을 수 있는 경우의 수

void Board(); //보드 출력
void Queen(int row); //시작행

int main(){
	
	cin>>N;
	
	Queen(0);
	
	cout<<count;
	
	return 0;
}

void Queen(int row){
	//행은 퀸을 놓고 건너뛰기 때문에 고려 X
	for(int j=0;j<N;j++)
	{
		int temp=1;
		//퀸이 놓여진 열인지 확인
		for(int i=0;i<row;i++)
		{
			if(board[i][j])
			{
				temp=0;
				break;
			}
		}
		
		//대각선방향에 퀸이 있는지 확인
		if(temp)
		{
			for(int k=0;row-k>=0&&j-k>=0;k++)
			{
				//좌측
				if(board[row-k][j-k])
				{
					temp=0;
					break;
				}
			}
			for(int k=0;row-k>=0&&j+k<N;k++)
			{
				//우측
				if(board[row-k][j+k])
				{
					temp=0;
					break;
				}
			}
		}
		
		//퀸을 놓을 수 있는 위치에 해당한다면
		if(temp)
		{
			if(row==N-1)
			{
				//board[row][j]=1;
				//Board();
				//board[row][j]=0;
				count++;
			}
			else
			{
				board[row][j]=1;
				Queen(row+1);
			}
		}
		board[row][j]=0; //재귀 종료시 퀸 위치에 놓인 정보 삭제
	}
}

void Board(){
	cout<<"Chess Board\n\n";
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n\n";
	}
}



