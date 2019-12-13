
#include<bits/stdc++.h>


using namespace std;

/*
void add(char *v ,int p)
{
    node *t =new node();
    strcpy(t->val,v);
    t->next= h;
    h=t;


}

*/



int listSize=10;

class node{
private:

public:

    char val[200];
    node *next;

};


node** lis;
node *h=NULL;

int searc(char *s, int p)
{

    node *t= new node();
    char v[20];
    t=lis[p];

        while(t!=NULL)
        {
           // cout<<"\n entry val \n";
           if(strcmp(t->val,s)==0)
           {

               return -1;
           }

           t=t->next;

        }

return 1;

}



void show()
{
cout<<"\n entry show \n";
    int i=0;

    node *t= new node();
    char v[20];
    for(int k=0;k<50;k++)
    {
            cout<<"-";

    }
    cout<<endl;

    //cout<<"\n going to while \n";;
    while(i<listSize)
    {
        //cout<<lis[i]->val<<"\n\n";
        //cout<<lis[i].val<<"\t";
        t=lis[i];


        cout<<" "<<i<<"|";
        //cout<<i<<" i\n";

        while(t!=NULL)
        {
           // cout<<"\n entry val \n";
           cout<<"\t"<<t->val;
           t=t->next;


        }

        cout<<endl;
       for(int k=0;k<50;k++)
        {
                cout<<"-";

        }


    i++;
    cout<<endl;

    }


}

void entry( char *s,int p)
{
    int ck;
        ck=searc(s,p);

   // while(lis[p]==NULL)
   // {
        if(ck!=-1)
        {
            node *t =new node();
            strcpy(t->val,s);
            t->next= lis[p];
            lis[p]=t;

        }
        else
        {

            cout<<"already in the list !!! \n";
        }
   // }


}

int position(char *s, int n)
{
    int l=strlen(s);
    int pos=0;
    int v;

    for(int i=0,j=9;i<l;i++,j+=n-1)

    {
        v=int(s[i])*j;
        //cout<<v<<"\t";
        pos+=v;
    }
   // cout<<pos<<"\t";
    return pos%n;


}







int main()
{
    char symbol[200];
    int n=20;

    int i=n;
    int c,a,ag;
    listSize=n;
    lis=new node*[listSize];
    for (int j = 0; j< listSize; j++)
    {

        lis[j] = NULL;

    }

    while(1)
    {
        cout<<"1.Insert \n2.Search \n3.Display "<<endl;
        cin>>c;
        if(c==1)
        {


                scanf("%s",symbol);
                int p=position(symbol,n);

                //store(symbol,p);
                //cout<< a;
                //add(symbol,p);

                entry(symbol,p);
                cout<<" at "<<p<<"\n";

        }

        else if(c==2)
        {
            scanf("%s",symbol);
            int p=position(symbol,n);
            if(searc(symbol,p)==-1)
            {
                cout<<"Found !!! at position ["<<p<<"] = "<<symbol<<endl;

            }
            else
            {

                cout<<"Not available in this list !!! "<<endl;
            }

        }
        else if(c==3)
        {
            show();
        }
        else{

            cout<<"Wrong Input !!! enter again \n"<<endl;

       }

    }

return 0;

}
