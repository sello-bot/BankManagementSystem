  # 🏦 Bank Management System
Bank Management System (C++) The Bank Management System is a simple console-based application built in C++ that allows users to manage basic banking operations. It uses Object-Oriented Programming (OOP) principles, the Standard Template Library (STL) for data storage, and file I/O for persistent data saving.
A simple console-based Bank Management System implemented in C++ using Object-Oriented Programming principles. 💻

## ⭐ Features

✅ **Object-Oriented Design** - Uses `Account` and `Bank` classes  
✅ **STL Integration** - Uses `vector` for efficient account storage  
✅ **Persistent Storage** - Automatically saves/loads data to/from `accounts.txt`  
✅ **Menu-Driven Interface** - User-friendly console interface  
✅ **Core Banking Operations:**
- 🏦 Create new accounts
- 💰 Deposit money
- 💸 Withdraw money (with balance validation)
- 📊 Display all accounts with formatted output

## 🛠️ Technical Specifications

- **Language:** C++11 or later 💻
- **Data Structure:** STL Vector 📚
- **File I/O:** Text file storage (`accounts.txt`) 📁
- **Design Pattern:** Object-Oriented Programming 🏗️
- **Memory Management:** RAII principles 🧠

## 📁 Project Structure

```
BankManagementSystem/
│
├── src/
│   └── main.cpp           # Main source code
├── data/
│   └── accounts.txt       # Sample data file
├── screenshots/
│   └── program_demo.png   # Program screenshot
├── README.md              # Project documentation
├── LICENSE                # MIT License
└── .gitignore            # Git ignore file
```

## 🚀 Compilation and Usage

### 📋 Prerequisites
- C++ compiler (GCC, Clang, or Visual Studio) 🔧
- C++11 or later standard support 📈

### 🛠️ Compilation
```bash
# Using g++
g++ -std=c++11 -o bank_system src/main.cpp

# Using clang++
clang++ -std=c++11 -o bank_system src/main.cpp

# Using Visual Studio (Windows)
cl /EHsc src/main.cpp
```

### ▶️ Running the Program
```bash
./bank_system
```

## 📖 Usage Guide

### 🎮 Main Menu Options:
1. **Create Account** - Add a new bank account 🆕
2. **Deposit** - Add money to an existing account 💰
3. **Withdraw** - Remove money from an account (with balance check) 💸
4. **Display All Accounts** - View all accounts in a formatted table 📊
5. **Exit** - Save data and quit 🚪

### 💡 Sample Interaction:
```
=== Bank Management System ===
1. Create Account
2. Deposit
3. Withdraw
4. Display All Accounts
5. Exit
Enter choice: 1

Enter account number: 1001
Enter holder name: John Doe
Enter initial balance: 5000.50
Account created successfully.
```

## 📄 File Format

The program automatically saves account data in `accounts.txt` with the following format:
```
1001
John Doe
5000.50
1002
Jane Smith
3000.00
```

## 🏗️ Class Structure

### 🏦 Account Class
```cpp
class Account {
private:
    int accountNumber;
    string holderName;
    double balance;
    
public:
    // Constructor, getters, deposit(), withdraw(), display()
};
```

### 🏢 Bank Class
```cpp
class Bank {
private:
    vector<Account> accounts;
    const string fileName = "accounts.txt";
    
public:
    // CRUD operations, file I/O methods
};
```

## 🎯 Key Features Explained

- **RAII Design:** Constructor loads data, destructor saves data automatically 🔄
- **Input Validation:** Prevents overdrafts and handles invalid inputs ✅
- **Formatted Output:** Uses `iomanip` for professional table display 📊
- **STL Usage:** Efficient memory management with `std::vector` 🧠
- **Move Semantics:** Optimized string handling in constructor ⚡

## 🚀 Future Enhancements

- [ ] 🔍 Account search functionality
- [ ] 📈 Transaction history
- [ ] 💹 Interest calculation
- [ ] 🗑️ Account deletion
- [ ] 🔐 Password protection
- [ ] 🗄️ Database integration
- [ ] 🖥️ GUI interface

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Author
SELLO KGOLE

Created as a demonstration of Object-Oriented Programming concepts in C++.

## 🙏 Acknowledgments

- C++ STL Documentation 📚
- Object-Oriented Design Principles 🏗️
- File I/O Best Practices 📁

---

**Note:** This is an educational project demonstrating basic banking operations. For production use, implement proper security measures, encryption, and database storage.
