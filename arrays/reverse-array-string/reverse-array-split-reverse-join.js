
/* TESTING:
 --> reverse() is a mutator function. Mutates in place.
 So we will deal with the console by using one command at a time.
 */

 // input: pandas. output: sadnap.

> var animalz = "pandas";
// undefined

> animalz
// "pandas"

// split() function splits into an array of characters.
> animalz = animalz.split("");
// ["p", "a", "n", "d", "a", "s"]

// reverse() is an in-place mutation. No expression required.
> animalz.reverse();
//["s", "a", "d", "n", "a", "p"]

> var sleep = animalz.join("");
// undefined

> sleep
// "sadnap"
