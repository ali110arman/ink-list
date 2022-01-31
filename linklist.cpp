#include<iostream>
using namespace std;

/*

علی آرمان
981406159
کد های  مربوط به:
لینک لیست ساده
لینک لیست چرخشی
لینک لیست دو طرفه
به صورت کلاس در این فایل نوشته شده



*/



//......................................................................................linklist sade
class node
{
public:
	int info;
	node* next;
};
node* start = NULL;
class list
{
public:
	~list();
	void InsertBegin(int);
	void InsertLast(int);
	void InsertAtPos(int, int);
	void SortList();
	void DeleteAtPos(int);
	void UpdateValue(int, int);
	int SearchValue(int value);
	void ReverseList();
	void PrintList();
private:
	node* NewNode(int);
};

node* list::NewNode(int value) {	//dorost kardan node jadid
	node* temp, * s;
	temp = new(node);
	temp->info = value;
	temp->next = NULL;
	return temp;
}
list::~list() {  //hazf tamam magadir
	node* temp = nullptr;
		temp = start;
		start = start->next;
		delete temp;
}
void list::InsertBegin(int value) {	//ezafe karn node be ebteda
	node* temp, * p;
	temp = NewNode(value);
	if (start == NULL)				//agar list khali bood
	{
		start = temp;
		start->next = NULL;
	}
	else
	{
		p = start;
		start = temp;
		start->next = p;
	}
}

void list::InsertLast(int value) {	//ezafe karn node be enteha
	node* temp, * s;
	temp = NewNode(value);
	s = start;
	while (s->next != NULL)			//peimash ta entehaye list
		s = s->next;
	temp->next = NULL;
	s->next = temp;
}

void list::InsertAtPos(int value, int pos) {	//ezafe karn node be pos delkhah
	int counter = 0;
	node* temp, * s, * ptr;
	temp = NewNode(value);
	int i;
	s = start;
	while (s != NULL)		//poeida kardan tedad anasor list
	{
		s = s->next;
		counter++;
	}
	if (pos == 1)			// agar pos makan aval bood
	{
		if (start == NULL)	//agar list khaly bood
		{
			start = temp;
			start->next = NULL;
		}
		else				//agar saf khaly nabood
		{
			ptr = start;
			start = temp;
			start->next = ptr;
		}
	}
	else if (pos > 1 && pos <= counter)
	{
		s = start;
		for (i = 1; i < pos; i++)	//peida kardan pos
		{
			ptr = s;
			s = s->next;
		}
		temp->next = s;		//ezafe kardan megdar dar pos
	}
}

void list::SortList() {				//moratab karn list
	node* ptr, * s;
	int value;
	if (start == NULL)			//baresi khaly boodan
		return;
	ptr = start;
	while (ptr != NULL)
	{
		for (s = ptr->next; s != NULL; s = s->next)	//peimayesh ta enteha
		{
			if (ptr->info > s->info)				//baresy bozorg boodan ya khochack boodan
			{
				value = ptr->info;					//avaz kardan pos bozorg ba koochak
				ptr->info = s->info;
				s->info = value;
			}
		}
		ptr = ptr->next;
	}
}

void list::DeleteAtPos(int pos) {	//hazf yek node dar pos delkhah
	int i, counter = 0;
	if (start == NULL)			//baresy khaly boodan list
		return;
	node * s, *ptr;
	s = start;
	if (pos == 1)				//agar node aval bod
		start = s->next;		//makan node badi tagir peida konad
	else
	{
		while (s != NULL)		//peida kardan tedad node ha
		{
			s = s->next;
			counter++;
		}
		if (pos > 0 && pos <= counter)
		{
			s = start;
			for (i = 1; i < pos; i++)	//halge baray tagir adress node ha
			{
				ptr = s;
				s = s->next;
			}
		}
		else
			return;
	}
}

