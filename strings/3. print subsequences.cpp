
void printSubsequence(string input, string output)
{
	if (input.empty()) {
		cout << output << endl;
		return;
	}
    printSubsequence(input.substr(1), output);
	printSubsequence(input.substr(1), output + input[0]);
}
int main(){
    string input="abc";
    string output="";
    printSubsequence(input,output);
}

// Iterative solution
for(int i=1;i<=(1<<n)-1;i++){
    for(int j=n-1;j>=0;j--){
        if (i&(1<<j)){
            cout<<s[j];
        }
    }
}