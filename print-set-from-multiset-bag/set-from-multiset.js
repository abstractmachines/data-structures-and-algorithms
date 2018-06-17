/* print unique items only (set) of a multiset/bag

Sample input: 1,2,3,1,1,3,4,7
Sample output: 2 4 7
*/

function reverseSet(set, multiSet){

  for(var i=0;i<multiSet.length;++i){

    var wasRepeated = false;

    for(var j=0;j<multiSet.length;++j){

      if(i !== j){ // indices

        if(multiSet[i] === multiSet[j]){ // content

          wasRepeated = true;
        }
      }
    }
  }

  if(wasRepeated === false){

    set.push(multiSet[i]);
  }

  console.log(set);
}


var multiSet = [1,2,3,1,1,3,4,7];

var set = [];

var x = reverseSet(set, multiSet);


// OUTPUT: From console

// ["2", "4", "7"]