void list::UpdateValue(int value, int pos) {	//tagir megdar yek node
	if (start == NULL)		//baresy khaly boodan list
		return;
	node * s, *ptr;
	s = start;
	if (pos == 1)		//aghar makan aval bood
		start->info = value;	//megdar avaz mishavad
	else
	{
		for (int i = 0; i < pos - 1; i++)	//peida kardan node mored nazar
			s = s->next;
		s->info = value;		//megdar avaz mishavad
	}
}

int list::SearchValue(int value) {	//peida kardan pos yek node
	int pos = 0;
	if (start == NULL)		//baresy khaly boodan list
		return 0;
	node * s;
	s = start;
	for (s; s != NULL; s = s->next)		//harekat ta akhar list
	{
		pos++;
		if (s->info == value)
			return pos;
	}
}

void list::ReverseList() {	//makoos kardan list
	node* ptr1, * ptr2, * ptr3;
	if (start == NULL)	//baresy khaly boodan list
		return;
	if (start->next == NULL)	//agar faght yek node dasht
		return;
	ptr1 = start;
	ptr2 = ptr1->next;			//avaz kardan magadir avali ba node temp
	ptr3 = ptr2->next;			//avaz kardan magadir avali ba node temp
	ptr1->next = NULL;			//avaz kardan magadir avali ba node temp
	ptr2->next = ptr1;			//avaz kardan magadir avali ba node temp
	while (ptr3 != NULL)	//harekat ta enteha
	{
		ptr1 = ptr2;			//avaz kardan magadir to node ba node temp
		ptr2 = ptr3;			//avaz kardan magadir to node ba node temp
		ptr3 = ptr3->next;
		ptr2->next = ptr1;		//avaz kardan magadir to node ba node temp
	}
	start = ptr2;				//avaz kardan node shoroo
}

void list::PrintList() {		//chap list
	node* temp;
	if (start == NULL)	//baresy khaly boodan list
		return;
	temp = start;
	for (temp; temp != NULL; temp = temp->next)
		cout << temp->info << ",";
}










//......................................................................................linklist charkheshi
class clNode {
public:
	int value;
	clNode* next;

	clNode(int x, clNode* info) {
		value = x;
		this->next = info;
	}

	~clNode() = default;
};


class CLinkedList {
private:
	clNode* head;
	clNode* tail;
	int size;
public:
	CLinkedList();
	~CLinkedList();
	bool IsEmpty();
	void InsertBegin(int);
	int PopFront();
	void InsertLast(int);
	int PopBack();
	void InsertAtPos(int, int);
	void UpdateValue(int, int);
	int DeleteAtPos(int);
	void PrintList();
	clNode* begin();
	clNode* end();
};

CLinkedList::~CLinkedList() {  //hazf tamam magadir
	clNode* temp = nullptr;
	while (head != tail) {
		temp = head;
		head = head->next;
		tail = head;
		delete temp;
	}

	delete head;
}

CLinkedList::CLinkedList() {	//megdar dehi avalie
		head = nullptr;
		tail = nullptr;
		size = 0;
}


bool CLinkedList::IsEmpty() {	//baresy khaly boodan list
	if (head == nullptr)
		return true;
	else
		return false;
}

void CLinkedList::InsertBegin(int value) {	//ezafe kardan node be ebteda
	clNode* temp = new clNode(value, head);
	head = temp;

	if (size == 0) { //agar saf khaly ast
		head->next = head;
		tail = head;
	}
	else 
		tail->next = head;

	size++;
}

int CLinkedList::PopFront() {	//pop kardan az front
	if (!IsEmpty()) {	//baresy khaly boodan list
		int value = head->value;
		if (size == 1) { //agar faghat yek node bood
			delete head;
			head = tail = nullptr;
		}
		else {
			tail->next = head->next;
			delete head;
			head = tail->next;
		}
		size--;
		return value;
	}
	else
		return NULL;

}

void CLinkedList::InsertLast(int value) {	//ezafe kardan node be enteha
	if (IsEmpty()) { //baresy khaly boodan list
		InsertBegin(value);	//agar khaly bood ebteda va enteha yek ja ast
	}
	else {
		clNode* temp = new clNode(value, head); // node akhar be node aval eshare mikonad
		tail->next = temp;
		tail = temp;
		size++;
	}
}

