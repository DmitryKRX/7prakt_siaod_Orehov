#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

struct Node {
	int data;

	Node* next;
	Node(int _data) : data(_data), next(nullptr) {}
};
struct list {
	Node* first;
	Node* last;
    list() : first(nullptr), last(nullptr) {}   
    bool is_empty() {
        return first == nullptr;
    }
    void push_back(int data) {
        Node* p = new Node(data);  
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;     
        last = p;          
    }
    void print() {
        if (is_empty()) {  
            cout << "Список пуст.\n";
            return;
        }
        cout << " ";
        Node* p = first;  
        while (p) {         
            cout << p->data << " ";
            p = p->next; 
        }
        cout << endl;
    }
};
list create_list(list l) {
    int n, k;
    cout << "Введите длину списка: "; cin >> n;
    cout << "Выберите способ создания списка (1 - вручную, 2 - автоматически): "; cin >> k;
    if (k == 1) {
        cout << "\nВведите через пробел значения элементов списка: ";
        for (int i = 0; i < n; i++) {
            cin >> k;
            l.push_back(k);
        }
        cout << "\nСписок сформирован: ";
        l.print();
    }
    else {
        for (int i = 0; i < n; i++) {
            l.push_back(rand() % 100);
        }
        cout << "\nСписок сформирован: ";
        l.print();
    }
    return l;
}

Node* find_node(Node* p, int k) {
    if (p->data == k) return p;
    if (p->next == nullptr) return nullptr;
    return find_node(p->next, k);
}

Node* find_node_iter(Node* p, int k) {
      
    while (p->next) {
        if (p->data == k)
            return p;
        p = p->next;
    }
    return nullptr;
}

int iteration_fibonacci(int n) {
	int x1 = 0, x2 = 1;
	int temp;
	for (int i = 0; i < n; i++) {
		temp = x1 + x2;
		x1 = x2;
		x2 = temp;
	}
	return x1;
}

int recursive_fibonacci(int n) {

    if (n == 1 ) return 1;
	if (n <= 0) return 0;
	return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int task;
    cout << " Выберите задание: 1, 2: ";
    cin >> task;
    // Первое задание 
    if (task == 1) {
        cout << " #";
        cout << setw(5) << " Рекурс." << " Итерац.";
        cout << endl;
        for (int i = 1; i < 13; i++) {
            
            cout << setw(2) << i;
            cout << setw(6) << recursive_fibonacci(i) << " " << setw(6) << iteration_fibonacci(i);
            cout << endl;
        }
        cout << endl;
    }

    // Второе задание
    else if (task == 2) {
        list l;
        l = create_list(l);
        int k;
        cout << "\nВведите значение для поиска: ";
        cin >> k;
        Node* x = find_node(l.first, k);
        Node* z = find_node_iter(l.first, k);
        if (x && z) {
            cout << "---Рекурсивный метод---\n";
            cout << "Указатель: " << x << endl;
            cout << "Значение:  " << x->data << endl;
            cout << endl;
            cout << "---Итерационный метод---\n";
            cout << "Указатель: " << z << endl;
            cout << "Значение:  " << z->data << endl;
        }
        else cout << "Узел не найден.\n";
    }
	return 0;
}