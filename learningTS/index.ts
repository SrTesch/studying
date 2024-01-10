// understanding how types works on typescript

//You can have an implicit or an explicit declaration

let number = 23 //IMPLICIT DECLARATION

//number = "23"; this will be an error

let number2 : number; //EXPLICIT DECLARATION

number2 = 45;

// You can asign the any type...

let goodLucky : any = 23; 

goodLucky = "I'm beautiful";


//you can create your own type if you want

type Style = string;

let font : Style;

//this can be super redundant... but let's say our style can only be 'bold', 'italic' or a number...

type Style2 = 'bold' | 'italic' | number;

let anotherExample : Style2 = 12
anotherExample = "bold";
//anotherExample = "eusoulindo"; this will be an error.

//Now We can talk about objects..

//Let's say that you have 2 differents objects

const person1: Person = {
    first: "Jeff",
    last: "Bezos"
}
console.log("person1:\n",person1)


const person2: Person2 = {
    first: "Bill",
    last: "Gates",
    age: 62
}

//creating objects or instance classes that don't have the correct shape is an easy way to create bugs in your program.
//To solve this problem, you can enforce the shape of an object with an interface:

//this allow you to make the things  in person 1 ok
interface Person {
    first: string;
    last: string;
}

interface Person2 {
    first: string;
    last: string;
    [key:string]: any; //this allow you to make the third property in person2 ok.
}

//Now we'll talk about functions types... can be to more complex bc you have types for arguments and also the return value

function pow(x: number, y: number) : string{ //with this syntax you have to return a string
    return Math.pow(x,y).toString();
}

console.log(pow(5,10));

//You can return void if you dont wanna return nothing

function pow2(x: number, y: number): void{
    console.log(Math.pow(x,y));
}

//Strong types on arrays

const arr: number[] = [] //arr now is declared explicit that is an array of numbers!

arr.push(1)
//arr.push("23"); this will be an error
//arr.push(false); and this too...

//You can create a type to use in your array... like:
type MyType = [number?, string?, boolean?]; //the "?" allows you to create an empty array an put these types in every or nowhere

const arr2 : MyType = []
arr2.push(1);
arr2.push("23");
arr2.push(false);


//Generics

//*Creating a class that can receive any types in your constructor:

class Observable<T>{ //T represents any type that you want to put in "value"
    constructor(public value : T){}
}

let x : Observable<number>;

let y:Observable<Person>;

let z = new Observable(23);