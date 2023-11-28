// O(n)
function sum(n) {
    var sum = 0;
    for (var i = 0; i < n.length; i++) {
        sum += 1;
    }
    return sum;
}
console.log("O(n): ".concat(sum('ABC')));
// O(n²)
function sum_two(n) {
    var sum = 0;
    for (var i = 0; i < n.length; i++) {
        for (var j = 0; j < n.length; j++) {
            sum += 1;
        }
    }
    return sum;
}
console.log("O(n\u00B2): ".concat(sum_two('ABC')));
// O(n^3)
function sum_three(n) {
    var sum = 0;
    for (var i = 0; i < n.length; i++) {
        for (var j = 0; j < n.length; j++) {
            for (var k = 0; k < n.length; k++) {
                sum += 1;
            }
        }
    }
    return sum;
}
console.log("O(n\u00B3): ".concat(sum_three('ABC')));
