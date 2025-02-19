#include<iostream>
#include<map>
#include<stack>
 using namespace std;
 map<string,int> calNumOfElements1(string str)
 {
 	stack<char> stc;
	//if(!str.empty())stc.push(str[0]);
	int i =0;
	map<string,int> myMap;
	while(i<str.length())
	{
		if(str[i]>='a'&& str[i]<='z')
		{
			stc.push(str[i]);
			i++;
		}
		else if(str[i]>='A'&&str[i]<='Z')
		{
			string temp_s="";
			while(!stc.empty()){
				temp_s+=stc.top();
				stc.pop();
			}
			reverse(temp_s.begin(),temp_s.end());
			if(temp_s!="")myMap[temp_s]++;
			stc.push(str[i]);
			i++;
		}
		else{
			string temp_s="";
			while(!stc.empty()){
				temp_s+=stc.top();
				stc.pop();
			}
			reverse(temp_s.begin(),temp_s.end());
			myMap[temp_s]++;
			int n = atoi(str.substr(i).c_str());
			myMap[temp_s]*=n;
			while(str[i]>='0'&&str[i]<='9')i++;
		}
	}
	string temp_s="";
	while(!stc.empty()){
		temp_s+=stc.top();
		stc.pop();
	}
	reverse(temp_s.begin(),temp_s.end());
	if(temp_s!="")myMap[temp_s]++;
		
	return myMap;
 }
 void insert_map(map<string,int> &dest,map<string,int> src)
 {
 	for(map<string,int>::iterator it=src.begin();it!=src.end();it++)
 	{
	 	if(dest.count(it->first))dest[it->first] +=src[it->first];
	 	else dest.insert(make_pair(it->first,it->second));
 	}
 }
 map<string,int> calNumOfElements2(string str)
 {
 	int i =0;
 	map<string,int> dest;
 	while(i<str.length())
 	{
 		string temp_s = "";
	 	while(i<str.length() && str[i]!='(')
	 	{
	 		temp_s+=str[i];
	 		i++;
	 		
	 	}
	 	map<string,int> myMap1;
		map<string,int> myMap2;
	 	if(temp_s!="")myMap1 = calNumOfElements1(temp_s);
	 	string temp_s2="";
	 	i++;
	 	while(i<str.length() && str[i]!=')')
	 	{
	 		
	 		temp_s2+=str[i];
		    i++;
	 		
	 	}
	 	//cout<<"i=="<<i<<endl;
	 	//cout<<temp_s2<<endl;
	 	if(temp_s2!="")myMap2 = calNumOfElements1(temp_s2);
	 	i++;
	 	//cout<<"i=="<<i<<endl;
	 	//for(map<string,int>::iterator it=myMap2.begin();it!=myMap2.end();it++)
//		{
//			cout<<it->first<<":"<<it->second<<" ";
//		}
	 	if(i<str.length()&&str[i]>='0'&&str[i]<='9')
	 	{
	 		int n = atoi(str.substr(i).c_str());
	 		//cout<<"n=="<<n<<endl;
	 		for(map<string,int>::iterator it=myMap2.begin();it!=myMap2.end();it++)it->second *=n;
	 		//cout<<"i=="<<i<<endl;
	 	}
	 	
	 	while(str[i]>='0'&&str[i]<='9')i++;
	 	if(!myMap1.empty())insert_map(dest,myMap1);
	 	if(!myMap2.empty())insert_map(dest,myMap2);
	 	//cout<<"i=="<<i<<endl;
    }
    return dest;
 }
 void test(){
	 
 }
void test3(){
	int i;
	int j;
	int k;
	int d;
	int e;
	int f;
	int g;
	
	int m;
	int s;
	
	int o;
	int v;
}

void fun3(int value){
	//todo
}
void fun(int value){
	//ToDo
}
void fun2(int value){
	//ToDo
}
int add(int val1,int val2){
	return val1+ val2;
}
int subtract(int a,int b){
	return a-b;
}

int divides(int a,int b){
	return a/b*2;
}
int multiply(int a,int b){
	return a*b;
}
int power(int x,int y){
	int temp = x;
	while(y--)x = temp*x;
}
int factorial(int n){
	if(n<=0) return 1;
	int res = 1;
	for(int i =1;i<=n;i++)res*=i;
	return res;
}
int main()
{
	printf("ÇëÊäÈë»¯Ñ§Ê½£º");
	string str;
	cin>> str;
	map<string,int> myMap = calNumOfElements2(str);
	for(map<string,int>::iterator it=myMap.begin();it!=myMap.end();it++)
	{
		cout<<it->first<<":"<<it->second<<" ";
	}
	printf("\n");
	return 0;
}
