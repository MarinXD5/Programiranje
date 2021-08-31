let navLinks = document.getElementById("navLinks");
 
            function showMenu(){
                navLinks.style.right = "0";
            }
 
            function hideMenu(){
                navLinks.style.right = "-200px";
            }

            function check(){
                let odgovor1=0, odgovor2=0, odgovor3=0;
                let p1=document.quiz.pitanje1.value;
                let p2=document.quiz.pitanje2.value;
                let p3=document.quiz.pitanje3.value;

                if(p1=="Garsonijera"){
                    odgovor1 = "Violina";
                }
                else if (p1=="Stan male kvadrature"){
                    odgovor1 = "Gitara";
                }
                else if (p1=="Stan srednje kvadrature"){
                    odgovor1 = "Saksofon";
                }
                else if (p1=="Stan velike kvadrature"){
                    odgovor1 = "Bubnjevi";
                }
                else if (p1=="Vila"){
                    odgovor1 = "Klavir";
                }

                if(p2=="Koncertant"){
                    odgovor2 = "Klavir i/ili Violina";
                }
                else if (p2=="Zabavljač"){
                    odgovor2 = "Gitara";
                }
                else if (p2=="Instruktor"){
                    odgovor2 = "Klavir";
                }
                else if (p2=="SOLO"){
                    odgovor2 = "Bubnjevi i/ili Saksofon";
                }

                if(p3=="manje od $20000"){
                    odgovor3 = "kupite: električni rabljeni instrument.";
                }
                else if(p3=="$20000-$40000"){
                    odgovor3 = "kupite: novi električni instrument.";
                }
                else if(p3=="$40000-$60000"){
                    odgovor3 = "kupite: YAMAHA instrument.";
                }
                else if(p3=="$60000-$80000"){
                    odgovor3 = "kupite: K. KAWAII pianino, Strunall violinu, HENRI Selmer saksofon, Ludwig Keystone X Gold bubnjeve, ili Fender PM-3 gitaru.";
                }
                else if(p3=="$80000-$100000"){
                    odgovor3 = "kupite: Petroff klavir, Stradivarievu violinu, Borgani Orteo Saksofon, Rolandove bubnjeve, ili Gibsonovu gitaru.";
                }
                else if(p3=="više od $100000"){
                    odgovor3 = "kupite: Steinways & Sons koncertni klavir, Stradivarievu violinu, Selmer MARK VI, DW Timeless Timber Romanian River bubnjeve, ili Ibanez gitaru.";
                }
                document.write("Ovisno o kvadraturi stana kupite: ", odgovor1, ", ovisno o karijeri: ", odgovor2, ", te vam, ovisno o godišnjem prihodu preporucujemo da ", odgovor3);
            }
 