package FizzBuzz;
// This is a simple Java program.

// FileName : "HelloWorld.java".

class HelloWorld {
    // Your program begins with a call to main().
    // Prints "Hello, World" to the terminal window.
    public static void main(String args[]) {
        for (int i = 1; i < 20; i++) {
            if ((i % 5 == 0) && (i % 3 == 0)) {
                System.out.println("FizzBuzz");
            } else if ((i % 5 == 0)) {
                System.out.println("Buzz");
            } else if ((i % 3 == 0)) {
                System.out.println("Fizz");
            } else {
                System.out.println(i);
            }
        }
    }
}