function push() {
    var clients = document.getElementById("ListOfClients").innerHTML.split(",");
    clients.push("Timothy");
    document.getElementById("Push").innerHTML = clients;
    return;
}

function pop() {
    var clients = document.getElementById("Push").innerHTML.split(",");
    var popped = clients.pop();
    document.getElementById("Pop").innerHTML = clients;
    document.getElementById("Pop1").innerHTML = popped;
    return;
}

function shift() {
    var clients = document.getElementById("Pop").innerHTML.split(",");
    var firstElement = clients.shift();
    document.getElementById("Shift").innerHTML = clients;
    document.getElementById("Shift1").innerHTML = firstElement;
    return;
}

function unshift() {
    var clients = document.getElementById("Shift").innerHTML.split(",");
    var firstElement = document.getElementById("Shift1").innerHTML
    clients.unshift(firstElement);
    document.getElementById("Unshift").innerHTML = clients;
    document.getElementById("Unshift1").innerHTML = firstElement;
    document.getElementById("Unshift1").style.display = "none";
    return;
}

function sort() {
    var clients = document.getElementById("Unshift").innerHTML.split(",");
    var sortedClients = clients.sort();
    document.getElementById("Sort").innerHTML = sortedClients;
    var customSortedClients = clients.sort(function (a, b) {
        return a[0] < b[0];
    });
    document.getElementById("Sort1").innerHTML = customSortedClients;
    return;
}

function concat() {
    var clients = document.getElementById("Sort1").innerHTML.split(",");
    var lastNames = document.getElementById("Concat1").innerHTML.split(",");
    var fullNames = clients[0] + ",";
    fullNames += clients[1].concat(lastNames[2]) + ",";
    fullNames += clients[2].concat(lastNames[3]) + ",";
    fullNames += clients[3].concat(lastNames[0]) + ",";
    fullNames += clients[4].concat(lastNames[1]);
    document.getElementById("Concat").innerHTML = clients;
    document.getElementById("Concat2").innerHTML = fullNames;
    return;
}

function forEach() {
    var clients = document.getElementById("Concat2").innerHTML.split(",");
    var modified = [];
    clients.forEach(function (element) {
        for (var i = 1; i < element.length; i++) {
            if (element[i].match(/^[A-Z]/)) {
                modified.push(element.replace(element[i - 1], element[i - 1] + " "));
                break;
            }
            else if (i + 1 == element.length) {
                modified.push(element);
            }
        }
    })
    document.getElementById("ForEach").innerHTML = clients;
    document.getElementById("ForEach1").innerHTML = modified;
    return;
}
/*
 * This function would be better with Php input capabilities.
 */
function includes() {
    var clients = document.getElementById("ForEach1").innerHTML.split(",");
    var search = document.getElementById("Includes").innerHTML;
    document.getElementById("Includes1").innerHTML = clients.includes(search);
    return;
}

function every() {
    var clients = document.getElementById("ForEach1").innerHTML.split(",");
    var sentinel = clients.every(function hasLast(client) {
        var flag;
        flag = client.indexOf(' ');
        if (flag > 0) {
            document.getElementById("Every1").style.display = "none";
            return true;
        }
        else {
            document.getElementById("Every1").innerHTML = client + " doesn't!";
            return false;
        }
    })
    document.getElementById("Every").innerHTML = sentinel;
    return;
}

function some() {
    var clients = document.getElementById("ForEach1").innerHTML.split(",");
    var themsWith = [];
    var sentinel = clients.some(function hasLetter(client) {
        var flag = false;
        flag = (client.indexOf('o') || client.indexOf('O'));
        if (flag > 0) {
            themsWith.push(client);
            flag = false;
        }
        if (client == clients[clients.length - 1] && themsWith[0] != null) {
            return true;
        }
    })
    document.getElementById("Some1").innerHTML = themsWith;
    document.getElementById("Some").innerHTML = sentinel;
    return;
}

function filter() {
    var clients = document.getElementById("ForEach1").innerHTML.split(",");
    var fil = clients.filter(function hasDup(client) {
        for (var i = 0; i < (client.length - 1); i++) {
            if (client[i].toLocaleLowerCase() == client[i + 1].toLocaleLowerCase()) {
                return true;
            }
        }
    });
    document.getElementById("Filter").innerHTML = fil;
    return;
}

function map() {
    var clients = document.getElementById("ForEach1").innerHTML.split(",");
    var len = clients.map(function nameLength(client) {
        return client.length.toString();
    })
    document.getElementById("Map").innerHTML = "";
    for (var i = 0; i < clients.length; i++) {
        document.getElementById("Map").innerHTML += clients[i] + " (Name Length: " + len[i] + ")<br>";
    }
    document.getElementById("Map1").innerHTML = len;
    return;
}

function reduce() {
    var len = document.getElementById("Map1").innerHTML.split(",");
    var intLen = [];
    for (var i = 0; i < len.length; i++) {
        intLen[i] = parseInt(len[i]);
    }
    var reducer = (accumulator, currentValue) => accumulator + currentValue;
    var totalLen = intLen.reduce(reducer);
    document.getElementById("Reduce").innerHTML = totalLen;
    return;
}

function splice() {
    var clients = document.getElementById("Map").innerHTML
    return;
}