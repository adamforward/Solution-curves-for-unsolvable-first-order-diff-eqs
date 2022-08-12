
#include <iostream>
#include <string> 
#include <stack> 
#include <vector> 
#include <queue>
using namespace std; 
bool isOperand(string n){ 
  
 for (int i=0;i<n.length();i++) if(n=="0"||n=="1"||n=="2"||n=="3"||n=="4"||n=="5"||n=="6"||n=="7"||n=="8"||n =="9"||n=="y"||n=="t"||n=="e"||n=="pi")//y^t get replaced by numbers when the string is evaluated. 
   return true; 
  else 
   return false;//test all functions before using. this one works. 
}
bool isPrefix(string s){
  if(s=="tan"||s=="cos"||s=="sin"||s=="ln")
    return true; 
  else if(s=="arcsin"||s=="arctan"||s=="arccos")
    return true; 
  else
    return false; 
}
int priority(string op){
  if (op=="+"||op=="-")
    return 1; 
  if (op=="*"||op=="/")
    return 2; 
  if (op=="^")
    return 3; 
  if (isPrefix(op)==true)
    return 4; 
}

bool hasHigherPriority(string topOfStack, string index){
  if (priority(topOfStack)<priority(index))
    return false;
  else 
    return true;
}
bool isLeftParenthases(string x){
  if (x=="(")
    return true; 
  else
    return false; 
}
bool isRightParenthases(string x){
  if (x==")")
    return true;
  else
    return false;
}

bool isOperator(string s){
  if (s=="+"||s=="-"||s=="*"||s=="/"||s=="^")
    return true;
  else 
    return false; 
}
bool isOp(string s){
  if(isOperator(s)==true||isPrefix(s)==true)
    return true; 
  else
    return false; 
}
stack<string> infixToPostfix(vector<string> infix){//this is the repl it where I am going to get this function working. 
stack<string> ops; 
  stack<string> res; 
  
  //infix to postfix 
  for (int i=0; i<infix.size(); i++){
    //1. Print operands as they arrive.
    if (isOperand(infix[i])==true){
      res.push(infix[i]); 
      continue; 
      }
    //2. If the stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack.
    if(isOp(infix[i])==true&&(ops.empty()==true|| isLeftParenthases(ops.top())==true)){
      ops.push(infix[i]);
      continue;
      }
    //3. If the incoming symbol is a left parenthesis, push it on the stack.
    if(isLeftParenthases(infix[i])) {
      ops.push(infix[i]);
      continue; 
      }
      // 4. If the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis. Discard the pair of parentheses.
    if(isRightParenthases(infix[i])==true){
      while(ops.top()!="("){
        res.push(ops.top()); 
        ops.pop(); 
      }
      ops.pop();
       //get rid of left paren. 
        }
      //5. If the incoming symbol has higher precedence than the top of the stack, push it on the stack.
      if (isOp(infix[i])&&priority(ops.top())<priority(infix[i]))
        ops.push(infix[i]);
      continue; 
    //6. If the incoming symbol has equal precedence with the top of the stack, use association. If the association is left to right, pop and print the top of the stack and then push the incoming operator. If the association is right to left, push the incoming operator. so A + B - C sin(tan(x))=xtansin-doesn't matter for prefix expressions due to parens so this rule is only for ops A + B - C prio(+)==prio(-), you want AB+C- 
      if(isOperator(infix[i])==true&&priority(infix[i])==priority(ops.top())){
          res.push(ops.top()); 
          ops.pop(); 
          ops.push(infix[i]);
          continue; 
        } 
      
        //7. If the incoming symbol has lower precedence than the symbol on the top of the stack, pop the stack and print the top operator. Then test the incoming operator against the new top of stack.
        if((isOperator(infix[i])==true||isPrefix(infix[i])==true)&& (priority(ops.top())>priority(infix[i]))){   
            while(priority(ops.top())>priority(infix[i])||ops.empty()==true){
          res.push(ops.top());
          ops.pop();
          }
          ops.push(infix[i]); 
          
        }
        }//8. At the end of the expression, pop and print all operators on the stack. for loop ends here
    while(ops.empty()!=true){
      res.push(ops.top());
      ops.pop();
    }
    //next, test this algorithm. then write out the evaluate function and do the euler stuff in the main. 
    return res;
//return res; 
        }

  
  float evaluate(stack<string> postfix, float y, float t){
    queue<string> operators; 
    stack<float> operands; 
      while(postfix.empty())
    
  }
  //lines 78, 79, 178 183
int main() {
  string a; 
  /*
  vector<string> b; 
  while(a!="stop"){
    cin>>a; 
  if (a!="stop")
    b.push_back(a);
}
  stack<string> c=infixToPostfix(b); 
  while(c.empty()==false){
    cout<<c.top()<<endl; 
    c.pop(); 
  }
  */
  cin>>a; 
  int b=std::stof(a); //use the stof function 
  cout<<b<<endl; 
  return 0;
  }