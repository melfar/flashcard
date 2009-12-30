create table cards (
	id              integer primary key,
	text1           text,
	text2           text,
	correct_answers integer default 0,
	wrong_answers   integer default 0,
	fail_rate       double  default 10.0
);

-- insert into cards(text1, text2) values("Capital of Norway",    "Oslo");
-- insert into cards(text1, text2) values("Capital of Thailand",  "Bangkok");
-- insert into cards(text1, text2) values("Capital of Tibet",     "Lhasa");
-- insert into cards(text1, text2) values("Capital of Italy",     "Rome");
-- insert into cards(text1, text2) values("Capital of Uruguay",   "Montevideo");
-- insert into cards(text1, text2) values("Capital of Australia", "Canberra");
-- insert into cards(text1, text2) values("Capital of Syria",     "Damascus");
-- insert into cards(text1, text2) values("Capital of Denmark",   "Copenhagen");
-- insert into cards(text1, text2) values("Capital of Peru",      "Lima");
-- insert into cards(text1, text2) values("Capital of Nicaragua", "Managua");


insert into cards(text1, text2) values("be", "olla");
insert into cards(text1, text2) values("and", "ja");
insert into cards(text1, text2) values("to", "vaille");
insert into cards(text1, text2) values("in", "sisään");
insert into cards(text1, text2) values("he", "hän");
insert into cards(text1, text2) values("have", "olla");
insert into cards(text1, text2) values("it", "se");
insert into cards(text1, text2) values("that", "tuo");
insert into cards(text1, text2) values("for", "varten");
insert into cards(text1, text2) values("they", "he");
insert into cards(text1, text2) values("I", "minä");
insert into cards(text1, text2) values("with", "kanssa");
insert into cards(text1, text2) values("not", "ei");
insert into cards(text1, text2) values("on", "päällä");
insert into cards(text1, text2) values("she", "nainen");
insert into cards(text1, text2) values("by", "vieressä");
insert into cards(text1, text2) values("this", "tämä");
insert into cards(text1, text2) values("we", "me");
insert into cards(text1, text2) values("you", "sinä");
insert into cards(text1, text2) values("do", "tehdä");
insert into cards(text1, text2) values("but", "mutta");
insert into cards(text1, text2) values("or", "tai");
insert into cards(text1, text2) values("which", "mikä");
insert into cards(text1, text2) values("all", "kaikki");
insert into cards(text1, text2) values("will", "tahtoa");
insert into cards(text1, text2) values("there", "tuolla");
insert into cards(text1, text2) values("say", "sanoa");
insert into cards(text1, text2) values("who", "kuka");
insert into cards(text1, text2) values("make", "tehdä");
insert into cards(text1, text2) values("when", "milloin");
insert into cards(text1, text2) values("more", "enemmän");
insert into cards(text1, text2) values("if", "jos");
insert into cards(text1, text2) values("no", "ei");
insert into cards(text1, text2) values("man", "mies");
insert into cards(text1, text2) values("out", "ulos");
insert into cards(text1, text2) values("other", "toinen");
insert into cards(text1, text2) values("so", "joten");
insert into cards(text1, text2) values("what", "mitä");
insert into cards(text1, text2) values("time", "alka");
insert into cards(text1, text2) values("up", "ylhäällä");
insert into cards(text1, text2) values("go", "mennä");
insert into cards(text1, text2) values("about", "kieppeillä");
insert into cards(text1, text2) values("than", "kuin");
insert into cards(text1, text2) values("into", "sisään");
insert into cards(text1, text2) values("could", "voisi");
insert into cards(text1, text2) values("state", "kunto");
insert into cards(text1, text2) values("only", "vain");
insert into cards(text1, text2) values("new", "uutinen");
insert into cards(text1, text2) values("year", "vuosi");
insert into cards(text1, text2) values("some", "joku");
insert into cards(text1, text2) values("take", "ottaa");
insert into cards(text1, text2) values("come", "tulla");
insert into cards(text1, text2) values("these", "nämä");
insert into cards(text1, text2) values("know", "tietää");
insert into cards(text1, text2) values("see", "ymmärtää");
insert into cards(text1, text2) values("use", "käyttö");
insert into cards(text1, text2) values("get", "saada");
insert into cards(text1, text2) values("like", "sellainen");
insert into cards(text1, text2) values("then", "silloin");
insert into cards(text1, text2) values("first", "ensiksi");
insert into cards(text1, text2) values("any", "kukaan");
insert into cards(text1, text2) values("work", "tehdä");
insert into cards(text1, text2) values("now", "nyt");
insert into cards(text1, text2) values("may", "voida");
insert into cards(text1, text2) values("such", "sellainen");
insert into cards(text1, text2) values("give", "maksaa");
insert into cards(text1, text2) values("over", "yllä");
insert into cards(text1, text2) values("think", "ajatella");
insert into cards(text1, text2) values("most", "enin");
insert into cards(text1, text2) values("even", "tasainen");
insert into cards(text1, text2) values("find", "löytää");
insert into cards(text1, text2) values("day", "päivä");
insert into cards(text1, text2) values("also", "myös");
insert into cards(text1, text2) values("after", "takana");
insert into cards(text1, text2) values("way", "suunta");
insert into cards(text1, text2) values("many", "moni");
insert into cards(text1, text2) values("must", "täytyy");
insert into cards(text1, text2) values("look", "katse");
insert into cards(text1, text2) values("before", "aikaisemmin");
insert into cards(text1, text2) values("great", "suuri");
insert into cards(text1, text2) values("back", "takaisin");
insert into cards(text1, text2) values("through", "läpi");
insert into cards(text1, text2) values("long", "pitkä");
insert into cards(text1, text2) values("where", "missä");
insert into cards(text1, text2) values("much", "paljon");
insert into cards(text1, text2) values("should", "pitäsi");
insert into cards(text1, text2) values("well", "hyvin");
insert into cards(text1, text2) values("people", "ihmiset");
insert into cards(text1, text2) values("down", "alas");
insert into cards(text1, text2) values("own", "omistaa");
insert into cards(text1, text2) values("just", "vain");
insert into cards(text1, text2) values("because", "koska");
insert into cards(text1, text2) values("good", "hyvä");
insert into cards(text1, text2) values("each", "kukin");
insert into cards(text1, text2) values("those", "nuo");
insert into cards(text1, text2) values("feel", "tuntea");
insert into cards(text1, text2) values("seem", "näyttää");
insert into cards(text1, text2) values("how", "miten");
insert into cards(text1, text2) values("high", "korkea");


create index cards_fail_rate_idx on cards(fail_rate);


create table info (
	cards_shown integer default 0
);

insert into info(cards_shown) values(0);

create table card_stats (
    not_shown      integer,
	unlearned      integer,
	medium_learned integer,
	well_learned   integer,
	updated_at     date default current_timestamp
);

