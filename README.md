# Skip List Implementation in C++

A simple and efficient implementation of the **Skip List** data structure using **C++**. This project includes interactive command-line functionality for inserting, deleting, and searching elements.

---

## 🚀 Features

* Skip List implemented with random level generation
* Insert, Search, and Delete operations
* Console-based user interface
* Easy to compile and run

---

## 📂 Project Structure

```
SkipList-CPP-Project/
├── skiplist.cpp         # Main implementation file (C++)
├── README.md            # Project documentation
├── report.pdf           # Project report (see /docs)
├── analysis.pdf         # Complexity analysis
├── presentation.pptx    # Slide deck for presentation
```

---

## 🧠 How Skip List Works

A Skip List is a data structure that allows O(log n) search complexity by maintaining multiple levels of forward pointers. Nodes are assigned levels probabilistically, leading to a balance similar to binary search trees but simpler to implement.

![Skip List Diagram](https://upload.wikimedia.org/wikipedia/commons/thumb/8/86/Skip_list.svg/800px-Skip_list.svg.png)

---

## ⚙️ Installation & Compilation

### Prerequisites:

* g++ or any C++ compiler

### Compile:

```bash
g++ skiplist.cpp -o skiplist
```

### Run:

```bash
./skiplist
```

---

## 🧪 Sample Usage

```text
Skip List Menu
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter your choice: 1
Enter value to insert: 15
Inserted key: 15
```

---

## 📈 Time & Space Complexity

| Operation | Average Case | Worst Case |
| --------- | ------------ | ---------- |
| Search    | O(log n)     | O(n)       |
| Insert    | O(log n)     | O(n)       |
| Delete    | O(log n)     | O(n)       |

Space Complexity: O(n log n)

---

## 📚 Resources

* William Pugh, "Skip Lists: A Probabilistic Alternative to Balanced Trees"
* [Wikipedia: Skip List](https://en.wikipedia.org/wiki/Skip_list)
* [GeeksForGeeks: Skip List](https://www.geeksforgeeks.org/skip-list/)

---

## 🧑‍💻 Author

**Hafiz Tanzeel Shamshad**
MERN Stack Web Developer | C++ Programmer | Machine Learning Enthusiast

[LinkedIn](https://www.linkedin.com/in/tanzeel-shamshad-8680a8309/)
[Portfolio](#)

---

## 📝 License

This project is open-source and available under the [MIT License](LICENSE).

---

## 📊 Presentation & Report

Find detailed analysis and slides in the [report.pdf](./report.pdf) and [presentation.pptx](./presentation.pptx).

---

Happy coding! 🚀
