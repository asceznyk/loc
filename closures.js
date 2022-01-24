/*
Example to demonstrate an important use of closures: to maintain a private reference to a variable in the outer scope.
*/

function secretPassword() {
  var password = 'xh38sk';
  return {
    guessPassword: function(guess) {
      if (guess === password) {
        return true;
      } else {
        return false;
      }
    }
  }
}

var passwordGame = secretPassword();
console.log(passwordGame.guessPassword('heyisthisit?'))
console.log(passwordGame.guessPassword('xh38sk'))

/*
This is a very powerful technique — it gives the closure function guessPassword exclusive access to the password variable, while making it impossible to access the password from the outside.
*/
