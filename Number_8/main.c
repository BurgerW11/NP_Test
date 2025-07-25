/* 
    8. Create two threads, thread A is used to read files and send data to thread B, thread B receives thread A's data and writes to files.

    a. The program has two parameters, the first parameter is the path to read the file, and the second parameter is the path to write the file.

    b. Communication between threads supports pipes and sockets, and the default communication method can be selected when the program is initialized.

    c. Design the middle layer, and use the same function for communication initialization, sending data, receiving data, and deinitialization.

    d. The middle layer is compiled into a dynamic library, which can provide a communication interface for other programs.
 */