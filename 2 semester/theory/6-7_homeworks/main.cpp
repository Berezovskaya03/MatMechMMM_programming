#include <iostream>
#include <queue>
using namespace std;
 
struct node
{
	int data;
	node *left;
	node *right;
	int height;
};
 
class BST
{
	public:
		void insert(int,node * &);
		void del(int, node * &);
		void balance( int, node * &);
		int deletemin(node * &);
		void find(int,node * &);
		void makeempty(node * &);
		void copy(node * &, node * &);
		node * nodecopy(node * &);
		void show_growth(node *);
		void show_level(node *);
		void postorder(node *);
		int bsheight(node *);
		node * small_left(node * &);
		node * big_left(node * &);
		node * small_right(node * &);
		node * big_right(node * &);
		int max(int,int);
};

void BST::insert(int x,node * &p)
{
	if (p == NULL){
		p = new node;
		p->data = x;
		p->left=NULL;
		p->right = NULL;
		p->height=0;
	}
	else
	{
		if (x < p->data) {
			insert(x, p->left);
			if ((bsheight(p->left) - bsheight(p->right))==2){
				if (x < p->left->data){
					p=small_left(p);
				}
				else
				{
					p = big_left(p);
				}
			}
		}
		else if (x > p->data) {
			insert(x,p->right);
			if ((bsheight(p->right) - bsheight(p->left))==2){
				if (x > p->right->data)
				{
					p=small_right(p);
				}
				else
				{
					p = big_right(p);
				}
			}
		}

			else
			{
				cout<<"Элемет существует"<<endl;
			}
}
int m,n,d;
m=bsheight(p->left);
n=bsheight(p->right);
d=max(m,n);
p->height = d + 1;
}

void BST::find(int x, node * &p)
{
	if (p==NULL)
	{
		cout<<"Элемент не найден"<<endl;
	}
	else
	{
		if (x < p->data)
		{
			find(x,p->left);
		}
		else
		{
			if (x>p->data)
			{
				find(x,p->right);
			}
			else
			{
				cout<<"Элемент найден"<<endl;
			}
		}
	}
}

void BST::copy(node * &p, node * &p1)
{
	makeempty(p1);
	p1 = nodecopy(p);
}

void BST::makeempty(node * &p)
{
	node * d;
	if (p != NULL)
	{
		makeempty(p->left);
		makeempty(p->right);
		d=p;
		free(d);
		p=NULL;
	}
}

node * BST::nodecopy(node * &p)
{
	node * temp;
	if (p==NULL)
	{
		return p;
	}
	else
	{
		temp = new node;
		temp->data = p->data;
		temp->left = nodecopy(p->left);
		temp->right = nodecopy(p->right);
		return temp;
	}
}
 

void BST::del(int x,node * &p)
{
	node * d;
	if (p==NULL)
	{
		cout<<"Элемент для удаления не найден"<<endl;
	}
	else if ( x < p->data)
	{
		del(x,p->left);
	}
	else if (x > p->data)
	{
		del(x,p->right);
	}
	else if ((p->left == NULL) && (p->right == NULL))
	{
		d=p;
		free(d);
		p=NULL;
		if (x<p->data){
			insert(x,p->left);
			if ((bsheight(p->left) - bsheight(p->right))==2){
				if (x < p->left->data){
					p=small_left(p);
				}
				else
				{
					p = big_left(p);
				}
			}
		}
		else if (x>p->data){
			insert(x,p->right);
			if ((bsheight(p->right) - bsheight(p->left))==2){
				if (x > p->right->data)
				{
					p=small_right(p);
				}
				else
				{
					p = big_right(p);
				}
			}
		}
	}
	else if (p->left == NULL)
	{
		d=p;
		free(d);
		p=p->right;
		cout<<"Элемент удален"<<endl;
	}
	else if (p->right == NULL)
	{
		d=p;
		p=p->left;
		free(d);
		cout<<"Элемент удален\n"<<endl;
	}
	else
	{
		p->data = deletemin(p->right);
	}
int m,n,a;
m=bsheight(p->left);
n=bsheight(p->right);
a=max(m,n);
p->height = a + 1;
}

int BST::deletemin(node * &p)
{
	int c;
	if (p->left == NULL)
	{
		c=p->data;
		p=p->right;
		return c;
	}
	else
	{
		c=deletemin(p->left);
		return c;
	}
}

void BST::show_growth(node * p)
{
	if (p!=NULL)
	{
		show_growth(p->left);
		cout<<p->data<<" ";		
		show_growth(p->right);
	}
}
 
void BST::show_level(node * p)
{
	queue <node*> A;
		A.push(p);
		while (!A.empty()){
			node* tmp=A.front();
			A.pop();
			cout<<tmp->data<< " ";
			if (tmp->left) A.push(tmp->left);
			if (tmp-> right) A.push(tmp->right);
		}		
}
 
 
int BST::max(int value1, int value2)
{
	return ((value1 > value2) ? value1 : value2);
}

int BST::bsheight(node * p)
{
	int t;
	if (p == NULL)
	{
		return -1;
	}
	else
	{
		t = p->height;
		return t;
	}
}
 
node * BST:: small_left(node * &ptr){
	node* p= ptr;
	node* q=p->left;
	p->left = q->right;
	q->right= p;
	p->height = max(bsheight(p->left),bsheight(p->right)) + 1;
	q->height = max(bsheight(q->left),p->height) + 1;
	return q;
}

node * BST:: small_right(node * &ptr)
{
	node* p= ptr;
	node* q = p->right;
	p->right = q->left;
	q->left = p;
	p->height = max(bsheight(p->left),bsheight(p->right)) + 1;
	q->height = max(p->height,bsheight(q->right)) + 1;
	return q;
}
node * BST:: big_left(node * &ptr)
{
	node* p = ptr;
	node* q = p->left;
	node* r = q->right;
	q->right = r->left;
	p->left = r->right;
	r->left = q;
	r->right = p;
	p->height = max(bsheight(p->left),bsheight(p->right)) + 1;
	q->height = max(bsheight(q->left),bsheight(q->right)) + 1;
	r->height = max(p->height, q->height) + 1;
	return r;
}
node * BST::big_right(node * &ptr)
{
	node* p = ptr;
	node* q = p->right;
	node* r = q->left;
	q->left = r->right;
	p->right = r->left;
	r->right = q;
	r->left = p;
	p->height = max(bsheight(p->left),bsheight(p->right)) + 1;
	q->height = max(bsheight(q->left),bsheight(q->right)) + 1;
	r->height = max(p->height, q->height) + 1;
	return r;
}
 
int main()
{
node * root;
BST bst;
root = NULL;
int count, element;
cout << "Количество вставленных элементов ";
cin >> count;
int* a= new int[count];
for (int i=0; i<count; i++){
cin>>a[i];
bst.insert(a[i],root);	
}
cout<< "Вывод элементов в порядке возрастания ";
bst.show_growth(root);
cout<<endl;
cout <<"Вывод элементов по уровням ";
bst.show_level(root);
cout<<endl;
cout <<"Какой элемент ищем? ";
cin >> element;
if (root != NULL)
	{
		bst.find(element,root);
	}
cout<<endl;
cout <<"Какой элемент удаляем? ";
cin >> element;
bst.del(element ,root);
bst.show_growth(root);
	return 0;
}
