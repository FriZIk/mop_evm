#include <iostream>
using namespace std;

struct list {
	__int64 data;
	struct list *next;
};

int main() {
	// Циклический односвязный список с зацикливанием «через голову»

	// Дополнительные операции: 
	// a) добавить новый узел в указанную позицию
	// б) удалить узлы с заданным значением данных


	// инициализация пустого списка
	list *head = new list;
	list *temp = new list;

	head->next = head;
	head->data = NULL;

	int n;
	__int64 len_list = 0, num;
	bool flag = true, flag_tmp;

	while (flag) {
		cout << "Enter the command(1-8, 0 - exit)" << endl;
		cin >> n;

		switch (n) {
			case 1:
				// уничтожение списка с освобождением памяти
				temp = head->next;

				while (head->next != NULL && head->next != head) {
					temp = head->next;
					head->next = temp->next;
					delete temp;

					len_list--;
				}

				break;
			case 2:
				// добавление узла в голову списка
				cout << "Enter the number to insert: ";
				cin >> num;

				temp = new list;
				temp->next = head->next;
				temp->data = num;
				head->next = temp;

				len_list++;

				break;
			case 3:
				// добавление узла в хвост списка
				flag_tmp = true;

				cout << "Enter the number to insert: ";
				cin >> num;

				temp = new list;

				for (temp = head->next; flag_tmp; temp = temp->next)
					if (temp->next == head) {
						list *p = new list;
						p->next = head;
						temp->next = p;
						p->data = num;
						flag_tmp = false;
					}

				len_list++;

				break;
			case 4:
				// удаление узла из головы списка
				if (head->next != NULL && head->next != head) {
					temp = head->next;
					head->next = temp->next;
					delete temp;

					len_list--;
				}

				break;
			case 5:
				// удаление узла из хвоста списка
				if (head->next != NULL && head->next != head) {
					temp = head->next;

					if (temp->next == head) {
						head->next = temp->next;
						delete temp;
					}
					else
						for (; temp != head; temp = temp->next)
							if (temp->next->next == head) { 
								delete temp->next;
								temp->next = head;
							}

					len_list--;
				}

				break;
			case 6:
				// выдача текущего списка на экран
				if (head->next != NULL && head->next != head)
					for (temp = head->next; temp != head && temp != NULL; temp = temp->next)
						cout << temp->data << " ";
				else
					cout << "List is empty!";

				cout << endl;

				break;
			case 7:
				// a) добавить новый узел в указанную позицию
				__int64 ind, count;

				flag_tmp = true;
				count = 0;

				cout << "Enter the number to insert: ";
				cin >> num;

				cout << "Enter the index to insert (length list: " << len_list << "): ";
				cin >> ind;

				temp = head->next;

				if (ind <= len_list) {
					if (ind == 0) {
						list *p = new list;
						p->next = temp;
						head->next = p;
						p->data = num;
					}
					else {
						while (flag_tmp) {
							if (count + 1 == ind) {
								list *p = new list;
								p->next = temp->next;
								temp->next = p;
								p->data = num;
								flag_tmp = false;
							}

							temp = temp->next;
							count++;
						}
					}

					len_list++;
				}
				else
					cout << "Error! Length list: " << len_list << endl;

				break;
			case 8:
				// б) удалить узлы с заданным значением данных
				cout << "Enter the number to delete: ";
				cin >> num;

				flag_tmp = true;
				count = 0;
				temp = head;

				while (flag_tmp) {
					if (count >= len_list + 1)
						flag_tmp = false;
					else
						if (temp->next->data == num) {
							list *p = new list;
							p = temp->next;
							temp->next = temp->next->next;
							delete p;

							len_list--;
							count = 0;
						}

					temp = temp->next;
					count++;
				}

				temp = head->next;

				if (temp->data == num) {
					list *p = new list;
					p = temp->next;
					delete temp;
					head->next = p;

					len_list--;
				}

				break;
			default:
				flag = false;
				break;
			}
	}

	return 0;
}