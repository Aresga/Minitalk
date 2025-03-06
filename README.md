# Minitalk

Minitalk is a small data exchange program using UNIX signals. It allows for communication between a client and a server using signals like `SIGUSR1` and `SIGUSR2`.

## Features

- Send and receive messages using UNIX signals.
- Supports basic data transfer between client and server.

## Getting Started

### Prerequisites

- A UNIX-like operating system.
- GCC (GNU Compiler Collection) installed.

### Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/Aresga/minitalk.git
    cd minitalk
    ```

2. Compile the project:
    ```sh
    make
    ```

### Usage

1. Start the server:
    ```sh
    ./server
    ```

2. In a separate terminal, start the client and send a message:
    ```sh
    ./client <server_pid> "Your message"
    ```

### Files

- `server.c` - Server-side code for receiving messages.
- `client.c` - Client-side code for sending messages.
- `Makefile` - Build script for compiling the project.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or suggestions.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Inspired by the need for simple inter-process communication using UNIX signals.
