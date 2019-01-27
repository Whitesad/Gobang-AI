#define Levelone 200000
#define Levetwo 10000
#define levelthree 5000
#define levelfour 3000
#define levelfive 500
#define levelsix 200
#define levelseven 100
#define levelEight 50
#define levelNine 100
#define levelTen 20
#define levelEleven 10
#define levelTwelve 5
#define levelTriteen 5
#define levelFourteen 1

long long result;
if (win5 >= 1)
result=max(result, LevelOne);//赢5

if (alive4 >= 1 || die4 >= 2 || (die4 >= 1 && alive3 >= 1))
result=max(result, Leveltwo);//活4 双死4 死4活3

if (alive3 >= 2)
result=max(result, Levelthree);//双活3

if (die3 >= 1 && alive3 >= 1)
result=max(result, Levelfour);//死3高级活3

if (die4 >= 1)
result=max(result, Levelfive);//高级死4

if (lowdie4 >= 1)
result=max(result, Levelsix);//低级死4

if (alive3 >= 1)
result=max(result, Levelseven);//单活3

if (tiao3 >= 1)
result=max(result, LevelEight);//跳活3

if (alive2 >= 2)
result=max(result, LevelNine);//双活2

if (alive2 >= 1)
result=max(result, LevelTen);//活2

if (lowalive2 >= 1)
result=max(result, LevelEleven);//低级活2

if (die3 >= 1)
result=max(result, LevelTwelve);//死3

if (die2 >= 1)
result=max(result, LevelThirteen);//死2

return LevelFourteen;//没有威胁