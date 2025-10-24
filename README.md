# AP HTTP - C++ Web Server

This project is a simple, server-side web application framework written in C++ for an Advanced Programming course. It is designed to handle HTTP requests, serve static content, and render dynamic templates.

The server appears to manage data for a university, including students, courses, professors, and majors, likely loaded from the `.csv` files.

## Features

* **HTTP Server:** Core server logic to handle `GET` and `POST` requests.
* **Static File Serving:** Serves static assets (e.g., HTML, CSS) from the `/static` directory.
* **Dynamic Templating:** Renders dynamic web pages using templates from the `/template` directory.
* **Data Handling:** Parses and manages data from `.csv` files (students, courses, etc.).
* **Modular Structure:** Organized with separate directories for server logic, utilities, and assets.

## Technologies Used

* **C++** (for all backend logic)
* **HTML** (for templates and static pages)
* **Makefile** (for build automation)

## Build and Run

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/imSaDy/AP-Project6.git](https://github.com/imSaDy/AP-Project6.git)
    cd AP-Project6
    ```

2.  **Compile the project:**
    Run `make` to compile the server executable.
    ```bash
    make
    ```

3.  **Run the server:**
    *\[TODO: Add the command to run the executable. What is the executable's name?]*
    ```bash
    ./[your_server_executable_name]
    ```

4.  **Access the application:**
    Once running, the application can be accessed at `http://localhost:[PORT]` (e.g., `http://localhost:8080`).
