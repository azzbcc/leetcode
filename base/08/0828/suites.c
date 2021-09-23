/**
 * suites.c
 * Copyright(c) 2020 beijing. All rights reserved.
 * Description:
 * Version    :
 * Created on : 2020/7/30 下午5:00
 * Modified   :
 *     Author : Clarence <xjh.azzbcc@gmail.com>
 */
#include <common.h>

#include "0828.c"

START_TEST(test_official_1) {
    char *str  = "ABC";
    int target = 10, ans = uniqueLetterString(str);

    ck_assert_msg(target == ans, "error, except %d but got %d on uniqueLetterString(str).", target, ans);
}

START_TEST(test_official_2) {
    char *str  = "ABA";
    int target = 8, ans = uniqueLetterString(str);

    ck_assert_msg(target == ans, "error, except %d but got %d on uniqueLetterString(str).", target, ans);
}

START_TEST(test_official_3) {
    char *str  = "LEETCODE";
    int target = 92, ans = uniqueLetterString(str);

    ck_assert_msg(target == ans, "error, except %d but got %d on uniqueLetterString(str).", target, ans);
}

START_TEST(test_tle_1) {
    char *str  = "KYKUUUAEGDIPWWGQNQABVIAPSNPZPWBQSQBLOSNXWUOGENFXXONJQVIPVINNRDGUXGEHERGMWZLLQFIJGJEDGKNSTRDCAQXLIDKGAPEQVZYQCGNVTIWQNMSFZLSMJWHJBTFUQNSCQNCFXBMVTDOTXQKAREQMRBOFVDXHKKZLPCGJVECXLMHGUAJIOIKIXTCUEGFELPELOUTDYEXTVVZPLSKWXUZNWQAEACXFSKYAVPCDCFYULBSOIJOXKFQDPHKMWYTLKCZFVRDTVVSHDJBIFBNRSDHDNXNVQOIIEZUZNUNOMXKCFJADSRPNQRDEWVKLJPXNKQJYNULQVIUDAFGUKLJGUNUZPQQTVTCWNYXMEBQJZJMYRZWJMXHGTAXKNZHAEGHBSAPIJFYCGUDWPZPTQPFYHQKILZVQJYXSSVLGUZVCTGAULDFTNFARWHJDVMUPOXUTIGDHPNORIGPRYZAKHNUVTNNIJRHZTWHODOCTMJRUJRBBUNWOKAYMMLWSCPDMZENXBMGRJNUXAJLKANLFMILNZCSDZKYUVMJRKLDTOYBTFURNJGRFDIYDMJCBWWPKTWOMQUAAJSCZTUNFNCCFFXBWLVJUQTVDWJJRHLYIWPJWXDSRHZJNBTGFDVIUUZWQYVGERYAYYPYJQDAGRGQKSOIUDVRUPKGSLSAHMBELKDOENTOXXJIWMUPWTQATIWOKNAHFTCEBTTPZIWCEXQOCRFKLXZLATNYCGKQNFIKWDHHPWCPVJJNYKSYBCOCDIRGGCDFOETIAOWAJYNAREOIUEGBMNKVJFWCAXAUPLHOQVQBXXZCKLVZGIODZFQZABTQLECEGYQXBFCJCISBEEAKGEQKDQTQAMTNPJFNGZGJSCQNZTAQZLVPMTUPFIDPEDWTFQMSTRQDEYKTDRPIIRSSQGJQCYNATXUDYLDHJXNGNDEMFKPGLVSWAHTKFIUYYFGIWMENBQHFMENNAHXRUYYTTDVWYNAZYPNJKRUFLGRGDRUTCJUBVCCXIKSSAUOZUSPRKIIFNPTRYQZYMVFFWXSZHTYZBPJNSKSKWWSKLYGMNGSQGNVBGFMOOYOXQVPERHWWXIGPKXFHGBEVBLPSNUXQQTOQLIMCBOPGKBTBMMEGUPUXDCLPEGYEYSABQDZFTAABVDJNEHIYZXLLZVLLPTOPDBHXEDIKTMTXJIBXDIAKKQVXBDXINCITQCWYCMXPCUSIYVGZZWPCRPDCJPSIDSJHHKGEZVRLCFMBQKVGCBFGYLQPFVWDWFXUOKRHTTWXRUPWJYZQOCBZWWDAFILTFXJGOQOWGWFAJTELWYSHIIPVQOHMVKGCYDYFTROFAYQPFDSJSEKQGOEPMZZGJDTVRWUJHJSMEHREVHHTFXZFVCJGVZFDBWPMFUKHFMTVMNRAZEGKROFXYAZIXOZLFHJXAFPVYHRRSJAOADMHJVKOWJIVVHIBGVIJXVZESJLPONKAKSEMIHKJKMCSNSZMUTGCZMCQNRBSETEGGECLDOBHHZHFLBXROBNXSTJAZOOZWDXJQOZATGPWPOVCWDRTVQUDHLZKKOMPWAVWJMPRPXLTGLBQWBOQLGOSKHTOGGLIIKIWGYFYCXJDXWCZLRLIROVJPALPUQOCHTICVIOKIBYBETFWRWFPNRVQEYDQKIPQEZWRGMJKMDEZHFXGSTQVWNDSDYQDVIXJCCOAVCOPBGYOQBNTRHYICEFSEDKWSQBTBICBCGMSCZHHBDWPHQGWJUGFKEUYKSFWZUQKBKZIQOJTEPJUHHIOGVBQNSXQTQDWXQBCDDJGNLHDONFPWENFIMGEDBNHGPGXHZRUIUIBKVFFNEBSHRFMILUHNHDRJVLHJQEEWWBFZXFBQVWODISZPDCCJDLVQSREONZTMPKGXNCPWVBVDTBIYUCBFGENUWVTKOTNRFRJYOSMEHIPTREJWSYSQDUHWXQDHHPOLXURTEFDDTUMJKIQBRFDMQWYMVYHXRMWYYVQVEMXWNNGYXEJSJKTBNFNNXWRLFHHGRDJTHHTVSTCBWJQJVXKKNJZXRURXZRHELYLEEHVPQHNRNMFGXUNMONRCNJBWZENGPFOARGTEAWTQTJVYQAKYTRUPYVEZLKKEAGAEUXGFCMYKKMLPVORVYZRFQWLNQKXOGSWLCAIPBSVOKMRREDHXYMDMXLGAQVDMGACFQSNXYQVMZSAFEUAMUDDYVNKMDENEYCDVDRFABCWOWTHKDSLNIFLFDIZTJYLMJQGWKJGVFGRGOKWWKXJRQCGRMEHGVXWYSYWCWBLBWSFEBPKDFBYSJKPMGPHKVPEOOYNMCLUFKUIPGLNDYNLZEZPCCMIVVUFKFTAREPAUWLBHZATZXNLTIZBAIDEYGCTRINUSLXSWTDFFATAHAXTHBSYVTOFNALHGHDWEIAPFWPTGPGKYGHIMTRVKXJATJJSICTXFWGVCKBJMHPAXXZWTYIBRRHZOKOPQFXWCZDHTSPINYXKZXYVZPNKVWVKFPYABIRLUWGNZNJKFZAIHDCZSPXTXZGUHGQZABGWSDHQPZEXRKIQXIYPZNNHUPMIGBJVMCUZITFYTKLALWQKQVNQRVBOZXEZTZASUXEKLSHDESJZSQRMRETQHHOHWVSGMRPJYXZAPBOUNVMKSRLMYETEIJSYSBBWDKQNXFNEPBFSDNDVGBSQSUXWZWKXANQMYXUCWYKBOOTKNIAJUWELKFAGVNMEGUBNVHWPAPNSKPYVQJEPXQUSVWLWDNLWIPOFRMTXZGUFKHFPUUIEPETMUHBMCYUZQZNJUDOESXHAWMSFPKIXCIONOLNSDYNWRMOGJRVUWHRVIAYOVRXQBZIJXZQBQCNDCGNSPRZASEAOGJIJMILJFODZLNYLKOSNFNALYLIESXKNVOVHGTIWDTWNUUBCBNPUUOLCZVYPHMUBSTSLWNMUYHSILLOATAWZVOCEQHCQGYHWQCRWEQOSQXIZLPFCEPESOURQCOXHNLGLUKZPYSLNNTSRNVRNECBITGPZCJVFPHTWBHHRHBOTQQRUQOWUBKTIEFEOJIVGVKFXBCNNIEFHSPLAXCTFWDKUVWRKKQVGYORGRZRCXSKGNBHMAQOOXBOSMNRVCBHMCYGCGXQPHAILFNDHYWUCRGHBTJVEAZSBOPFBLWIGYZJUNNNTVLSORDDCQXZXPSWRGDJBKQQZNNPLVMOFOGBHHZEZZIXGXDULHCMGJYOIBQTQSYNJHAFWDEQYZLVSCYHQIKTEJCYJNRZUWNEHHVUMIPHFUNAFLEMHVEKHPEVLZVSUVIFRXTKQSJGHHBYIFZDBDMACURXNIYEXEUYFATAKQCAWKGESLKCDYYCXOAOZHWCPUHVRNUKCWQKHCFINYYEDWUGQXPNEADKYFTHDRQLHJFVBUOSSIRYZWPUKIBCPKUGWMEFCDHEPMRIUCKEQAYRBMZQDODVJQHPDJUXXENFRWZMGRKMYIIOSKUJNCQHPZKFWFULYDFQUDOLLOMSIXCHGNXAFVXDBQNNMCGQEFVYYXPAAGHNHKHEPXHZVJCVUCUWLQKYHNJSQCXNTWWUGBYUEOWQYVMNVJKVNJRWNEYXGTUNUSWUZHIOKRNJPQWMCIAGJPFTKFKIMWITJWBZAYVYHKPFEZRFMRHCZCZSIYDEEMLWRBRVTIJNNZRKLCFKJVFKBHVALVBOPETWTXIKYPSHTQXZDGFKNEIVWLKTJIGFNTURXZLQRHERHAVESDRFQJJUZYXAZTRUQGBJVBCGRAZBGFRHPEBCRMLXJDSKCZKFWKOLNGWJHXPUWTJWBXBUUTQCOPAZZEJKKQCXAHTPHQKEKQLJZKEVQBXPDZROTOCKZAHBKFHFUDQYACDBTXLWZBZWTKIYQYOKYVWDVZGFCODPISNAIVBTZIZMYYBNBOXCYPEKCLYLMZXHLCEIMAVEGZLJIVRJQUQFPXMROVGLFQHRGDIYZDBMQCCBEOANSVTRKBFUPUCCKIKNZOKFJABCVLMZYBAMWDNGUECWKSUUZVGSJYRFCJFTGMBWPROBVIJPXLZTZHAEWEVUDPISIRHUKKWZVVYSQTUEEUPGZFJMIYRMYNOTNPPVSBXBMEMIEURLGCQVLPEKYTXYUVSNQQKMZBLQEXLXEHKBVYZOMFCVIFDKMWPWQSCWIEFIUESTQWZKRYWWLXKWEYCJZQVABINMMIQWNSMHFXWPIOVOJBPNPXJHTLAKWWOOWFLDUWSWWSPKRUNAVVRTQWZISEPNLRYKHGNGVRCTPZTQNNORJUPTHQRIKXNIPAYUWWQGHGPACXVYLWFANVNXBRXOXXHRMSYQLQKGFVGMRDRZTNOXVYLCAEVDRDTNOOGIEULOBYSDLIYYLTVOFOVBFEELKADDMWHLNXCWQZUWAEXMJGIYBIPLAPVFTEBVTBBTMMUICTEPZXLJJMVHBYADFSRDHHRMZWRRIXXZCDWZRPSMJKIZUKODHAKFZYGUHGHQWQYSMBVGJWIIYLZFNDHCTMJJMOSLNBAXXCLVSDPXRHIIKIJTHSJEUUVLMUGZFDTMFRGISAFMBRALRLJRSHXZXTUSNZNTJSHKIXZIFHOJNEMFNMMJWPMTDJJNSZMMRPVSHKZMYMHRIFXAJNKAFVCHXGCTFENMUNZKEATWXQSHIVSFSLGGLYHALHSVAIEVDTDUSZULCDQVNNKNUBYAWLVUHTRYEYVYUWTNZEAKHISAECEWUABAPINFHYUADVKRSHSQLTBFCEKFGNNRNVGHADOSPGSQJVAFYYPAKYZWCVWMZPEOONKQBWKPXVHHDTHPCNCIDEDGXBCZCKVGPLMFOLMCJTAPCBMJKNPJQKIDLBKYMZAIJJONUCJEKZFIUPHQBFLMTYJVGXNCPBFXNHZXOHYZZIJDTLUHVWHUFVJRDRNCSWFANYACGGELVTZIINPAIOIJDHBNLESPOWAZUHSOQODXIMTPBFXRAZCGKDMNZXNABDQWCWGKIFQSNXTPUXZXNNARVVTSHJTHARBGQHEAEOZKNCSDZJFMAJOCQAGWUOEKQTKNHOFFFKXNGLYFCXEHBYPISUIMRJDUVIOYLDWMZMFXYOKEKTVKMYYRAUNKWFWAAUVGFUOTJWVEHXYLCMHVEPPLAMRDBAZPSESLMGJUVZIWMWSRHYZELYBTIXZMTHMNKAHUCEFWEJDAPZQKHLDDBEUOBBYNLSZOLBZSFEGFLXMRALYMSMZHPGGQGBJSETVQKZZCOZSEGYLWTKZIDRCESDGKZIZTCUKFAALOAHNNTPXEWQWVZAHNTVRFSEIEBFEESQIGCWIKACVZYXKMAGNEOTGBRZUIXDIBIDOACZXTKHBBQJQXLRPCRPMOZABHPIVYHMDEAXMXKREDTGZNQCOZDVDKTWCYWRDHZPVHPKGKUEGGXIYCMOPENWZTNOJRTYZQGGKWGSTZTTOPBINFMILFOCKWCZUHHNETXZMFUHQVJKJFDVFTWFMTAUAAKAECRBDYRBWCGBEKDWIKANGOPDQTYXJGEPUASSWLEJNRIUXCYKHKSGBAQHTVJXDLPKSLSRKKEJIENQVDFKJAJEPKMULATAVQUXOVETPUCPMZDDFQCZENWWKVQCMBUZJSWXWUQGXWAIQDFJAOBVDAMRURYPJTGDBLIYYFWOSQBYYSVRAZHYYAFKRHKNWXKAJXZATGTERGTOZRYYNCEIWGVSJIFVZIXZRJYEYKYDLJFLJFOMUWXRSOGIFNBAIBVSRREXQZDQXXMMYIFLQOWMMPOQTRMPGGUOPBEOVSLQHZHADLLIAYHNLJBRYUOXKFTXSENFFKZLDVDIGVJMYVTKSISUBRHSVTQYVSHWMWRVGAYGXRNJBNVFDREYXSEPFLOSNTHUFGFCCPUVTTCMWGROOGOCHLXQZYXMJYXEQQLAPUCXPNMTBLWPIIMYCGYYMTMFLDYEJAXRWIAVLKRHQPAGGPDJFBQEIGDFVXHHZFLQFOGBKAMQJOQOJPJUEUAZBQZLVJNKNPGUFONFHJKULFWARNISQJVAGMIMZZJGXXRXVXOTMMJEHQGRBHWTRSLGZFRIIXIFZYZWPJCEDDYQPPJXCPLXWPQAMPQDAVYDYTJTJQIPMYEKKCLEWPPWOPBYPMWUMBUELSMSGJFPQAZFQJYUNZUMGWWFXOBWZTWWKGQZTMCGGWKAUGCLVWMUBPLCYHXXVIUUJTISDDSNNMUEUOOPPFHNILDPXXUCPNFLEFBLVFMSHWNOPDNYNVAXVCCZYCWFHMBUKWKTZWYKQNZOABOHULNGBJERUVPAPQWKLTJXKNXYRNXJTXATVUQQPFSZUCKOMEZJKFFASWGXBPRFCDPLKLCUXQWGBMJTIAZCPTMYYCABCIOUBCUTHCPUHAPAZRWQRUKOPDDPXNUNIWKIBVCPQJZGHPDDSGNIPYQFXSFEILKRWKGCGCMRISMMIIUMCSMGCLQWHXRLSEYTGVMVQPMEWWWUPUZBGPSZOEADEMRKPSCOHNZDFNIZILWUZKRNXWWJFTMNKYICSXQTIRTWVBHNYYZQKGISSDHMUBQUVGYNJPZNDQDOZMMJPAUVEIBZYEPMCYXGOXUCFOAPFDOMCEXFDXKGBEQRMIQGSINZKVHZJQTSSGUTJSLIIQDMZSRZUMVZZBXFLQLCDVTMWRKXTNFHXBYHHVAJRDEUWZOKYNGFPPVVGOIUAAWVBGDWKXJOENHORTITPSQPYRNSYVUEOGSHSDHJEZZFTCNZGJZJDJTFRSWCOFAGJJEVGGCRTKDFBQJPGSVRNPARNFNGHQFHPWHTHCQIOSJMOQTMOBGSJCJFGAIIYAXYEUFWJQVKAXFDGEMSZRTSHQSJNVEQRAKMKVWWYYDCGHRXGRDPHXBIQYSEEFRUGYGUOZWDQDOBVNPJGFSBDYHKVKQIPJVAZBLEENLSECNYYFQXQNAHOMAIIZTTWWOGVBRGMSCWXSLMLZAAAYQQYKIZSIRWRGBVKHYQCSLUWGRZLEKMABYZGDHUFZPDPDKFSNTYILTMQNBFSXQWGPKQXUDFZCFPONIVFUKCTMGEUIPGWXCQJJXEEWYMFSHJQTGVGFJTPMOISXBTPMLIPWGMESTGGWDJUCRDJKOIDVZKOJSBAZSHVQZBWETPGRNMFFQCOEIJDNBSYEBUKCYKANAFBKPKBPWDGRMAHSOOEVBMJRZVFROXGVVUUQMAXTZWHWWFSVLEASWCXFIWYNZDDJWJZNIDMFGULRUYOVQFQKRRAXNNBTZZNJRHZDAUSVAAENOUOGHMVSREIFAZGCZCFQINSNKWUJAWBOJGMACYEOUGMNEKMGYLUKINSZBYNFNGKPMWPUEHHCBQVZBZNQKOPUHMZNUBRTLHTBZORLFJGGHRBTWPRAACKMGQSFYEJEYJKLJHBVEHNHILKSQQCRWILDYCCVYBBYKBOGQRJZHZSFIRCWCVKAQBFAHPHSSVAQXGXFEMHEWPNOXJYIEEPVMTAKPATRWDKADHFSSSMSRWKYXGCYAOIPVPWRIRTEHXKSYBRTBNNZBYGIKKIBKTXUPTBZMBHOHJRXSXIBNHGFIDOTFEWLQUOKGETXTLNVTOXJZIPDUUQFNOZQWBQOHKDRYFPOCGPWJSDULBROIZNJXVCLRJJEYQVRAEMWBZSZJLITIHBWZEHPIFWYAEIJNYCTACFTQLNUWEWAOGEOKIFBZQNWNJGQDOHTQYJUZPLOWDSVTOJMGJQSSMLNIPCNQQHXMBYCDTMVFZLEPKUOIUGBFOTITSHEUVSQVMBPUZSAMLSMIRJQQXEHDJRLSQHCAHMLAVEMKVNIJTSHCNCLWPXMZWMCKHQFFBMCUFIPJYIFKMNZJSHUZNJUNAILIRLHURCBXGFRGLRKKILZAQESBTGDJRZTAZAXKXACWWMYOULRLGJCZZNVSDWUTEESMMVZPULSUNGOBHHMMPJZRVQOVWSTQFAJYIYKBYBXQCGADPECHOJTNJTUUYDCHODDGSYPYDWXYCPXEDPMVCJDVFHMBZFLRXJJXTFWHDHVNORGSAKPMAICONFKNZACPKLSBXNAJCSHWAYBRGRMZNRYSUDOTBZKIOCEUMQXKZVUIWYEBKLTYMOAZGMLMBGNDJBMEKBQFNMEUKHKIYAEZTJDAXRYOSQTCWZMEHNSAIXJHNCVRMTCXKZGRXAPUMMTYHZRPFCNQLKYQITUPHPQDXWAVANGMMWCJDGWVPXESVTNNMNQORYOBDRZVHKBRTZMOECHQGFLBIPYXMPMEOIKGJYSYCKKTOJAYEIQOZRFBSBVYHUOTEANCRFBHQJTLLYCNZQXNZIHFUAVYAWPZPBWSJYMLMYJOZCKLBDKSMHMCTLTYDSZOWUWHSYSHMVXRVHHKNTKGRCWFVVDWLAJLFCYVIUKEXEGJJQSPICZLKVFVOMIRMGCUJYBDQMZBVISRISGTWVDRTUAHBVSYTHKEOCLEFOPOCCEKRCGAFRLUZCRBHPGKISROMVRXMVBCAGGOBRAAYGVLQGPJVHEYTFWEISOWCSKUOHGTEYALONEPPOBKAKENZPXNQLBCRWSIUHTFEAEORTHJSHOWVUDHXSMBZJRGGOSERIZIFKBCOQWYFMMOZMZJHIJWLEXGGTQQQVKGEEVZJFMEOTAAIFSSEPKDTOFMRSWYDHVFVTZJHQAPBWQWWDUJLINNOVWLMXKGEGBSTBOTEXRSFNTETOYCTKPRYGAGMAVCNRFDZKDGEXEMQTSCPZNEWQCYYINNUUSTEXWSXBDAZSTVLHLBKKOVKYGKYQQDOGGJILXYTBJONMFBAHKHGGOKSRLMQEWKLTQEXHYQETOGAOGIOJNZVBAVCMDOLECQVYKSRGKUPFUGDGMPNLNGRDRJOIITQVKLIPUIQBMUGXFEAKIALKMVEHMGNXFAOYOJVFVZHJILNBUTRBPRDWHXNESLETKDWGMCJKGHZCTOVKQCMMXHVGJGCSNZHMICTALQZXMNEKIPCOEGWNTYQMLQZHFUBHTGFYDJBVSXNWLQTOCHATGIMBSACZDBPOKWKYARXLULAJZJTQLKIOCFXUPKNSNQJCRXDCSOPINIQXYXPSXFMTPVMJBQTGCFOWBOYCNEAOEDASUOWQDGJBRZZZXALIUCSHEJZXZTQMLEHSHUIGRBMONZDPMKBONDPMAYHUNUJDWDWIAWDGOJIJGKZKEINHEECJZDTVQADHAUHMGRTMBPMQNDBVWAZPRRWIMPQIEQSJZMZEUUUFCVFTQSNQXZXQYZLIDGUZZCEAZWDKZJHFSZUZSNZEFHMMNCKFGCZJGTQRCKYXLIFGFZNFOJJEGNOFLLZWYZBUOZIVFIOXIGKCLSAFBEBZNSBITSGGMILRNWINJHJNNZRVIDVOIRNADGILEIVFNGHDXBMURQRQAFTTWWJWWWXSNBTREOULGJSYCGXPVSIYLZTCCXZGDFYEXCRRRREFIESRCJDIOJEUZWSCXODRLCOYDHCSITZPTWFPRHESBQRYIKFFVYWEJEAWBPDOMVCCVIQGXQLTBEDSUUIXNBUEGQFBCXXFZLMBKLUWRRCUEBSMMQISPPVNKNILWDYDEWUHJUTHMDQLXYAVJXGGNLKUEXOYDZVFSCMQVOULBSWUEVOQGQEKMHWUTOGLZLLGXTORHIHNLFHUQZCKMMCFHBTWOYAYMAVUZNSVREEMMXEDQAOSKWGMXROSBMJHPYRGHYTGHWBWHDHCWZNXIEPEFTJIJUDIJFKUDBKCJONPVHLYWCKCRXELZCBGIFZRMEHBXQBFMQNZMSQRMZJZIQQJZEXOQIOLIZJKJIZBFVLGDCFFCQPFGMCRUTRDABULVVLQJDNCPJJVBXEJFQLAYWVILBHTYQXSAAWULWIGXYSRBQKIGHQLKECEAPRXKZTBCWWLJEDKOYZDXPCAGAWNDACPHEHRCOITVYWGCNXGWKLIPFUPIBDDWSBJWYOFQLRFWGOVBEDIWUFBUJAKHHPPIMAPXZHWVMUGUZMSQTJFFBLIQZADJMYNMOAKABZNZINMYKJUNVLCJYVUORQUEPGBTUFRKVVQPJYMMBLVUABCQZXAVBEKCMUSUQTUHIE";
    int target = 6600621, ans = uniqueLetterString(str);

    ck_assert_msg(target == ans, "error, except %d but got %d on uniqueLetterString(str).", target, ans);
}

