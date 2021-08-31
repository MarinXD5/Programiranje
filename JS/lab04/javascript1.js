let niz = [10,20,30,40,50,60,70,80,90,100];
let x = Math.round(Math.random()*11);

console.log(x);
console.log(niz);

let rbrojevi = niz.map(function(a) {return a*x;});
console.log(rbrojevi);

let filtriraniBrojevi = rbrojevi.filter(function(a){
    if (a > 19 && a < 201)
    {
        return a;
    }
})

console.log(filtriraniBrojevi);

let zbroj = filtriraniBrojevi.reduce(function(x,y){
    return x+y;
});

let popis = `<ul>
    ${filtriraniBrojevi.map(broj => `<li>${broj}</li>`).join("")}
</ul>`;
document.write(popis);

console.log("Zbroj je: ", zbroj);