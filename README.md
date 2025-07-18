# Simple Shell

A minimalist UNIX command line interpreter implemented in C, designed to replicate basic shell functionality with support for built-in commands, external program execution, and interactive/non-interactive modes.

## 🚀 Features

- **Interactive Mode**: Provides a command prompt for real-time user interaction
- **Non-Interactive Mode**: Executes commands from scripts or piped input
- **Built-in Commands**: Implements essential shell built-ins like `exit`, `env`, `cd`, `setenv`, `unsetenv`
- **External Command Execution**: Runs system programs and utilities
- **Path Resolution**: Automatically searches for executables in PATH directories
- **Command Line Parsing**: Handles arguments and maintains proper tokenization
- **Error Handling**: Comprehensive error reporting and graceful failure management
- **Environment Variables**: Full support for environment variable management
- **Signal Handling**: Proper handling of keyboard interrupts (Ctrl+C)

## 📋 Requirements

- **Operating System**: Linux/Unix-based systems
- **Compiler**: GCC (GNU Compiler Collection)
- **Standard**: C89/C90 compliant
- **Dependencies**: Standard C library only

## 🛠️ Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/fatmasoly/simple_shell.git
   cd simple_shell
   ```

2. **Compile the shell**:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
   ```

3. **Run the shell**:
   ```bash
   ./hsh
   ```

## 💡 Usage

### Interactive Mode
```bash
$ ./hsh
($) ls -la
($) pwd
($) echo "Hello, World!"
($) exit
```

### Non-Interactive Mode
```bash
$ echo "ls -la" | ./hsh
$ ./hsh < script.sh
```

### Built-in Commands

| Command | Description | Usage |
|---------|-------------|-------|
| `exit` | Exit the shell | `exit` or `exit [status]` |
| `env` | Display environment variables | `env` |
| `cd` | Change directory | `cd [directory]` |
| `setenv` | Set environment variable | `setenv VARIABLE VALUE` |
| `unsetenv` | Remove environment variable | `unsetenv VARIABLE` |

### Example Commands
```bash
($) ls -l /tmp
($) cat /etc/passwd
($) ps aux
($) pwd
($) echo $PATH
($) which ls
($) env
($) cd /home/user
($) setenv MY_VAR hello
($) unsetenv MY_VAR
($) exit
```

## 🏗️ Architecture

### Core Components

- **main.c**: Entry point and main shell loop
- **shell.c**: Core shell functionality and command execution
- **builtins.c**: Implementation of built-in commands
- **parser.c**: Command line parsing and tokenization
- **path.c**: PATH resolution and executable location
- **env.c**: Environment variable management
- **utils.c**: Utility functions and helpers
- **shell.h**: Header file with function prototypes and structures

### Program Flow

1. **Initialization**: Set up signal handlers and environment
2. **Main Loop**: 
   - Display prompt (interactive mode)
   - Read user input
   - Parse and tokenize commands
   - Execute built-in or external commands
   - Handle errors and return codes
3. **Cleanup**: Free allocated memory and exit gracefully

## 🔧 Implementation Details

### Memory Management
- Dynamic memory allocation for command arguments
- Proper cleanup to prevent memory leaks
- Safe string handling with buffer overflow protection

### Error Handling
- Comprehensive error messages following POSIX standards
- Proper exit codes for different error conditions
- Graceful handling of invalid commands and arguments

### Process Management
- Fork/exec model for external command execution
- Parent process waits for child completion
- Proper signal handling for process control

## 🧪 Testing

### Manual Testing
```bash
# Test basic commands
./hsh -c "ls -la"
./hsh -c "pwd"
./hsh -c "echo 'Hello World'"

# Test built-ins
./hsh -c "env"
./hsh -c "cd /tmp && pwd"
./hsh -c "exit 0"

# Test error handling
./hsh -c "nonexistent_command"
./hsh -c "ls /nonexistent_directory"
```

### Comparison with Standard Shell
```bash
# Compare outputs
echo "ls -la" | sh
echo "ls -la" | ./hsh

# Verify exit codes
echo $?
```

## 📚 Learning Objectives

This project demonstrates understanding of:
- System calls (`fork`, `exec`, `wait`, `access`)
- Process creation and management
- File system navigation
- Environment variable handling
- Memory management in C
- String manipulation and parsing
- Error handling and debugging
- UNIX/Linux system programming concepts

## 🤝 Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👥 Authors

- **Fatma Soliman** - [@fatmasoly](https://github.com/fatmasoly)

## 🙏 Acknowledgments

- Holberton School for project inspiration and requirements
- The Unix/Linux community for shell design principles
- Contributors and reviewers who helped improve this implementation

## 📖 Additional Resources

- [GNU Bash Manual](https://www.gnu.org/software/bash/manual/)
- [POSIX Shell Command Language](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/sh.html)
- [Advanced Programming in the UNIX Environment](https://www.apuebook.com/)

---

*This shell implementation serves as an educational project to understand the fundamental concepts of command-line interfaces and system programming in Unix-like environments.*
