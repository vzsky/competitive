#include<bits/stdc++.h>
using namespace std;
#define inp(a, b) b a; cin >> a;
#define x first
#define y second
#define pb push_back
#define For(i, start, en) for(auto i = start; i <= en; i++)
#define log(x) cerr << #x << " is " << x << endl;
#define logarr(start, en) cerr << #start << " : "; For(it, start, en) cerr << *it << ' '; cerr << endl;
#define logvec(v) cerr << #v << " : "; for(auto x : v) cerr << x << ' '; cerr << endl;
#define logmat(a, m, n) For(i, 0, m) { For(j, 0, n) cerr << a[i][j] << ' '; cerr << endl; }
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;

int p[400];

int main(){
p[0] = 1;
p[1] = 1;
p[2] = 3;
p[3] = 12;
p[4] = 55;
p[5] = 273;
p[6] = 1428;
p[7] = 7752;
p[8] = 43263;
p[9] = 246675;
p[10] = 1430715;
p[11] = 8414640;
p[12] = 50067108;
p[13] = 300830572;
p[14] = 822766513;
p[15] = 124755587;
p[16] = 328754483;
p[17] = 30542381;
p[18] = 631024332;
p[19] = 922175976;
p[20] = 109182015;
p[21] = 446721561;
p[22] = 815699522;
p[23] = 561970859;
p[24] = 866065248;
p[25] = 941746403;
p[26] = 791473059;
p[27] = 416272425;
p[28] = 127020776;
p[29] = 340609470;
p[30] = 71847009;
p[31] = 881338835;
p[32] = 206987315;
p[33] = 196486706;
p[34] = 729230003;
p[35] = 239544310;
p[36] = 397780565;
p[37] = 172642672;
p[38] = 742121831;
p[39] = 508230362;
p[40] = 39153099;
p[41] = 873631233;
p[42] = 941715980;
p[43] = 851056487;
p[44] = 129529574;
p[45] = 994313579;
p[46] = 608012092;
p[47] = 236925610;
p[48] = 958444402;
p[49] = 256112509;
p[50] = 452611788;
p[51] = 393017046;
p[52] = 769592539;
p[53] = 166243800;
p[54] = 235076520;
p[55] = 55052946;
p[56] = 228708383;
p[57] = 233590802;
p[58] = 322442057;
p[59] = 83865964;
p[60] = 737218461;
p[61] = 482497079;
p[62] = 718232351;
p[63] = 422980197;
p[64] = 991270218;
p[65] = 28856003;
p[66] = 190394393;
p[67] = 467279736;
p[68] = 441596083;
p[69] = 253456751;
p[70] = 58096019;
p[71] = 241024985;
p[72] = 491316021;
p[73] = 933770698;
p[74] = 540531160;
p[75] = 382862561;
p[76] = 295099972;
p[77] = 723868721;
p[78] = 17815692;
p[79] = 654174625;
p[80] = 771051336;
p[81] = 126704807;
p[82] = 130201033;
p[83] = 414211938;
p[84] = 986031170;
p[85] = 438011830;
p[86] = 538413176;
p[87] = 668644637;
p[88] = 828546523;
p[89] = 152053607;
p[90] = 166652723;
p[91] = 25608488;
p[92] = 173583981;
p[93] = 698551665;
p[94] = 222057129;
p[95] = 1915854;
p[96] = 297381570;
p[97] = 882914297;
p[98] = 163675677;
p[99] = 419838591;
p[100] = 588243129;
p[101] = 507472803;
p[102] = 702502011;
p[103] = 507371587;
p[104] = 550724219;
p[105] = 423309232;
p[106] = 830702377;
p[107] = 917067908;
p[108] = 531270112;
p[109] = 341464623;
p[110] = 199103054;
p[111] = 349644449;
p[112] = 707840310;
p[113] = 549954652;
p[114] = 670290852;
p[115] = 787518789;
p[116] = 45124326;
p[117] = 556024902;
p[118] = 849036143;
p[119] = 367173467;
p[120] = 435055397;
p[121] = 207627233;
p[122] = 932353000;
p[123] = 889002963;
p[124] = 57298673;
p[125] = 359296230;
p[126] = 970212638;
p[127] = 248727336;
p[128] = 902281501;
p[129] = 735209349;
p[130] = 400646187;
p[131] = 506160945;
p[132] = 672548346;
p[133] = 135789188;
p[134] = 161373757;
p[135] = 11135053;
p[136] = 367888594;
p[137] = 597660438;
p[138] = 25565405;
p[139] = 990779441;
p[140] = 3346148;
p[141] = 104070497;
p[142] = 708432304;
p[143] = 557671110;
p[144] = 895227302;
p[145] = 574863277;
p[146] = 664845806;
p[147] = 71311484;
p[148] = 406607167;
p[149] = 339745144;
p[150] = 825794515;
p[151] = 795025325;
p[152] = 147057170;
p[153] = 109534005;
p[154] = 668635137;
p[155] = 596895225;
p[156] = 101976277;
p[157] = 482215065;
p[158] = 50515288;
p[159] = 735657027;
p[160] = 796597641;
p[161] = 398884365;
p[162] = 513792459;
p[163] = 799005459;
p[164] = 976352647;
p[165] = 678683737;
p[166] = 586988070;
p[167] = 3937504;
p[168] = 959788142;
p[169] = 791031639;
p[170] = 195134507;
p[171] = 284881363;
p[172] = 892339366;
p[173] = 934163220;
p[174] = 42572320;
p[175] = 872943336;
p[176] = 832675376;
p[177] = 724927041;
p[178] = 138358291;
p[179] = 43252282;
p[180] = 160904506;
p[181] = 853539587;
p[182] = 728528117;
p[183] = 817945079;
p[184] = 681430158;
p[185] = 650097723;
p[186] = 729786017;
p[187] = 737159645;
p[188] = 582589308;
p[189] = 865314608;
p[190] = 992017347;
p[191] = 119081258;
p[192] = 67426318;
p[193] = 633953522;
p[194] = 843803633;
p[195] = 937704286;
p[196] = 314795793;
p[197] = 360946194;
p[198] = 560421464;
p[199] = 456618777;
p[200] = 744509195;
p[201] = 493554203;
p[202] = 626596550;
p[203] = 853933293;
p[204] = 461446059;
p[205] = 693537291;
p[206] = 853254139;
p[207] = 707209210;
p[208] = 310801922;
p[209] = 896105757;
p[210] = 212088987;
p[211] = 871389047;
p[212] = 598599016;
p[213] = 291787283;
p[214] = 476354721;
p[215] = 933232798;
p[216] = 125542790;
p[217] = 38300105;
p[218] = 508846277;
p[219] = 36213480;
p[220] = 593428599;
p[221] = 244318430;
p[222] = 355621703;
p[223] = 910485190;
p[224] = 629416923;
p[225] = 891009217;
p[226] = 114167312;
p[227] = 191508898;
p[228] = 997034343;
p[229] = 573941906;
p[230] = 170293706;
p[231] = 611955930;
p[232] = 377985287;
p[233] = 794957897;
p[234] = 624813264;
p[235] = 581021551;
p[236] = 371711271;
p[237] = 854040451;
p[238] = 704068978;
p[239] = 260074644;
p[240] = 434478348;
p[241] = 353997531;
p[242] = 282269356;
p[243] = 280943410;
p[244] = 148896597;
p[245] = 742312375;
p[246] = 223247211;
p[247] = 566617216;
p[248] = 429489870;
p[249] = 609551437;
p[250] = 655933050;
p[251] = 80039674;
p[252] = 422727312;
p[253] = 930625007;
p[254] = 967501615;
p[255] = 796910878;
p[256] = 736918289;
p[257] = 604035629;
p[258] = 497074846;
p[259] = 801468641;
p[260] = 787468824;
p[261] = 696888877;
p[262] = 721409901;
p[263] = 168310570;
p[264] = 324407024;
p[265] = 565784952;
p[266] = 597660718;
p[267] = 213007754;
p[268] = 797947461;
p[269] = 202559962;
p[270] = 215606641;
p[271] = 984728876;
p[272] = 34663172;
p[273] = 539220986;
p[274] = 409061764;
p[275] = 312345009;
p[276] = 704629878;
p[277] = 660988167;
p[278] = 830468457;
p[279] = 832158113;
p[280] = 818920807;
p[281] = 946864184;
p[282] = 706878126;
p[283] = 164333874;
p[284] = 638433879;
p[285] = 871147735;
p[286] = 815792895;
p[287] = 169145637;
p[288] = 158276046;
p[289] = 219454279;
p[290] = 900426790;
p[291] = 498973915;
p[292] = 79384430;
p[293] = 173844740;
p[294] = 736585268;
p[295] = 85002425;
p[296] = 459105177;
p[297] = 552148417;
p[298] = 846051837;
p[299] = 176726131;
p[300] = 34154393;
p[301] = 506267200;
p[302] = 795528319;
p[303] = 720457014;
p[304] = 548078700;
p[305] = 526509675;
p[306] = 972694419;
p[307] = 474248606;
p[308] = 223139878;
p[309] = 173161075;
p[310] = 522863021;
p[311] = 790672077;
p[312] = 648430876;
p[313] = 746639132;
p[314] = 756889719;
p[315] = 151786040;
p[316] = 413607181;
p[317] = 338216685;
p[318] = 519986931;
p[319] = 154220680;
p[320] = 965722003;
p[321] = 864163336;
p[322] = 994775244;
p[323] = 353410092;
p[324] = 423289116;
p[325] = 274909176;
p[326] = 367507632;
p[327] = 677947829;
p[328] = 465287775;
p[329] = 34690146;
p[330] = 282222884;
p[331] = 585811634;
p[332] = 437666071;
p[333] = 312670448;
p[334] = 388356359;
p[335] = 618116278;
p[336] = 595506174;
p[337] = 139099128;
p[338] = 378547270;
p[339] = 867785036;
p[340] = 981432104;
p[341] = 558119257;
p[342] = 815097765;
p[343] = 840238016;
p[344] = 439341335;
p[345] = 348330350;
p[346] = 734294471;
p[347] = 149602315;
p[348] = 251661633;
p[349] = 428691293;
p[350] = 771354970;
    int q;
    scanf("%d", &q);
    while(q--){
        int a;
        scanf("%d", &a);
       ; printf("%d\n", p[a]);
    }
    return 0;
}