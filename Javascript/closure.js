//A closure is the combination of a function bundled together (enclosed) with references to its surrounding state (the lexical environment).


function greeting() {
    let message = 'Hi';

    function sayHi() {
        console.log(message);
    }

    return sayHi;
}
let hi = greeting();
hi(); // still can access the message variable


/*
Outside of the greeting() function, we assigned the hi variable the value returned by the greeting() function, which is a reference of the sayHi() function.
Then we executed the sayHi() function using the reference of that function: hi().
It means that when the greeting() function has completed executing, the message variable is no longer accessible.
In this case, we execute the hi() function that references the sayHi() function, the message variable still exists.
In other words, the sayHi() function is a closure.
*/