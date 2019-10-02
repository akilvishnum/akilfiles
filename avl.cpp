#include<iostream>
using namespace std;

#include<math.h>

struct avlnode
{
int data;
struct avlnode * l;
struct avlnode * r;
}*root;

class avlTree
{
public:
int height(avlnode *);
int diff(avlnode *);
avlnode * rl(avlnode *);
avlnode * ll(avlnode *);
avlnode * rr(avlnode *);
avlnode * lr(avlnode *);
avlnode * balance(avlnode *);
avlnode * insert (avlnode *,int);
void display(avlnode*,int);
void del(avlnode*,int);
avlnode *findmin(avlnode *);
avlTree()
{
root=NULL;
}
};
avlnode * avlTree::insert(avlnode * tree,int val)
{
if(tree==NULL)
{
tree=new avlnode;
tree->data=val;
tree->l=NULL;
tree->r=NULL;
return tree;
}
else if(tree->data>val)
{
tree->l=insert(tree->l,val);
tree=balance(tree);
}
else
{
tree->r=insert(tree->r,val);
tree=balance(tree);
}
return tree;
}


//balance
avlnode * avlTree::balance(avlnode * temp)
{
int bal=diff(temp);
if(bal>1)                                     //if balancing factor is greater than one it will be ll or lr rot.
{
 if(diff(temp->l)>0)
  temp=ll(temp);
  else
  temp=lr(temp);
}

else if (bal<-1)                               //if balancing factor is lesser than on it will be rr or rl rotation.
{
if(diff(temp->r)>0)

              temp=rl(temp);
else
temp=rr(temp);
}
return temp;
}

int avlTree::diff(avlnode * t)
{
int lheight=height(t->l);
int rheight=height(t->r);
int bal=lheight-rheight;
return bal;
}
  
int avlTree::height(avlnode *t )
{
int h=0; int max;
if(t!=NULL)
{
int l_height=height(t->l);
int r_height=height(t->r);
if(l_height>r_height)
{
max=l_height;
}
else
max=r_height;
//int max=max(l_height,r_height);
h=max+1;
}
return h;
}


avlnode * avlTree::ll(avlnode * p)
{
avlnode * t;
t=p->l;
p->l=t->r;
t->r=p;
return t;
}

avlnode * avlTree::rr(avlnode * p)
{
avlnode * t;
t=p->r;
p->r=t->l;
t->l=p;
return t;
}
avlnode * avlTree::lr(avlnode * p)
{
avlnode * t;
t=p->l;
p->l=rr(t);
return ll(p);
}
avlnode * avlTree::rl(avlnode * p)
{
avlnode * t;
t=p->r;
p->r=ll(t);
return rr(p);
}

void avlTree::display(avlnode* p,int x)
{
if(p!=NULL)
{
cout<<p->data<<endl;
display(p->l,0);
display(p->r,0);
}
}
void avlTree::del(avlnode* root,int x)
{
if(root==NULL)
cout<<"It is empty";
else
{
if((root->data)>x)
{
del(root->l,x);
}
else if(root->data<x)
{
del(root->r,x);
}
else if(((root->l)!=NULL)&&((root->r)!=NULL))
{
avlnode * temp;
temp=findmin(root->r);
root->data=temp->data;
del(root->r,root->data);
}
/*
else
{
}
*/
else
{ 
    if(root->l==NULL&&root->r==NULL)
    delete root;
    /*if(root->l==NULL)
    {
        
avlnode * temp;
temp=root->r;

root=temp;


    }*/
    




 if(root->l==NULL)
    {
        
avlnode * temp;
temp=root->r;


*root=*temp;
cout<<root->data<<"is deleted";
delete temp;

    }
    else
    {
        avlnode *temp;
        temp=root->l;
        *root=*temp;
        cout<<root->data<<"is deleted";
        delete temp;
    }

  /*if(root->l==NULL)
  {
      avlnode * lol=root;
      root=root->r;
      delete lol;
      
  }*/
    
    
    
    

}

}
balance(root);
}





avlnode * avlTree::findmin(avlnode *t)
{
if(t==NULL)
return 0;
if(t->l!=NULL)
t=findmin(t->l);
return t;




}


/*
void avlTree::display(avlnode * ptr,int level)
{
int i;
if(ptr!=NULL)
{
display(ptr->r,level+1);
printf("");
if(ptr==root)
cout<<"ROOT--->";
for(int i=0;i<level&&ptr!=root;i++)
{
cout<<"";
cout<<ptr->data;
}
cout<<ptr->data;
display(ptr->l,level+1);
}
}*/
int main()
{
int choice,a ,item; avlTree avl; 
do{
cout<<"Enter choice:";
cin>>choice;
switch(choice)
{
case 1:cout<<"Enter the value to be included";
cin>>item;
root=avl.insert(root,item);
break;
case 2: cout<<"Display Tree"<<endl;
if(root==NULL)
{
cout<<"NOTREEISPRESENT";
}
cout<<"balanced tree"<<endl;
avl.display(root,0);
break;
case 3:cout<<"Enter element to be deleted";
cin>>a;
avl.del(root,a);
break;
case 4:exit(1);
      choice=9;
break;
default:cout<<"";
choice=9;
}
}
while(choice!=9);
}





