<img src="https://thumbs.dreamstime.com/b/vending-machine-bottled-drinks-isolated-icon-vector-illustration-design-139879624.jpg" width="200px" height="200px">

## Vending Machine

Write code for basic vending machine implementation.

### Problem Statement: 

- Display the products with prices and quantities currently available
- Ask the user to select product with quantities and show him the cost
- Do a transaction if everything is valid and return the change 

- Items can be changed or increased
- It should be scalable and production ready code.
- Denominations can also change.


#### Sample data

```
Products: 
Pepsi, Dairy milk, Lays

Quantities:
20, 10, 30

Price  (per unit)
25, 10, 20

Denominations: (currency in INR)
5, 10, 20, 50 , 100 
```


-------

### Code/Run

- Download code file: [cr.cpp](https://github.com/alpha74/LLD-MachineCoding/blob/main/Z3Jvd3c%3D/Vending_Machine/cr.cpp)
- Downloan [run.sh](https://github.com/alpha74/LLD-MachineCoding/blob/main/Z3Jvd3c%3D/Vending_Machine/run.sh) file.
- Run `./run.sh` 


### Classes


#### VendingMachine

- Has a list of `Inventory`
- Has a list of `Coin`s defined
- Has some list of coins called `Cash` 


#### Inventory

- productId
- qty


#### Product

- id
- price
- name


#### Coin

- value


#### Cash

- `Coin`
- qty: -1