START_TEST(test_tle_2) {
    char *str  = "WEVNOCCPTSKWHGNKXTUAHWERFVQGPAQUHGUSUITSYRIZGBQUXDASQPHHCPOLXJTJPSTJWIVSNDESXBYLRZXXMKKKLZEDPDXXRWTVSDDPXHIBURSHWWUVZMSDCPKLUWTYBYVHDRSRQIKLHZGXBETNGRALRWONWZOEORQLRQZYQHDFKTJEUOJXCHQQVBIYKIKCBOEOOKKOTOHLOYHOUTIQXALOKSSJBBBQXYQTOUCHHZWCLCYGWFZVABJLVGXGHPTXSIDMAZUISNEZWBSJPQGVRSBTPUAFFQBXPKFCSTETFGQKMDHJWQSMVYYQERNLWRWNIDZMFTKUZCPBGAWAVXYHAKCQDFYPLIZFKRIPWHSSSQWUKEFTLPNQFCRLYCYGOZBWXPDSUCYZMDCWHHNZDGRSRRNNBEOQCYQAVFGQFCXCOQQLZUKXUOPBEPBNQXIGIXWYKUIPSPZDNUVZQEUVWLAUXTGOWJYRTRLOLUODWZJJBEESAUKDDKDMKIFNVYYJGDRJHZBAKMWAOVOCQXALSALYVNINYAGMGHYATSWMGDMICPGAEJPIQQZZOTIINWTQCWLEGXRDMFQJVFLNKENDDTOIALDWLGLOFHRUYOTNCVKCFJOQZZAKYJXBKXKTXTMOUDJKAESQOCYEDUYEXNUKVJPDTFCEWWOTQTGLKHUUEASNKDAWWNJPVTPTAOTNYZWCUCTZCCIHTRQZFKVDVFRXKYILHSQUTHYKYEELRRCLIAXPSLWCIPAYKZDBBIYRBEKHMFCNGNOCLMSFOWDOIIUDAYRQUOFSZZTEVHRWELDBIVYWDYXAKAIORSDYQJRAUQFLBWQYLUEHEFQFQGPIYHXPKXARFJEWUKLOXRFHZUYNOZEYRPGOPPFAYOEKYBJXIPEFHMPVDOVIYREIYGQUQUNOVLWNCKQARQWEOURFCKGBJEJEHULFGZJSUJTKZJMGWYCSXZETHYRWKWVJXSPXIHQCXAXEHBSPFTTYLCPYWCLJDORCEMAYZDIGSUHUBSUQDZVRGXBFSLYWTYKRDNMMEDJVUPBFVUVIJYONGADBLXZAMNPFTAEHGHSZMGSRDYNLPTGCAAPWEZVXPPIPCJFKIJYXJRTOECQCONURCOKAPSXWUTEKEDSPMPMYIAZQSXWDUJNZEWCEIZPZOCVCXJAVQMPNXVNCFXELZKBSPABACUHGOSWPYOFOGQKULZCXGSTAFEIPKVDRVOYMDWPGROBLPZIDPVYTFCAVHKUMTKDDNGFSJRTUXWPTVAJXQOOITLAKAJUKCJVGJIHGRCUPBESKVVNCAVXBLKGRGVDFRUVKDMIPYQDKXWVKSJGCQHXYCSKLUSPNDAGSTYXJJTIHIRWNIHYIXDOCYAFLWYNYSFOBLDHUIRQGRRWHOLWSBFJENNJVGSSTYQNYLEGTLBXCKQQPPHWLDWZDNAWTXASKWWSGXRKYBWIXAMWNWZBITVVSTUTLAWTDFJEPUGTNLULWNKCBRUDNWQMAGNRIVTZCTXZKRTASWFRLNUVUGUZPUKZGGLWPUQXGKMEWOBLTJIRSXHVKWGKNUTJJFWCZAXAKKVXAVVHYYLYLULRYBSWRKUZRDZQMQGXGQSYSJTOHFKFBLZAJYGXYXGQTBJEYYNKRFCADFIGVYDYLURCSSBIRTFLKXURLLPJLQYTFZGEHDLMJDYJWOEKXYWOATDMQKRDFCSXFQEMBMUQHSUBBQLMBHOHMFIDCLURHFKRHAQRGHUKYMELQGDEGLPKFADXEPVKUGZNTNUXPWRMJZGWMFAUXGYMTKJBBINTYUNVMCFOQNLBUNEEVFYQASSYDBQWPMMVAWGCSKTYQUMKMSFEBBAJAEKUFOMUFEPZVZNILAPTMPGTGWZGVBGMWMRKSNQSLWDIRNWSFVIFIXFEZSMUOVIKMRCFXPTLXJNFFDYWJZRMTVVAODMHEJBTUPMFDSJFMXKPYTWABLKZNQXPDJNGRYKPPIVKJRBWWMQPQCLXBNUFALTKSIMOTDDAJIMGYRLPPJEKFKBANCMLXTGVBKUQVVEKUNTPXNYNOQLRDCXWXCMGZWTYGTCAPJGHSNTQUMTKFWOWHXQBJALFYQBIWARUAWKOFRJDYPVTXKNWRHEKZYJGHBTTXZBLGNTVKEWFXGZLLCHZSGDYQFOADZHSBMBHTXCGTQJQKXOUHGKCXVGLHSJSVIGRTNJVRIFUECWWASLZCSCYCEUEJRETYXSFKLYBMDJBXJVQERHOSWTBJHJPJRRNVWKCQWMEZURSMRYKBVINGXZLIJEUIOPTZZYUXDDZFRMFHPAXFLTRXCSLUQPSHGZUVJNOYQYJYCLGJUWJHYTEGPDGKOXJUBOIRZBGCDSQRETGXRGABOIJDLABYKCHIJRBUKUOZWMPLVRJQOVTHFMEHFLKXKONFNEYFHKPHOCOTAAAKFAOQQLLFFPRETRPNDTPNRNMEHJKAEMHLPDIQEJAYWXCLKJLQBGGFNYPKRVMMXGWOFBJYDLIQWVNWFCIHTKTDFONQXTIRAWITYBKKMLXWGJMSHVQGLLCOVOVYQBAZSYPPRHERAERZCNAZDZMJZSECTHXGUDNYXTVNEIVQRKCXZSTJOTVMEPARRWEIFQMRTJVOEMEALQUUQEXEULVWGXMYFRXKAHLTKEHHGBGRKGTDDMVEDBROLHTMQLKNBMFAOKBIQOJJHZOWNIZGWKVKGSCMTOXMXWYINNUGTKFOTOIXBDUYMZUKEYWRVLXMUKLOLYULFCYCANYILLYPJUFJFMLWKATMAAIHLCSRKLAARSEJMGYLENTWCVOORPAOAWPCZIJVSRERDPGNGVHUAFHWKCYWSVFTQBGYEVWBJVGCPWBYZYMVKKHRBZIERGZEREGJZCAJHDNQBGQWREJKQFQAXHCJYLYLVINWBEUYMKBTSTBOAVWNCONJZGHQSSXABEIAKWEZPCKETIFGOTSQSADJDPRFCILBTTFVCJGWVZZBJNINBNZTCOLDBYRUHENVSVKCJGITSHERZQZCLEQNSPTWRRLPDRQYMFOVMZIJNTKEGNMYKPOQBMCGGOTZAEEWTNLSUGSTGFVYWPQCJLUIKMXUITCYTTHPKEOHILHFMGMGANQEAKFTIJSAVWLARJKNBOXYNGIZAPLNKKOGRLZBXFLYEAGDJEQCMTRYPDSJIFOWGVHWOJNRNZQTPJHIHIRQGKBFSSFOWWKLSJEYQFLVMQEVLCCBYPWIVATQHLUEXOQNDAATIMLIGDFQSWVVPQOFQWJWKQMUWAJJRAKZEHQKWSCUASZLPXNYPCLJGADGOULHGPMIUIRTQFNPBPBISLGCJCSOBZPNQJJAAZZXYZQEYPUHXCDWYZMZOXFYCNDPJEZJBNHLBKRWJGBVXCYVSKZYVMMYJKNUNUMAGIGAUXQDYZTSPKTZAUROFCYAFDKTUEQRKIVBSNDZEOENKUZONYXIXOMCZNRFURVYLWWLLCJQUQFNDTVJBSAHRBAXXVTFKHSVLKGUNKHZGZORALKSRRNYSLZDYNQXMGCPGKYLXHASQKDMOBFNVQZUMZIZEGTTIMXCFVGHNLGBQLNAOSAAAOAVBDEJIFHVUWDDHYFDUCQDEDYAHXILGHJYTMGPFDTJQNCQYQZWBWPLQPMNJMDPRPBWJZUHCOYVSNTUXLQCCOLRGXZULSMZHGVIHDIAUVZAZPYGYMMPTOXURVEEKTWERULAIETFSBQCYMHKFHIBIJFFZCOYRKSRDHEVTAUVXXQGPBKQVRJJEGKCXJTVDCZKLUGWOPNWHWTFXXRZDRYSTIYFXYIAHDEZIVCWSOIOFKGWFUQGXWIKKXZUCVAKGWEJTOQRPQZRZGOJOVQTJKVFVOUHBDBIUNWJRAAFAVEXQWWAISLQIDCYOUTPMBBJXWNICJUFHDRJZOGDEXHVNTDYPDBHRPCRVPIITUYLZLRPKSUTCKMXSXAKYBEXKXHLCVEHXNNBZOXRVWGJOTFZQZZRMZKNFOWANLFZCRQLWSDAKQEQJGKKZNJDQZUWRBVBRTXKJOZFBSDZENXGZRKPAOFTJAEZTWVXZDFTRRXXUURPCSKHQDXKZTIJJUXIVMEXCYQOKQQVBFZUAYWTFNLWZPMFPRCNRYDFSNMNVFOHPJMVBJPXYJPBKJEFGOGWHPPUBAXVGPOFRQFYNZYHVYOUWLAKXAAFTNZYKRSAAPYRLTCMPEBQETNYAQGLRGSQDMZPBSCFKCZMHXXDGDDLKIBILGTHXDJHDGZLDQTNUNJNLHZZEPDOQHMOCIKDSKXGXXJFYYRZGIHANZYAPZIERLTHXKMXMFKTCRFWYMDJVMFJHGZHEKVQCELFTNHYOGETOHSADQPCYDIIPWLKHZTJROPJKFBICWSKXVXQEZZDTKDZEREGTLCQVJYMWEPDLYCJPLQFNAUQNJEHXNGSRAFICDHFWUHWZTJRWUCWGNQVGWIGDGTJKZCGLZCOXXJXTYQVLODFTMMALTKDFFQAHEBNFDEFIURXCTUHZHARDKXUGVUFRLDQORAJKITSYMQDDXVBNNHVGMWBDVYOABFWQEXJDRZIMTLAEJILMWFBETZTVJGZKTUFYYXHURSLUUXLUOUIDVLHPJYCAZPPIULSKIBPCEIAAWLYBGPQQJWVHAWORVALDKDZRDGOERTQBPRPHSQPWOIKDNJZXTJUPLUKSLXMMWZGSAWZBMYMIROAARVRKUVCNARWBCYVBAENMBLGDXGWPKNZJFTDOWGPOGAYHZLQMEMFRPLDQBRENOEXHBHMPNDMJITLMMHXNBNECMUTWQZSBLBNSAIMQQNZGUBSFTXXZAGMRBOLSWJDXNGLEVZYWKMKZOECJKIMRWGGAKOTEQUOVRXIJKFOCOFSSIKIQTKDIYJYFPPKPSQUYOTSXXOELEOXYLDRSNLJHUDORYUQNNIOSADIBTEQSJPULVRIJBKFJCZYWVFQWONDZKISFYZANAXLMMZZGEGCMDVCPUJQQDGCJGKZIWQWRBENXCVUCECWVEPYTQOCTKWFZWOAUXOPKGLAEZOLPVLTSQZDTRCLDKLRVHAOBRQSZIWYKADFFVVUGVYSXSKCJOEVHYEGLYDBAEBTTZGPLYFDBWHYPLUWOMBIKSVKODWCOTSZUSBKYQFUPAROJNTKBAUROALBCRIBKWCTIHAOGTXKTDIELZHKVCTKIEWHEIHBYLHXYFWGOSPHBVGTKSXPCLCTIZUKTYODDEGFBLOATOAURBCXDVORQEZDWDBFMDVDKHZYHBSZAKBYDKWZWEJGQNRIQIFTILKXALOGMNKLZOTFFGOASZAPEYMFWCMDJGOEXIFPONHFOUHIJMDYYZFFXACDSRZUIJQYDMHDHSOPCIVGFGRUARODOFULYQLZMCYVCYQWNJSUIEKDEDHUOSQQPQUAJNWAADKRIFLXSBIOPORJVXAAWNKFNSOTPPBMSFHORJNUUOCXZSVSTCICKXGQVZOBLQRKCCEFSRLIHMFFMLAZUAVLIYAHMVTJMUPLKBPOFORWXVOGEHEQDCQPAYBTTXETVJVTUXSGSRJJPROCBTGEHLKPAVDTYZTEQJYVLLZTKWRWUDIQIVRVYABKKLLRRKHPZQPPYCVLHOHVFNVZBXPSVVTJIWWMYVEIUNJROGFRUZPPHTIEKFAOAMTLKSEKTWKUJLILQCUFUAXCMQJLAAFQRNFMXCDAETWKFQKNHOPOFVDJNDKXOPFFYYSDLRDGRONVYGOKNBEPVLYHUSWUMCQMVHXXHOITPOIJDGZQLLFHPYEASXFZOHRGIZIYODCJXKKIMVBYOXZVOUYLXXRSMGGEZANWSHXVVENHYRQNJQTZDYIKBSYEAAKFTHDJMXZJZVDSEZJXZDJDXEIPXPBTOLLGNBUWJCDJYXJTBQLTAWPALHXYVZDVGGABJWAHCUQJEVLNRTYAZNKUBTFLXRJETQBXKFOGBVQRTCWHBASKSXUSYGDQLEMVQDSJNTHUZDMMNCVWSDRZPFKAYYOCLBVTQSTVBOBTWDUPIVIFXFMUAXWLOYPIQIIGOHPIFQLNTDHUUEBLRMDBOPEETWLSLVWPWJIZDCIBNRMRPPAMUXOIPKNTOMCBIOVAKWDHEKRWKGIPDGDCJLPVIJZOPTBBLYXEAMJEPJNACPTPDPRXRBLTDKTTCWTISUPCEZSMZNBBBQXKOHNYWEOHJSUUUTBYKGGHIUSPULYMWIBYNQEHACCAQLLGHCQEVNQYGQVXZLFVKQBWFDUZUDQAGMNLWCGQHQCFXKGIEUFUMAKNYEMOMONYSCUBUKRQXRTMOEBYWNBNRWDKBDZVJWYFLBPAVYAEBWWWZZPERYVEGHZZZPFDKROFJBKJTAOYTBVPCISUFTZGHCQEYJSFGBNGDKRIPLLZCZRGVIWSMBMYDQRIILCJQLKMORYRMOCNWQWSZXGGAMRKKJLASROIDJBKTPBJVPLEVOAUZPZWCGSXJPNSEHBAFVUUBPTGPHEBHAAYXIMEURDGKQEWXUMMCAIBAQLZPQVAJVIEXEDWZBCOCMIQNXNUZVXVYAWHNKXROZMSWSYOQBUBYYULBVEGPTCXFXCTVJIFZDQMTBMNJWMCQPTXCQCROVZSXOGKYLOMLTEQUOICSTLYJMYBQFGXPCFYWYHYZYBGZNGAUHZGSEFYPHSINBLXKGYBIQOETVPSIICUXNLTHHQRRSISPKJGIKSTNCUGRCRONSFLMBJOLMYPSFQHSCWIRFYPNGBKRWQKSNQEHJUFQAYULVMRVYQRMGFLUYTOHUEIQMTTCGCQRGHYKNWNRSZRBBTVCWUPFHMVWRMIQXMSLEYIHBIQTAEEEZYKXAILEWPYHCTTJULYESIIANHEWKUUVQJSZKRXEGUMYSBLKETIIZVPSBVXSVLHSTIMYYWLLSVEXDKBBIWSHXKPBJCDFCCYIWLCILHFMIRVQBLYDUKOWAAGKMULNKRTCMIBVWSZJZNXWIPBRPFSYCCTQJEGLCQTDONVSLDSBDCKKDRMIEMLJMCGFPGCVQILGQHXQOUNVAMLQYOMYTYZKLQSHFLBPAUEIFKENZSCYTGAQKNNEPEKETNIQQFSWLBJLIBDKEOGOXOEDPSCVCRSWJBITCFZVFJNRWJLAJOGKLVPMEYRJCLKAHNOSMWOZBZKGYTDAVDPCLEYYKJXSVUBDJFYXTTXKTTISBTRVDHBPCSVVBWNMILCECNLBNJJQEMUDIASNFJUSRTYXLVTASTVVGCBWNFTRQSIQVOIRFBUATUTAXSXLZMSRKYMMRHJUPPOVUJMHMCSCNPDIUJJTEAFUZLCFSRJVHKKZRUBMIFKGZDJGKJPTQCZRCIDLXIUQODKNVFJEACIOEODEWNCXTWAVBHJUDIQKXRLTRBMHFCQVSHYVQBUCFFCMVLOMFEKOIUCIBMFLEXPWQRJUQEYCQOHFDGFJGZIHMLOZCIRSTGLZNTKRAQOPPAYKCWAIAAJBAADPEMWGKGJBNJQYXBUVGGFQKXTQJMYQTEJUZEQYJSRUMYXORYGKFZLEQDDWNGRSTHTQDTRIYPTNZQXOADLLYPSVHYCEGGEOSOQLIJTBUYAMKBUBYIGFPYWDPLKSOTOWDMTVHDFKXADPKEQDRZTIRXJUREOGFWEPMOWYXIOMRPYEDLJLMFSZMVZTKJIOFNXEPJDIGVEJJNUHDMTXKSHNVFTSFXTQHCEXTTLUBSASRAPQFUMACVRWFAVEXMRCWSTLHCFZMIPHTVXRSSNOKFSVVVTBVTCKPEWSIKTJTYVWTWFHYVZDKEDFLCYTWDUQBBLJXACRRBDSFBZQKADHHYYWTLTMPPBWIMJOOIEKJOIZOLNRBZHGSFRCLDGBIKSPOOSXOUWIWLLEMMDBMNKKFIEMUADFASRRIGYLGACMBNHSPVWTSNHQUISKFTMPPVHYRNZNAENZSLBJLDSKJSIZCJANDZVLEMXIEDLEQFUZHXZAQTCZYEENYIJDOHJJQDVYCITZNFQYXOCRXGSPMXKGTICSQETVODNHZPVTUHYVEVNTBUGVGLXNPPRLWLSWIKANDWTFMKQPZPTSJFNJLFOYSWPTDEAEUQFIIHYNSYNFNLRTBMHAEWXOPFVNZRXRMUDXOCBVTDPDRZULDTVJBKERPQIXEESGRUENHKPMOYBHHLNGFMVCQRCRPDRFLMQXDUFVZSZIFUOUJQBQCYQRFTSIYUOLRPNMXMHFQHWZAIRFJHJFIKHWZKQXPTZMMJZPPFFPASUTKEEBYOUZLAMQBVXAJGSFHNOBDVLBFSFCDXCOFKXOVASAMCNDJCAXPNBOQJAQPYTZBTSMEURATZZWKLKEBKPOVQGXUYJEQYBGBDDHJQACAMWNRQYTZOMXXNEBZXERPZSLJIADESNJMTBDWJIQFTIUCFPEUUAPIPSUKKOXNBNBZTULTLUGULDNRACEQLJIPUASDJFETCYDZWGSWHDLGBRIEIMFOJPLVTTJMAVCPTTFBCVLHZUUTOACMMIHSIXKSQWVAGBEBNXIZCNZVWFVKNCDSYEBTHAMBPGSUHPSNDYHRGWJOYWSOCQPMCMHXRBMNLGRMEFYBWWOXGBTYVGCUVOEQRNUGRWNSJCCNMNZGDXLTXDXNYBZYJSLWHKAODREMXMBGFCBATFIJEYQOWKXZPXYGVIDJBZUDJRFNDJDRGQYSLHJWPOZNFFCBZMAODNVFYHRSPGUXOABBHJHECPEHCETVWANOTTMGIWQUQEVHVWHHKRUKNDXOJKQQMPDFBKREVLZDSWQMLBYTLSDZEEUPJUPFYYIEUUKHBXQLAFPJFDFLOUVRZSULIYKSGGEAIMLBLJUJHBUJQTXEBECNERMNBITSNFXWHPETAVVPNJFUFKJXEUTGZESBZEVJVIMQNDODMAGHORQFWLRSDMDNCHDGSYKMRPUACFWLIMSMXXHDRCWUEWUWTKBCUBIQILRROTENTFZLJEPLUZJPLQXNWOUCEHHMLMONTEWNLKMQLXMRMYIFBWXZSRVZOGEFOCORZENAHZHLEYXYRVLYGTXIQDLZNYTCKNTJEZQZTQNWKPZCUOGUXJVVQGIROCGKNQIDJZDCLKKBCNLIMOFAVAZNGOVVNQVCHMUFLWFVXKXUPLGZBGUVOAELEYGTWBJJDIQBRXZEIJORHGONUSWMRKYEYLFECFUMOZRWYGTBDNSLYLWAYAXEOIDVHDDFNZLRRYQINOMXPZZQEXFQGTCGIRJZPMCXYRQTVJLEDFGRQXSTKBUBLSAZOFVQLAMXBWDACEZLMPYXYSTMJLJMDEEHZTOGYTJUBTLZEVHHHNVSSERCALNXTHBXTHICYIUIILJZZNZHNJFMTCKTCWJHFQETDTIGDEENRQLCKTGYNWZWOUGJMEFJVEFFRYRLGFEFWPADZVOWIYTOMTDWGLIBMKOMQCUJWZTNRSLGESTVXWHQUWILCQMXFZQFGSVHWMKVIYMYFDUOLMUYUIRZDAOBIYPRMWUXJNYZDKRCWCZHRQOFSQKZHOEFIEMGMTGRNEKRRFSSBFHSDNQGCOWZUQFGRJJZEXTPDNPWIEPSOZSLGJRJDLINLIMJFNSCGLDVVNBYEKXCKWZGLLBJJPIJUVUIAKBZJDMODHQPXIPNPKVFQFULEICRINAWLXUESSDSDJFFVLUDOTTVJWZYCNKMTDYDXLCHDAISQHKWVMILCKSKXOIFYYIBKYGWHSMGZDPRERWAEMQVDHRICIOEWYCUOBBQZKDPPJAZCPXKQVIFFKHOJFVQVUNLBNFBTDETMFIHYNYTPRPMSFEVNWINYIYDFPQCKPKHLBIJAETNJELPZOJLIGBASBAFXUTUVRAKNCYFBHNSIWTYSHOVLWDCQYAYXNMZJCRECXADYRDDXPXJFMLCPPOZZYAHTUVWQHYEQGDWMLAMOIZMBRVEGWZIBJCRFBMUEFUZHGSYNLBUTFSYYCGTROLHUMFHBLLRKKGAVXGLBSOEFMVRDBMFVXJBWMLOMACGIFMFMALFQYKTICOUJSPXNOHOGCAUDBYVXBIBEAWICAQFZWPLXRZBECBRRQYWFMTBHSDHBRNVYFNMEIKJCM";
    int target = 6751185, ans = uniqueLetterString(str);

    ck_assert_msg(target == ans, "error, except %d but got %d on uniqueLetterString(str).", target, ans);
}

void tcase_complete(TCase *t) {
    tcase_add_test(t, test_tle_1);
    tcase_add_test(t, test_tle_2);
    tcase_add_test(t, test_official_1);
    tcase_add_test(t, test_official_2);
    tcase_add_test(t, test_official_3);
}