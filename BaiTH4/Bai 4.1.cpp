//Nguyen Huu Dung - 2021545
#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};
// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
	//# Nguyen Huu Dung - 20215545 #
	Node* tmp = new Node(data); //Tao mot nut tmp co gia tri la data
	tmp -> next = head;  //tmp -> next tro den dau danh sach
	return tmp; //Tra ve dau danh sach moi
}
// print the list content on a line
void print(Node* head) {
	//# Nguyen Huu Dung - 20215545 #
	while (head != NULL) { //Neu danh sach con nhieu hon 1 nut
		cout << head -> data <<" ";  //In ra nut
		head = head -> next; //Tro den nut tiep theo
	}
	cout << endl; 
}// return the new head of the reversed list
Node* reverse(Node* head) {
	//# Nguyen Huu Dung - 20215545 #
	if ((head==NULL)||(head->next==NULL))  return head; //Neu danh sach co 0 hoac 1 nut thi tra ve 
	
	if(head->next->next == NULL){ //Neu danh sach co 2 nut 
		head->next->next = head; //Next cua nut 2 tro nguoc lai nut 1
		Node *tmp = head->next;  //Luu danh sach bat dau tu nut thu 2 vao tmp
		head->next = NULL; //Next cua nut cuoi cung tro den NULL
		return tmp; //Tra ve dau danh sach lien ket
	}
	
	else{ //Danh sach co nhieu hon 2 nut
		Node *tmp = reverse(head->next); //Dao nguoc danh sach bat dau tu nut thu hai
										//Nut cuoi cua tmp hien co 2 con tro tro vao trong do co con tro head->next
		head->next->next = head; 
		head->next = NULL; //head tro den nut cuoi cung cua danh sach
		return tmp; //Tra ve dau danh sach lien ket
	}
}
int main() {
	int n, u;
	cin >> n;
	Node* head = NULL;
	for (int i = 0; i < n; ++i){
		cin >> u;
		head = prepend(head, u);
	}
	cout << "Original list: ";
	print(head);
	head = reverse(head);
	cout << "Reversed list: ";
	print(head);
	return 0;
} //Nguyen Huu Dung - 20215545
