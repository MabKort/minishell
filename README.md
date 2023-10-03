<div align='center'>

<h1>Minishell: As Beautiful as a Shell</h1>
<p>Welcome to the repository for the `Minishell` project. Experience the essence of shell programming and uncover the intricacies of processes, pipes, and file descriptors.</p>


</div>

## 📜 Introduction
The `Minishell` project revives the age-old art of shell programming. As developers, while modern GUIs simplify our tasks, it's crucial to understand the backbone of these systems - the shell. This project throws you into the deep end, challenging you to create a shell from scratch, enabling you to engage with foundational IT concepts.

## 🎯 Challenges and Learning Objectives

This endeavor into shell programming is not just about mimicking the bash. It's about understanding intricate details like:

- **Processes:** Diving deep into how processes are created, managed, and terminated.
- **File Descriptors:** Gaining insights into how file descriptors work, especially when it comes to input and output redirection.
- **Pipes:** Grappling with the challenge of setting up communication between processes using pipes.
- **Signal Handling:** Crafting responsive software by managing signals, ensuring graceful handling of interruptions like `ctrl-C`, `ctrl-D`, and `ctrl-\`.
- **Environment Variables:** Implementing and manipulating environment variables, key components for any shell.
  
While the above are key areas of focus, the project also touches upon foundational programming concepts and ensures rigorous adherence to C programming, algorithmic thinking, and more.

## 🚀 Compilation & Usage

Ensure you're on a system with a C compiler.

### Compilation
Compile the project with the provided Makefile.
```bash
make
```

### Execution
Execute the program.
```bash
./minishell
```

## 💡 Features

Your Minishell should provide:
- A prompt display waiting for user commands.
- Command execution based on the PATH variable or using relative/absolute paths.
- Built-in implementations for `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.
- Redirections (`<`, `>`, `<<`, `>>`) and pipes (`|`).
- Environment variable expansions, including `$?`.
- Proper signal handling for a responsive user experience.

## 🌌 Insight into the Shell

The shell is much more than just a command executor. It's the bridge between the user and the operating system. When developing `Minishell`, here are some insights:

- **Pipes and Redirections:** The shell's ability to redirect output to a file or take input from a file is thanks to file descriptors. Each process has a table of file descriptors, and by default, 0 is standard input, 1 is standard output, and 2 is standard error. Redirections manipulate these default assignments, allowing for powerful command chaining and data direction.
  
- **Environment Variables:** These are a set of dynamic-named values stored within the system. They can affect the processes' behavior, ensuring that each process can have its own environment. Manipulating these can change process behaviors, a fundamental aspect of shell programming.
  
- **Signal Management:** Signals are software interrupts that can provide robust and dynamic inter-process communication. Managing these signals ensures that processes can handle unexpected events gracefully.
  
Remember, while GUIs are beautiful, the shell is powerful. It's the heart of the system, and understanding it offers unparalleled control and automation capabilities.

## 👥 Contributors

<ul>
    <li>
      <img src="https://github.com/MabKort.png?size=50" width="50" height="50" alt="ContributorOne's avatar">
      <a href="https://github.com/MabKort">MabKort</a>
    </li>
    <li>
      <img src="https://github.com/jrainpre.png?size=50" width="50" height="50" alt="ContributorTwo's avatar">
      <a href="https://github.com/jrainpre">jrainpre</a>
    </li>
</ul>
