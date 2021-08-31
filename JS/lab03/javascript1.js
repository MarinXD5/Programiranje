function parnost(x)
{
    if (x%2==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

function stvoriBrojac()
{
    let i = 0;

    return function(){
        return i++;
    }
}

let brojac1 = stvoriBrojac();
let brojac2 = stvoriBrojac();

var i = 0;
let x = 0;

while (i<15)
{
    x = Math.round(Math.random()*50+50);
    console.log(x);
    if (parnost(x))
    {
        brojac1();
    }
    else
    {
        brojac2();
    }
    i++;
}


console.log(brojac1());
console.log(brojac2());