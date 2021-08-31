var a = +prompt("Unesite a");
var b = +prompt("Unesite b");

function zbrojIumnozak(a,b)
{
    var zbroj = a + b;
    var umnozak = a*b;

    return [zbroj, umnozak];
}

var zadatak = zbrojIumnozak(a,b);

var zbrojZadatak = zadatak[0];
var umnozakZadatak = zadatak[1];

console.log(zbrojZadatak);
console.log(umnozakZadatak);