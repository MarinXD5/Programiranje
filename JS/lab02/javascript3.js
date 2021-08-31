var a = +prompt("Unesite broj a");
var b = +prompt("Unesite broj b");
var operacija = prompt("Unesite zeljenu operaciju: (+,-,/,*)");
var rezultat;

function main(callback, a,b)
{
    console.log(callback(a,b));
}

if (operacija == "+")
{
    main(function(a,b){return a+b;},a,b);
}
else if (operacija == "-")
{
    main(function(a,b){return a-b;},a,b);
}

else if (operacija == "*")
{
    main(function(a,b){return a*b;},a,b);
}

else if (operacija == "/")
{
    main(function(a,b){if (b==0)return -1; else return a/b}, a,b);
}
