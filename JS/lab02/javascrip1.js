var a = prompt("Unesite a");
var b = prompt("Unesite b");
var c = prompt("Unesite c");
var d = prompt("Unesite d");
var e = prompt("Unesite e");
var f = prompt("Unesite f");
var g = prompt("Unesite g");

function zadatak()
{
    for (var i = 0; i<arguments.length; i++)
    {
        console.log(arguments[i]);
    }
}

zadatak(a);
zadatak(b,c);
zadatak(d,e,f,g);