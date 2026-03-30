# Hash Tables

## Description
This project implements **hash tables** in C using **chaining** to handle collisions.  
You will learn how to create hash tables, store key/value pairs, and understand the underlying data structure.

## Data Structures
- **hash_node_t**: Node of the hash table
  - `key`: Unique string key
  - `value`: Value associated with the key
  - `next`: Pointer to the next node (for collisions)
- **hash_table_t**: Hash table
  - `size`: Size of the array
  - `array`: Array of pointers to `hash_node_t` lists

## Tasks
- **0. hash_table_create**: Create a new hash table
- More tasks to follow: adding key/value pairs, retrieving values, printing the table, deleting nodes, etc.

## Requirements
- C standard library allowed
- Betty coding style must be followed
- All functions declared in `hash_tables.h`
- Include guards in header files
- No global variables












