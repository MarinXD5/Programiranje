let rezultat = (nazivKolegija) =>{
    return (ostvareniBrojBodova) => {
        return (ukupniBrojBodova) => {
            console.log("Iz kolegija " + (nazivKolegija) + " ostvarili ste " + (ostvareniBrojBodova/ukupniBrojBodova * 100).toFixed(2) + "%");
        }
    }
}

rezultat("MUP")(25)(35);