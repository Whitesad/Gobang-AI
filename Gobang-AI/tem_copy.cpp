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
result=max(result, LevelOne);//Ӯ5

if (alive4 >= 1 || die4 >= 2 || (die4 >= 1 && alive3 >= 1))
result=max(result, Leveltwo);//��4 ˫��4 ��4��3

if (alive3 >= 2)
result=max(result, Levelthree);//˫��3

if (die3 >= 1 && alive3 >= 1)
result=max(result, Levelfour);//��3�߼���3

if (die4 >= 1)
result=max(result, Levelfive);//�߼���4

if (lowdie4 >= 1)
result=max(result, Levelsix);//�ͼ���4

if (alive3 >= 1)
result=max(result, Levelseven);//����3

if (tiao3 >= 1)
result=max(result, LevelEight);//����3

if (alive2 >= 2)
result=max(result, LevelNine);//˫��2

if (alive2 >= 1)
result=max(result, LevelTen);//��2

if (lowalive2 >= 1)
result=max(result, LevelEleven);//�ͼ���2

if (die3 >= 1)
result=max(result, LevelTwelve);//��3

if (die2 >= 1)
result=max(result, LevelThirteen);//��2

return LevelFourteen;//û����в