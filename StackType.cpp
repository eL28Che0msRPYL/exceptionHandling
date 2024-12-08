// File: StackType.cpp

#include "StackType.h"
#include <iostream>
//using namespace std;

StackType::StackType() {
  top = -1;
}

bool StackType::IsEmpty() const {
  // Function: Determines whether the stack is empty.
  // Pre:  Stack has been initialized.
  // Post: Function value = (stack is empty)
  bool isEmpty = true;
  for (int i = 0; i < MAX_ITEMS -1; i++){
    if (items[i] != 0){
      isEmpty = false;
      break;
    };
  };
  if (isEmpty == true ){
      std::cerr << "stack is empty";
  }
  return (top == -1);
}

bool StackType::IsFull() const {
  // Function: Determines whether the stack is full.
  // Pre:  Stack has been initialized.
  // Post: Function value = (stack is full)
  bool isFull = true;
  for (int i = 0; i < MAX_ITEMS; i++){
    if (items[i] == 0){
      isFull = false;
      break;
    };
  };
  if (isFull == true ){
      std::cerr << "stack is full";
  }
  return (top ==  MAX_ITEMS-1);
}

void StackType::Push(ItemType newItem) {
  // Function: Adds newItem to the top of the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is full), FullStack exception is thrown;
  //     otherwise, newItem is at the top of the stack.
  bool isFull = true;
  for (int i = 0; i < MAX_ITEMS; i++){
    if (items[i] == 0){
      isFull = false;
      break;
    }else{
      top++;
    }
    ;
  };
  if (isFull == true ){
        throw FullStack();
  }
    else{
      items[top] = newItem;
    }
}

void StackType::Pop() {
  // Function: Removes top item from the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is empty), EmptyStack exception is thrown;
  //     otherwise, top element has been removed from stack.
    bool isEmpty = true;
  for (int i = 0; i < MAX_ITEMS; i++){
    if (items[i] != 0){
      isEmpty = false;
      break;
    }else{
        top--;
    };
  };
  if (isEmpty == true ){
        throw EmptyStack();
  }else{
      items[top] = 0;
  };
}

ItemType StackType::Top() {
  // Function: Returns a copy of top item on the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is empty), EmptyStack exception is thrown;
  //     otherwise, top element has been removed from stack.
      bool isEmpty = true;
  for (int i = 0; i < MAX_ITEMS; i++){
    if (items[i] != 0){
      isEmpty = false;
      break;
    }else{
        top--;
    };
  };
  if (isEmpty == true ){
        throw EmptyStack();
  };
  return items[top];
}
