/* Statement: Create structure to manage the books in “Library” with following data item and functions.
i.	Name of the book
ii.	Author of the book
iii.	Price of the book
iv.	No. of copies 
Implement following functions to perform operations
1.	Read the data of 5 books
2.	Display the data of books
3.	Search the specified book in the Library by name, if it is available or not, if available then display no of copies of the book.
4.	Search the specified book in the Library by Author Name, display all the books of the same author.
5.	Sort the list of books by its name.*/

#include <iostream>
using namespace std;
struct Library
{
    string book;
    string author;
    float price;
    int copies;
    void ReadBook()
    {
        cout<<"Enter the name of the book: ";
        getline(cin>>ws,book);
        cout<<"Enter the name of the author: ";
        getline(cin>>ws,author);
        cout<<"Enter the price of the book: ";
        cin>>price;
        cout<<"Enter the number of copies of the book: ";
        cin>>copies;
        cout<<endl;
    }
    void Display()
    {
        cout<<"Book: "<<book<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Number of Copies: "<<copies<<endl<<endl;
    }
    void searchbyname(Library B[], int n)
    {
        string s;
        int y=0;
        cout<<"Enter the name of the book to be searched: ";
        getline(cin>>ws,s);
        for(int i=0;i<n;i++)
        {
            if(B[i].book==s)
            {
                if(B[i].copies>0)
                {
                    cout<<"Book available"<<endl;
                    cout<<"Number of copies: "<<B[i].copies<<endl;
                    y=1;
                }
            }
        }
        if(y==0)
        cout<<"Book not available"<<endl;
    }
    void searchbyauthor(Library B[], int n)
    {
        string a;
        int z=0;
        cout<<"Enter the name of the author of book to be searched: ";
        getline(cin>>ws,a);
        for(int i=0;i<n;i++)
        {
            if(B[i].author==a)
            {
                if(B[i].copies>0)
                {
                    cout<<B[i].book<<endl;
                    z=1;
                }
            }
        }
        if(z==0)
        cout<<"Book not available"<<endl;
    }
    void sort(Library B[], int n)
    {
        Library B1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(B[i].book>B[j].book)
                {
                    B1=B[i];
                    B[i]=B[j];
                    B[j]=B1;
                }
            }
        }
    }
};
int main()
{
    Library B[5];
    int c,i;
    char x='Y';
    while(x=='Y'||x=='y')
    {
        cout<<"\tWelcome to the Library!!"<<endl;
        cout<<"Enter 1 to read the data of books"<<endl;
        cout<<"Enter 2 to display the data of books"<<endl;
        cout<<"Enter 3 to search a book by its name"<<endl;
        cout<<"Enter 4 to search a book by author's name"<<endl;
        cout<<"Enter 5 to sort the list of books by name"<<endl;
        cout<<"Enter 6 to exit"<<endl;
        cin>>c;
        switch(c)
        {
            case 1:
            for(i=0;i<5;i++)
            B[i].ReadBook();
            break;
            case 2:
            for(i=0;i<5;i++)
            B[i].Display();
            break;
            case 3:
            B[0].searchbyname(B,5);
            break;
            case 4:
            B[0].searchbyauthor(B,5);
            break;
            case 5:
            B[0].sort(B,5);
            break;
            case 6:
            exit(0);
        }
        cout<<"Do you wish to continue? Y/N"<<endl;
        cin>>x;
    }
    return 0;
}
