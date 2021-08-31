var i;
var zbroj = 0;

for (i = 0; i<180; i++)
{
    if (i%50==0 )
    {
        zbroj += i;
        console.log(i);
    }
}

console.log(zbroj);