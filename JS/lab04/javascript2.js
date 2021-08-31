let string1 = 'cascading style sheet';
let i = 0;

ps = string1.charAt(0);
ds = string1.charAt(10);
ts = string1.charAt(16);

ps = ps.toUpperCase();
ds = ds.toUpperCase();
ts = ts.toUpperCase();

let rezultat = string1.concat("(",ps,ds,ts,")");

console.log(rezultat);