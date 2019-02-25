'use strict';
const inquirer = require('inquirer');

class Animal {
  constructor(name, color, age, noise) {
    this.name = name;
    this.color = color;
    this.age = age;
    this.noise = noise;
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
    console.log('Purr');
  }
}

var defaults = {
  catName: {
    value: false,
    ask: true
  },
  isJag: {
    value: false,
    ask: true
  },
  catSpeed: {
    value: false,
    ask: true
  },
}



//new
function main() {
  var tomcat = new Cat(null, 'black', null, 'Meow!');
  console.log(`defaults: `);
  console.log(defaults);


  inquirer.prompt(getQuestions(), answers => {
    console.log(answers);
    console.log(JSON.stringify(answers, null, '  '));
  })
}

function getQuestions() {
  var questions = [{
      type: 'input',
      name: 'catName',
      message: `What is the name of the cat?`,
      default: () => {
        if (defaults.catName.ask == true) {
          return ;
        }
        return 'Fluffy';
      },
      validate: (answer) => {
        return answer !== null && answer !== '';
      },
      when: (answers) => {
        if (settings.catName.ask) {
          return true;
        } else if (settings.catName.ask === false) {
          answers.catName = defaults.catName;
          return false;
        }
      }
    },
    {
      type: 'confirm',
      name: 'isJag',
      message: (answers) => {
        return `is ${answers.catName} an actual jaguar?`
      },
      default: () => {
        if (defaults.isJag) {
          return true
        }
        return false
      },
      when: (answers) => {
        if (settings.isJag.ask && settings.catName.ask) {
          return true;
        } else if (settings.isJag.ask === false) {
          answers.isJag = defaults.isJag;
          return false;
        } else if (answers.catName === 'Jaguar') {
          return true;
        } else return false;
      }
    },
    {
      type: 'input',
      name: 'catSpeed',
      message: (answers) => {
        return `How fast is ${answers.catName}?`
      },
      default: (answers) => {
        if (answers.isJag === true) {
          return 50;
        } else return 5;
      },
      validate: (answer) => {
        return parseInt(answer) > 0;
      },
      when: (answers) => {
        return answers.catName !== false;
      }
    }
  ]
  return questions;
}


main();