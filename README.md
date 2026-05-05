# Car Dealership Database (C + SQLite)

## Live Demo

Run instantly in GitHub Codespaces (no setup required):

Open the repo → Click **Code → Codespaces → Create Codespace** → Run:

```bash
cd build
./car_db
```

---

## What This Project Does

This is a small, static demonstration of using **SQLite with C** to:

* Create a relational database schema
* Insert sample records
* Query and display results in a CLI

The program initializes a local database (`car.db`), seeds it with fixed data, and prints query output.

The goal is not complexity, it’s a **clear, quickly-runnable example of embedded database usage in C**.

---

## Why It Exists

Most C/database projects require setup, dependencies, or manual configuration.

This project is designed so that:

* It runs with **zero manual setup**
* The database is **created automatically**
* The output is **deterministic and easy to verify**
* A reviewer can understand it in **under a minute**

It’s meant to be **quickly evaluatable**, not feature-heavy.

---

## How It Works

* On startup, the program:

  * Opens (or creates) a SQLite database file (`car.db`)
  * Creates a simple `Customer` table if it doesn’t exist
  * Inserts a small set of sample records
* A query is executed to retrieve all records
* Results are printed directly to the console

There is no user input, everything is static for consistency, ease and speed.

---

## Project Structure

```text
src/
  main.c          Core program (SQLite integration)
CMakeLists.txt    Build configuration
README.md         Project overview
```

---

## Running Locally (Optional)

```bash
mkdir build
cd build
cmake ..
cmake --build .
./car_db
```

---

## Notes

* No external database setup required
* Uses a **local SQLite file** created at runtime
* Data is **hardcoded for demonstration purposes**
* Focus is on **clarity, portability, and structure**
* Not intended as a full CRUD application

---

## Possible Extensions

* Add additional tables (Dealership, Salesperson, etc.)
* Re-introduce user input (CLI menu system)
* Load seed data from SQL files instead of hardcoding static data
* Add basic validation and error handling
* Expand queries (joins, filtering, aggregation)

---

## Summary

A minimal, runnable example of combining **C and SQLite** to demonstrate:

* Embedded database usage
* Schema creation
* Query execution
* Clean, portable project structure
