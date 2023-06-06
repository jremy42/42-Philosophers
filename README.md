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
| **🔄 Version Control and Collaboration** | The codebase is hosted on GitHub, indicating that version control and collaboration are important aspects of the development process. |
| **🔌 External Integrations** | The codebase does not appear to have any external dependencies or integrations. |
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

## 🧩 Modules

<details closed><summary>Includes</summary>

| File                 | Summary                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  | Module                                    |
|:---------------------|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:------------------------------------------|
| philosophers.h       | The provided code snippet contains the header file for a multithreaded program that simulates a dining philosophers problem. It defines various macros, data structures, and function prototypes used in the program, such as initializing global variables, launching threads, printing messages, and handling philosopher states.                                                                                                                                                                                                      | philo/includes/philosophers.h             |
| philosophers_bonus.h | The provided code snippet contains a header file for a multi-threaded program that simulates philosophers at a table. The program utilizes various C libraries such as pthread.h, semaphores, and sys/time.h to implement mutexes, semaphores, and time-related functionalities to synchronize and simulate the actions of philosophers, such as eating, sleeping, and thinking. Additionally, the header file contains various helper functions for printing messages, converting string to integer, and initializing global variables. | philo_bonus/includes/philosophers_bonus.h |

</details>

<details closed><summary>Philo</summary>

| File     | Summary                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   | Module         |
|:---------|:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:---------------|
| Makefile | This code is a makefile for compiling and building a C program called'philo'. It includes various header files and source files divided into folders. It uses the'clang' compiler and has options for thread sanitization and debugging. It also includes rules for cleaning and removing compiled object files and the executable file.                                                                                                                                                                  | philo/Makefile |
| test.sh  | The provided code snippet is a bash script that runs a series of tests on a program called "philo" using Valgrind, a memory profiling tool. The script invokes Valgrind with different command line arguments to test various scenarios, and checks whether Valgrind reports any memory leaks or errors. If there are no leaks or errors, the script outputs "[OK]", otherwise it outputs "[NOK]" and displays the details of the detected issues. Finally, the script cleans up the generated log files. | philo/test.sh  |

</details>

<details closed><summary>Philo_bonus</summary>

| File     | Summary                                                                                                                                                                                                                                                                                                                                                                                                             | Module               |
|:---------|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:---------------------|
| Makefile | This code snippet is a makefile for compiling a C program called "philo_bonus". The makefile sets the compiler, compiler flags, and necessary header files and source code files to build the final executable. It also includes rules for cleaning and rebuilding the project. The final executable is linked with the pthread library.                                                                            | philo_bonus/Makefile |
| test.sh  | The provided code snippet is a Bash script that runs multiple tests on a program called "philo_bonus" using Valgrind. The tests have various arguments passed to "philo_bonus" and check for memory leaks using the options specified in Valgrind. The script then evaluates whether the tests have passed or not and prints the result to the terminal. Finally, it deletes any generated log files for each test. | philo_bonus/test.sh  |

</details>

<details closed><summary>Print</summary>

| File           | Summary                                                                                                                                                                                                                                                                                                                                                                                         | Module                                   |
|:---------------|:------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:-----------------------------------------|
| ft_putstr_fd.c | The provided code snippet defines a function called "__putstr_fd" that takes a string and writes it to a specified file descriptor. The function uses the standard C library function "write" and the "__strlen" function to write the string to the file descriptor. This function is used in the "philosophers.h" header file.                                                                | philo/minilib/print/ft_putstr_fd.c       |
| ft_putstr_fd.c | The code defines a function named "__putstr_fd" that takes in a character string and an integer file descriptor as arguments. The function writes the input string to the specified file descriptor using the "write" function. The length of the input string is calculated using the "__strlen" function. This code is part of a larger program for managing the dining philosophers problem. | philo_bonus/minilib/print/ft_putstr_fd.c |

</details>

<details closed><summary>Srcs</summary>

