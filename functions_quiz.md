**Which of the following about a function prototype is NOT true?**

It makes sure that the parameters are named accordingly in the function declaration.

> This is indeed NOT true! The compiler is concerned with 3 things when it comes to function prototypes: 1) The function name 2) The return type 3) The parameter type(s). The names of the parameter are not necessary.

**This one’s a bit tricky! Remember the getRandomNumber(int a) function you created earlier in the lesson? Instead of returning a random number from 1 to a, try adding a second parameter b to the function so that it now returns a random number between a and b:**

```c
int getRandomNumber(int a, int b) {
  int randomNumber = rand() % (b - a + 1) + a;
  return randomNumber;
}
```

**Complete the abs() function by providing the correct return type and using the correct logic inside the body.**

```c
int abs(int n) {
  if (n < 0) {
    return -n;
  }
  else return n;
}
```

**Which of the following is NOT true about functions?**

A function cannot take a different number of arguments each time it is called.

> Indeed, this is not always true! Some functions are quite flexible with the number of arguments they can take. (Remember `printf()`?)

**What is the output of the following code?**

```c
#include<stdio.h>

void f(int *p) {
  int b = 2;
  p = &b;
  printf("%d ", *p);
}

int main() {
  int a = 1;
  int *p = &a;
  f(p);
  printf("%d ", *p);
}
```
Output:

```bash
2 1
```

> The trick lies in knowing that a pointer being passed to a function is still being passed by value, and therefore the copy of the pointer inside the function now points to a different variable at a different memory address than that of the original pointer in the main function.

**Which of the following is true regarding an argument passed to a function as a pointer?**

Passing the argument to a function as a pointer can change the value it points to both inside and outside the function.

> If the value it points to changes inside the function, this means the change is recorded wherever the variable can be accessed (including outside the function) because the change is made directly at the memory address of the variable and not by making a copy of the variable.

**Which of the following is true about passing an argument to a function by value?**

Passing the argument to a function by value can change the value of the parameter variable but not the original variable’s value.

> As covered earlier in the lesson, when a function has received an argument by value, the function makes a copy of the argument’s value and stores it in the parameter variable. We can safely alter the variable value inside the function while maintaining the original value outside.

**Which of the following is a function in C?**

```c
time()
```

> As introduced earlier, when passed the argument NULL, the `time()` function will return the number of seconds passed since the date, January 1, 1970.
