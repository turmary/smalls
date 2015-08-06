////////////////////////////////////////////////////////////////////// 
// 
// Compile options needed: /GX
// 
// StackTop&Empty.cpp : Illustrates how to use the top function to
//                      retrieve the last element of the controlled
//                      sequence. It also illustrates how to use the
//                      empty function to loop though the stack.
// Functions:
// 
//    top   :  returns the top element of the stack.
//    empty :  returns true if the stack has 0 elements.
// 
// Written by Derek Jamison
// of Microsoft Product Support Services,
// Copyright (c) 1996 Microsoft Corporation. All rights reserved.
////////////////////////////////////////////////////////////////////// 

#pragma warning(disable:4786)

#include <stack>
#include <iostream>

using namespace std;  // std c++ libs implemented in std

typedef stack<int, deque<int> > STACK_INT;


int main()

{

   STACK_INT stack1;

   cout << "stack1.empty() returned " <<

      (stack1.empty()? "true": "false") << endl;  // Function 3

   cout << "stack1.push(2)" << endl;
   stack1.push(2);

   if (!stack1.empty())                           // Function 3

      cout << "stack1.top() returned " <<
      stack1.top() << endl;                       // Function 1

   cout << "stack1.push(5)" << endl;
   stack1.push(5);

   if (!stack1.empty())                           // Function 3

      cout << "stack1.top() returned " <<
      stack1.top() << endl;                       // Function 1

   cout << "stack1.push(11)" << endl;
   stack1.push(11);

   if (!stack1.empty())                           // Function 3

      cout << "stack1.top() returned " <<
      stack1.top() << endl;                       // Function 1

   // Modify the top item. Set it to 6.
   if (!stack1.empty()) {                         // Function 3
      cout << "stack1.top()=6;" << endl;
      stack1.top()=6;                             // Function 1
   }

   // Repeat until stack is empty
   while (!stack1.empty()) {                      // Function 3
      const int& t=stack1.top();                  // Function 2
      cout << "stack1.top() returned " << t << endl;
      cout << "stack1.pop()" << endl;
      stack1.pop();
   }

} 
