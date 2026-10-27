# UTMS: University Management System

A command-line university system in C++ for the Advanced Programming course at the University of Tehran, Spring 2024.

Students, professors and an administrator log in and send requests in a simple `GET` / `POST` / `PUT` / `DELETE` format. The system supports:

- logging in and out, and connecting to other users
- posting on a personal page
- course offerings created by the administrator, with capacity, time slot, exam date and class number
- students enrolling in and dropping courses, with checks for clashing class times or exam dates and for the student's semester and major
- notifications to connected users and course members
- profile photos, and a channel for each course
- teaching-assistant application forms that professors open and students apply to

Each request returns `OK`, `Not Found`, `Bad Request`, `Permission Denied` or `Empty`. Majors, students, courses and professors are loaded from the CSV files in `csv/` at startup.

## Building and running

Requires g++ with C++20 support.

```sh
make
./utms.out csv/majors.csv csv/students.csv csv/courses.csv csv/professors.csv < input.txt
```

`input.txt` is a sample list of requests.

The `server`, `utils`, `static`, `template` and `examples` folders contain the APHTTP library provided by the course and its example files. The command-line program in `src` does not use them.