| File           | Summary                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      | Module                          |
|:---------------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:--------------------------------|
| philosophers.c | The code is for a program that simulates a multi-threaded dining philosopher problem. The program takes in command line arguments, initializes a global variable, and then launches multiple threads to simulate the dining philosophers. If any error occurs during execution, the program cleans up memory and exits with a non-zero status.                                                                                                                                                               | philo/srcs/philosophers.c       |
| print.c        | The provided code defines two functions to aid in printing messages for the dining philosophers problem. The "__get_message" function returns a message based on the philosopher's current state, while the "__print_message" function uses this message to print information about the current state of a given philosopher. These functions are used in conjunction with other code to simulate philosophers dining at a table.                                                                            | philo/srcs/print.c              |
| state.c        | The code snippet provides four functions that control the state of a philosopher in a dining philosophers problem. The functions include __sleeping, __eating, __take_left_fork, and __try_to_eat. These functions are responsible for regulating the philosopher's actions such as sleep, eat, take the left fork, and try to eat. The functions utilize mutexes to ensure that the philosopher only takes one fork at a time while trying to eat and sleeps or thinks after eating for a specified period. | philo/srcs/state.c              |
| init.c         | The code snippet provides functions for initializing the global structure, the philosopher structure, and the fork structure. It also checks for errors in the provided input data, initializes mutex locks, and assigns values to various variables within the structures. The functions aim to provide a smooth start for the dining philosophers problem simulation.                                                                                                                                      | philo/srcs/init.c               |
| time.c         | The provided code snippet contains two functions, `__usleep` and `__get_time`, used in a program for a simulation of the dining philosophers problem. The `__usleep` function takes a parameter for sleep duration and waits until that duration has passed. The `__get_time` function returns the current system time in milliseconds, using the `gettimeofday` function.                                                                                                                                   | philo/srcs/time.c               |
| routine.c      | The code snippet provides functions for checking if a philosopher is dead, determining if a philosopher should die, checking the state of a philosopher, and running the routine of a philosopher. These functions are used in a program that simulates the dining philosophers problem. The program creates a set number of philosophers, forks, and threads and then simulates each philosopher's actions as they dine.                                                                                    | philo/srcs/routine.c            |
| launcher.c     | The provided code snippet defines and invokes the "__launcher_threads" function, which creates multiple new threads using pthread_create() function. It also allocates memory for a thread ID array, sets a start time, and awaits thread completion using pthread_join() function before returning a 1 value to signify successful execution.                                                                                                                                                               | philo/srcs/launcher.c           |
| philosophers.c | The code snippet is a program for simulating the Dining Philosophers problem with concurrent threads using semaphores. The main function initializes a global data structure and launches threads that represent the philosophers. The program handles error cases and ensures proper cleanup of resources at exit.                                                                                                                                                                                          | philo_bonus/srcs/philosophers.c |
| print.c        | The provided code snippet contains two functions that enable printing messages about the current state of a philosopher in a concurrent program. The "__get_message" function returns a string message corresponding to the current state of a philosopher, while the "__print_message" function prints this message, along with the philosopher's ID and the current time. These functions are used in a larger program that simulates the dining philosophers problem.                                     | philo_bonus/srcs/print.c        |
| state.c        | The provided code snippet contains four functions that represent the different states of a philosopher's activity: sleeping, eating, taking the left fork, and trying to eat. Each function handles a specific task, such as checking the time, taking the left and right forks, printing a message, and updating the philosopher's status. The functions use semaphores to prevent concurrent access to shared resources, such as forks and the console output.                                             | philo_bonus/srcs/state.c        |
| init.c         | The provided code snippet contains functions for initializing the global structure, semaphores, and philo structure. It also includes a function for checking the input data. The global structure stores the input arguments, semaphores are used to synchronize fork usage, death, and print messages, and the philo structure is used to keep track of the philosopher's state and their actions. The code ensures that the input data is valid and errors are printed to stderr.                         | philo_bonus/srcs/init.c         |
| time.c         | The provided code snippet contains two functions for time management in the context of a concurrent dining philosophers problem. The "__usleep" function sleeps for a given number of milliseconds by repeatedly sleeping for 100 microseconds until the desired amount of time has passed, while the "__get_time" function returns the current time in milliseconds using the "gettimeofday" system call.                                                                                                   | philo_bonus/srcs/time.c         |
| routine.c      | The provided code snippet defines four functions (__check_dead, __should_i_die, __check_state, and __routine) used in a concurrent program to monitor and control the actions of a group of philosophers. The functions check for various conditions, such as whether a philosopher should die or whether they are able to eat, and call other functions to perform relevant actions, such as eating, sleeping, or thinking. The program uses semaphores to synchronize the actions of the philosophers.     | philo_bonus/srcs/routine.c      |
| launcher.c     | The provided code snippet is a function that launches multiple philosopher threads as child processes using fork(). It does so by iterating through the number of philosophers specified in the global struct, forking a child process for each philosopher and starting their routine. The parent process then waits for all child processes to finish executing before returning a value indicating success or failure. The function also uses semaphores to control access to shared resources.           | philo_bonus/srcs/launcher.c     |

