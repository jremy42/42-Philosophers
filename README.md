<div align="center">
<h1 align="center">
<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="100" />
<br>
42-Philosophers [![jremy's 42 Philosophers Score](https://badge42.vercel.app/api/v2/cl27cprhd001109mercwbbu5l/project/2510693)](https://github.com/JaeSeoKim/badge42)
</h1>
<h3 align="center">📍 Unleash your inner philosopher with 42-Philosophers on GitHub!</h3>
<h3 align="center">⚙️ Developed with the software and tools below:</h3>

<p align="center">
<img src="https://img.shields.io/badge/GNU%20Bash-4EAA25.svg?style=for-the-badge&logo=GNU-Bash&logoColor=white" alt="GNU%20Bash" />
<img src="https://img.shields.io/badge/C-A8B9CC.svg?style=for-the-badge&logo=C&logoColor=black" alt="C" />
<img src="https://img.shields.io/badge/Markdown-000000.svg?style=for-the-badge&logo=Markdown&logoColor=white" alt="Markdown" />
</p>
</div>

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
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```
- number_of_philosophers: The number of philosophers, as well as the number of forks.
- time_to_die (in milliseconds): If a philosopher hasn't started eating within time_to_die milliseconds after the beginning of their previous meal or since the start of the simulation, they die.
- time_to_eat (in milliseconds): The time a philosopher takes to eat. During this time, a philosopher must hold onto both forks.
- time_to_sleep (in milliseconds): The time a philosopher spends sleeping.
- number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation ends. If this argument is not specified, then the simulation ends when a philosopher dies.

## 👏 Acknowledgments

> - [📌  List any resources, contributors, inspiration, etc.]

---
