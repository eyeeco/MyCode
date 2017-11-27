#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <set>
using namespace std;
/** Pascal Source program grammar checker
 *  name : ÁõÏà
 *  studentNumber: 21724005
 *
 *  The code can check 'if','then','else','begin','end' symbol in a stack
 *  The input are a file of lines like following:
 *  """
 *  if
 *  then
 *  else
 *  """
 *  There are 3 examples in the main function.
 *
 */
class Solution{
public:
    bool isValid(vector<string> arr){
        stack<string> stack_base;
        for(int i=0;i<arr.size();i++){
            if(!arr[i].compare("if")||!arr[i].compare("begin")) stack_base.push(arr[i]);
            if(!arr[i].compare("else")) return false;
            if(!arr[i].compare("then")){
                if(!stack_base.top().compare("if")) {
                    stack_base.pop();
                    if((i+1)<arr.size()&&!arr[i+1].compare("else")) i++;
                    }
                else return false;}
            if(!arr[i].compare("end")){
                if(!stack_base.top().compare("begin")) stack_base.pop();
                else return false;
            }
        }
        if(stack_base.size()==0) return true;
        else return false;
    }
};
int main()
{
    ifstream in("test_correct1.txt");
//    ifstream in("test_correct2.txt");
//    ifstream in("test_error1.txt");
    string line ;
    vector<string> pascal_origin ;
    //只过滤关键词
    set<string> key_word;
    key_word.insert("if");
    key_word.insert("else");
    key_word.insert("then");
    key_word.insert("begin");
    key_word.insert("end");
    //按照单词一个一个读入，只留下关键词
    if(in){
        while(in >> line){
            if(key_word.find(line)!=key_word.end())
                pascal_origin.push_back(line);
        }
    };
    //调用函数 1 ：合法 2 ：不合法
    Solution func;
    cout<<"The file is Valid ? " << func.isValid(pascal_origin) <<endl ;
    return 0;
}
