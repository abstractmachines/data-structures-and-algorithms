// Reverse an array. Choice: for loop.

// Sample input: "pandas" Sample output "sadnap"

function reverseString(x){
var y = "";

for(var i = x.length-1;i>=0;--i){
 y += x[i];												// JS concatenation.
}
return y;
}

// in console: or main()

> var result = reverseString("pandas");

// in console:

> result;

// EXPECTED OUTPUT: "sadnap"
