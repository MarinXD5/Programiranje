var broj = prompt();
var brojslovo;

switch(broj)
{
    case 0:
        brojslovo = "Jedan"
        break;
    case 1:
        brojslovo = "Dva";
        break;
    case 2:
        brojslovo = "Tri";
        break;
    case 3:
        brojslovo = "Cetiri";
        break;
    case 4:
        brojslovo = "Pet";
        break;
    default:
        brojslovo = "Nula";
}

console.log(brojslovo);