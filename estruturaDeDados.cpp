#include <iostream>
#include <stack>
using namespace std;
using ItemType = char;

/*
Programa criado em aula da faculdade sobre estrutura de dados que verifica se uma string é bem formada.
*/

class Stack {
private:
    stack<ItemType> stackContainer;

public:
    // Adiciona um item no topo da pilha
    void push(ItemType item) {
        stackContainer.push(item);
    }

    // Remove e retorna o item do topo da pilha
    ItemType pop() {
        if (stackContainer.empty()) {
            throw runtime_error("Pilha vazia");
        }
        ItemType topItem = stackContainer.top();
        stackContainer.pop();
        return topItem;
    }

    // Verifica se a pilha está vazia
    bool isEmpty() const {
        return stackContainer.empty();
    }
};

int main() {
    ItemType character;
    Stack stack;
    ItemType stackItem; 
    
    cout << "Insira uma string" << endl;
    cin.get(character);

    bool isMatched = true;

    while (isMatched && character != '\n') {
        if (character == '{' || character == '(' || character == '[') {
            stack.push(character);
        }
        if (character == '}' || character == ')' || character == ']') {
            if (stack.isEmpty()) {
                isMatched = false;
            } else {
                stackItem = stack.pop();
                isMatched = (character == '}' && stackItem == '{') ||
                            (character == ')' && stackItem == '(') ||
                            (character == ']' && stackItem == '[');
            }
        }
        cin.get(character);
    }

    if (isMatched && stack.isEmpty()) {
        cout << "Bem formada \n";
    } else {
        cout << "Mal formada \n";
    }

    return 0;
}