</details>

<details closed><summary>Stdlib</summary>

| File      | Summary                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    | Module                               |
|:----------|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:-------------------------------------|
| ft_atol.c | The code provides a function ft_atol() that converts a string argument to a long integer value. It checks for numeric digit characters and allows for a leading sign (+ or-). The function also includes checks to prevent integer overflow and returns a success or failure flag as well as the resulting integer value. The code is included as a part of a larger program for a philosophy problem.                                                                                                                     | philo/minilib/stdlib/ft_atol.c       |
| ft_atoi.c | The provided code snippet contains a function called'__atoi' that converts a string of characters to an integer. The function skips any leading white space characters, determines the sign of the value, and repeatedly multiplies the current value by ten and adds the value of the next character until a non-digit character is encountered. The function also includes two helper functions,'__isdigit' and'__isisspace', which check whether a given character is a digit or a white space character, respectively. | philo/minilib/stdlib/ft_atoi.c       |
| ft_itoa.c | The provided code snippet includes an implementation of the C function __itoa, which takes an integer as input and returns a corresponding string representation. It does so by converting the integer into a string of characters through recursive division, with special considerations for negative numbers and zero. The function is dependent on the "libft.h" library.                                                                                                                                              | philo/minilib/stdlib/ft_itoa.c       |
| ft_atol.c | The provided code snippet is a function implementation of a custom alternative to the C standard library function atol(). It converts a string representation of a long integer to an integer and checks for overflow conditions. The function returns 1 if the conversion is successful and 0 otherwise. The code also includes helper functions that check if a string is entirely composed of digits, if a character is a digit, and if the conversion result exceeds the maximum or minimum integer values.            | philo_bonus/minilib/stdlib/ft_atol.c |
| ft_atoi.c | This code snippet contains a function, __atoi, that converts a string into an integer. It handles whitespace, positive and negative signs, and numbers consisting of one or more digits. The function is static and is used internally within another file, philosophers_bonus.h.                                                                                                                                                                                                                                          | philo_bonus/minilib/stdlib/ft_atoi.c |
| ft_itoa.c | The provided code snippet is a C function __itoa which converts an integer input into a char string output. It determines the size of the string required for holding the integer as a string, handles negative numbers, allocates memory for the string, and recursively converts integer to characters, then returns the resulting string. The code extends the functionality of itoa from C standard library which is not used anymore due to its undefined behavior.                                                   | philo_bonus/minilib/stdlib/ft_itoa.c |

</details>

<details closed><summary>String</summary>

| File        | Summary                                                                                                                                                                                                                                                                                                                                     | Module                                 |
|:------------|:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:---------------------------------------|
| ft_strlen.c | The code snippet defines a function named `__strlen` that takes in a string as input and returns its length as an output. The function iterates through the string character by character until it reaches the null terminator and counts the number of characters it encounters. The function is used in the `philosophers.h` header file. | philo/minilib/string/ft_strlen.c       |
| ft_strlen.c | The code snippet defines a function called "__strlen" that takes a string as input and returns its length. It does this by iterating over the characters in the string until it reaches the null character, counting each character along the way. It is included in a file named "philosophers_bonus.h".                                   | philo_bonus/minilib/string/ft_strlen.c |

</details>

---

## 🚀 Getting Started

### ✅ Prerequisites

Before you begin, ensure that you have the following prerequisites installed:
> - [📌  PREREQUISITE-1]
> - [📌  PREREQUISITE-2]
> - ...

### 🖥 Installation

1. Clone the 42-Philosophers repository:
```sh
git clone https://github.com/jremy42/42-Philosophers
```

2. Change to the project directory:
```sh
cd 42-Philosophers
```

3. Install the dependencies:
```sh
gcc -o myapp main.c
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
