#include <iostream>

#include <stack>



class stack {

    int top;

    int maxSize;

    int* stackArray;



int main() {

    std::stack<int> myStack;



     public:



        Stack(int size) {

            maxSize = size;

            stackArray = new int[maxSize];

            top = -1;



        }



    myStack.push(10);

    myStack.push(20);

    myStack.push(30);

    myStack.push(40);

    myStack.push(50);



    try {

        while (true) {

            myStack.push(100);

        }

    } catch (...) {

        std::cout << "Stack overflow!" << std::endl;

    }



        ~Stack() {

            delete[] stackArray;

        }



        bool isEmpty() {

            if (top == -1) {

                return true;



            }

            return false;

        }



        bool isFull() {

            if (top - 1 == maxSize) {

                return true;



            }

            return false;

        }



        void push(int value) {

            if (top >= maxSize -1) {

                std::cout << "Overflow!";



            }

            else {



                top++;

                stackArray[top] = value;

            }



        }



        void pop() {

            if (top <= -1) {

                std::cout << "Underflow!";



            }



            else {

                stackArray[top] = 0;

                top--;

            }

        }



        int peek() {

            return stackArray[top];

        }




};




int main() {

    Stack newStack(5);



    newStack.push(30);

    std::cout << newStack.peek();



    newStack.push(20);

    std::cout << newStack.peek();



    newStack.pop();

    std::cout << newStack.peek();



    newStack.pop();

    std::cout << newStack.peek();




    newStack.pop();

    std::cout << newStack.peek();



}

    return 0;



};
