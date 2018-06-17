function reverseString(str) {
  if (str === "")
    return "";

  else

  return reverseString(str.substr(1)) + str.charAt(0);
}

// in console:
var result = reverseString("pandas");

// in console:
result;

// EXPECTED OUTPUT: "sadnap"
