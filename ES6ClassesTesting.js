class Point {
    constructor(x = 0, y = 0, z = 0) {
        this._x = x;
        this._y = y;
        this._z = z;
    };
    setPosition() {
        switch (arguments.length) {
            case 1:
                this._x = arguments[0]._x;
                this._y = arguments[0]._y;
                this._z = arguments[0]._z;
                break;
            case 3:
                this._x = arguments[0];
                this._y = arguments[1];
                this._z = arguments[2];
                break;
            default:
                console.error('Error: need a [point] or [x, y, z]');
                break;
        };
    };
    getPosition() {
        return `x: ${this._x}, y: ${this._y}, z: ${this._z}`;
    };
};

class Shape {
    constructor() {
        this._color = "black";
        this._point = new Point(0, 0, 0);
        if (this.constructor == Shape) {
            throw new Error("Abstract classes can't be instantiated.");
        };
    };
    changeColor(color) {
        this._color = color;
    };
};

class Rectangle extends Shape {
    constructor(width = 1, height = 1) {
        super();
        this._height = height;
        this._width = width;
    };
    grow(number = 1) {
        this._height = this._height + number;
        this._width = this._width + number;
    };
    shrink(number = 1) {
        this._height = this._height - number;
        this._width = this._width - number;
    };
    calcArea() {
        return this._height * this._width;
    };
};

class Circle extends Shape {
    constructor(radius = 1) {
        super();
        this._radius = radius;
    };
    grow(number = 1) {
        this._radius = this._radius + number;
    };
    shrink(number = 1) {
        this._radius = this._radius - number;
    };
    calcArea() {
        return this._radius * this._radius * Math.PI;
    };
}

function main() {
    let circle = new Circle(5);
    let square = new Rectangle(5, 5);

    //Circle Driver, also Point and the calcArea, grow method
    console.log(`Gotta start somewhere! ${circle._radius}`);
    circle.grow();
    console.log(`Gotta git big! ${circle._radius}`);
    console.log(`my area is now ${circle.calcArea()}!`);

    console.log(`In this place: ${circle._point.getPosition()}`);
    circle._point.setPosition(new Point(5, -5, 5));
    console.log(`In this other place: ${circle._point.getPosition()}`);
    circle._point.setPosition(1, 2, 3);
    console.log(`In this, yet another, place: ${circle._point.getPosition()}`);

    console.log('\n--- --- --- ---\n')

    //Square(Rectangle), shrink also Shape Driver
    console.log(`I am fickle, but my current favorite color is: ${square._color}`);
    square.changeColor("red");
    console.log(`Nevermind, now it's: ${square._color}`);

    console.log(`I'm a tiny little square, I only have ${square.calcArea()} area!`);
    square.grow(50);
    console.log(`Now I'm a big fat square, I have ${square.calcArea()} area!`);
    square.shrink(52);
    console.log(`Now I'm even smaller than before, ${square.calcArea()} area!`);
}

main();