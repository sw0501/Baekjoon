//너무 어렵게 풀었다 나중에 고쳐야지

#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int N;

class Information{
	private :
	int Year;
	string Name;
	int Sequence;
	
	public :
	Information(){};
	Information(int year,string &name,int sequence){
		Year = year;
		Name = name;
		Sequence = sequence;
	}
	string name(){
		return Name;
	}
	int year(){
		return Year;
	}
	int sequence(){
		return Sequence;
	}
	bool operator<(Information s) const{
		if(this->Year==s.year()){
			return this->Sequence>s.sequence();
		}
		else {
			return this->Year<s.year();
		}
	}
};

vector<Information>arr;

void init();

void buble_sort();
void selection_sort_min();
void selection_sort_max();
void merge(int s,int m,int e);
void merge_sort(int s,int e);

int compare(int &i,int &j);
void change(int &i,int &j);
void change(Information &i,Information &j);

void print();

int main(){
	
	init();
	
	return 0;
}

void init(){
	
	cin>>N;
	for(int i=0;i<N;i++){
		int x; string y;
		cin >> x >> y;
		//scanf("%d",&x);
		//getline(cin,y);
		arr.push_back({x,y,i});
	}
	
	//buble_sort();
	//selection_sort_min();
	//selection_sort_max();
	merge_sort(0,N-1);
    //sort(arr.begin(),arr.end());
	
	print();
}

//버블 정렬
void buble_sort(){
	for(int i=0;i<N;i++){
		for(int j=i;j<N;j++){
			if(compare(i,j)){
				change(i,j);
			}
		}
	}
}

//최소 선택 정렬
void selection_sort_min(){
	int min = 0;
	for(int i=0;i<N;i++){
		for(int j=i;j<N;j++){
			if(compare(i,j)){
				min = j;
			}
		}
		change(i,min);
	}
}

//최대 선택 정렬 내림차순일경우 사용
void selection_sort_max(){
	int max = 0;
	for(int i=0;i<N;i++){
		for(int j=i;j<N;j++){
			if(arr[j].year()>arr[max].year()||(arr[j].year()==arr[max].year()&&arr[j].sequence()<arr[max].sequence())){
				max=j;
			}
		}
		change(i,max);
	}
}

//합병 정렬
void merge(int s,int m,int e){
	vector<Information>temp;
	for(int i=0;i<e-s+1;i++){
		temp.push_back({});
	}
	int i = s;
	int j = m+1;
	int copy = 0;
	while(i<=m&&j<=e){
		if(!compare(i,j)){
			swap(temp[copy++],arr[i++]);
		}
		else if(compare(i,j)){
			swap(temp[copy++],arr[j++]);
		}
	}
	while(i<=m){
		swap(temp[copy++],arr[i++]);
	}
	while(j<=e){
		swap(temp[copy++],arr[j++]);
	}
	for(int k=s;k<=e;k++){
		swap(temp[k-s],arr[k]);
	}

}

//합병 정렬
void merge_sort(int s, int e){
	if(s<e){
		int m = (s+e)/2;
		merge_sort(s,m);
		merge_sort(m+1,e);
		merge(s,m,e);
	}
}

int compare(int &i,int &j){
	if(arr[j].year()<arr[i].year()||(arr[j].year()==arr[i].year()&&arr[j].sequence()<arr[i].sequence()))return 1;
	return 0;
}

void change(int &i,int &j){
	Information temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void change(Information &i,Information &j){
	Information &temp = i;
	i=j;
	j=temp;
}


void print(){
	for(int i=0;i<N;i++){
		cout << arr[i].year() << " " << arr[i].name() <<"\n";
		//printf("%d %s\n",arr[i].year(),arr[i].name().c_str());
	}
}





