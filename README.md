<div align="center">
<h1 align="center">
<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="100" />
<br>
42-Philosophers
</h1>
<h3 align="center">📍 Unleash your inner philosopher with 42-Philosophers on GitHub!</h3>
<h3 align="center">⚙️ Developed with the software and tools below:</h3>

<p align="center">
<img src="https://img.shields.io/badge/GNU%20Bash-4EAA25.svg?style=for-the-badge&logo=GNU-Bash&logoColor=white" alt="GNU%20Bash" />
<img src="https://img.shields.io/badge/C-A8B9CC.svg?style=for-the-badge&logo=C&logoColor=black" alt="C" />
<img src="https://img.shields.io/badge/Markdown-000000.svg?style=for-the-badge&logo=Markdown&logoColor=white" alt="Markdown" />
</p>
</div>
[![jremy's 42 Philosophers Score](https://badge42.vercel.app/api/v2/cl27cprhd001109mercwbbu5l/project/2510693)](https://github.com/JaeSeoKim/badge42)
---

## 📚 Table of Contents
- [📚 Table of Contents](#-table-of-contents)
- [📍 Overview](#-overview)
- [💫 Features](#-features)
- [📂 Project Structure](#project-structure)
- [🧩 Modules](#modules)
- [🚀 Getting Started](#-getting-started)
- [🗺 Roadmap](#-roadmap)
- [🤝 Contributing](#-contributing)
- [📄 License](#-license)
- [👏 Acknowledgments](#-acknowledgments)

---


## 📍 Overview

The 42-Philosophers project is a multithreaded program that simulates the dining philosophers problem. It includes various files for initializing global variables, launching threads, printing messages, and handling philosopher states. The program offers a practical implementation of concurrent programming and synchronization using mutexes, semaphores, and time-related functionalities. Its value proposition lies in its ability to provide a hands-on learning experience for students to understand the challenges of concurrent programming and develop strategies to resolve them.

---

## 💫 Features

Feature | Description |
|---|---|
| **🏗 Structure and Organization** | The codebase is structured into separate folders for the main program, header files, and library functions. The makefiles allow for easy compilation and building of the program. |
| **📝 Code Documentation** | The code is well documented with descriptive function and variable names, comments, and a separate header file for declarations, making it easy to understand the code's functionality without examining the implementation details. |
| **🧩 Dependency Management** | The codebase uses standard C libraries for Time, String, and other functions, and includes custom library functions for string manipulation, making it easy to manage dependencies. |
| **♻️ Modularity and Reusability** | The code is designed with modularity in mind, with separate functions and files for each individual task and reusable code in the libraries. The functions are designed to be reusable for similar programs or problems. |
| **✔️ Testing and Quality Assurance** | The codebase includes a test script for checking for memory leaks, and the code is well formatted and commented, indicating a focus on quality control. |
| **⚡️ Performance and Optimization** | The codebase uses mutexes and semaphores for synchronizing access to shared resources and minimizing race conditions, indicating an emphasis on performance and optimization. |
| **🔒 Security Measures** | The codebase does not contain any known security vulnerabilities or exploits. |
| **📈 Scalability and Extensibility** | The code is designed to handle a variable number of philosophers, forks, and threads, and can be easily extended and modified for similar problems. The use of standard libraries and modular functions also enables easy scalability. |

---


<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-github-open.svg" width="80" />

## 📂 Project Structure


```bash
repo
├── README.md
├── en.subject.pdf
├── philo
│   ├── Makefile
│   ├── includes
│   │   └── philosophers.h
│   ├── minilib
│   │   ├── print
│   │   │   └── ft_putstr_fd.c
│   │   ├── stdlib
│   │   │   ├── ft_atoi.c
│   │   │   ├── ft_atol.c
│   │   │   └── ft_itoa.c
│   │   └── string
│   │       └── ft_strlen.c
│   ├── srcs
│   │   ├── init.c
│   │   ├── launcher.c
│   │   ├── philosophers.c
│   │   ├── print.c
│   │   ├── routine.c
│   │   ├── state.c
│   │   └── time.c
│   └── test.sh
└── philo_bonus
    ├── Makefile
    ├── includes
    │   └── philosophers_bonus.h
    ├── minilib
    │   ├── print
    │   │   └── ft_putstr_fd.c
    │   ├── stdlib
    │   │   ├── ft_atoi.c
    │   │   ├── ft_atol.c
    │   │   └── ft_itoa.c
    │   └── string
    │       └── ft_strlen.c
    ├── srcs
    │   ├── init.c
    │   ├── launcher.c
    │   ├── philosophers.c
    │   ├── print.c
    │   ├── routine.c
    │   ├── state.c
    │   └── time.c
    └── test.sh

15 directories, 32 files
```

---

<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-src-open.svg" width="80" />

## 🚀 Getting Started

### ✅ Prerequisites

Before you begin, ensure that you have the following prerequisites installed:
> - Make

### 🖥 Installation

1. Clone the 42-Philosophers repository:
```sh
git clone https://github.com/jremy42/42-Philosophers
```

2. Change to the project directory:
Mandatory:
```sh
cd 42-Philosophers/philo
```
Bonus:
```sh
cd 42-Philosophers/philo_bonus
```


3. Compilation
```sh
make
```

### 🤖 Using 42-Philosophers

```sh
./myapp 
```

### 🧪 Running Tests
```sh
/* No common unit test framework in C */
```

---


## 🗺 Roadmap

> - [X] [📌  Task 1: Implement X]
> - [ ] [📌  Task 2: Refactor Y]
> - [ ] [📌  Task 3: Optimize Z]
> - [ ] ...


---

## 🤝 Contributing

Contributions are always welcome! Please follow these steps:
1. Fork the project repository. This creates a copy of the project on your account that you can modify without affecting the original project.
2. Clone the forked repository to your local machine using a Git client like Git or GitHub Desktop.
3. Create a new branch with a descriptive name (e.g., `new-feature-branch` or `bugfix-issue-123`).
```sh
git checkout -b new-feature-branch
```
4. Make changes to the project's codebase.
5. Commit your changes to your local branch with a clear commit message that explains the changes you've made.
```sh
git commit -m 'Implemented new feature.'
```
6. Push your changes to your forked repository on GitHub using the following command
```sh
git push origin new-feature-branch
```
7. Create a pull request to the original repository.
Open a new pull request to the original project repository. In the pull request, describe the changes you've made and why they're necessary.
The project maintainers will review your changes and provide feedback or merge them into the main branch.

---

## 📄 License

This project is licensed under the `[📌  INSERT-LICENSE-TYPE]` License. See the [LICENSE](https://docs.github.com/en/communities/setting-up-your-project-for-healthy-contributions/adding-a-license-to-a-repository) file for additional info.

---

## 👏 Acknowledgments

> - [📌  List any resources, contributors, inspiration, etc.]

---