int CLinkedList::PopBack() { 
	if (!IsEmpty()) {	//baresy khaly boodan list
		if (size == 1) {	//agar node aval bood
			return PopFront();
		}
		else {
			int value = tail->value;
			clNode* temp = head;
			for (int i = 0; i < size - 2; i++)
				temp = temp->next;
			delete temp->next; // hazfe node akhar
			temp->next = head;
			tail = temp;
			size--;
			return value;
		}
	}
	else
		return NULL;
}

void CLinkedList::InsertAtPos(int index, int value) { //azafe kardan node be pos delkhah
	if (index < 0 || index > size) //aghar por ya khalu bood
		return;
	if (index == 0)	//agar makan aval bood
		InsertBegin(value);
	else if (index == size)	//agar onsor alhar bood
		InsertLast(value);
	else {
		clNode* temp = head;
		for (int i = 0; i < index - 1; i++)	//peida kardan pos delkhah
			temp = temp->next;
		clNode * n = new clNode(value, temp->next);
		temp->next = n;
		size++;
	}
}

void CLinkedList::UpdateValue(int index, int value) { //azafe kardan node be pos delkhah
	if (index < 0 || index > size) //aghar por ya khalu bood
		return;
	if (index == 0)	//agar makan aval bood
		begin()->value = value;
	else if (index == size)	//agar onsor alhar bood
		end()->value = value;
	else {
		clNode* temp = head;
		int i = 0;
		for (i; i < index ; i++)	//peida kardan pos morede nazar
			temp = temp->next;
		if (i == index)
			temp->value = value;
		size++;
	}
}

int CLinkedList::DeleteAtPos(int index) { //hazf kardan node dar pos delkhah
	if (index < 0 || index >= size) //aghar por ya khalu bood
		return 0;
	if (index == 0)	//agar makan aval bood
		return PopFront();
	else if (index == size - 1)	//agar onsor alhar bood
		return PopBack();
	else {
		clNode* temp = head;
		for (int i = 0; i < index - 1; i++)	//peida kardan pos delkhah
			temp = temp->next;
		int value = temp->next->value;
		clNode * t = temp->next;
		temp->next = t->next;
		delete t;
		size--;
		return value;
	}
}


void CLinkedList::PrintList() { //chap magadir
	if (!IsEmpty()) {
		clNode* temp = head;
		while (temp->next != head) {	//harekhat ta enteha
			std::cout << temp->value << "\t";
			temp = temp->next;
		}
		cout << temp->value << endl;
	}
}

clNode* CLinkedList::begin() { //peida kardan onsor ebteda
	return head;
}

clNode* CLinkedList::end() { //peida kardan onsor enteha
	return tail;
}











//......................................................................................linklist dotarfe
class DNode {
public:
	int value;
	DNode* next;
	DNode* prev;
	DNode(int info, DNode* nextinput, DNode* previnput) {
		value = info;
		next = nextinput;
		prev = previnput;
	}	
};

class DLinkedList {
private:
	DNode* head;
	DNode* tail; 
	int size; 
public:
	DLinkedList();
	~DLinkedList();
	void PushFront(int);
	bool IsEmpty();
	int PopFront();
	void PushBack(int);
	int PopBack();
	void InsertAtPos(int, int);
	int Delete(int);
	void PrintList();;
};

DLinkedList::DLinkedList() {	//tabe sazande
	head = nullptr;
	tail = nullptr;
	size = 0;
}

