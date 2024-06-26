//Constants from Codecademy library
const Node = require('./Node.js');
const makeLinkedList = require('./makeLinkedList.js');

// Solution for swapping nodes in a singly-linked list
function swapNodes(list, data1, data2) {  
  let prevNode1 = null;
  let prevNode2 = null;
  let node1 = list;
  let node2 = list;

  // Function throws error if any null values were passed
  if(list === null || data1 === null || data2 === null){
    throw new Error("Swapping is not possible - Cannot handle null arguments.");
  }

  // Function will return the list if the data swapped is the same
  if(data1 === data2){
    console.log("The data you wanted swapped are the same.");
    return list;
  }
  
  // Locate data1 in the list
  while(node1 !== null){
    if(node1.data === data1){
      break;
    }
    prevNode1 = node1;
    node1 = node1.next;
  }

  // Return if we couldn't find data1
  if(node1 === null){
    console.log("Cannot swap data: " + data1 + " not found.");
    return list;
  }

  // Find data2 in the list
  while(node2 !== null){
    if(node2.data === data2){
      break;
    }
    prevNode2 = node2;
    node2 = node2.next;
  }

  // Return if we couldn't find data2.
  if(node2 === null){
    console.log("Cannot swap data: " + data2 + " not found.");
    return list;
  }

  // Swap parent nodes with the new respective node.

  // If the first node in list is null, set it to the second data point
  if(prevNode1 === null){
    list = node2;
  }
  else{
    // Node1's parent node will point to Node2 now
    prevNode1.next = node2;
  }

  // If the first node in list is null, set it to the second data point
  if(prevNode2 === null){
    list = node1;
  }
  else{
    //Node2's parent node will point to Node1
    prevNode2.next = node1;
  }

  // Switch Node1 and Node2's children, so the list order will be otherwise maintained.
  temp = node1.next;
  node2.next = temp;
  node1.next = node2.next;
  
  return list;
}

// Function for printing the list for easier debugging
function printList(list){
  iterList = list;
  while(iterList != null){
    console.log(iterList.data);
    iterList = iterList.next;
  }
  return;
}

let exampleList = makeLinkedList([1, 2, 3, 4, 5, 6]);
let retList = swapNodes(exampleList, 1, 3);
//console.log(retList);
printList(retList);
