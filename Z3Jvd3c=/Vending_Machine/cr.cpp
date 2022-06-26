/*
    Aman Kumar 
*/


#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <math.h>

using namespace std ;


// ------------- CLASSES ----------------

/*
    A type of denomination
*/
class Coin
{
    int val ;
    
    public:
        Coin(int v)
        {
            val = v ;
        }
}; 

/*
    A type of product
*/
class Product
{
    static int pindex ;
    int id ;
    string name ;
    double price ;

    public:
        Product()
        {
            id = pindex++ ;
            name= "NULL" ;
            price = -1.0 ;
        }

        Product( string n, double p)
        {
            id = pindex++ ;
            name = n ;
            price = p ;
        }

        int getId()
        {
            return id ;
        }

        void setPrice( double p )
        {
            price = p ;
        }

        double getPrice()
        {
            return price ;
        }

} ;
int Product :: pindex = 1 ;



class VendingMachine
{
    unordered_map<int,int> inventory ;          // Mapping between productid and qty
    unordered_map<string,Product> products ;    // List of all products served by machine

    public:
        VendingMachine()
        {
            ;
        }

        // Add a new product, updates price, updates quantity
        void addProduct( string prodName, double prodPrice, int prodQty )
        {
            Product newProduct ;

            // First check if product exists or not
            auto iter = products.find( prodName ) ;

            // If does not exist
            if( iter == products.end() )
            {
                newProduct = Product( prodName, prodPrice ) ;
                products[ prodName ] = newProduct ;

                inventory[ newProduct.getId() ] = prodQty ;
            }
            // If product already exists, it will exist in inventory also
            else
            {
                newProduct.setPrice( prodPrice );
                inventory[ newProduct.getId() ] = prodQty ;
            }
            
        }

        // Prints list of products having qty > 0
        void listAllProducts()
        {
            cout << "\n List of Products \n\n " ;
            
            cout << "\n Name \t\t Qty \t\t Price" ;

            for( auto iter = products.begin() ; iter != products.end() ; iter++ )
            {
                Product currProduct = iter -> second ;
                int qty = 0 ;

                qty = inventory[ currProduct.getId() ] ;

                if( qty > 0 )
                    cout << "\n " << currProduct.getId() << ". " << iter -> first << "\t " << qty << " Rs. " <<  currProduct.getPrice() ;
            }
        }

        // Check if a product exists or not
        double isProductPresent( string prodName, int qty )
        {
            auto productObj = products.find( prodName ) ;

            // -1 : product does not exist
            if( productObj == products.end() ) 
                return -1 ;
            
            Product currProduct = productObj -> second ;
            auto inventoryObj = inventory.find( currProduct.getId() ) ;

            // -2 : Qty is less in VM
            if( inventoryObj -> second < qty )
            {
                return -2 ;
            }

            return qty * currProduct.getPrice() ;
        }


        // Check if quantity if 

}; 

//  --------- GLOBAL VARIABLES ---------


// -------------- METHODS --------------


// -------------- MAIN -----------------

void driver()
{
    VendingMachine VM ;

    VM.addProduct("Pepsi", 25, 10 ) ;
    VM.addProduct("Lays", 10, 10 ) ;
    VM.addProduct("Pepsi", 25, 20 ) ;

    VM.listAllProducts() ;

    string buyProductName = "NULL" ;
    int buyProductQty = 0 ;
    cout << "\n\n Buy Product " ;
    cout << "\n\n Enter Product Name: " ;
    cin >> buyProductName ;

    cout << "\n Enter Qty : " ;
    cin >> buyProductQty ;

    double result = VM.isProductPresent( buyProductName, buyProductQty ) ;

    if( int(result) == -1 )
    {
        cout << "\n\n >> Product does not exist" ;
        return ;
    }
    else if( int(result) == -2 )
    {
        cout << "\n\n >> Qty is not present" ;
        return ;
    }
    else
    {
        cout << "\n Total price: " << result ;
    }
    
    cout << "\n Enter " ;

    /*
    int option = 0 ;

    while( option != -1 )
    {
        cout << "\n\n\t  Vending Machine " ;
        cout << "\n\n 1. Add Product  \n 2. List all Products " ;

        cin >> option ;

        switch( option )
        {
            
        }
    }
    */
}

int main()
{
    driver() ;

    cout << "\n\n\n Exiting Vending Machine " ;

    cout << "\n" ;
}
