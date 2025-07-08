# 🛒 Grocery Billing System By team **The Debuggers**

This is a simple C++ Console Application for managing a Grocery Shop's billing system. The system handles Product Management, Customer Billing, and Invoice Generation with input validation and file storage.


## 🔧 Features

### ✅ Product Management
- Add new products with ID, name, and price
- Update products by ID
- Delete products by ID
- View all available products

### 👲 Custome's detials
- Add customer name and mobile number
- Add products using Product ID to the bill with quantity
- Add discount(in %)
- Calculate total amount for customer purchase

### 🧾 Invoice Generation
- Generate invoice with a unique invoice number
- Display purchased items, quantity, price, and total
- Save invoice details to a file

### 🗃️ File Structure

- "product.txt" – Stores all available products
- "customer.txt" – Stores temporary customer cart details
- "allcustomer.txt" – Stores all customers invoice records
- "main.cpp" – Main source code


## 🧪 Input Validations

- **Product ID**: Must be a positive integer
- **Product Name / Customer Name**: Must contain only alphabets and spaces
- **Price / Quantity**: Must be positive float
- **Mobile Number**: Must be 10 digits


## ▶️ How to Run

### 👨‍💻 Using VsCode--
-- open the vscode and run the compiled file.


## 📋 MENU Options

###  main menu
 1. for product management.
 2. for printInvoice.
 3. for Exit.

  #### product management menu
  1. for add product
  2. for update any product using Product id
  2. for delete any product using Product id
  3. for display products available on the store
  4. exit back...

  #### printInvoice
  1. Enter invoice number
  2. Enter your name
  3. Enter mobile numebr
  4. Enter product id and quantity which product he buy
  5. Enter discount
  - -> then Invoice will be autometic generate


## 📃 Sample Invoice output:
<pre>
------------------   Welcome   -----------------
         ** Radhe-Radhe Grocery shop **

/--------------------Invoice--------------------/
invoice number: 112      T&D: Fri Jun 27 09:23:01 2025

name: sanjay        mob_number: 1245789636

--------------------***-------------------------
id    price      qt.         name      total
------------------------------------------------
11   45        5.13          apple     230.85
13   45.9      2.35          papaya    107.865
12   45.26     15.23         banana    689.31
------------------------------------------------
yours total amount is: 1028.02
discount: 3%
tax: 5%
tax amount is: 51.40
------------------------------------------------
your final amount is: 1048.59
*----------------------------------------------*

</pre>
##  ⚙️ Technologies Used
- -> Standard Template Library (iostream, fstream, string, cctype, ctime)
- -> C++ (Object-Oriented Programming)
- -> File Handling (txt files)

## 🧑🏻‍🤝‍🧑🏽 About Team:
- **Organised by**: **SPARKS(beginner)**
- **Team Name**- **The Debuggers**
- **Team Members**
  - *Sanjay Kumar Kumawat* you can see my profile on  <a target="_blank" href="https://www.linkedin.com/in/sanjay-kumawat-461b23358/"> Linkden</a>
  - *Vishal Sharma*
 
