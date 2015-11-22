#include <stdio.h>
#include <iostream>




struct rb_node
{
	int data;
	struct rb_node* leftptr;
	struct rb_node* rightptr;
	struct rb_node* parentptr;
	char color;
};

	struct rb_node* nil = new rb_node;
	struct rb_node* root;

void insert(int value);
void insert_rbtree(struct rb_node *z);
void leftRotate(struct rb_node* x);
void rightRotate(struct rb_node* y);
void search(int value);
void print(struct rb_node *temp);

int main(int argc, char const *argv[])
{
	/* code */
	nil->color = 'B';
	nil->leftptr = NULL;
	nil ->rightptr = NULL;
	root = nil;
	// struct rb_node *temp = root;
	int i,n;
	while(true){

		printf("Enter 1 to insert value into red black tree\n2 to search for an element\n3 to print the tree\n4 to exit program\n");
		scanf("%d",&n);
		switch(n){
			case 1:
				printf("Enter the value to insert\n");
				scanf("%d",&n);
				insert(n);
				break;
			case 2:
				printf("Enter the number to be searched\n");
				scanf("%d",&n);
				search(root,n);
				break;
			case 3:
				
				print(root);
				break;
			case 4:
				return 0;

		}
	}

	return 0;
}

void insert(int value){
		struct rb_node *y = nil;
		struct rb_node * x = root;
		printf("%d\n",x->data );
		printf("%d\n",root->data );
		struct rb_node* z = new struct rb_node;
		z->data = value;
		while(x!=nil){
			printf("eter\n");
			y = x;
			if(z->data < x->data)
				x = x->leftptr;
			else
				x = x->rightptr;

	}
	

		z->parentptr = y;
		if(y==nil)
			(root)= z;
		else if(value<y->data)
			y->leftptr = z;
		else
			y->rightptr = z;
		z->leftptr = nil;
		z->rightptr = nil;
		z->color= 'R';
		//printf("%d\n",root->data );
		//printf("%d\n",&nil);

		//insert_rbtree(z);


}






void insert_rbtree(struct rb_node* z){
	printf("enter build tree\n");
	struct rb_node* y = NULL;
	if(z->parentptr!=NULL&&z->parentptr->parentptr!=NULL&&z->parentptr->parentptr->leftptr!=nil&&z->parentptr->parentptr->rightptr!=nil){
	while(z->parentptr->color=='R'){
		printf("entered while loop\n");
		if(z->parentptr==z->parentptr->parentptr->leftptr){
			y = z->parentptr->parentptr->rightptr;
			if(y->color=='R'){
				z->parentptr->color='B';
				y->color = 'B';
				z->parentptr->parentptr->color = 'R';
				z = z->parentptr->parentptr;
			}else if(z==z->parentptr->rightptr){
				z = z->parentptr;
				printf("going to leftRotate1\n");
				leftRotate(z);
			}
			z->parentptr->color = 'B';
			z->parentptr->parentptr->color = 'R';
			printf("going to rightRotate1\n");
			rightRotate(z);
		}else{
				y = z->parentptr->parentptr->leftptr;
			if(y->color=='R'){
				z->parentptr->color='B';
				y->color = 'B';
				z->parentptr->parentptr->color = 'R';
				z = z->parentptr->parentptr;
			}else if(z==z->parentptr->leftptr){
				z = z->parentptr;
				printf("going to leftRotate2\n");

				leftRotate(z);
			}
			z->parentptr->color = 'B';
			z->parentptr->parentptr->color = 'R';
			printf("going to rightRotate2\n");

			rightRotate(z);
		}
	}
		(root)->color = 'B';
	}

}


void leftRotate(struct rb_node* x){
	printf("leftRotate\n");
	struct rb_node *y = x->rightptr;
	x->rightptr = y->leftptr;

	if(y->leftptr!=nil){
		y->leftptr->parentptr=x;
	}

	y->parentptr = x->parentptr;
	if(x->parentptr==nil)
		root = y;

	 else if (x == x->parentptr->leftptr)
        x->parentptr->leftptr = y;
    else   
     x->parentptr->rightptr = y;
 
    
    y->leftptr = x;
 
    
    x->parentptr = y;
}

void rightRotate(struct rb_node* y){
	printf("rightRotate\n");
	struct rb_node *x = y->leftptr;
    y->leftptr = x->rightptr;
    if (x->rightptr != nil)
        x->rightptr->parentptr = y;
    x->parentptr =y->parentptr;
    if (y->parentptr == nil)
        (root) = x;
    else if (y == y->parentptr->rightptr)
        y->parentptr->rightptr = x;
    else
     	y->parentptr->leftptr = x;
    x->rightptr = y;
    y->parentptr = x;
}



void print(struct rb_node * temp){
	if(root==nil)
		return;
	if(temp->leftptr!=nil){
	print((temp->leftptr));
}
	printf("%d\n",temp->data );
	if(temp->rightptr!=nil)
	print((temp->rightptr));

}


void search(struct rb_node * temp){
	if(root==NULL)
		return;
	if(temp->leftptr!=nil){
	print((temp->leftptr));
}
	printf("%d\n",temp->data );
	if(temp->rightptr!=nil)
	print((temp->rightptr));

}




