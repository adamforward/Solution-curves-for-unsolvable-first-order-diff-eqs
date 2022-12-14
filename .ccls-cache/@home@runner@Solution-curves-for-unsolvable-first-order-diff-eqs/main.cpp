#include <iostream>
#include <string> 
#include <stack> 
#include <vector> 
#include <math.h>
#include <limits.h> 
#include <string.h> 
#include <sstream>
using namespace std; 

bool isNumber(string n){
  bool z; 
 for (int i=0;i<n.length();i++) {
   if(n[i]=='0'||n[i]=='1'||n[i]=='2'||n[i]=='3'||n[i]=='4'||n[i]=='5'||n[i]=='6'||n[i]=='7'||n[i]=='8'||n[i] =='9')//y^t get replaced by numbers when the string is evaluated. 
   z=true; 
  else 
   z=false;
  //test all functions before using. this one works. 
}
  return z;
}
bool isOperand(string n){ 
  bool z; 
 for (int i=0;i<n.length();i++) {
   if(n=="y"||n=="t"||n=="e"||n=="pi")//y^t get replaced by numbers when the string is evaluated. 
   z=true; 
  else if(isNumber(n)==true)
    z=true;
  else 
   return false;
  //test all functions before using. this one works. 
}
  return z;
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
  else if (op=="*"||op=="/")
    return 2; 
  else if (op=="^")
    return 3; 
  else if (isPrefix(op)==true)
    return 4; 
  else 
    return INT_MAX; 
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
vector<string> infixToPostfix(vector<string> infix){
stack<string> ops; 
  vector<string> res; 
  
  //infix to postfix 
  for (int i=0; i<infix.size(); i++){
    string c=infix[i]; 
    //1. Print operands as they arrive.
    if (isOperand(c)==true){
      res.push_back(c);   
      }
      //3. If the incoming symbol is a left parenthesis, push it on the stack.
    else if(isLeftParenthases(c)) {
      ops.push(c); 
      }
      // 4. If the incoming symbol is a right parenthesis, pop the stack and print the operators until you see a left parenthesis. Discard the pair of parentheses.
     else if(isRightParenthases(infix[i])==true){
      while(ops.top()!="("){
        res.push_back(ops.top()); 
        ops.pop(); 
      }
      ops.pop();
       //get rid of left paren.  
        }
    //2. If the stack is empty or contains a left parenthesis on top, push the incoming operator onto the stack.
      else if(ops.empty()==true&&isOp(c)==true){
      ops.push(c);
      continue;
      }
    else if(isOp(c)==true&&ops.empty()==false){
     if(isLeftParenthases(ops.top())==true){
      ops.push(c); 
      continue; 
      }
      
      //5. If the incoming symbol has higher precedence than the top of the stack, push it on the stack.
     if (priority(ops.top())<priority(c)){
        ops.push(c);
       continue; 
        }
    //6. If the incoming symbol has equal precedence with the top of the stack, use association. If the association is left to right, pop and print the top of the stack and then push the incoming operator. If the association is right to left, push the incoming operator. so A + B - C sin(tan(x))=xtansin-doesn't matter for prefix expressions due to parens so this rule is only for ops A + B - C prio(+)==prio(-), you want AB+C- 
     else if(priority(c)==priority(ops.top())){
          string b=ops.top(); 
          res.push_back(b); 
          ops.pop(); 
          ops.push(infix[i]);       
       }
        //7. If the incoming symbol has lower priority than the symbol on the top of the stack, pop the stack and print the top operator. Then test the incoming operator against the new top of stack.
      else if(priority(ops.top())>priority(c)){   
            while(priority(ops.top())>priority(c)){
            string a=ops.top();
            res.push_back(a); 
            ops.pop();
            if(ops.empty()==true)
              break; 
          }
          ops.push(infix[i]); 
        }
      }
    else{
      res.push_back("not valid");
    }
    
        }//exit for loop 
       //8. At the end of the expression, pop and print all operators on the stack. for loop ends here
    while(ops.empty()!=true){
      res.push_back(ops.top());
      ops.pop();
    }
    //next, test this algorithm. then write out the evaluate function and do the euler stuff in the main. 
    return res;
//return res; 
        }

float oneNumOp(float a, string op){
      if(op=="sin")
        return sin(a);
      else if(op=="cos")
        return cos(a); 
      else if(op=="tan")
        return tan(a); 
      else if(op=="log")
        return log(a);
      else if(op=="arcsin")
        return asin(a); 
      else if(op=="arccos")
        return acos(a);
      else if(op=="arctan")
        return atan(a); 
      else
        return INT_MIN; 
}
float twoNumOp(float a, float b, string op){
      //Perform operation
      if(op == "+")
         return b+a;
      else if(op == "-")
         return b-a;
      else if(op == "*")
         return b*a;
      else if(op == "/")
         return b/a;
      else if(op == "^")
         return pow(b,a);
      else if(op== "ln")
        return log(a); 
      else if(op== "sin")
        return sin(a); 
      else if(op== "cos")
        return cos(a); 
      else if(op== "ln")
        return log(a); 
      else if(op== "ln")
        return log(a); 
      
      else
   return INT_MIN; //return negative infinity
}

/*
Start reading the expression from left to right.
If the element is an operand then, push it in the stack.
If the element is an operator, then pop two elements from the stack and use the operator on them.
Push the result of the operation back into the stack after calculation.
Keep repeating the above steps until the end of the expression isreached.
The final result will be now left in the stack, display the same.
convert the stack over to a vector of strings first, loop through it backwards 
*/

float betterEvalPostFix(vector<string> postfix, float y, float t){
  stack<float> answer;
  float conv=0; 
  for(int i=0; i<postfix.size(); i++){//Start reading the expression from left to right.
    if(isOperator(postfix[i])==true && answer.size()<2)
      return 340282346638528859811704183484516925440.0000000000000000;
    if (isPrefix(postfix[i])==true && answer.empty()==true)
      return 340282346638528859811704183484516925440.0000000000000000;
    if(isNumber(postfix[i])==true){//If the element is an operand then, push it in the stack.
    conv=std::stof(postfix[i]);
      answer.push(conv); 
      }
    else if(postfix[i]=="e")
      answer.push(2.71828);
    else if(postfix[i]=="pi")
      answer.push(3.14159);
    else if(postfix[i]=="y")//these are all the operands 
      answer.push(y);
    else if(postfix[i]=="t")
      answer.push(t); 
    else if(isPrefix(postfix[i])==true){
      float a=answer.top(); 
      answer.pop(); 
      answer.push(oneNumOp(a,postfix[i]));
    }
    else if(isOperator(postfix[i])==true){
      float a=answer.top();
      answer.pop();
      float b=answer.top(); 
      answer.pop(); 
      answer.push(twoNumOp(a,b,postfix[i])); 
    }
    else 
      return 340282346638528859811704183484516925440.0000000000000000;
  }
  if(answer.size()==1)
  return answer.top();
  else 
    return 340282346638528859811704183484516925440.0000000000000000;
}

  void error(){
    cout<<"Error: please enter a valid infix expression"<<endl; 
    return; 
  }
    /*
    float euler(vector<string> postfix, float curry, float currt, float stepsize){
        float yprime=betterEvalPostFix(postfix, curry, currt);
        float yNext=curry+yprime*stepsize; 
        return yNext; 
      }
  */
/*
  vector<string> splitString(string infix){
    vector<string> inf; 
    int currIndex = 0;
    int i=0; 
    int startIndex = 0, endIndex = 0;  
    while (i <= infix.size())  
    {  
        if (infix[i] == '|' || i == inf.size()-1)  
        {  
            endIndex = i;  
            string subStr = "";  
            subStr.append(infix, startIndex, endIndex - startIndex);  
            inf.push_back(subStr); 
            currIndex++;  
            startIndex = endIndex + 1;  
        }  
        i++;  
        } 
  }
*/
    void errorTwo(){
      cout<<"please enter a step size greater than zero"<<endl; 
      return; 
    }
    void errorThree(){
      cout<<"please enter a t final value greater than tzero"<<endl; 

    }

/*
char *token;
char *line = "LINE TO BE SEPARATED";
char *search = " ";
Token will point to "LINE". 
token = strtok(line, search);

*/
/*
  vector<string> splitStringTwo(string infix){
    char inf[infix.size()]; 
    vector<string> answer;
    for (int i=0; i<infix.size(); i++){
      inf[i]=infix[i]; 
    }
  char * pointer;
  pointer = strtok (inf,"|");
  string a=
  answer.push_back(a); 
  while (pointer != NULL)
  {
    pointer = strtok (NULL, "|");
    answer.push_back(a); 
  }
    }
  
*/
//after these two attempts at the splitstring algorithm, I did some more research and found out how to use the stringstream data type

int main() {
  
  //all the code from here
  cout<<"Adam Forward"<<endl; 
  cout<<"  Euler's method can be used to approximate the solution curve for any ordinary first order differential equation in the form dy/dt=f(y,t), where the solution is a function y(t)."<<endl; 
  cout<<"  While using methods such as integrating factors or seperation of variables to obtain a solution y(t) is ideal for analysing any given first order differential equation, many are unsolvable and require euler's method to approximate any given y value at some point t."<<endl; 
  cout<<"  Euler's method evaluates each point y(n+1) as y(n)+h*f(y,t) where f(y,t) is equal to dy/dt. However, this method can require an excessive number of calculations so programming is often a nessessary tool for analysing unsolvable first order differential equations. As the step size, h, decreases, the accurracy for which the solution curve represents the function, y(t), increases while the runtime of the program also increases."<<endl; 
  cout<<"  This program uses the standard library of C++ and includes the iostream, string, vector, stack, string.h, limits.h, sstream and math.h libraries. Using the input of any string that properly represents an infix expression for the function dy/dt, this problem is able to produce a set of values y and t that represent different points along the solution curve up until any given t value. Initially, the input string is broken up into a vector of strings seperating the operands and operators. The arguements taken as operands in this program are: y, t, e, pi, and any string of numbers. The arguements taken as operators are (, ), ^, *, +, -, /, sin, cos, tan, arcsin, arccos, arctan and ln. The vector of strings is then converted into a stack of strings organized by a modified postfix notation where trig and logarithm functions have priority over every operator besides (. At each function call of the euler formula, this postfix expression is evaluated while taking new arguements for y and t each time. "<<endl; 
  bool valid=false;
  vector<string> postFixVector; 
  while(valid==false){


  string infixString;
  cout<<"Enter a first order differential equation in the form dy/dt=f(y,t). Note: this has to be a valid infix expression"<<endl; 
  cin>>infixString; 
  string intermediate=""; 
  stringstream ss(infixString);
  vector <string> tokens; 
  while(getline(ss, intermediate, '|')){//string splitting function works 
    tokens.push_back(intermediate); 
  }
  postFixVector=infixToPostfix(tokens);
  for(int i=0;i<postFixVector.size();i++){
    if (postFixVector[i]=="not valid")
      error();
      continue; 
    } 
    if(betterEvalPostFix(postFixVector, 5, 5)!=340282346638528859811704183484516925440.0000000000000000){
      valid=true; 
      }
    else
      error(); 
    }//exit validity tester 
  cout<<"what is your initial y value"<<endl; 
  float y; 
  cin>>y; 
  cout<<"what is your initial t value"<<endl;
  float t; 
  cin>>t; 
  bool validStepSize=false; 
  float stepSize; 
  while(validStepSize==false){
  cout<<"what is your stepsize"<<endl;
    cin>>stepSize; 
    if (stepSize>0)
      validStepSize=true; 
    else 
      errorTwo(); 
    }
  bool validTFinal=false; 
  float tFinal; 
  cout<<"What is your final t value?"<<endl; 
  while(validTFinal==false){
    cin>>tFinal;
    if(tFinal<=t)
    errorThree();
    else
      validTFinal=true; 
  }
  for(int i=0;i<postFixVector.size(); i++){
    cout<<postFixVector[i]<<endl; 
  }
  
  vector<float> yVals;
  vector<float> tVals; 
  yVals.push_back(y); 
  tVals.push_back(t);
  cout<<"here are the approximated values in your solution curve:"<<endl; 
  cout<<" yPrime="<<yPrime<<" t="<<t<<" y="<<y<<endl;
  while(t<tFinal){
    float yPrime=betterEvalPostFix(postFixVector,y,t);  
    float yIncrease=yPrime*stepSize; 
    t=t+stepSize; 
    y=y+yIncrease; 
    cout<<" yPrime="<<yPrime<<" t="<<t<<" y="<<y<<endl;
  }
  
    //to here is part of the main that doesn't test functions

    /*
  string a; 
  vector<string> b; 
  while(a!="stop"){
    cin>>a; 
    if(a!="stop")
    b.push_back(a);
}
*/

  /*
  stack<string> c=infixToPostfix(b); 
  vector<float> yvals; 
  vector<float> tvals; 
  
  stack<string> yPrime2=c; 
  //euler function evaluating 
  cout<<"What is your initial y value?"<<endl; 
  float y; 
  cin>>y;
  yvals.push_back(y);
  cout<<"What is your initial t value?"<<endl; 
  float t; 
  cin>>t; 
  tvals.push_back(t); 
  float k; 
  cout<<"What is your step size?"<<endl;
  cin>>k; 
  cout<<"What is your final t value?"<<endl; 
  float tfinal; 
  cin>>tfinal; 
  
  for(int i=0; i<yvals.size(); i++){
    cout<<"t="<<tvals[i]<<"   y(t)="<<yvals[i]<<endl; 
  }
*/
  /*
  vector<string> a; 
  a.push_back("+");
  a.push_back("4");
  a.push_back("2");
 cout<<betterEvalPostFix(a,.4,.3)<<endl; 
  return 0; 
  */
  //tester for splitString(comment everything else to test)
  /*
  string b; 
  cin>>b; 
  vector<string> c=splitString(b); 
  for(int i=0; i<c.size(); i++){
    cout<<c[i]<<endl; 
  }
  */
  
  return 0; 
  } 