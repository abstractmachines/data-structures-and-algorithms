// Reverse an array using JS .map() API. @ console >

> var cray = "crazy";
//undefined

> var craytoo = cray.split("");
//undefined

> craytoo
// ["c", "r", "a", "z", "y"]

// .map() applies invoked function to each element, returns new array w/ results.
> Array.prototype.map.call(craytoo,function(x){ return x; }).reverse().join("");

// "yzarc"
