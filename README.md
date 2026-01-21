# E-Commerce System (OOPS in C++)

A console-based E-Commerce Platform implemented in modern C++ demonstrating Object-Oriented Programming (OOP) principles. This repository contains a self-contained, menu-driven application that models core e-commerce functionality such as user authentication, product browsing, cart management, purchase history, and simple recommendations.

## Table of Contents

- Overview
- Features
- OOP Concepts Demonstrated
- Project Structure
- Requirements
- Build & Run
- Default Users
- Sample Categories & Products
- Future Enhancements
- Contributing
- License
- Author

## Overview

This project is intended for learning and academic use. It models how an e-commerce system can be structured using OOP principles in C++ and uses the Standard Library (STL) for container and string management. The application runs in the terminal and provides a menu-based interface to interact with users and products.

## Features

- User management
  - User registration with email validation (regex) and phone validation
  - Secure login system and view account details

- Product management
  - Multiple product categories (Electronics, Fashion, Home Appliances, Books, Sports)
  - Each category implemented as a derived class from a common `Product` base class

- Cart system
  - Add products to cart
  - View cart items
  - Selectively purchase items from the cart

- Purchase history
  - Track purchased items and view past purchases

- Product recommendations
  - Simple recommendation display after adding items to cart (implemented using polymorphism)

- Error handling and input validation
  - Robust checks for invalid input and safe `cin` usage
  - Menu-based navigation with basic exception handling

## OOP Concepts Demonstrated

- Abstraction: `Product` abstract base class
- Inheritance: Category classes derive from `Product`
- Polymorphism: Virtual functions like `display()` and `getRecommendations()`
- Encapsulation: Data members accessed via class methods
- Use of STL: `vector`, `string`, `regex`

## Project Structure

````markdown
```text
E-commerce_system_OOPS_CPP/
├── main.cpp          # Complete source code
├── README.md         # Project documentation
├── LICENSE           # MIT License
```
````

## Requirements

- C++ compiler (GCC, Clang, MinGW)
- C++11 or later

## Build & Run

From the repository root, compile and run the application:

```bash
g++ main.cpp -o ecommerce -std=c++11
./ecommerce       # On Windows: ecommerce.exe
```

## Default Users (Preloaded)

| Name     | Email             | Password     |
|----------|-------------------|--------------|
| Niharika | nikky@gmail.com   | password123  |
| Bhavya   | bav@gmail.com     | password123  |
| Madhav   | m@gmail.com       | p12          |
| Sandeep  | s@gmail.com       | p19          |

> These are sample users added for testing the console application.

## Sample Categories & Products

- Electronics: Smartphone, Laptop, Smart TV, Smartwatch
- Fashion: T-Shirts, Jeans, Sneakers
- Home Appliances: Refrigerator, Microwave, Blender
- Books: C++, Data Structures, Operating Systems
- Sports: Basketball, Yoga Mat, Dumbbells

## Future Enhancements

Planned improvements include:

- File handling for persistent data storage
- Randomized and improved recommendation logic
- Admin panel for product management
- Detailed price calculation and checkout summary
- Discount & coupon system
- Payment simulation and integration

## Contributing

Contributions, suggestions and improvements are welcome. Please open an issue or submit a pull request describing your change.

## License

This project is licensed under the MIT License — see the LICENSE file for details.

## Author

Sandeep Jat — Computer Science Student

GitHub: https://github.com/JAT-SANDEEP8117
