let mail = "marinjurlina@nesto.nest.com";
let regex = /^[\w_]+@[a-z]+\.[a-z]{2,3}$/;

if (mail.match(regex))
{
    console.log("Email je uredu");
}
else
{
    console.log("EMail nije uredu");
}