DLinkedList::~DLinkedList() {	//tabe mokhareb
	DNode* temp = nullptr;
	while (head) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

bool DLinkedList::IsEmpty() {	//baresy khaly boodan
	return head == nullptr;
}

void DLinkedList::PushFront(int value) {
	DNode* n = new DNode(value, nullptr, nullptr);
	if (head) { //agar dar ebteda list node bood
		n->next = head;
		head->prev = n;
	}
	head = n;
	if (size == 0) //agar nody nabood
		tail =  head;
	else
		tail =  tail;
	size++;
}

int DLinkedList::PopFront() {	//pop kardan node az front
	if (!IsEmpty()) {	////baresy khaly boodan
		int value = head->value;

		DNode* temp = head;
		head = head->next;
		if (head) head->prev = nullptr; //update kardan node dovom agar bood
		delete temp;
		size--;

		if (size == 0) //agar faghat yek node bood
			tail = head;

		return value;
	}
	else
		return NULL;
}


void DLinkedList::PushBack(int value) {
	if (IsEmpty()) //baresy khaly boodan
		PushFront(value);
	else {
		DNode* temp = new DNode(value, nullptr, tail);
		tail->next = temp; // update kardan megdar node konoony
		tail = temp;
		size++;
	}
}

int DLinkedList::PopBack() {	//pop kardan az ebteda
	if (!IsEmpty()) {	//baresy khaly boodan
		if (size == 1)	//agar yek khane bood
			return PopFront();
		else {
			int value = tail->value;
			DNode* temp = head;
			for (int i = 0; i < size - 2; i++)	//petda kardan node enteha
				temp = temp->next;
			temp->next = nullptr;
			delete tail;
			tail = temp;
			size--;
			return value;
		}
	}
	else
		return NULL;
}

void DLinkedList::InsertAtPos(int index, int value) { //ezafe kardan be pos delkhah
	if (index < 0 || index > size)	//agar khaly bood
		return;
	if (index == 0)	//agar dar makan aval bood
		PushFront(value);
	else if (index == size)
		PushBack(value);
	else {
		DNode* temp = head;
		for (int i = 0; i < index - 1; i++)	//peهda kardan node enteha
			temp = temp->next;
		DNode * n = new DNode(value, temp->next, temp);	//dorost kardan node jadad
		temp->next->prev = n; // update kardan megdar node bady
		temp->next = n; // update kardan node gablu
		size++;
	}
}

int DLinkedList::Delete(int index) { //hazf kardan khane ba adress
	if (index < 0 || index >= size) //megdar namoshakhas pos
		return 0;
	if (index == 0)	//agar khane aval bood
		return PopFront();
	else if (index == size - 1)
		return PopBack();
	else {
		DNode* temp = head;
		for (int i = 0; i < index - 1; i++)	//peida kardan makan morode nazar
			temp = temp->next;

		int value = temp->next->value;	//hazf kardan
		DNode * t = temp->next;
		t->next->prev = t->prev; //updakardan megadar node bady
		t->prev->next = t->next; //updakardan megadar node ghabli
		delete t;
		size--;
		return value;
	}
}


void DLinkedList::PrintList() { //chap kardan magadir
	if (!IsEmpty()) {	//baresy khaly boodan
		DNode* temp = head;
		while (temp) {
			std::cout << temp->value << "\t";
			temp = temp->next;
		}
	}
	cout << endl;
}

void main() {
	//link list sade

	//list s;
	//s.InsertBegin(12);
	//s.InsertLast(14);یه 
	//s.InsertBegin(11);
	//s.InsertLast(17);
	////s.ReverseList();
	//s.UpdateValue(1, 1);
	//s.DeleteAtPos(1);
	//s.PrintList();


	

	//link list charckeshi

	//CLinkedList l;
	//l.InsertBegin(1);
	//l.InsertBegin(0);
	//l.InsertLast(2);	
	//l.PrintList();
	//l.InsertAtPos(0, 200);
	//l.PrintList();
	//l.UpdateValue(1, 400);
	//l.PrintList();






	//link list dotarafe

	DLinkedList list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);
	list.PushBack(6);
	list.PrintList();
	list.InsertAtPos(2, 10);
	list.PrintList();
	list.InsertAtPos(3, 20);
	list.PrintList();
	list.Delete(4);
	list.PrintList();
}
