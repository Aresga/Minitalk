# Minitalk

Minitalk is a project that demonstrates inter-process communication using Unix signals. In this project, a client sends messages to a server using only signals, and the server reconstructs and displays the messages.

---

## Table of Contents

- [Introduction](#introduction)
- [What Are Unix Signals?](#what-are-unix-signals)
- [Project Overview](#project-overview)
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [License](#license)
- [Author](#author)

---

## Introduction

Minitalk showcases how processes can communicate on Unix systems without using traditional IPC methods like sockets or pipes. Instead, it utilizes Unix signals to send data between processes. This project is both an educational exercise and a demonstration of low-level process communication.

---

## What Are Unix Signals?

Unix signals are a limited form of inter-process communication used to notify a process that a specific event has occurred. Some key points include:

- **Signals Identification:** Each signal is identified by a name (e.g., `SIGINT`, `SIGUSR1`, `SIGUSR2`) and a number.
- **Signal Handling:** Processes can define custom handlers to execute specific actions when a signal is received. This allows for asynchronous event handling.
- **Usage in Minitalk:** In this project, signals are used to send bits of data. The client sends signals (typically `SIGUSR1` and `SIGUSR2`) to represent binary data, and the server reconstructs the message from these signals.

For more detailed information on signals, you can check out the [man pages](https://man7.org/linux/man-pages/man7/signal.7.html) or other Unix programming resources.

---

## Project Overview

Minitalk is divided into two main components:

- **Server:** Waits for incoming signals, interprets them, and reconstructs the message sent by the client.
- **Client:** Takes user input, encodes it into signals, and sends it to the server.

The project is implemented in C and leverages the basics of Unix signal handling.

---

## Installation

1. **Clone the repository:**
   ```sh
   git clone https://github.com/Aresga/minitalk.git
   ```

2. **Navigate to the project directory:**
   ```sh
   cd minitalk
   ```

3. **Compile the project:**
   Depending on your setup, there may be separate Makefiles for the client and server. For example:
   ```sh
   make all
   ```
   This should build both the server and client executables.

---

## Usage

1. **Start the Server:**
   Run the server executable in one terminal:
   ```sh
   ./server
   ```
   The server will display its process ID (PID), which is needed by the client.

2. **Run the Client:**
   In another terminal, run the client executable with the server’s PID and the message you want to send:
   ```sh
   ./client [SERVER_PID] "Your message here"
   ```
   Replace `[SERVER_PID]` with the PID displayed by the server and `"Your message here"` with your actual message.

---

## Features

- **Signal-Based Communication:** Uses only Unix signals for data transmission.
- **Asynchronous Handling:** Demonstrates asynchronous event handling using custom signal handlers.
- **Educational:** Provides a clear example of how low-level IPC can be implemented in C.

---

## License

This project is open-source and available under the [MIT License](LICENSE).

---

## Author

Created by [Aresga](https://github.com/Aresga).

---

Feel free to contribute or open issues if you encounter any bugs or have suggestions for improvements!
