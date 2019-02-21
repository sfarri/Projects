'use strict';

class Animal {
  constructor(name, color, age) {
    this.name = name;
    this.color = color;
    this.age = age;
  }
  speak(noise) {
    console.log(noise);
  }
  
}

class Cat extends Animal {
  constructor(name, color) {
    super();
    this.name = name;
    this.color = color;
  }
  purr() {
    console.log('Purr')
  }
}

//new
var tomcat = new Cat('Tomcat', 'black');

console.log(tomcat);
tomcat.speak('Meow!');
tomcat.purr();