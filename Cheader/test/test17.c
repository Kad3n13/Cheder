#include "13.h"

int main() {
    void *file;

    // Print to console your puts equivelent
    ps("Hello, World!\n");

    // Open a file  for writing (mode 1 = write)
    file = o("hello.text", 1);
    if (!file) {
    ps("Error opening file\n");
    return 1;
    }

    // Write "Hello, World! to the file
    fps(file, "Hello, World!\n");

    // Close the file
    c(file);

    // inform user that the writing is done 
    ps("wrote 'Hello, World!' to hello.txt\n");

    return 0;    
    }

