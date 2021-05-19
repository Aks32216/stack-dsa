#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends


int minele;
void push(stack<int>& s, int a){
	if(s.size()==0)
	{
	    s.push(a);
	    minele=a;
	}
	else
	{
	    if(a>=minele)
	        s.push(a);
	    else
	    {
	        s.push(2*a-minele);
	        minele=a;
	    }
	}
}

bool isFull(stack<int>& s,int n){
	if(s.size()==n)
	    return 1;
	else
	    return 0;
}

bool isEmpty(stack<int>& s){
	if(s.size()==0)
	    return 1;
	else
	    return 0;
}

int pop(stack<int>& s){
    if(s.empty())
        return -1;
    int ans=s.top();
    s.pop();
    if(ans<minele)
        minele=2*minele-ans;
}

int getMin(stack<int>& s){
	if(s.empty())
	    return -1;
	return minele;
}