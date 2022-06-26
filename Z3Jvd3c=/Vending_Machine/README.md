# Vending Machine

Write code for basic vending machine implementation.

## Functionality: 

- Display the products with prices and quantities currently available
- Ask the user to select product with quantities and show him the cost
- Do a transaction if everything is valid and return the change 


### Other features

- Items can be changed or increased
- It should be scalable and production ready code.
- Denominations can also change.


### Sample data

Products: 
Pepsi, Dairy milk, Lays

Quantities:
20, 10, 30

Price  (per unit)
25, 10, 20

Denominations: (currency in INR)
5, 10, 20, 50 , 100 



-------

## Notes

- Code file `cr.cpp`
- Run `./run.sh`


### VendingMachine

- Has a list of `Inventory`
- Has a list of `Coin`s defined
- Has some list of coins called `Cash` 


### Inventory

- productId
- qty


### Product

- id
- price
- name


### Coin

- value


### Cash

- `Coin`
- qty: -1
