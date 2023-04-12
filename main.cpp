#include <iostream>

using namespace std;

const int MAX_ITEMS = 5;

class EmptyStack{};

class FullStack{};

template <class ItemType>
class StackType{
    private:
        int top;
        ItemType items[MAX_ITEMS];
        string parentheses = "(()(()))";

    public:
        // Constructor assigning top index -1 as 0 will represent a valid index.
        StackType(){
            top = -1;
        }

        //checks if stack is full or not.
        bool isFull(){
            return (top == MAX_ITEMS-1);
        }

        //checks if stack is empty or not.
        bool isEmpty(){
            return (top == -1);
        }
        void makeEmpty(){
            top = -1;
        }

        //push an item to stack
        void push(ItemType newItem){
            if(isFull()){
                // If stack full through an exception
                throw FullStack();
            }
            //increase value of top
            top++;
            //insert item at the top of stack.
            items[top] = newItem;
        }

        //pop an item to stack. That is pop the top item of the stack.
        void pop(){
            if(isEmpty())
                //if empty through this exception.
                throw EmptyStack();
            // decrease the value of top.
            top--;
        }


        // Check if the parenthesess are balanced or not.

        bool balance_check(){
            //Checks each characters of the string parentheses.
            try{
                for(int i=0; parentheses[i] != '\0'; i++){
                    if(parentheses[i] == '('){
                        push(parentheses[i]);
                    }
                    else{
                        pop();
                    }
                }
            }
            // If the code gets ')' at the begining, it should through an exception EmptyStack.
            // This exception will only occur if we have a pop() operation on an empty stack.
            // The code will only get a pop operation when it gets ')'.
            //That's why ')()' will not balence parenthesis and should return flase
            catch(EmptyStack){
                return false;
            }

            if(isEmpty()){
                return true;
            }
            else{
                return false;
            }
        }

};

int main()
{
    StackType<char> arr;
    cout << (arr.balance_check()? "True" : "False");
    return 0;
}
