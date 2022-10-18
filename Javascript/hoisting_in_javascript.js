//Hoisting is the default behaviour of javascript where all the variable and function declarations are moved on top.

//Example 1
hoistedVariable = 3;
console.log(hoistedVariable); // outputs 3 even when the variable is declared after it is initialized	
var hoistedVariable;

//Example 2

hoistedFunction();  // Outputs " Hello world! " even when the function is declared after calling

function hoistedFunction(){ 
  console.log(" Hello world! ");
} 

//Example 3

// Hoisting takes place in the local scope as well
function justFunc(){
    x = 33;
    console.log(x);
    var x;
  } 
justFunc(); // Outputs 33

// NOTE : Variable initializations are not hoisted, only variable declarations are hoisted
var x;
console.log(x); // Outputs "undefined" since the initialization of "x" is not hoisted
x = 23;
